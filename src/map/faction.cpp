// Complete Faction System (c) Lilith
// Skype: amurov4shtefan
// ICQ: 450327002
// Gmail: amurov.ro@gmail.com
// MSN: amurov.ro@hotmail.com

#include "../common/db.hpp"
#include "../common/malloc.hpp"
#include "../common/socket.hpp"
#include "../common/showmsg.hpp"
#include "../common/strlib.hpp"
#include "../common/nullpo.hpp"

#include "atcommand.hpp"
#include "faction.hpp"
#include "elemental.hpp"
#include "homunculus.hpp"
#include "map.hpp"
#include "mercenary.hpp"
#include "mapreg.hpp"
#include "mob.hpp"
#include "npc.hpp"
#include "pc.hpp"
#include "pet.hpp"
#include "skill.hpp"
#include "status.hpp"
#include "script.hpp"
#include "channel.hpp"

#include <stdlib.h>

static DBMap* faction_db; // int faction_id -> struct faction_data*
static DBMap* voting_db; // int char_id -> struct voting_data*

void faction_change_leader(int faction_id, int char_id)
{
	struct faction_data *fdb;
	TBL_PC *sd = NULL, *new_sd = NULL;
	struct skill_unit_group *group = NULL;
	char output[CHAT_SIZE_MAX];

	if( (fdb = faction_search(faction_id)) == NULL )
		return;

	if( fdb->leader_id == char_id )
		return;

	if( (sd = map_charid2sd(fdb->leader_id)) ) {
		if( sd->sc.data[SC_FACTION_AURA] && (group = skill_id2group(sd->sc.data[SC_FACTION_AURA]->val4)) ) {
			skill_delunitgroup(group);
			status_change_end(&sd->bl,SC_FACTION_AURA,INVALID_TIMER);
		}
	}

	memset(output, '\0', sizeof(output));
	sprintf(output, "$faction_leader_id_%d",faction_id);
	mapreg_setreg(add_str(output), char_id);
	fdb->leader_id = char_id;

	if( (new_sd = map_charid2sd(char_id)) )
		faction_factionaura(new_sd);
}

void faction_voting_add(struct map_session_data *sd, struct map_session_data *ssd, int votes)
{
	struct voting_data *vdb;

	if( !ssd->status.faction_id )
		return;

	if( (vdb = voting_search(ssd->status.char_id)) == NULL ) {
		CREATE(vdb,struct voting_data,1);
		memcpy(vdb->name, ssd->status.name, NAME_LENGTH);
		vdb->faction_id = ssd->status.faction_id;
		vdb->char_id = ssd->status.char_id;
		vdb->votes = votes;
		idb_put(voting_db,ssd->status.char_id,vdb);

	} else vdb->votes += votes;

	if( sd ) {
		if( (vdb = voting_search(sd->status.char_id)) == NULL ) {
			CREATE(vdb,struct voting_data,1);
			memcpy(vdb->name, sd->status.name, NAME_LENGTH);
			vdb->faction_id = sd->status.faction_id;
			vdb->char_id = sd->status.char_id;
			vdb->voted = true;
			idb_put(voting_db,sd->status.char_id,vdb);

		} else vdb->voted = true;
	}
}

void faction_voting_finish(int faction_id)
{
	struct faction_data *fdb;
	struct voting_data *vdb = NULL;
	int max = 0, char_id = 0, k = 0;
	DBIterator *iter;

	if( (fdb = faction_search(faction_id)) == NULL )
		return;

	fdb->voting_active = false;

	iter = db_iterator(voting_db);
	for( vdb = (struct voting_data*)dbi_first(iter); dbi_exists(iter); vdb = (struct voting_data*)dbi_next(iter) ) {
		if( vdb->faction_id == faction_id && vdb->votes > max ) {
			max = vdb->votes;
			char_id = vdb->char_id;
		}
		k++;
	}
	dbi_destroy(iter);

	faction_change_leader(faction_id, char_id);
}

void faction_voting_start(int faction_id)
{
	struct faction_data *fdb;
	struct voting_data *vdb;
	DBIterator *iter;

	if( (fdb = faction_search(faction_id)) == NULL )
		return;

	iter = db_iterator(voting_db);
    for( vdb = (struct voting_data*)dbi_first(iter); dbi_exists(iter); vdb = (struct voting_data*)dbi_next(iter) )
		if( vdb->faction_id == faction_id )
			idb_remove(voting_db,vdb->char_id);
	dbi_destroy(iter);

	fdb->voting_active = true;
}

