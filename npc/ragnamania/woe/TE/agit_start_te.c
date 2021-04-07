//===== rAthena Script =======================================
//= War of Emperium - Auto-Start
//===== Description: =========================================
//= Basic auto-start for War of Emperium TE.
//===== Changelogs: ==========================================
//= 1.0 First version. [Capuche]
//============================================================

-	script	woe_TE_contoller	-1,{
function WoeTimer;

// OnSun2000:// date woe start
// 	if (agitcheck3() == 0)
// 		agitstart3;
// 	end;
// OnSun2100:// date woe end
// 	if (agitcheck3() == 1)
// 		agitend3;
// 	end;

OnAgitInit3:
	WoeTimer( SUNDAY,20,21 );// <day>, <hour start>, <hour end>
	end;

function WoeTimer {
	.@day = getarg(0);
	.@hour_start = getarg(1);
	.@hour_end   = getarg(2);
	.@woe_status = agitcheck3();
	.@hour_today = gettime(DT_HOUR);
	.@day_today  = gettime(DT_DAYOFWEEK);
	setd ".day_"+ .@day, 1;
	setd ".hour_start_"+ .@hour_start, 1;

	if (.@day_today == .@day) {
		if (.@hour_today >= .@hour_start && .@hour_today < .@hour_end && .@woe_status == 0)
			agitstart3;
		else if (.@hour_today == .@hour_end && .@woe_status)
			agitend3;
	}
	return;
}
}
