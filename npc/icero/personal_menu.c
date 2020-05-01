-	script	MenuSetting	FAKE_NPC,{
OnInit:
	$@pre_level$ = "^FF0088←回到上層選單←^000000";
	$@pre_page$ = "^227700↑上一頁↑^000000";
	$@next_page$ = "^227700↓下一頁↓^000000";
	$@menu_search$ = "^FF8800輸入搜尋文字^000000";
	//$@NumberPerPage = 30;
	end;
}

/*  MenuInit ()
 *  清空暫存@Menu
 */
function	script	MenuInit	{
	deletearray @Menu_menu$;
	deletearray @Menu_func$;
	deletearray @Menu_Group;
	
	@Menu_count = 0;
	@Menu_Limit = 30;
	@Menu_LastGroup = 0;
	
	if (getargcount() > 0)
	if (getarg(0) > 0)
		@Menu_Limit = getarg(0);
	
	return;
}

/*  MenuGroup (Name)
 *  在暫存@Menu中新增一個 Group 項目
 */
function	script	MenuGroup	{
	for (.@i = 0; .@i < getargcount(); .@i++) {
		@Menu_menu$[.@i + @Menu_count] = getarg(.@i);
		@Menu_Group[.@i + @Menu_count] = 1;
		@Menu_LastGroup = .@i + @Menu_count;
	}

	deletearray getd("@Menu_type_"+@Menu_LastGroup+"$");
	deletearray getd("@Menu_name_"+@Menu_LastGroup+"$");
	@Menu_count += getargcount();
	return;
}

/*  MenuGroup (Name)
 *  在暫存@Menu中新增一個 Group 項目
 */
function	script	MenuGroupAdd	{
	.@currentMneuCount = getarraysize(getd("@Menu_type_"+@Menu_LastGroup+"$"));
	setd2 "@Menu_type_"+@Menu_LastGroup+"$", .@currentMneuCount, getarg(0);
	setd2 "@Menu_name_"+@Menu_LastGroup+"$", .@currentMneuCount, getarg(1);
	return;
}

/*  MenuAdd (Name)
 *  在暫存@Menu中新增一個 Name 項目
 */
function	script	MenuAdd	{
	for (.@i = 0; .@i < getargcount(); .@i++)
		@Menu_menu$[.@i + @Menu_count] = getarg(.@i);

	@Menu_count += getargcount();
	
	return;
}

/*  MenuAddFunc (Name, Funcname)
 *  在暫存@Menu中新增一個 Name 項目，並讓使用�芨嚝靮幙s結到 Funcname 的Function
 */
function	script	MenuAddFunc	{
	@Menu_menu$[@Menu_count] = getarg(0);
	@Menu_func$[@Menu_count] = getarg(1);
	@Menu_count++;

	return;
}

/*  MenuAddFuncSelf (Name)
 *  在暫存@Menu中新增一個 Name 項目，並讓使用�芨嚝靮幙s結到 F_Name 的Function
 */
function	script	MenuAddFuncSelf	{
	@Menu_menu$[@Menu_count] = getarg(0);
	@Menu_func$[@Menu_count] = "F_"+getarg(0);
	@Menu_count++;

	return;
}

/*  MenuSearch ()
 *  從暫存@Menu搜尋，並回傳 index，若取消搜尋則回傳-1
 */
function	script	MenuSearch	{
	while (1) {
		mes "輸入要搜尋的字詞";
		next;
		input .@search$;
		
		.@c = 0;
		for (.@i = 0; .@i < @Menu_count; .@i++) {
			if (compare(@Menu_menu$[.@i], .@search$)) {
				.@sel_menu$[.@c] = @Menu_menu$[.@i];
				.@sel_list[.@c] = .@i;
				.@c++;
			}
		}
		
		if (!.@c) {
			mes "["+.@search$+"] 搜尋不到相關結果";
			next;
			
			if (select("繼續搜尋:取消搜尋") == 2) {
				next;
				return -1;
			}
			
			continue;
		} else if (.@c >= @Menu_Limit) {
			mes "["+.@search$+"] 太過廣泛，請輸入更精準的字詞";
			next;
			
			if (select("繼續搜尋:取消搜尋") == 2) {
				next;
				return -1;
			}
			
			continue;
		}
		
		for (.@i = 0; .@i < .@c; .@i++)
			.@menu$ += .@sel_menu$[.@i] + ":";
		
		return .@sel_list[select(.@menu$) - 1];
	}
}

