Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "Où vas-tu comme ça avec tes\n"
    .string "POKéMON?\p"
    .string "À la LIGUE POKéMON?\p"
    .string "Tes POKéMON t'aiment-ils assez\n"
    .string "pour que tu l'emportes?\p"
    .string "Voyons voir…$"

SandstormHouse_Text_LoyalMon:
    .string "Ah! Ton POKéMON te fait\n"
    .string "vraiment confiance.\p"
    .string "Ça fait plaisir de voir un bon\n"
    .string "DRESSEUR.\p"
    .string "Tiens. Un cadeau pour la route.$"

SandstormHouse_Text_TM37Description:
    .string "La CT37, c'est TEMPÊTE DE SABLE.\p"
    .string "Une capacité qui blesse les deux\n"
    .string "combattants.\p"
    .string "Elle est réservée aux DRESSEURS\n"
    .string "chevronnés.\p"
    .string "Utilise-la si tu l'oses. Bonne\n"
    .string "chance!$"

SandstormHouse_Text_DisloyalMon:
    .string "S'il ne te fait pas davantage\n"
    .string "confiance, ça va être dur.\p"
    .string "La confiance est le lien qui unit\n"
    .string "POKéMON et DRESSEURS.$"


