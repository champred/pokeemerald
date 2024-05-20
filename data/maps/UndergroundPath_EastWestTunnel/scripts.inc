UndergroundPath_EastWestTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundPath_EastWestTunnel_OnTransition
	.byte 0

UndergroundPath_EastWestTunnel_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_UNDERGROUND_PATH_EAST_WEST_TUNNEL
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_Potion::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_POTION, EventScript_ReleaseEnd
	dofieldeffectsparkle 7, 3, 0
	setvar VAR_TEMP_F, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_Antidote::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ANTIDOTE, EventScript_ReleaseEnd
	dofieldeffectsparkle 62, 5, 0
	setvar VAR_TEMP_E, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_ParalyzeHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_PARALYZE_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 17, 5, 0
	setvar VAR_TEMP_D, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_Awakening::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_AWAKENING, EventScript_ReleaseEnd
	dofieldeffectsparkle 31, 4, 0
	setvar VAR_TEMP_C, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_BurnHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_BURN_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 45, 3, 0
	setvar VAR_TEMP_B, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_IceHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ICE_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 70, 3, 0
	setvar VAR_TEMP_A, 1
	end

UndergroundPath_EastWestTunnel_EventScript_Sparkle_Ether::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ETHER, EventScript_ReleaseEnd
	dofieldeffectsparkle 55, 2, 0
	setvar VAR_TEMP_9, 1
	end