/*  MenuSelect ({Funcname})
 *  從暫存裡的 @Menu 中選擇，回傳 index
 *  如果FunctionName被指定，會新增 '上一層' 選單並callfunc FunctionName，最後回到原本的位置
 */
function	script	MenuSelect	{
	.@p = 0;
	.@max_page = @Menu_count / @Menu_Limit;   
	
	while (1) {
		.@menu$ = "";
		deletearray .@p_menu$;
		deletearray .@p_sel;

		if (.@max_page)
			.@p_menu$[getarraysize(.@p_menu$)] = $@menu_search$;

		if (.@p > 0)
			.@p_menu$[getarraysize(.@p_menu$)] = $@pre_page$;

		for (.@i = 0; .@i + .@p * @Menu_Limit < @Menu_count && .@i < @Menu_Limit; .@i++) {
			.@n = getarraysize(.@p_menu$);
			.@p_menu$[.@n] = @Menu_menu$[.@i+.@p*@Menu_Limit];
			.@p_sel[.@n] = .@i;
		}
		
		if (.@p < .@max_page)
			.@p_menu$[getarraysize(.@p_menu$)] = $@next_page$;

		if (getargcount() > 0)
			.@p_menu$[getarraysize(.@p_menu$)] = $@pre_level$;
		.@p_menu$[getarraysize(.@p_menu$)] = "結束";
			
		
		for (.@i = 0; .@i < getarraysize(.@p_menu$); .@i++)
			.@menu$ += .@p_menu$[.@i]+":";
		
		.@sel = select(.@menu$) - 1;
		
		if (getargcount() > 0 && .@p_menu$[.@sel] == $@pre_level$) {
			//callfunc getarg(0);
			return -1;
		}
		
		if (.@p_menu$[.@sel] == $@pre_page$) {
			.@p--;
			continue;
		} else if (.@p_menu$[.@sel] == $@next_page$) {
			.@p++;
			continue;
		} else if (.@p_menu$[.@sel] == $@menu_search$) {
			.@ret = MenuSearch();
			
			if (.@ret < 0)
				continue;
			else
				return .@ret;
		} else if (.@p_menu$[.@sel] == "結束") {
			cutin "",255;
			close;
		}
		
		.@sel = .@p_sel[.@sel];
		.@sel += .@p * @Menu_Limit;		
		break;
	}
	
	if (@Menu_func$[.@sel] != "")
		callfunc @Menu_func$[.@sel];
	
	if (@Menu_Group[.@sel]) {
		next;
		copyarray .@MenuType$, getd("@Menu_type_"+.@sel+"$"), getarraysize(getd("@Menu_type_"+.@sel+"$"));
		copyarray .@MenuName$, getd("@Menu_name_"+.@sel+"$"), getarraysize(getd("@Menu_name_"+.@sel+"$"));
		MenuInit;
		for (.@i = 0; .@i < getarraysize(getd("@Menu_type_"+.@sel+"$")); .@i++)
			callfunc getd2("@Menu_type_"+.@sel+"$", .@i), getd2("@Menu_name_"+.@sel+"$", .@i);
		callfunc "MenuSelect";
	}
	
	return .@sel;
}	

/*  MenuSelectString ({Funcname})
 *  從暫存裡的 @Menu 中選擇，回傳 @Menu_menu$
 *  如果FunctionName被指定，會新增 '上一層' 選單並callfunc FunctionName，最後回到原本的位置
 */
function	script	MenuSelectString	{
	if (getargcount() > 0)
		.@sel = MenuSelect(getarg(0));
	else
		.@sel = MenuSelect();
	
	if (.@sel < 0)
		return "-1";
	else
		return @Menu_menu$[.@sel];
}	

/*  MenuContinue ([msg])
 *  簡單確認詢問，若有msg，附加msg到確認之後
 */