void faction_voting_info(int faction_id)
{
	int j = 0;
	struct voting_data *vdb = NULL;
	DBIterator *iter = db_iterator(voting_db);
	for( vdb = (struct voting_data*)dbi_first(iter); dbi_exists(iter); vdb = (struct voting_data*)dbi_next(iter) ) {
		if( vdb->faction_id == faction_id ) {
			mapreg_setreg(reference_uid(add_str("$@voting_charid"), j),vdb->char_id);
			mapreg_setregstr(reference_uid(add_str("$@voting_charname$"), j),vdb->name);
			mapreg_setreg(reference_uid(add_str("$@voting_votes"), j),vdb->votes);
			mapreg_setreg(reference_uid(add_str("$@voting_voted"), j),vdb->voted);
			j++;
		}
	}
	dbi_destroy(iter);
	mapreg_setreg(add_str("$@votinglist_count"),j);
	return;
}

struct voting_data *voting_search(int char_id)
{
	return (struct voting_data*)idb_get(voting_db,char_id);
}

int faction_check_leader(struct map_session_data *sd)
{
	struct faction_data *fdb;

	if( (fdb = faction_search(sd->status.faction_id)) == NULL )
		return 0;

	return (fdb->leader_id == sd->status.char_id);
}

int faction_reload_fvf_sub(struct block_list *bl, va_list ap)
{
	if( !faction_get_id(bl) )
		return 0;

	switch( bl->type ) {
		case BL_PC:
			{
				TBL_PC *sd = (TBL_PC*)bl;
				status_calc_pc(sd,SCO_NONE);
				if( !pc_isdead(sd) )
					pc_setpos(sd, sd->mapindex, bl->x, bl->y, CLR_RESPAWN);
			}
		break;

		case BL_NPC:
		case BL_MOB:
			{
				struct status_change* sc = status_get_sc(bl);
				if( sc->option&(OPTION_HIDE|OPTION_CLOAK|OPTION_CHASEWALK|OPTION_INVISIBLE) || sc->data[SC_CAMOUFLAGE] )
					break;
			}
		default:
			clif_spawn(bl);
		break;
	}
	return 0;
}

int faction_relic_change_sub(struct map_session_data *sd, va_list ap)
{
	int faction_id = va_arg(ap,int);

	if( !sd->status.faction_id || sd->status.faction_id != faction_id )
		return 0;

	faction_calc(&sd->bl);
		return 0;
}

void faction_factionaura(struct map_session_data *sd)
{
	struct skill_unit_group *group = NULL;

	if( sd->sc.data[SC_FACTION_AURA] && (group = skill_id2group(sd->sc.data[SC_FACTION_AURA]->val4)) ) {
		skill_delunitgroup(group);
		status_change_end(&sd->bl,SC_FACTION_AURA,INVALID_TIMER);
	}

	if( (group = skill_unitsetting(&sd->bl,FACTION_AURA,1,sd->bl.x,sd->bl.y,0)) != NULL )
		sc_start4(&sd->bl,&sd->bl,SC_FACTION_AURA,100,1,group->faction_id,0,group->group_id,600000);
}

void faction_calc(struct block_list *bl)
{
	struct faction_data *fdb;

	if( (fdb = faction_search(faction_get_id(bl))) == NULL )
		return;

	if( bl->type == BL_PC ) {
		TBL_PC *sd = (TBL_PC*)bl;
		struct item_data *item_data = NULL;
		struct status_change *sc = status_get_sc(bl);
		int i;

		if( fdb->script )
			run_script(fdb->script,0,sd->bl.id,0);

		if( sc && sc->data[SC_FACTION_AURA] && sc->data[SC_FACTION_AURA]->val2 && sc->data[SC_FACTION_AURA]->val2 == sd->status.faction_id ) {
			struct faction_data *t_fdb = faction_search(sc->data[SC_FACTION_AURA]->val2);
			if( t_fdb->aura_bonus )
				run_script(t_fdb->aura_bonus,0,sd->bl.id,0);
		}

		for( i = 0; i < MAX_RELIC; i++ )
			if( ((map[bl->m].faction.id == sd->status.faction_id && map[bl->m].faction.relic == i) || fdb->relic[i].active) &&
				(item_data = itemdb_exists(fdb->relic[i].item_id)) && item_data->script )
				run_script(item_data->script,0,sd->bl.id,0);
	}

	if( battle_config.faction_status_bl&bl->type ) {
		struct status_data *status = bl->type == BL_MOB ? status_get_status_data(bl) : status_get_base_status(bl);

		status->race 	= fdb->race;
		status->def_ele	= fdb->ele;
		status->ele_lv 	= fdb->ele_lvl;
		status->size	= fdb->size;
	}
}

