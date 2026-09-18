MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "Il paraît qu'un LÉVIATOR rouge\n"
    .string "est apparu au LAC.\p"
    .string "C'est étrange: même les LÉVIATOR\n"
    .string "ordinaires y sont rares…$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "Mon émission préférée? Je dirais\n"
    .string "MUSIQUE POKéMON.$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "J'entends des rires à la radio…\p"
    .string "C'est glaçant.$"