function	script	MenuContinue	{
	if (getargcount() > 0)
		.@postfix$ = getarg(0);
	mes "要繼續進行嗎？";
	next;

	if (select("確認"+.@postfix$+":取消") == 2) {
		cutin "", 255;
		close;
	}
	
	return;
}

/*  MenuYesOrNo ()
 *  簡單確認詢問
 */
function	script	MenuYesOrNo	{
	next;

	if (select("確認:取消") == 2) {
		cutin "", 255;
		close;
	}
	
	return;
}

/*  MenuSelectNumbers (min, max, {Prefix}, {Postfix})
 *  建立從 min 到 max 的清單，讓使用者選擇
 *  並回傳所選的值
 */
function	script	MenuSelectNumbers	{
	.@min = getarg(0);
	.@max = max(getarg(1), .@min);
	
	if (getargcount() > 2)
		.@prefix$ = getarg(2);
	
	if (getargcount() > 3)
		.@postfix$ = getarg(3);
	
	MenuInit;
	for (.@i = .@min; .@i <= .@max; .@i++) {
		MenuAdd .@prefix$+.@i+.@postfix$;
		.@valuelist[.@c++] = .@i;
	}
	
	return .@valuelist[MenuSelect()];
}

/*  ArraySelect (Array, {Funcname})
 *  從Array清單中建立 Menu，並讓使用�芨嚝雂均A最後回傳選擇的項目(index)
 *  如果FunctionName被指定，Array的項目會先傳進FunctionName之後在進入MenuAdd
 */
function	script	ArraySelect	{ 
	MenuInit;
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++) {
		if (getargcount()>1)
			MenuAdd callfunc(getarg(1),getelementofarray(getarg(0), .@i));
		else
			MenuAdd getelementofarray(getarg(0), .@i);
	}
	
	return MenuSelect();
}

/*  ArrayFind (Array, target)
 *  從Array尋找符合target的項目並回傳index
 */
function	script	ArrayFind	{ // Array, target
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
	if (getelementofarray(getarg(0), .@i) == getarg(1))
		break;
	return .@i;
}

/*  ArrayExist (Array, target)
 *  從Array尋找符合target的項目，若存在回傳1，否則回傳0
 */
function	script	ArrayExist	{ // Array, target
	if (ArrayFind(getarg(0), getarg(1)) < getarraysize(getarg(0)))
		return 1;
	
	return 0;
}

/*  ArrayAdd (Array, target)
 *  把target加入進Array
 */
function	script	ArrayAdd	{ // Array, target
	.@count = getarraysize(getarg(0));
	copyarray .@temp, getarg(0), .@count;
	.@temp[.@count] = getarg(1);
	copyarray getarg(0), .@temp, getarraysize(.@temp);
	return;
}

/*  ArrayAddString (Array, target)
 *  ArrayAdd 字串版
 */
function	script	ArrayAddString	{ // Array, target
	.@count = getarraysize(getarg(0));
	copyarray .@temp$, getarg(0), .@count;
	.@temp$[.@count] = getarg(1);
	copyarray getarg(0), .@temp$, getarraysize(.@temp$);
	return;
}

/*  ArrayAddUnique (Array, target)
 *  若target不存在於Array中，則把target加入進Array
 */
function	script	ArrayAddUnique	{ // Array, target
	if (ArrayExist(getarg(0), getarg(1)))
		return;
	
	ArrayAdd(getarg(0), getarg(1));
	return;
}

/*  ArrayAddUniqueString (Array, target)
 *  ArrayAddUnique 字串版
 */
function	script	ArrayAddUniqueString	{ // Array, target
	if (ArrayFind(getarg(0), getarg(1)) < getarraysize(getarg(0)))
		return;
	
	ArrayAddString(getarg(0), getarg(1));
	return;
}

/*  ArrayRemove (Array, target)
 *  若target存在於Array中，則把target從Array移除
 */
function	script	ArrayRemove	{ // Array, target
	while(1) {
		if ((.@i= ArrayFind(getarg(0), getarg(1))) < getarraysize(getarg(0))) {
			deletearray getelementofarray(getarg(0), .@i), 1;
			continue;
		}
		
		return;
	}
}

/*  ArrayCount (Array, target)
 *  從Array尋找符合target的數量並回傳總數
 */
