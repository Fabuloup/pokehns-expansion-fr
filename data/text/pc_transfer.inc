gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} est envoyé vers\n"
	.string "le PC de QUELQU'UN.\p"
	.string "Il est placé dans la\n"
	.string "BOÎTE {STR_VAR_1}.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} est envoyé vers\n"
#if IS_FRLG || IS_HNS
	.string "le PC de BILL.\p"
#else
	.string "le PC de LANETTE.\p"
#endif
	.string "Il est placé dans la\n"
	.string "BOÎTE {STR_VAR_1}.$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "La BOÎTE {STR_VAR_3} du\n"
	.string "PC de QUELQU'UN est pleine.\p"
	.string "{STR_VAR_2} est envoyé vers\n"
	.string "la BOÎTE {STR_VAR_1}.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "La BOÎTE {STR_VAR_3} du\n"
#if IS_FRLG || IS_HNS
	.string "PC de BILL est pleine.\p"
#else
	.string "PC de LANETTE est pleine.\p"
#endif
	.string "{STR_VAR_2} est envoyé vers\n"
	.string "la BOÎTE {STR_VAR_1}.$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} est envoyé vers\n"
	.string "{B_PC_CREATOR_NAME} PC.\p"
	.string "Il est placé dans la\n"
	.string "BOÎTE {STR_VAR_1}.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} obtient\n"
	.string "{STR_VAR_1} !$"

gText_NoMoreRoomForPokemon::
	.string "Plus de place pour les POKéMON !\p"
	.string "Toutes les BOÎTES POKéMON sont\n"
	.string "pleines !$"

gText_NicknameThisPokemon::
	.string "Veux-tu donner un surnom à\n"
	.string "ce {STR_VAR_1} ?$"
