UndergroundPath_NorthSouthTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundPath_NorthSouthTunnel_OnTransition
	.byte 0

UndergroundPath_NorthSouthTunnel_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_Potion::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_POTION, EventScript_ReleaseEnd
	dofieldeffectsparkle 5, 30, 0
	setvar VAR_TEMP_F, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_Antidote::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ANTIDOTE, EventScript_ReleaseEnd
	dofieldeffectsparkle 5, 6, 0
	setvar VAR_TEMP_E, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_ParalyzeHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_PARALYZE_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 3, 15, 0
	setvar VAR_TEMP_D, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_Awakening::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_AWAKENING, EventScript_ReleaseEnd
	dofieldeffectsparkle 1, 24, 0
	setvar VAR_TEMP_C, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_BurnHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_BURN_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 2, 57, 0
	setvar VAR_TEMP_B, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_IceHeal::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ICE_HEAL, EventScript_ReleaseEnd
	dofieldeffectsparkle 6, 53, 0
	setvar VAR_TEMP_A, 1
	end

UndergroundPath_NorthSouthTunnel_EventScript_Sparkle_Ether::
	goto_if_set FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ETHER, EventScript_ReleaseEnd
	dofieldeffectsparkle 3, 39, 0
	setvar VAR_TEMP_9, 1
	end
