// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _CHAR_LOGIF_HPP_
#define _CHAR_LOGIF_HPP_

#include "../common/cbasetypes.h"

struct char_session_data;

#if PACKETVER_SUPPORTS_PINCODE
void chlogif_pincode_notifyLoginPinError( uint32 account_id );
void chlogif_pincode_notifyLoginPinUpdate( uint32 account_id, char* pin );
void chlogif_pincode_start(int fd, struct char_session_data* sd);
#endif
int chlogif_send_acc_tologin(int tid, unsigned int tick, int id, intptr_t data);
int chlogif_broadcast_user_count(int tid, unsigned int tick, int id, intptr_t data);
void chlogif_send_usercount(int users);
void chlogif_upd_global_accreg(uint32 account_id, uint32 char_id);
void chlogif_prepsend_global_accreg(void);
void chlogif_send_global_accreg(const char *key, unsigned int index, intptr_t val, bool is_string);
void chlogif_request_accreg2(uint32 account_id, uint32 char_id);
void chlogif_send_reqaccdata(int fd, struct char_session_data *sd);
void chlogif_send_setacconline(int aid);
void chlogif_send_setallaccoffline(int fd);
void chlogif_send_setaccoffline(int fd, int aid);

int chlogif_parse_ackconnect(int fd, struct char_session_data* sd);
int chlogif_parse_ackaccreq(int fd, struct char_session_data* sd);
int chlogif_parse_reqaccdata(int fd, struct char_session_data* sd);
int chlogif_parse_keepalive(int fd, struct char_session_data* sd);
void chlogif_parse_change_sex_sub(int sex, int acc, int char_id, int class_, int guild_id);
int chlogif_parse_ackchangesex(int fd, struct char_session_data* sd);
int chlogif_parse_ackchangecharsex(int char_id, int sex);
int chlogif_parse_ack_global_accreg(int fd, struct char_session_data* sd);
int chlogif_parse_accbannotification(int fd, struct char_session_data* sd);
int chlogif_parse_askkick(int fd, struct char_session_data* sd);
int chlogif_parse_updip(int fd, struct char_session_data* sd);

int chlogif_parse_vipack(int fd);
int chlogif_reqvipdata(uint32 aid, uint8 flag, int32 timediff, int mapfd);
int chlogif_req_accinfo(int fd, int u_fd, int u_aid, int u_group, int account_id, int8 type);

int chlogif_parse(int fd);

int chlogif_isconnected();
int chlogif_check_connect_logserver(int tid, unsigned int tick, int id, intptr_t data);
void do_init_chlogif(void);
void chlogif_reset(void);
void chlogif_check_shutdown(void);
void chlogif_on_disconnect(void);
void chlogif_on_ready(void);
void do_final_chlogif(void);

#define loginif_check(a) { if(!chlogif_isconnected()) return a; }

#endif	/* _CHAR_LOGIF_HPP_ */

