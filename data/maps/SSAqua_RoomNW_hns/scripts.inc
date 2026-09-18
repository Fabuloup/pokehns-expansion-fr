SSAqua_RoomNW_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY_HNS, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD_HNS, SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY_HNS, SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "Ouais, je suis marin, et alors.\p"
	.string "Je ne glandais pas!\p"
	.string "Cette cabine était vide, alors\n"
	.string "j'ai fait une petite sieste!\p"
	.string "Ah, laisse tomber! Battons-nous!$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "Désolé! Tout est ma faute!$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "Marin, c'est du travail physique.\n"
	.string "C'est épuisant!$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "Oh non. J'ai perdu quelque chose\n"
	.string "de très important.$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "Je… Je ne le trouve pas…$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "J'abandonne. Ne cherche pas.\p"
	.string "Oublie ça!$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "Youpi! Quelle chance!$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "Pas de bol! J'ai perdu!$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "J'ai trouvé une jolie pièce ici.\p"
	.string "Quelqu'un a dû la perdre…$"
