Route21_North_MapScripts::
	.byte 0

Route21_North_EventScript_Sparkle_Pearl::
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE21_NORTH_PEARL, EventScript_ReleaseEnd
	dofieldeffectsparkle 17, 42, 0
	setvar VAR_TEMP_F, 1
	end
