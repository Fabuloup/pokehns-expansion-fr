PokemonLeague_KogasRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KogasRoom_EventScript_KogaRematchPostOBC

PokemonLeague_KogasRoom_EventScript_KogaRematchStandard::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematchPostOBC::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_POSTOBC_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "KOGA: Fwahahahaha!\p"
    .string "Te revoilà, brave adversaire.\p"
    .string "Mes techniques de ninja se sont\n"
    .string "perfectionnées.\p"
    .string "De nouveaux pièges sournois\n"
    .string "t'attendent.\p"
    .string "Poison, sommeil et bien plus…\n"
    .string "Sois prêt!\p"
    .string "Fwahahahaha!\p"
    .string "Montre-moi tes progrès!$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Fwahahahaha!\p"
    .string "Je suis KOGA du CONSEIL 4.\p"
    .string "Je vis dans l'ombre tel un ninja!\p"
    .string "Mon style complexe saura te\n"
    .string "dérouter et te terrasser!\p"
    .string "Confusion, sommeil, poison…\p"
    .string "Prépare-toi à subir ma technique\n"
    .string "sournoise!\p"
    .string "Fwahahahaha!\p"
    .string "Un combat POKéMON ne se gagne pas\n"
    .string "par la seule force brute… Tu le\l"
    .string "verras bien assez tôt!$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "Ah!\n"
    .string "Tu as prouvé ta valeur!$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "Je t'ai soumis à tout ce dont\n"
    .string "j'étais capable.\p"
    .string "Mais mes efforts ont échoué. Je\n"
    .string "dois encore perfectionner mon art.\p"
    .string "Passe dans la salle suivante et\n"
    .string "mets tes talents à l'épreuve!$"
