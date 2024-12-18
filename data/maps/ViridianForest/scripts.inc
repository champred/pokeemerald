.equ ICE_ROCK, 1
.equ MOSS_ROCK, 2

ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Nurse::
	lock
	faceplayer
	msgbox ViridianForest_Text_HealPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianForest_EventScript_NurseHeal
	msgbox ViridianForest_Text_PokemonNotHealed, MSGBOX_DEFAULT
	release
	end

ViridianForest_EventScript_NurseHeal::
	closemessage
	special HealPlayerParty
	playse SE_USE_ITEM
	waitse
	msgbox ViridianForest_Text_PokemonHealed, MSGBOX_DEFAULT
	release
	end

ViridianForest_EventScript_UseRock::
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_ReleaseEnd
	specialvar VAR_RESULT, GetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EEVEE, ViridianForest_EventScript_RockWorks
	msgbox ViridianForest_Text_MissingEevee, MSGBOX_DEFAULT
	release
	end

ViridianForest_EventScript_RockWorks::
	goto_if_eq VAR_TEMP_1, ICE_ROCK, ViridianForest_EventScript_IceRock
	goto_if_eq VAR_TEMP_1, MOSS_ROCK, ViridianForest_EventScript_MossRock
	release
	end

ViridianForest_EventScript_IceRock::
	callnative UseIceRock
	call EventScript_AskChangeNickname
	release
	end

ViridianForest_EventScript_MossRock::
	callnative UseMossRock
	call EventScript_AskChangeNickname
	release
	end

EventScript_AskChangeNickname::
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_ChangePokemonNickname
	return

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_IceRockUse, MSGBOX_YESNO
	setvar VAR_TEMP_1, ICE_ROCK
	goto_if_eq VAR_RESULT, YES, ViridianForest_EventScript_UseRock
	closemessage
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_MossRockSign, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_MossRockUse, MSGBOX_YESNO
	setvar VAR_TEMP_1, MOSS_ROCK
	goto_if_eq VAR_RESULT, YES, ViridianForest_EventScript_UseRock
	closemessage
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_TrainerTaunt, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_IceRockSign, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end
