OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "On s'entraîne dans ce PHARE.\p"
	.string "La montée est difficile avec tous\n"
	.string "les Dresseurs à l'intérieur.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "Autrefois, des POKéMON éclairaient\n"
	.string "la mer autour d'OLIVILLE la nuit.\p"
	.string "Le PHARE fut bâti en l'honneur\n"
	.string "de ces nobles POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Les hommes de la mer cherchent\n"
	.string "toujours un bon combat!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Argh!\n"
	.string "J'ai perdu!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "Quelle puissance! Veux-tu\n"
	.string "parcourir les mers avec moi?$"

OlivineLighthouse_Text_HueyRegister:
	.string "Quelle puissance! Veux-tu\n"
	.string "parcourir les mers avec moi?$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "Les hommes de la mer cherchent\n"
	.string "toujours un bon combat!$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "Argh!\n"
	.string "J'ai perdu!$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "Quelle puissance! Veux-tu\n"
	.string "parcourir les mers avec moi?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hum? Ce n'est pas un endroit\n"
	.string "pour jouer.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah! Je vois que tu es\n"
	.string "sérieux.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Au sommet, un POKéMON maintient\n"
	.string "le PHARE allumé.\p"
	.string "Mais il paraît qu'il est malade\n"
	.string "et aucun soin ordinaire ne suffit.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Pourquoi es-tu ici? Juste\n"
	.string "pour regarder? Va-t'en!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "Le POKéMON malade te préoccupe\n"
	.string "vraiment…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "Comment diable monte-t-on?\p"
	.string "Je veux voir le POKéMON malade,\n"
	.string "mais je ne peux pas monter…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Les marins sont gentils et forts.\n"
	.string "Et toi?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Tu es gentil et fort…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "À chaque retour à OLIVILLE,\n"
	.string "je visite l'ARÈNE.\p"
	.string "Le type de la CHAMPIONNE\n"
	.string "a changé sans que je le remarque.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Je parcours le monde avec mes\n"
	.string "POKéMON. Je souhaite t'affronter.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…soupir… Je dois m'entraîner…$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE utilisait des POKéMON\n"
	.string "de type Roche, comme ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "JASMINE s'inquiète beaucoup pour\n"
	.string "le POKéMON d'ici.\p"
	.string "Elle ne sourit même plus.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Moi non plus, je ne peux sourire…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "Pour les maladies, il y a\n"
	.string "une bonne PHARMACIE à IRISIA.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE est la CHAMPIONNE locale.\p"
	.string "Je compte la ramener avec moi.\p"
	.string "Que nul ne se mette en travers!$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaah! Mon POKéMON!$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Chacun s'inquiète quand\n"
	.string "son propre POKéMON était blessé.\p"
	.string "Je vais prier pour ce POKéMON\n"
	.string "que JASMINE retourne à l'ARÈNE.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Je voulais voir JASMINE, mais\n"
	.string "n'est pas en état.\p"
	.string "Alors, pourquoi pas toi?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Ouah, ouah. Tu m'écrases!$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Être CHAMPION ne se résume pas à\n"
	.string "la force.\p"
	.string "Il faut aussi faire preuve de\n"
	.string "compassion.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "Nous sommes très haut. Mes POKéMON\n"
	.string "Oiseaux sont en pleine forme.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Oups… Ils se sont écrasés…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mes POKéMON ont appris VOL à\n"
	.string "IRISIA.\p"
	.string "Comme j'ai perdu, je survolerai\n"
	.string "la mer…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE: …Ce POKéMON éclairait\n"
	.string "la mer la nuit.\p"
	.string "…Mais il est soudain malade… Il\n"
	.string "cherche son souffle…\p"
	.string "…Il paraît qu'il existe une\n"
	.string "excellente PHARMACIE à IRISIA…\p"
	.string "Mais c'est au-delà de la mer…\n"
	.string "Je ne peux laisser PHARY seul…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…Puis-je te demander un médicament\n"
	.string "pour moi? S'il te plaît?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Il y a une excellente PHARMACIE\n"
	.string "à IRISIA…\p"
	.string "Mais c'est au-delà de la mer…\n"
	.string "Je ne peux laisser PHARY seul…\p"
	.string "…Puis-je te demander un médicament\n"
	.string "pour moi? S'il te plaît?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE: …Cela guérira-t-il\n"
	.string "PHARY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} donne la POTION SECRÈTE à\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE: …Euh, ne te vexe\n"
	.string "pas…\p"
	.string "…PHARY n'accepte rien de\n"
	.string "personne d'autre que moi…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE: …\p"
	.string "PHARY, comment te sens-tu?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE: …Oh, quel soulagement…\p"
	.string "C'est vraiment merveilleux…\p"
	.string "Merci mille et mille fois.\p"
	.string "…Je vais retourner à l'ARÈNE…\p"
	.string "Attention, les types ACIER\n"
	.string "sont puissants.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE: …Je vois…\n"
	.string "…PHARY, tiens bon!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "PHARY: …\n"
	.string "…Pha… phary…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Sa respiration est terriblement\n"
	.string "difficile…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "PHARY: Phary! Pharrry!$"

