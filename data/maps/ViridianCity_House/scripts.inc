ViridianCity_House_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_House_EventScript_EvoMon
	closemessage
	end

ViridianCity_House_EventScript_EvoMon::
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_ReleaseEnd
	specialvar VAR_RESULT, GetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_LICKITUNG, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_TANGELA, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_AIPOM, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_YANMA, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_PILOSWINE, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_GLIGAR, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_SNEASEL, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_PORYGON2, ViridianCity_House_EventScript_EvoWorks
	goto_if_eq VAR_RESULT, SPECIES_DUSCLOPS, ViridianCity_House_EventScript_EvoWorks
	msgbox ViridianCity_House_Text_EvoFailed, MSGBOX_NPC
	release
	end

ViridianCity_House_EventScript_EvoWorks::
	callnative EvolveMon
	goto_if_eq VAR_0x8009, SPECIES_NONE, ViridianCity_House_EventScript_EvoFails
	call EventScript_AskChangeNickname
	release
	end

ViridianCity_House_EventScript_EvoFails::
	msgbox ViridianCity_House_Text_EvoUnderleveled, MSGBOX_NPC
	release
	end

ViridianCity_House_EventScript_Speary::
	special ChoosePartyMon
	waitstate
	lock
	specialvar VAR_RESULT, GetPartyMonSpecies
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	bufferspeciesname STR_VAR_1, VAR_RESULT
	call EventScript_ChangePokemonNickname
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end