void faction_hp(struct map_session_data *sd)
{
	uint8 buf[34];
	const int cmd = 0x2e0;
	nullpo_retv(sd);

	WBUFW(buf,0) = cmd;
	WBUFL(buf,2) = sd->status.account_id;
	memcpy(WBUFP(buf,6), sd->status.name, NAME_LENGTH);

	if( sd->battle_status.max_hp > INT16_MAX ) {
		WBUFW(buf,30) = sd->battle_status.hp/(sd->battle_status.max_hp/100);
		WBUFW(buf,32) = 100;
	} else {
		WBUFW(buf,30) = sd->battle_status.hp;
		WBUFW(buf,32) = sd->battle_status.max_hp;
	}
	clif_send(buf, packet_len(cmd), &sd->bl, FACTION_AREA_WOS);
}

void faction_spawn(struct block_list *bl)
{
	struct faction_data *fdb;
	uint8 buf[33];

	if( (fdb = faction_search(faction_get_id(bl))) == NULL )
		return;

	if( map_getmapflag(bl->m, MF_FVF) ) {
		if( battle_config.faction_ally_info_bl ) {
			if( battle_config.faction_ally_info_bl&bl->type ) {
				WBUFW(buf, 0) = 0x2dd;
				WBUFL(buf,2) = bl->id;
				safestrncpy((char*)WBUFP(buf,6), status_get_name(bl), NAME_LENGTH);
				WBUFW(buf,30) = faction_get_id(bl);
				clif_send(buf,packet_len(0x2dd), bl, FVF_OTHER_AREA_CHAT);
			}
		} else {
			WBUFW(buf,0) = 0x1b4;
			WBUFL(buf,2) = bl->id;
			WBUFL(buf,6) = fdb->id;
			WBUFW(buf,10) = faction_check_leader(((TBL_PC*)bl)) ? fdb->l_emblem_id : fdb->emblem_id;
			clif_send(buf, 12, bl, AREA_WOS);
		}
	}

	if( battle_config.faction_size_bl&bl->type && ((battle_config.fvf_visual_size&1 && map_getmapflag(bl->m, MF_FVF)) || battle_config.fvf_visual_size&2) ) {
		if( fdb->size == SZ_BIG )
			clif_specialeffect(bl,423,AREA);
		else if( fdb->size == SZ_MEDIUM )
			clif_specialeffect(bl,421,AREA);
	}

	faction_show_aura(bl);
}

void faction_show_aura(struct block_list *bl)
{
	struct faction_data *fdb = faction_search(faction_get_id(bl));
	struct status_change *sc = NULL;
	int i;

	if( bl->type&(BL_CHAR|BL_NPC) ) {
		sc = status_get_sc(bl);
		if( sc->option&(OPTION_HIDE|OPTION_CLOAK|OPTION_CHASEWALK|OPTION_INVISIBLE) || sc->data[SC_CAMOUFLAGE] )
			return;
	}

	if( !((battle_config.faction_aura_settings&1 && map_getmapflag(bl->m, MF_FVF) || battle_config.faction_aura_settings&2)) )
		return;

	if( battle_config.faction_aura_bl&bl->type ) {
		for( i = 0; i < MAX_AURA_EFF; i++ )
			if( fdb->aura[i] > 0 )
				clif_specialeffect(bl, fdb->aura[i], AREA);
	}
}

