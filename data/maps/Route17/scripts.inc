Route17_MapScripts::
	.byte 0

Route17_EventScript_ItemsNotice::
	msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
	end

Route17_EventScript_TrainerTips1::
	msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
	end

Route17_EventScript_TrainerTips2::
	msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
	end

Route17_EventScript_RouteSign::
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end

Route17_EventScript_BallsNotice::
	msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
	end

Route17_EventScript_CyclingRoadSign::
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route17_EventScript_Sparkle_RareCandy::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE17_RARE_CANDY, EventScript_ReleaseEnd
	dofieldeffectsparkle 18, 83, 0
	setvar VAR_TEMP_F, 1
	end

Route17_EventScript_Sparkle_FullRestore::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE17_FULL_RESTORE, EventScript_ReleaseEnd
	dofieldeffectsparkle 10, 53, 0
	setvar VAR_TEMP_E, 1
	end

Route17_EventScript_Sparkle_PPUp::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE17_PP_UP, EventScript_ReleaseEnd
	dofieldeffectsparkle 4, 68, 0
	setvar VAR_TEMP_D, 1
	end

Route17_EventScript_Sparkle_MaxRevive::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE17_MAX_REVIVE, EventScript_ReleaseEnd
	dofieldeffectsparkle 4, 125, 0
	setvar VAR_TEMP_C, 1
	end

Route17_EventScript_Sparkle_MaxElixir::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE17_MAX_ELIXIR, EventScript_ReleaseEnd
	dofieldeffectsparkle 14, 157, 0
	setvar VAR_TEMP_B, 1
	end
