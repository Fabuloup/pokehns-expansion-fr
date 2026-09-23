BattleFrontier_Lounge1_hns_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder_hns::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns
	end

BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat_hns::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP_hns
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef_hns
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue_hns::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow_hns
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid_hns
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax_hns
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments_hns::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow_hns::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid_hns::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax_hns::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1_hns::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2_hns::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns:
	.string "Ça fait 70 ans que j'élève\n"
	.string "des POKéMON! On m'appelle\l"
	.string "l'ELEVEUR DE POKéMON légendaire!\p"
	.string "Quand tu auras pris autant\n"
	.string "de bouteille que moi, tu\l"
	.string "reconnaîtras les capacités\p"
	.string "d'un POKéMON au premier regard.\n"
	.string "Tu es un DRESSEUR. Tu veux\l"
	.string "connaître les capacités de\p"
	.string "tes POKéMON? Allez! Je vais\n"
	.string "jeter un œil à tes POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility_hns:
	.string "Hum… Celui-là, je\p"
	.string "dirais que ses capacités\n"
	.string "sont dans la moyenne.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns:
	.string "Hum… Celui-là, je dirais\p"
	.string "que ses capacités sont\n"
	.string "au-dessus de la moyenne.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility_hns:
	.string "Hum… Celui-là, je dirais\p"
	.string "que ses capacités sont\n"
	.string "plutôt impressionnantes!$"

BattleFrontier_Lounge1_Text_OutstandingAbility_hns:
	.string "Hum… Celui-là, je dirais\p"
	.string "que ses capacités sont\n"
	.string "vraiment excellentes!$"

BattleFrontier_Lounge1_Text_BestAspectHP_hns:
	.string "Son point fort,\n"
	.string "ce sont ses PV…$"

BattleFrontier_Lounge1_Text_BestAspectAtk_hns:
	.string "Son point fort,\n"
	.string "c'est son ATTAQUE…$"

BattleFrontier_Lounge1_Text_BestAspectDef_hns:
	.string "Son point fort,\n"
	.string "c'est sa DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns:
	.string "Son point fort, c'est\n"
	.string "son ATTAQUE SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef_hns:
	.string "Son point fort, c'est\n"
	.string "sa DEFENSE SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed_hns:
	.string "Son point fort,\n"
	.string "c'est sa VITESSE…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood_hns:
	.string "Cette stat est relativement\n"
	.string "bonne. Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_StatImpressive_hns:
	.string "Cette stat est assez\n"
	.string "impressionnante. Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_StatOutstanding_hns:
	.string "Cette stat est\n"
	.string "excellente! Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_StatFlawless_hns:
	.string "Cette stat est\n"
	.string "parfaite! Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns:
	.string "Comment? Tu n'as\n"
	.string "pas le temps? Tu ne\p"
	.string "devrais jamais refuser\n"
	.string "l'aide de tes aînés!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending_hns:
	.string "Oui, qu'y a-t-il encore?\p"
	.string "J'ai des affaires à régler!\n"
	.string "On verra ça une autre fois!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns:
	.string "Dis, mon petit! Tu aimerais en\n"
	.string "savoir plus sur les capacités\p"
	.string "de tes POKéMON? Bien, bien!\n"
	.string "Jetons un œil à ces POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell_hns:
	.string "Comment pourrais-je évaluer un\n"
	.string "POKéMON qui n'a pas encore éclos!\p"
	.string "Montre-moi un POKéMON! C'est\n"
	.string "un POKéMON que je veux voir!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns:
	.string "Il trouve mon POKéMON excellent!\n"
	.string "Je suis fier de l'avoir élevé!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns:
	.string "Mon POKéMON est excellent,\n"
	.string "il a dit! Je n'ai rien\l"
	.string "fait de spécial, pourtant…$"