function	script	ArrayCount	{ // Array, target
	.@c = 0;
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
	if (getelementofarray(getarg(0), .@i) == getarg(1))
		.@c++;
	return .@c;
}

/*  ArrayForeach (Array, Func)
 *  把Array的項目依序run Func
 */
function	script	ArrayForeach	{ // Array, Func
	.@argcount = getargcount();
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++) {
		switch(.@argcount) {
		case 2: callfunc(getarg(1), getelementofarray(getarg(0), .@i)); break;
		case 3: callfunc(getarg(1), getelementofarray(getarg(0), .@i), getarg(2)); break;
		case 4: callfunc(getarg(1), getelementofarray(getarg(0), .@i), getarg(2), getarg(3)); break;
		case 5: callfunc(getarg(1), getelementofarray(getarg(0), .@i), getarg(2), getarg(3), getarg(4)); break;
		case 6: callfunc(getarg(1), getelementofarray(getarg(0), .@i), getarg(2), getarg(3), getarg(4), getarg(5)); break;
		}
	}
	return .@c;
}

/*  ArraySelectBin (Array)
 *  從Array中選擇勾選項目並回傳出其Bin總和
 */
 
function	script	ArraySelectBin	{
	.@bin = 0;
	
	while(1) {
		MenuInit;
		MenuAdd "設定完畢";
		for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
			MenuAdd ((.@bin & (pow(2, .@i)))?"[●] ":"[○] ")+getelementofarray(getarg(0), .@i);
		
		.@sel = MenuSelect() - 1;
		
		if (.@sel < 0)
			break;
		
		.@sel_bin = pow(2, .@sel);
		if ((.@bin & .@sel_bin) == .@sel_bin)
			.@bin -= .@sel_bin;
		else
			.@bin |= .@sel_bin;
	}
	
	return .@bin;
}

/*  ArrayShowBinMes (Array, Bin, {Prefix})
 *  Mes出Array中與Bin對應的項目
 */
 
function	script	ArrayShowBinMes	{
	.@bin = getarg(1);
	
	if (getargcount()>2)
		.@prefix$ = getarg(2);
	
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
	if (.@bin & (pow(2, .@i)))
		mes .@prefix$+getelementofarray(getarg(0), .@i);

	return;
}

/*  ArrayBinForeach (Array, Bin, func)
 *  Array中與Bin對應的項目，將其值傳給func
 */
 
function	script	ArrayBinForeach	{
	.@bin = getarg(1);
	.@func$ = getarg(2);
	
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
	if (.@bin & (pow(2, .@i)))
		callfunc(.@func$, getelementofarray(getarg(0), .@i));

	return;
}

function	script	F_ServerAnnounce	{ // data
	announce getarg(0), bc_all;
	return;
}

function	script	F_Dispbottom	{ // data
	dispbottom getarg(0);
	return;
}

function	script	F_ServerDebugMes	{ // data
	debugmes getarg(0);
	return;
}

/*  ArrayMessage (Array)
 *  把Array的項目依序透過 mes 訊息推送出去
 */
function	script	ArrayMessage	{ // Array
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
		mes getelementofarray(getarg(0), .@i);
	return;
}

function	script	ArrayDispbottom	{ // Array
	for(.@i = 0; .@i < getarraysize(getarg(0)); .@i++) {
		if (getargcount() > 1)
			dispbottom getelementofarray(getarg(0), .@i), getarg(1);
		else
			dispbottom getelementofarray(getarg(0), .@i);
	}
	return;
}

function	script	ArrayRandomPickSingle	{ // Source_Array
	return getelementofarray(getarg(0), rand(getarraysize(getarg(0))));
}

function	script	ArrayRandomPickMultiple	{ // Source_Array, TargetArray, size
	freeloop(1);
	
	if (getarraysize(getarg(0)) < getarg(2))
		return;
	
	for(.@i = 0; .@i < getarraysize(getarg(0));) {
		.@n = ArrayRandomPickSingle(getarg(0));
		
		if (ArrayFind(.@pick_array, .@n) == getarraysize(.@pick_array)) {
			.@pick_array[getarraysize(.@pick_array)] = .@n;
			.@i++;
		}
	}
	
	copyarray getarg(1), .@pick_array, getarg(2);
	return;
}

