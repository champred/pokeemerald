.equ LOCALID_DADDY,    1
.equ LOCALID_BIKER,    2
.equ LOCALID_LOSTELLE, 3

TwoIsland_JoyfulGameCorner_MapScripts:: @ 81713D0
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

TwoIsland_JoyfulGameCorner_OnTransition:: @ 81713E5
	call_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos:: @ 81713EF
	setobjectxyperm LOCALID_DADDY, 6, 2
	setobjectmovementtype LOCALID_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	return

TwoIsland_JoyfulGameCorner_OnWarp:: @ 8171404
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth:: @ 8171416
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

TwoIsland_JoyfulGameCorner_OnFrame:: @ 817141B
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 0, TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene:: @ 8171435
	lockall
	textcolor 0
	msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle
	textcolor 1
	special BufferBigGuyOrBigGirlString
	msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_LOSTELLE, Movement_WalkInPlaceFastestDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene:: @ 817145F
	lockall
	textcolor 0
	applymovement LOCALID_DADDY, Movement_171520
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_DADDY, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DADDY, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DADDY, Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DADDY, Movement_171527
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Movement_17152C
	waitmovement 0
	playbgm MUS_SHOUNEN, 0
	addobject LOCALID_BIKER
	applymovement LOCALID_BIKER, TwoIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland
	applymovement LOCALID_BIKER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt
	msgbox TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_BIKER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_KAIDAN
	removeobject LOCALID_BIKER
	fadedefaultbgm
	delay 60
	msgbox TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_THREE_ISLAND, 2
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

Movement_171520:: @ 8171520
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_fastest_up
	delay_16
	step_end

Movement_171527:: @ 8171527
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

Movement_17152C:: @ 817152C
	walk_left
	walk_in_place_fastest_right
	step_end

TwoIsland_JoyfulGameCorner_Movement_BikerLookAround:: @ 817152F
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	step_end

TwoIsland_JoyfulGameCorner_EventScript_InfoMan:: @ 8171535
	lock
	faceplayer
	compare VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	goto_if_eq JoyfulGameCorner_EventScript_InfoMan2
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon:: @ 8171555
	msgbox TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
TwoIsland_JoyfulGameCorner_EventScript_LostellesDaddy:: @ 817155F
	lock
	faceplayer
	compare VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	goto_if_eq JoyfulGameCorner_EventScript_MinigameAttendant
	goto_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	compare VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	goto_if_eq TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite:: @ 817158A
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	textcolor 3
	playfanfare MUS_ME_WAZA
	message TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_METEORITE, 1
	msgbox TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone:: @ 81715C4
	checkitemspace ITEM_MOON_STONE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	additem ITEM_MOON_STONE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	msgreceiveditem TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning:: @ 81715F5
	msgbox TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone:: @ 81715FF
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_Lostelle:: @ 817160C
	lock
	faceplayer
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end