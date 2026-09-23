CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA maîtrise les POKéMON\n"
	.string "de type PLANTE.\p"
	.string "Mieux vaut rester sur tes gardes,\n"
	.string "ou tu le regretteras.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "Le repaire de la TEAM ROCKET\n"
	.string "se trouve sous le CASINO.\p"
	.string "Ah, non. C'était il y a trois ans.$"

Celadon_Text_Eusine1:
	.string "EUSINE: Salut!\p"
	.string "Je visite ma ville natale.\p"
	.string "Ça faisait longtemps.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, tu es au courant?\p"
	.string "Une nouvelle rumeur parle d'un\n"
	.string "POKéMON couleur arc-en-ciel\l"
	.string "apparu à la TOUR FERRAILLE.\p"
	.string "Mon équipe vient d'être soignée,\n"
	.string "alors je pars pour ROSALIA.\p"
	.string "À bientôt, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Au fait, {PLAYER}.\p"
	.string "As-tu attrapé les POKéMON\n"
	.string "légendaires RAIKOU et ENTEI?\p"
	.string "<……><……><……>\p"
	.string "D'accord…\p"
	.string "Si tu en attrapes ne serait-ce\n"
	.string "qu'un, préviens-moi.\p"
	.string "Je compte sur toi, {PLAYER}!$"