/*  ItemID2Name (ItemID)
 *  回傳 ItemID 的 item name
 */
function	script	ItemID2Name	{
	return getitemname(getarg(0));
}

function	script	MobID2Name	{
	return strmobinfo(2,getarg(0));
}

function	script	MobID2NameMVP	{
	return ((strmobinfo(9,getarg(0))==2)?"[MVP]":"")+strmobinfo(2,getarg(0));
}

function	script	ItemIsSpecial	{
	.@n = getarg(0);
	return (.@n == 255 || .@n == 254 || .@n == -256);
}

function	script	ShowDatetime	{
	.@datetime$ = gettimestr("%Y-%m-%d %H:%M:%S", 21, getarg(0));
	return .@datetime$;
}

function	script	DispBigAmount	{
	function	Sub	{
		if (getarg(0) < 1)
			return "000";
		if (getarg(0) < 10)
			return "00"+getarg(0);
		if (getarg(0) < 100)
			return "0"+getarg(0);
		else
			return getarg(0);
	}

	.@neg = 0;
	.@amount = getarg(0);
	if (.@amount < 0) {
		.@neg = 1;
		.@amount *= -1;
	}
	.@msg$ = "";
	
	if (!.@amount)
		return 0;
	
	while(.@amount/1000) {
		if (.@level)
			.@msg$ = ","+.@msg$;
		.@msg$ = ""+Sub(.@amount % 1000)+""+.@msg$;
		.@amount /= 1000;
		.@level++;
	}
	
	if (.@level)
		.@msg$ = ","+.@msg$;
	.@msg$ = ""+.@amount+""+.@msg$;
	
	return ((.@neg)?"-":"")+.@msg$;
}

function	script	DispBigAmount2	{
	.@amount = getarg(0);
	
	if (!.@amount)
		return 0;
	
	
	.@neg = 0;
	if (.@amount < 0)
		.@neg = 1;
	
	if (.@amount/100000000 > 0)
		.@msg$ += (.@amount/100000000)+"億";
	if ((.@amount%100000000)/10000 > 0)
		.@msg$ += ((.@amount%100000000)/10000)+"萬";
	if (.@amount%10000 > 0)
		.@msg$ += ""+(.@amount%10000)+"";
	
	return ((.@neg)?"-":"")+.@msg$;
}

function	script	SelectInventory	{ // (.@retVal, .@amount, .@npc_name$, .@func$, .@no_pre, {.@offset})
	function	check	{
		for (.@i = 0; .@i < getarraysize(getarg(0)); .@i++)
		if (getelementofarray(getarg(0), .@i) == getarg(1)+1)
			return .@i;
		
		return -1;
	}
	// .@target_retVal = getarg(0);
	.@amount = getarg(1);
	.@npc_name$ = getarg(2);
	.@func$ = getarg(3);
	
	freeloop(1);
	disable_items;
	
	getinventorylist();
	deletearray .@retVal;
	
	if (getargcount() > 4) {
		.@no_pre = getarg(4);
		
		if (getargcount() > 5)
			.@offset = 3;
	}

	// 製作物品清單
	for(.@i = .@c = 0; .@i < @inventorylist_count; .@i++) {
		if (callfunc(.@func$, SI_EXAM+.@offset, .@i)) {
			.@list[.@c++] = .@i;
			
			if (!.@no_pre)
			if (getarraysize(.@retVal) < .@amount)
				.@retVal[getarraysize(.@retVal)] = .@i + 1;
		}
	}
	
	if (.@c == 0) {
		mes .@npc_name$;
		mes "找不到符合以下條件的物品：";
		callfunc .@func$, SI_RULE+.@offset;
		close;
	}
	
	// 選擇
	while(1) {
		mes .@npc_name$;
		if (.@amount >=0)
			mes "請選擇 "+.@amount+" 項物品";
		else
			mes "請選擇物品";
		mes "需符合以下條件：";
		callfunc .@func$, SI_RULE+.@offset;
		next;
		
		MenuInit;
		if (.@amount < 0 || getarraysize(.@retVal) == .@amount)
			MenuAdd "選擇完畢，已經選擇了 "+getarraysize(.@retVal)+" 項";
		else
			MenuAdd "已經選擇了 "+getarraysize(.@retVal)+" 項";
		
		for (.@i = 0; .@i < .@c; .@i++)
			MenuAdd (check(.@retVal, .@list[.@i])>-1?"^0000FF[●]^000000":"[○]")+callfunc(.@func$, SI_DISP+.@offset, .@list[.@i]);
		
		.@sel = MenuSelect()-1;
		
		if (.@sel < 0) {
			if (.@amount < 0 || getarraysize(.@retVal) == .@amount) {
				copyarray getarg(0), .@retVal, getarraysize(.@retVal);
				return .@retVal[0]-1;
			} else {
				mes .@npc_name$;
				mes "你選擇不足 "+.@amount+" 件";
				mes "需符合以下條件：";
				callfunc .@func$, SI_RULE+.@offset;
				close;
			}
		}
		
		if ((.@r = check(.@retVal, .@list[.@sel])) > -1) {
			deletearray .@retVal[.@r],1;
			continue;
		}
		
		if (getarraysize(.@retVal) >= .@amount && .@amount >= 0) {
			mes .@npc_name$;
			mes "已經超過要選擇的數量需求";
			mes "請先取消選擇其他裝備。";
			next;
			continue;
		}
		
		.@retVal[getarraysize(.@retVal)] = .@list[.@sel] + 1;
		
		if (.@amount == 1) {
			copyarray getarg(0), .@retVal, getarraysize(.@retVal);
			return .@retVal[0]-1;
		}
	}
}