void faction_getareachar_unit(struct map_session_data *sd, struct block_list *bl)
{
	struct faction_data *fdb;
	struct status_change *sc = NULL;
	int i, fd;

	if( !sd->status.faction_id || (fdb = faction_search(faction_get_id(bl))) == NULL )
		return;

	fd = sd->fd;
	if( map_getmapflag(bl->m, MF_FVF) ) {
		if( battle_config.faction_ally_info_bl ) {
			if( battle_config.faction_ally_info_bl&bl->type && !faction_check_alliance(&sd->bl, bl) ) {
				WFIFOHEAD(fd,32);
				WFIFOW(fd,0) = 0x2dd;
				WFIFOL(fd,2) = bl->id;
				safestrncpy((char*)WFIFOP(fd,6), status_get_name(bl), NAME_LENGTH);
				WFIFOW(fd,30) = faction_get_id(bl);
				WFIFOSET(fd,packet_len(0x2dd));
			}
		} else {
			if( faction_check_leader(((TBL_PC*)bl)) ) {
				WFIFOHEAD(fd,fdb->l_emblem_len+12);
				WFIFOW(fd,2)=fdb->l_emblem_len+12;
				WFIFOL(fd,8)=fdb->l_emblem_id;
				memcpy(WFIFOP(fd,12),fdb->l_emblem_data,fdb->l_emblem_len);
			} else {
				WFIFOHEAD(fd,fdb->emblem_len+12);
				WFIFOW(fd,2)=fdb->emblem_len+12;
				WFIFOL(fd,8)=fdb->emblem_id;
				memcpy(WFIFOP(fd,12),fdb->emblem_data,fdb->emblem_len);
			}
				WFIFOW(fd,0)=0x152;
				WFIFOL(fd,4)=fdb->id;
				WFIFOSET(fd,WFIFOW(fd,2));
		}
	}

	if( battle_config.faction_size_bl&bl->type && ((battle_config.fvf_visual_size&1 && map_getmapflag(bl->m, MF_FVF)) || battle_config.fvf_visual_size&2) ) {
		if( fdb->size == SZ_BIG )
			clif_specialeffect_single(bl,423,fd);
		else if( fdb->size == SZ_MEDIUM )
			clif_specialeffect_single(bl,421,fd);
	}

	if( bl->type&(BL_CHAR|BL_NPC) ) {
		sc = status_get_sc(bl);
		if( sc->option&(OPTION_HIDE|OPTION_CLOAK|OPTION_CHASEWALK|OPTION_INVISIBLE) || sc->data[SC_CAMOUFLAGE] )
			return;
	}

	if( !((battle_config.faction_aura_settings&1 && map_getmapflag(bl->m, MF_FVF)) || battle_config.faction_aura_settings&2) )
		return;

	if( battle_config.faction_aura_bl&bl->type ) {
		for( i = 0; i < MAX_AURA_EFF; i++ )
			if( fdb->aura[i] > 0 )
				clif_specialeffect_single(bl, fdb->aura[i], fd);
	}
}

int faction_aura_clear(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd = BL_CAST(BL_PC,bl);
	struct block_list *tbl = va_arg(ap,struct block_list*);

	if( bl == tbl )
		return 0;

	clif_getareachar_unit(sd,tbl);
	return 0;
}

int faction_check_alliance(struct block_list *bl, struct block_list *t_bl)
{
	struct faction_data *fdb = NULL, *t_fdb = NULL;
	int i;

	if( (fdb = faction_search(faction_get_id(bl))) == NULL ||
		(t_fdb = faction_search(faction_get_id(t_bl))) == NULL )
		return 0;

	if( faction_get_id(bl) == faction_get_id(t_bl) )
		return 1;

	ARR_FIND( 0, MAX_FACTION_ALLIANCE, i, (fdb->alliance[i] == faction_get_id(t_bl) || t_fdb->alliance[i] == faction_get_id(bl)) );
	if( i < MAX_FACTION_ALLIANCE )
		return 1;	

	return 0;
}

struct faction_data *faction_search(int id)
{
	return (struct faction_data*)idb_get(faction_db,id);
}

int faction_get_id(struct block_list *bl)
{
	if( bl )
	switch( bl->type ) {
		case BL_PC:			// Player
			return ((TBL_PC*)bl)->status.faction_id;
		case BL_PET:		// Pet
			if( ((TBL_PET*)bl)->master )
				return ((TBL_PET*)bl)->master->status.faction_id;
		case BL_MOB:		// Monster
		{
			struct map_session_data *msd;
			struct mob_data *md = (TBL_MOB*)bl;
			if( md->special_state.ai && (msd = map_id2sd(md->master_id)) != NULL )
				return msd->status.faction_id;
			return md->faction_id;
		}
		case BL_NPC:		// NPC
			return ((TBL_NPC*)bl)->faction_id;
		case BL_HOM:		// Homunculus
			if( ((TBL_HOM*)bl)->master )
				return ((TBL_HOM*)bl)->master->status.faction_id;
		case BL_MER:		// Mercenary
			if( ((TBL_MER*)bl)->master )
				return ((TBL_MER*)bl)->master->status.faction_id;
		case BL_ELEM:		// Elemental
			if( ((TBL_ELEM*)bl)->master )
				return ((TBL_ELEM*)bl)->master->status.faction_id;
		case BL_SKILL:		// Skill
			return ((TBL_SKILL*)bl)->group->faction_id;
		default:
			break;
	}
	return 0;
}

