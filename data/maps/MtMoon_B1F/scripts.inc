MtMoon_B1F_MapScripts::
	.byte 0

MtMoon_B1F_EventScript_Sparkle_TinyMushroom::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM, EventScript_ReleaseEnd
	dofieldeffectsparkle 46, 2, 0
	setvar VAR_TEMP_F, 1
	end

MtMoon_B1F_EventScript_Sparkle_TinyMushroom2::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_2, EventScript_ReleaseEnd
	dofieldeffectsparkle 26, 2, 0
	setvar VAR_TEMP_F, 1
	end

MtMoon_B1F_EventScript_Sparkle_TinyMushroom3::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_3, EventScript_ReleaseEnd
	dofieldeffectsparkle 39, 34, 0
	setvar VAR_TEMP_F, 1
	end

MtMoon_B1F_EventScript_Sparkle_BigMushroom::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM, EventScript_ReleaseEnd
	dofieldeffectsparkle 24, 35, 0
	setvar VAR_TEMP_E, 1
	end

MtMoon_B1F_EventScript_Sparkle_BigMushroom_2::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_2, EventScript_ReleaseEnd
	dofieldeffectsparkle 6, 12, 0
	setvar VAR_TEMP_F, 1
	end

MtMoon_B1F_EventScript_Sparkle_BigMushroom3::
	goto_if_set FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_3, EventScript_ReleaseEnd
	dofieldeffectsparkle 25, 34, 0
	setvar VAR_TEMP_D, 1
	end