/*  MenuInputNumber (min_number, max_number)
 */
function	script	MenuInputNumber	{
	.@min_number = getarg(0);
	.@max_number = getarg(1);
	
	if (.@max_number < .@min_number) {
		mes "系統出錯，請回報管理員";
		close;
	}
	
	while (1) {
		input .@number;
		
		if (.@number > .@max_number || .@number < .@min_number) {
			mes "請輸入 "+.@min_number+" ~ "+.@max_number+" 範圍內的數字";
			cutin "", 255;
			next;
			continue;
		}
		
		break;
	}
	
	return .@number;
}

function	script	getarmorenhanceid	{ // (enhance_kind, lv, stack)
	.@kind = getarg(0);
	
	if (getarg(1) <= 0)
		return 0;
	
	if (.@kind >= ENCHANT_MAX_KIND)
		return 0;
	
	if (.@kind <= ENCHANT_PATIENT)
		return 50000 + getarg(0) * 1000 + (getarg(1)-1) * 10 + getarg(2);
	
	.@kind -= ENCHANT_FIGHT;
	return 50000 + .@kind * 1000 + 400 + (getarg(1)-1) * 10 + getarg(2);
}

function	script	Talk	{
	mes "["+strnpcinfo(1)+"]";
	for (.@i = 0; .@i < getargcount(); .@i++)
		mes getarg(.@i);
	return;
}

function	script	ShowTime	{
	if (getarg(0) > 3600) {
		.@h = getarg(0) / 3600;
		.@rest = getarg(0) - .@h * 3600;
		return .@h + " 時 " + (.@rest / 60) + " 分 " + (.@rest % 60) + " 秒";
	} else if (getarg(0) > 60)
		return (getarg(0) / 60) + " 分 " + (getarg(0) % 60) + " 秒";
	else
		return getarg(0) + " 秒";
}

function	script	CalcTime	{
	.@hour = getarg(0);
	.@minute = getarg(1);
	
	if (getargcount() <= 2) {
		return .@hour * 60 + .@minute;
	} else {
		.@second = getarg(2);
		return .@hour * 60 * 60 + .@minute * 60 + .@second;
	}
}

/*  SelectEquip ( [Array] )
 *  從 $@NormalRefineEQI_List 清單中選擇身上的裝備
 *  若有指定 Array 則從 Array 中選擇
 */