// ID,Faction Name,Faction Player name,Location,X,Y,Race,Element,Element lvl,Size,Clothes Color,Color of mes,{ Aura: #1 #2 #3 },{ Script Bonus },{ Faction Aura Script Bonus }
static int faction_readdb(void)
{
	struct faction_data *fdb;
	const char *filename = "faction_db.txt";
	uint32 lines = 0, count = 0;
	char line[1024], path[256];
	FILE *fp;
	void *aChSysSave = NULL;

	sprintf(path, "%s/%s", db_path, filename);
	if((fp = fopen(path, "r")) == NULL ) {
		ShowWarning("faction_readdb: File not found \"%s\", skipping.\n", path);
		return 0;
	}

	while(fgets(line, sizeof(line), fp)) {
		char *str[14], *p, *p_tmp, map[MAP_NAME_LENGTH], out[100];
		int i, id, race, ele, ele_lvl, size, x, y, k = 0, ccolor;
		int aura[MAX_AURA_EFF];
		unsigned long chat_color;
		uint16 mapindex = -1;
		FILE *fp2 = NULL;

		lines++;
		if(line[0] == '/' && line[1] == '/')
			continue;
		memset(out, 0, sizeof(out));
		memset(map, 0, sizeof(map));
		memset(aura, 0, sizeof(aura));
		memset(str, 0, sizeof(str));

		p = line;

		while( ISSPACE(*p) )
			++p;
		if( *p == '\0' )
			continue;
		for( i = 0; i < 12; ++i ) {
			str[i] = p;
			p = strchr(p,',');
			if( p == NULL )
				break;
			*p = '\0';
			++p;
		}

		if( p == NULL ) {
			ShowError("faction_readdb: Insufficient columns in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}

		id = atoi(str[0]);
		if( id < 1 || id > MAX_FACTION ) {
			ShowError("faction_readdb : Incorrect Faction ID: %d, must be between 0 and %d\n", id, MAX_FACTION);
			continue;
		} else if( faction_search(id) ) {
			ShowError("faction_readdb : Duplicate Faction ID %d, line %d.\n", id, lines);
			continue;
		}

		safestrncpy(map,str[3],MAP_NAME_LENGTH);
		if( map[0] != '\0' && (mapindex = mapindex_name2id(map)) < 0 ) {
			ShowWarning("faction_readdb: Invalid map: '%s' in line %d of \"%s\" (faction id %d).\n", map, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb: removing home location...\n");
			memset(map, '\0', sizeof(map));
		}

		if( mapindex >= 0 ) {
			x = atoi(str[4]);
			if( x < 0 || x > 512 ) {
				ShowWarning("faction_readdb : Invalid X coordinate: %d, in line %d of \"%s\" (faction id %d).\n", x, lines, path, atoi(str[0]));
				ShowWarning("faction_readdb : X must be between 0 and 512. Default to 0.\n");
				x = 0;
			}

			y = atoi(str[5]);
			if( y < 0 || y > 512 ) {
				ShowWarning("faction_readdb : Invalid Y coordinate: %d, in line %d of \"%s\" (faction id %d).\n", y, lines, path, atoi(str[0]));
				ShowWarning("faction_readdb : Y must be between 0 and 512. Default to 0.\n");
				y = 0;
			}
		} else x = y = 0;

		race = atoi(str[6]);
		if( race < RC_FORMLESS || race > RC_DRAGON ) {
			ShowWarning("faction_readdb : Invalid race: %d, in line %d of \"%s\" (faction id %d).\n", race, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : race must be between %d and %d. Default to %d.\n", RC_FORMLESS, RC_DRAGON, RC_DEMIHUMAN);
			race = RC_DEMIHUMAN;
		}

		ele = atoi(str[7]);
		if( ele < ELE_NEUTRAL || ele > ELE_UNDEAD ) {
			ShowWarning("faction_readdb : Invalid element: %d, in line %d of \"%s\" (faction id %d).\n", ele, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : element must be between %d and %d. Default to %d.\n", ELE_NEUTRAL, ELE_UNDEAD, ELE_NEUTRAL);
			ele = ELE_NEUTRAL;
		}

		ele_lvl = atoi(str[8]);
		if( ele_lvl < 1 || ele_lvl > 4 ) {
			ShowWarning("faction_readdb : Invalid element level: %d, in line %d of \"%s\" (faction id %d).\n", ele_lvl, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : element must be between 1 and 4. Default to 1.\n");
			ele_lvl = 1;
		}

		size = atoi(str[9]);
		if( size < 0 || size > 2 ) {
			ShowWarning("faction_readdb : Invalid size: %d, in line %d of \"%s\" (faction id %d).\n", size, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : size must be 0, 1 or 2. Default to 0.\n");
			size = 0;
		}

		ccolor = atoi(str[10]);
		if( ccolor < battle_config.min_cloth_color || ccolor > battle_config.max_cloth_color ) {
			ShowWarning("faction_readdb : Invalid clothes color: %d, in line %d of \"%s\" (faction id %d).\n", ccolor, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : clothes color must be between %d and %d. Default to %d.\n", battle_config.min_cloth_color, battle_config.max_cloth_color, battle_config.min_cloth_color);
			ccolor = battle_config.min_cloth_color;
		}

		chat_color = strtoul(str[11],NULL,0);
		chat_color = ( chat_color&0x0000FF ) << 16 | ( chat_color&0x00FF00 ) | ( chat_color&0xFF0000 ) >> 16;

		if( *p != '{' ) {
			ShowError("faction_readdb: Invalid format in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}
		p_tmp = p;
		p_tmp = strchr(p_tmp+1,'#');
		for( i = 0; i < MAX_AURA_EFF && p_tmp; i++ ) {
			if( !sscanf(p_tmp, "%d", &aura[k]) && !sscanf(p_tmp, "#%d", &aura[k]) )
			{
				ShowWarning("faction_readdb: Error parsing aura effects in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
				p_tmp = strchr(p_tmp+1,'#');
				continue;
			}
			p_tmp = strchr(p_tmp+1,'#');
			k++;
		}
		p = strstr(p+1,"},");
		if( p == NULL ) {
			ShowError("faction_readdb: Invalid format (Faction Bonus column) in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}
		p[1] = '\0';
		p += 2;
		if( *p != '{' ) {
			ShowError("faction_readdb: Invalid format (Faction Bonus column) in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}
		str[12] = p;
		p = strstr(p+1,"},");
		if( p == NULL ) {
			ShowError("faction_readdb: Invalid format (Faction Bonus column) in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}
		p[1] = '\0';
		p += 2;
		if( *p != '{' ) {
			ShowError("faction_readdb: Invalid format (Faction Aura Bonus column) in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}
		str[13] = p;
		p = strstr(p+1,"}");
		if ( strchr(p,',') != NULL ) {
			ShowError("faction_readdb: Extra columns in line %d of \"%s\" (faction with id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}

		CREATE(fdb,struct faction_data,1);
		fdb->id = id;
		safestrncpy(fdb->name,str[1],sizeof(fdb->name));
		safestrncpy(fdb->pl_name,str[2],sizeof(fdb->pl_name));
		memcpy(fdb->map, map, MAP_NAME_LENGTH);
		fdb->x = x;
		fdb->y = y;
		fdb->race = race;
		fdb->ele = ele;
		fdb->ele_lvl = ele_lvl;
		fdb->size = size;
		fdb->ccolor = ccolor;
		fdb->chat_color = chat_color;
		memcpy(&fdb->aura, &aura, sizeof(fdb->aura));
		fdb->script = parse_script(str[12],path,lines,0);
		fdb->aura_bonus = parse_script(str[13],path,lines,0);
		for( i = 0; i < MAX_RELIC; i++ ) {
			sprintf(out, "$faction_relics_%d",id);
			fdb->relic[i].item_id = mapreg_readreg(reference_uid(add_str(out), i));
		}
		sprintf(out, "$faction_leader_id_%d",id);
		fdb->leader_id = mapreg_readreg(add_str(out));

		fdb->emblem_id = 1;
		sprintf(path, "db/faction_emblem/faction_id_%d.ebm", id);
		if( (fp2 = fopen(path, "rb")) != NULL ) {
			fseek(fp2, 0, SEEK_END);
			fdb->emblem_len = ftell(fp2);
			fseek(fp2, 0, SEEK_SET);
			fread(&fdb->emblem_data, sizeof(fdb->emblem_data), 1, fp2);
			fclose(fp2);
		} else memset(fdb->emblem_data, 0, sizeof(fdb->emblem_data));

		fdb->l_emblem_id = 2;
		sprintf(path, "db/faction_emblem/faction_id_%d_leader.ebm", id);
		if( (fp2 = fopen(path, "rb")) != NULL ) {
			fseek(fp2, 0, SEEK_END);
			fdb->l_emblem_len = ftell(fp2);
			fseek(fp2, 0, SEEK_SET);
			fread(&fdb->l_emblem_data, sizeof(fdb->l_emblem_data), 1, fp2);
			fclose(fp2);
		} else memset(fdb->l_emblem_data, 0, sizeof(fdb->l_emblem_data));

		idb_put(faction_db,id,fdb);
		count++;
	}
	fclose(fp);
	ShowStatus("Done reading '" CL_WHITE"%lu" CL_RESET "' factions in file '" CL_WHITE "%s" CL_RESET "'.\n", count, filename);

	return 0;
}

static bool faction_read_alliance(char *str[], int columns, int current)
{
	struct faction_data *fdb, *t_fdb = NULL;
	int faction_id, alliance, i, k = 0;
	char *tmp;

	faction_id = atoi(str[0]);
	if( ( fdb = faction_search(faction_id) ) == NULL ) {
		ShowWarning("faction_read_alliance: Invalid faction id %d.\n", faction_id);
		return false;
	}
	tmp = str[1];
	for( i = 0; i < MAX_FACTION_ALLIANCE && tmp; i++ ) {
		if( !sscanf(tmp, "%d", &alliance) && !sscanf(tmp, ":%d", &alliance) ) {
			ShowError("faction_read_alliance: Parsing error.\n");
			continue;
		}
		if( (t_fdb = faction_search(alliance)) == NULL ) {
			ShowWarning("faction_read_alliance: Invalid alliance faction id %d.\n", alliance);
			tmp = strchr(tmp+1,':');
			continue;
		}
		tmp = strchr(tmp+1,':');
		fdb->alliance[k] = alliance;
		k++;
	}
	return true;
}

static void destroy_faction_data(struct faction_data *self, int free_self)
{
	if( self == NULL )
		return;
	if( self->script )
		script_free_code(self->script);
	if( self->aura_bonus )
		script_free_code(self->aura_bonus);
	if( free_self )
		aFree(self);
}

static int faction_final_sub(DBKey key, DBData *data, va_list ap)
{
	struct faction_data *fdb = (struct faction_data *)db_data2ptr(data);

	if( fdb != NULL )
		destroy_faction_data(fdb, 1);

	return 0;
}

static int voting_final_sub(DBKey key, DBData *data, va_list ap)
{
    struct voting_data *vdb = (struct voting_data *)db_data2ptr(data);

	if( vdb != NULL )
		aFree(vdb);

	return 0;
}

void faction_read(void)
{
	faction_readdb();
	sv_readdb(db_path, "faction_alliance.txt",',', 2, 2, -1, &faction_read_alliance, true);
}

void do_reload_faction(void)
{
	faction_db->clear(faction_db,faction_final_sub);
	faction_read();
	map_foreachiddb(faction_reload_fvf_sub);
}

void do_init_faction(void)
{
	faction_db 	= idb_alloc(DB_OPT_BASE);
	voting_db 	= idb_alloc(DB_OPT_BASE);
	faction_read();
}

void do_final_faction(void)
{
	// DBIterator *iter = db_iterator(faction_db);
	// struct faction_data *fdb;

    // for( fdb = (struct faction_data*)dbi_first(iter); dbi_exists(iter); fdb = (struct faction_data*)dbi_next(iter) ) {
    //     if( fdb->channel != NULL )
    //         channel_delete(fdb->channel,false);
    // }

	// dbi_destroy(iter);

	voting_db->destroy(voting_db,voting_final_sub);
	faction_db->destroy(faction_db,faction_final_sub);
}