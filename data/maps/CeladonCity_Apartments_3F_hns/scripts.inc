CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "C'est bien ça?\p"
	.string "Je suis le CONCEPTEUR DU JEU!\p"
	.string "Compléter ton POKéDEX n'est pas\n"
	.string "facile, mais n'abandonne pas!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "Waouh! Bravo! Tu as complété\n"
	.string "ton POKéDEX!\p"
	.string "Félicitations!$"

GameFreak_Text_GraphicArtist:
	.string "Je suis le GRAPHISTE.\p"
	.string "C'est moi qui t'ai dessiné!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Je suis le GRAPHISTE.\p"
	.string "Oh, tu as complété ton POKéDEX?\p"
	.string "Tu veux que j'imprime ton\n"
	.string "DIPLÔME?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Dis-moi si tu veux faire imprimer\n"
	.string "ton DIPLÔME.$"

GameFreak_Text_GraphicArtistError:
	.string "Il y a un problème. Je dois\n"
	.string "annuler l'impression.$"

GameFreak_Text_Programmer:
	.string "Moi? Je suis le PROGRAMMEUR.\p"
	.string "Va jouer aux machines à sous!$"

GameFreak_Text_CharacterDesigner:
	.string "Tu ne trouves pas les JUMELLES\n"
	.string "adorables?\p"
	.string "JASMINE aussi est jolie.\p"
	.string "Ah, je les adore!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "SALLE DE DÉVELOPPEMENT\n"
	.string "GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "Un dessin détaillé d'une jolie\n"
	.string "jeune fille.$"

CeladonMansion3F_Text_GameProgram:
	.string "C'est le programme du jeu. Le\n"
	.string "modifier risquerait d'y mettre\n"
	.string "un bug!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "C'est rempli de documents de\n"
	.string "référence. Il y a même une\n"
	.string "POKÉ POUPÉE.$"