function	script	SelectEquip	{
	copyarray .@eqi_list, $@NormalRefineEQI_List, getarraysize($@NormalRefineEQI_List);
	MenuInit;
	.@c = 0;
	for(.@i = 0; .@i < getarraysize(.@eqi_list); .@i++) {
		.@n = .@eqi_list[.@i];
		.@position$ = $@EQI_NAME$[.@n];
		MenuAdd .@position$+" "+((getequipisequiped(.@n))?("+"+getequiprefinerycnt(.@n)+" " + getequipname(.@n)):"- [沒有裝備]");
		.@c++;
	}
	
	if (getargcount() > 0) {
		if (getarg(0) == 1) {
			MenuAdd "^FF0000精煉NPC故障排除^000000";
		}
	}
	.@sel = MenuSelect();
	
	if (.@sel == .@c) {
		close2;
		atcommand "@unloadnpc GP_Refiner";
		atcommand "@loadnpc npc/icero/GamePoints/Refine.c";
		end;
	}
	
	return .@eqi_list[.@sel];
}

function	script	DispPointArray	{
	for (.@i = 1; .@i <= 20; .@i++)
		.@gap_name$[.@i] = "億("+.@i+")";

	copyarray .@points, getarg(0), getarraysize(getarg(0));
	for (.@i = getarraysize(.@gap_name$) - 1; .@i >= 0; .@i--) {
		if (.@points[.@i]) {
			.@gap = .@i+1;
			break;
		}
	}
	
	.@i = 0;
	.@lv = .@gap - (1 + .@i);
	
	if (.@lv < 0)
		return "0";
	
	.@disp_lv = .@gap - (1 + .@i);
	.@msg$ += DispBigAmount2(.@points[.@lv]);
	.@i++;
	
	if (.@i < .@gap) {
		.@lv = .@gap - (1 + .@i);
		if (.@points[.@lv] >= 10000000)
			.@msg$ += "."+(.@points[.@lv]/1000000)+"";
		else if (.@points[.@lv] >= 1000000)
			.@msg$ += ".0"+(.@points[.@lv]/1000000)+"";
	}
	
	.@msg$ += .@gap_name$[.@disp_lv];
	
	return .@msg$;
}

function	script	DispNumbers	{
	for (.@i = 1; .@i <= 20; .@i++)
		.@gap_name$[.@i] = "億("+.@i+")";

	copyarray .@points, getarg(0), getarraysize(getarg(0));
	for (.@i = getarraysize(.@gap_name$) - 1; .@i >= 0; .@i--) {
		if (.@points[.@i]) {
			.@gap = .@i+1;
			break;
		}
	}
	
	.@i = 0;
	.@lv = .@gap - (1 + .@i);
	
	if (.@lv < 0)
		return "0";
	
	.@disp_lv = .@gap - (1 + .@i);
	.@msg$ += DispBigAmount2(.@points[.@lv]);
	.@i++;
	
	if (.@i < .@gap) {
		.@lv = .@gap - (1 + .@i);
		if (.@points[.@lv] >= 10000000)
			.@msg$ += "."+(.@points[.@lv]/1000000)+"";
		else if (.@points[.@lv] >= 1000000)
			.@msg$ += ".0"+(.@points[.@lv]/1000000)+"";
	}
	
	.@msg$ += .@gap_name$[.@disp_lv];
	
	return .@msg$;
}

function	script	DispPointArrayDetail	{
	for (.@i = 1; .@i <= 20; .@i++)
		.@gap_name$[.@i] = "億("+.@i+")";

	copyarray .@points, getarg(0), getarraysize(getarg(0));
	for (.@i = getarraysize(.@gap_name$) - 1; .@i >= 0; .@i--) {
		if (.@points[.@i]) {
			.@gap = .@i+1;
			break;
		}
	}
	
	.@i = 0;
	.@lv = .@gap - (1 + .@i);
	
	if (.@lv < 0)
		return "0";
	
	.@disp_lv = .@gap - (1 + .@i);
	.@msg$ += DispBigAmount2(.@points[.@lv]);
	.@i++;
	
	if (.@i < .@gap) {
		.@lv = .@gap - (1 + .@i);
		if (.@points[.@lv] >= 10000000)
			.@msg$ += "."+(.@points[.@lv]/1000000)+"";
		else if (.@points[.@lv] >= 1000000)
			.@msg$ += ".0"+(.@points[.@lv]/1000000)+"";
	}
	
	.@msg$ += .@gap_name$[.@disp_lv];
	
	return .@msg$;
}
