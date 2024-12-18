const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =
{
    [SPECIES_BULBASAUR]  = {{EVO_LEVEL, 16, SPECIES_IVYSAUR}},
    [SPECIES_IVYSAUR]    = {{EVO_LEVEL, 32, SPECIES_VENUSAUR}},
    [SPECIES_CHARMANDER] = {{EVO_LEVEL, 16, SPECIES_CHARMELEON}},
    [SPECIES_CHARMELEON] = {{EVO_LEVEL, 36, SPECIES_CHARIZARD}},
    [SPECIES_SQUIRTLE]   = {{EVO_LEVEL, 16, SPECIES_WARTORTLE}},
    [SPECIES_WARTORTLE]  = {{EVO_LEVEL, 36, SPECIES_BLASTOISE}},
    [SPECIES_CATERPIE]   = {{EVO_LEVEL,  7, SPECIES_METAPOD}},
    [SPECIES_METAPOD]    = {{EVO_LEVEL, 10, SPECIES_BUTTERFREE}},
    [SPECIES_WEEDLE]     = {{EVO_LEVEL,  7, SPECIES_KAKUNA}},
    [SPECIES_KAKUNA]     = {{EVO_LEVEL, 10, SPECIES_BEEDRILL}},
    [SPECIES_PIDGEY]     = {{EVO_LEVEL, 18, SPECIES_PIDGEOTTO}},
    [SPECIES_PIDGEOTTO]  = {{EVO_LEVEL, 36, SPECIES_PIDGEOT}},
    [SPECIES_RATTATA]    = {{EVO_LEVEL, 20, SPECIES_RATICATE}},
    [SPECIES_SPEAROW]    = {{EVO_LEVEL, 20, SPECIES_FEAROW}},
    [SPECIES_EKANS]      = {{EVO_LEVEL, 22, SPECIES_ARBOK}},
    [SPECIES_PIKACHU]    = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU}},
    [SPECIES_SANDSHREW]  = {{EVO_LEVEL, 22, SPECIES_SANDSLASH}},
    [SPECIES_NIDORAN_F]  = {{EVO_LEVEL, 16, SPECIES_NIDORINA}},
    [SPECIES_NIDORINA]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOQUEEN}},
    [SPECIES_NIDORAN_M]  = {{EVO_LEVEL, 16, SPECIES_NIDORINO}},
    [SPECIES_NIDORINO]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOKING}},
    [SPECIES_CLEFAIRY]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_CLEFABLE}},
    [SPECIES_VULPIX]     = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_NINETALES}},
    [SPECIES_JIGGLYPUFF] = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_WIGGLYTUFF}},
    [SPECIES_ZUBAT]      = {{EVO_LEVEL, 22, SPECIES_GOLBAT}},
    [SPECIES_GOLBAT]     = {{EVO_FRIENDSHIP, 0, SPECIES_CROBAT}},
    [SPECIES_ODDISH]     = {{EVO_LEVEL, 21, SPECIES_GLOOM}},
    [SPECIES_GLOOM]      = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_VILEPLUME},
                            {EVO_ITEM, ITEM_SUN_STONE, SPECIES_BELLOSSOM}},
    [SPECIES_PARAS]      = {{EVO_LEVEL, 24, SPECIES_PARASECT}},
    [SPECIES_VENONAT]    = {{EVO_LEVEL, 31, SPECIES_VENOMOTH}},
    [SPECIES_DIGLETT]    = {{EVO_LEVEL, 26, SPECIES_DUGTRIO}},
    [SPECIES_MEOWTH]     = {{EVO_LEVEL, 28, SPECIES_PERSIAN}},
    [SPECIES_PSYDUCK]    = {{EVO_LEVEL, 33, SPECIES_GOLDUCK}},
    [SPECIES_MANKEY]     = {{EVO_LEVEL, 28, SPECIES_PRIMEAPE}},
    [SPECIES_GROWLITHE]  = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_ARCANINE}},
    [SPECIES_POLIWAG]    = {{EVO_LEVEL, 25, SPECIES_POLIWHIRL}},
    [SPECIES_POLIWHIRL]  = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_POLIWRATH},
                            {EVO_ITEM, ITEM_KINGS_ROCK, SPECIES_POLITOED}},
    [SPECIES_ABRA]       = {{EVO_LEVEL, 16, SPECIES_KADABRA}},
    [SPECIES_KADABRA]    = {{EVO_TRADE, 0, SPECIES_ALAKAZAM}},
    [SPECIES_MACHOP]     = {{EVO_LEVEL, 28, SPECIES_MACHOKE}},
    [SPECIES_MACHOKE]    = {{EVO_TRADE, 0, SPECIES_MACHAMP}},
    [SPECIES_BELLSPROUT] = {{EVO_LEVEL, 21, SPECIES_WEEPINBELL}},
    [SPECIES_WEEPINBELL] = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_VICTREEBEL}},
    [SPECIES_TENTACOOL]  = {{EVO_LEVEL, 30, SPECIES_TENTACRUEL}},
    [SPECIES_GEODUDE]    = {{EVO_LEVEL, 25, SPECIES_GRAVELER}},
    [SPECIES_GRAVELER]   = {{EVO_TRADE, 0, SPECIES_GOLEM}},
    [SPECIES_PONYTA]     = {{EVO_LEVEL, 40, SPECIES_RAPIDASH}},
    [SPECIES_SLOWPOKE]   = {{EVO_LEVEL, 37, SPECIES_SLOWBRO},
                            {EVO_ITEM, ITEM_KINGS_ROCK, SPECIES_SLOWKING}},
    [SPECIES_MAGNEMITE]  = {{EVO_LEVEL, 30, SPECIES_MAGNETON}},
    [SPECIES_MAGNETON]   = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_MAGNEZONE}},
    [SPECIES_DODUO]      = {{EVO_LEVEL, 31, SPECIES_DODRIO}},
    [SPECIES_SEEL]       = {{EVO_LEVEL, 34, SPECIES_DEWGONG}},
    [SPECIES_GRIMER]     = {{EVO_LEVEL, 38, SPECIES_MUK}},
    [SPECIES_SHELLDER]   = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_CLOYSTER}},
    [SPECIES_GASTLY]     = {{EVO_LEVEL, 25, SPECIES_HAUNTER}},
    [SPECIES_HAUNTER]    = {{EVO_TRADE, 0, SPECIES_GENGAR}},
    [SPECIES_ONIX]       = {{EVO_ITEM, ITEM_METAL_COAT, SPECIES_STEELIX}},
    [SPECIES_DROWZEE]    = {{EVO_LEVEL, 26, SPECIES_HYPNO}},
    [SPECIES_KRABBY]     = {{EVO_LEVEL, 28, SPECIES_KINGLER}},
    [SPECIES_VOLTORB]    = {{EVO_LEVEL, 30, SPECIES_ELECTRODE}},
    [SPECIES_EXEGGCUTE]  = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_EXEGGUTOR}},
    [SPECIES_CUBONE]     = {{EVO_LEVEL, 28, SPECIES_MAROWAK}},
    [SPECIES_LICKITUNG]  = {{EVO_LEVEL, 33, SPECIES_LICKILICKY}},
    [SPECIES_KOFFING]    = {{EVO_LEVEL, 35, SPECIES_WEEZING}},
    [SPECIES_RHYHORN]    = {{EVO_LEVEL, 42, SPECIES_RHYDON}},
    [SPECIES_RHYDON]     = {{EVO_ITEM, ITEM_HARD_STONE, SPECIES_RHYPERIOR}},
    [SPECIES_CHANSEY]    = {{EVO_FRIENDSHIP, 0, SPECIES_BLISSEY}},
    [SPECIES_TANGELA]    = {{EVO_LEVEL, 24, SPECIES_TANGROWTH}},
    [SPECIES_HORSEA]     = {{EVO_LEVEL, 32, SPECIES_SEADRA}},
    [SPECIES_SEADRA]     = {{EVO_ITEM, ITEM_DRAGON_SCALE, SPECIES_KINGDRA}},
    [SPECIES_GOLDEEN]    = {{EVO_LEVEL, 33, SPECIES_SEAKING}},
    [SPECIES_STARYU]     = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_STARMIE}},
    [SPECIES_SCYTHER]    = {{EVO_ITEM, ITEM_METAL_COAT, SPECIES_SCIZOR}},
    [SPECIES_ELECTABUZZ] = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_ELECTIVIRE}},
    [SPECIES_MAGMAR]     = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_MAGMORTAR}},
    [SPECIES_MAGIKARP]   = {{EVO_LEVEL, 20, SPECIES_GYARADOS}},
    [SPECIES_EEVEE]      = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_JOLTEON},
                            {EVO_ITEM, ITEM_WATER_STONE, SPECIES_VAPOREON},
                            {EVO_ITEM, ITEM_FIRE_STONE, SPECIES_FLAREON},
                            {EVO_ITEM, ITEM_SUN_STONE, SPECIES_ESPEON},
                            {EVO_ITEM, ITEM_MOON_STONE, SPECIES_UMBREON}},
    [SPECIES_PORYGON]    = {{EVO_ITEM, ITEM_UP_GRADE, SPECIES_PORYGON2}},
    [SPECIES_OMANYTE]    = {{EVO_LEVEL, 40, SPECIES_OMASTAR}},
    [SPECIES_KABUTO]     = {{EVO_LEVEL, 40, SPECIES_KABUTOPS}},
    [SPECIES_DRATINI]    = {{EVO_LEVEL, 30, SPECIES_DRAGONAIR}},
    [SPECIES_DRAGONAIR]  = {{EVO_LEVEL, 55, SPECIES_DRAGONITE}},
    [SPECIES_CHIKORITA]  = {{EVO_LEVEL, 16, SPECIES_BAYLEEF}},
    [SPECIES_BAYLEEF]    = {{EVO_LEVEL, 32, SPECIES_MEGANIUM}},
    [SPECIES_CYNDAQUIL]  = {{EVO_LEVEL, 14, SPECIES_QUILAVA}},
    [SPECIES_QUILAVA]    = {{EVO_LEVEL, 36, SPECIES_TYPHLOSION}},
    [SPECIES_TOTODILE]   = {{EVO_LEVEL, 18, SPECIES_CROCONAW}},
    [SPECIES_CROCONAW]   = {{EVO_LEVEL, 30, SPECIES_FERALIGATR}},
    [SPECIES_SENTRET]    = {{EVO_LEVEL, 15, SPECIES_FURRET}},
    [SPECIES_HOOTHOOT]   = {{EVO_LEVEL, 20, SPECIES_NOCTOWL}},
    [SPECIES_LEDYBA]     = {{EVO_LEVEL, 18, SPECIES_LEDIAN}},
    [SPECIES_SPINARAK]   = {{EVO_LEVEL, 22, SPECIES_ARIADOS}},
    [SPECIES_CHINCHOU]   = {{EVO_LEVEL, 27, SPECIES_LANTURN}},
    [SPECIES_PICHU]      = {{EVO_FRIENDSHIP, 0, SPECIES_PIKACHU}},
    [SPECIES_CLEFFA]     = {{EVO_FRIENDSHIP, 0, SPECIES_CLEFAIRY}},
    [SPECIES_IGGLYBUFF]  = {{EVO_FRIENDSHIP, 0, SPECIES_JIGGLYPUFF}},
    [SPECIES_TOGEPI]     = {{EVO_FRIENDSHIP, 0, SPECIES_TOGETIC}},
    [SPECIES_TOGETIC]    = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_TOGEKISS}},
    [SPECIES_NATU]       = {{EVO_LEVEL, 25, SPECIES_XATU}},
    [SPECIES_MAREEP]     = {{EVO_LEVEL, 15, SPECIES_FLAAFFY}},
    [SPECIES_FLAAFFY]    = {{EVO_LEVEL, 30, SPECIES_AMPHAROS}},
    [SPECIES_MARILL]     = {{EVO_LEVEL, 18, SPECIES_AZUMARILL}},
    [SPECIES_HOPPIP]     = {{EVO_LEVEL, 18, SPECIES_SKIPLOOM}},
    [SPECIES_SKIPLOOM]   = {{EVO_LEVEL, 27, SPECIES_JUMPLUFF}},
    [SPECIES_AIPOM]      = {{EVO_LEVEL, 32, SPECIES_AMBIPOM}},
    [SPECIES_SUNKERN]    = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_SUNFLORA}},
    [SPECIES_YANMA]      = {{EVO_LEVEL, 33, SPECIES_YANMEGA}},
    [SPECIES_WOOPER]     = {{EVO_LEVEL, 20, SPECIES_QUAGSIRE}},
    [SPECIES_MURKROW]    = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_HONCHKROW}},
    [SPECIES_MISDREAVUS] = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_MISMAGIUS}},
    [SPECIES_PINECO]     = {{EVO_LEVEL, 31, SPECIES_FORRETRESS}},
    [SPECIES_GLIGAR]     = {{EVO_ITEM, ITEM_DRAGON_FANG, SPECIES_GLISCOR}},
    [SPECIES_SNUBBULL]   = {{EVO_LEVEL, 23, SPECIES_GRANBULL}},
    [SPECIES_SNEASEL]    = {{EVO_ITEM, ITEM_QUICK_CLAW, SPECIES_WEAVILE}},
    [SPECIES_TEDDIURSA]  = {{EVO_LEVEL, 30, SPECIES_URSARING}},
    [SPECIES_SLUGMA]     = {{EVO_LEVEL, 38, SPECIES_MAGCARGO}},
    [SPECIES_SWINUB]     = {{EVO_LEVEL, 33, SPECIES_PILOSWINE}},
    [SPECIES_PILOSWINE]  = {{EVO_LEVEL, 45, SPECIES_MAMOSWINE}},
    [SPECIES_REMORAID]   = {{EVO_LEVEL, 25, SPECIES_OCTILLERY}},
    [SPECIES_HOUNDOUR]   = {{EVO_LEVEL, 24, SPECIES_HOUNDOOM}},
    [SPECIES_PHANPY]     = {{EVO_LEVEL, 25, SPECIES_DONPHAN}},
    [SPECIES_PORYGON2]   = {{EVO_ITEM, ITEM_UP_GRADE, SPECIES_PORYGON_Z}},
    [SPECIES_TYROGUE]    = {{EVO_LEVEL_ATK_LT_DEF, 20, SPECIES_HITMONCHAN},
                            {EVO_LEVEL_ATK_GT_DEF, 20, SPECIES_HITMONLEE},
                            {EVO_LEVEL_ATK_EQ_DEF, 20, SPECIES_HITMONTOP}},
    [SPECIES_SMOOCHUM]   = {{EVO_LEVEL, 30, SPECIES_JYNX}},
    [SPECIES_ELEKID]     = {{EVO_LEVEL, 30, SPECIES_ELECTABUZZ}},
    [SPECIES_MAGBY]      = {{EVO_LEVEL, 30, SPECIES_MAGMAR}},
    [SPECIES_LARVITAR]   = {{EVO_LEVEL, 30, SPECIES_PUPITAR}},
    [SPECIES_PUPITAR]    = {{EVO_LEVEL, 55, SPECIES_TYRANITAR}},
    [SPECIES_TREECKO]    = {{EVO_LEVEL, 16, SPECIES_GROVYLE}},
    [SPECIES_GROVYLE]    = {{EVO_LEVEL, 36, SPECIES_SCEPTILE}},
    [SPECIES_TORCHIC]    = {{EVO_LEVEL, 16, SPECIES_COMBUSKEN}},
    [SPECIES_COMBUSKEN]  = {{EVO_LEVEL, 36, SPECIES_BLAZIKEN}},
    [SPECIES_MUDKIP]     = {{EVO_LEVEL, 16, SPECIES_MARSHTOMP}},
    [SPECIES_MARSHTOMP]  = {{EVO_LEVEL, 36, SPECIES_SWAMPERT}},
    [SPECIES_POOCHYENA]  = {{EVO_LEVEL, 18, SPECIES_MIGHTYENA}},
    [SPECIES_ZIGZAGOON]  = {{EVO_LEVEL, 20, SPECIES_LINOONE}},
    [SPECIES_WURMPLE]    = {{EVO_LEVEL_SILCOON, 7, SPECIES_SILCOON},
                            {EVO_LEVEL_CASCOON, 7, SPECIES_CASCOON}},
    [SPECIES_SILCOON]    = {{EVO_LEVEL, 10, SPECIES_BEAUTIFLY}},
    [SPECIES_CASCOON]    = {{EVO_LEVEL, 10, SPECIES_DUSTOX}},
    [SPECIES_LOTAD]      = {{EVO_LEVEL, 14, SPECIES_LOMBRE}},
    [SPECIES_LOMBRE]     = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_LUDICOLO}},
    [SPECIES_SEEDOT]     = {{EVO_LEVEL, 14, SPECIES_NUZLEAF}},
    [SPECIES_NUZLEAF]    = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SHIFTRY}},
    [SPECIES_NINCADA]    = {{EVO_LEVEL_NINJASK, 20, SPECIES_NINJASK},
                            {EVO_LEVEL_SHEDINJA, 20, SPECIES_SHEDINJA}},
    [SPECIES_TAILLOW]    = {{EVO_LEVEL, 22, SPECIES_SWELLOW}},
    [SPECIES_SHROOMISH]  = {{EVO_LEVEL, 23, SPECIES_BRELOOM}},
    [SPECIES_WINGULL]    = {{EVO_LEVEL, 25, SPECIES_PELIPPER}},
    [SPECIES_SURSKIT]    = {{EVO_LEVEL, 22, SPECIES_MASQUERAIN}},
    [SPECIES_WAILMER]    = {{EVO_LEVEL, 40, SPECIES_WAILORD}},
    [SPECIES_SKITTY]     = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_DELCATTY}},
    [SPECIES_BALTOY]     = {{EVO_LEVEL, 36, SPECIES_CLAYDOL}},
    [SPECIES_NOSEPASS]   = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_PROBOPASS}},
    [SPECIES_BARBOACH]   = {{EVO_LEVEL, 30, SPECIES_WHISCASH}},
    [SPECIES_CORPHISH]   = {{EVO_LEVEL, 30, SPECIES_CRAWDAUNT}},
    [SPECIES_FEEBAS]     = {{EVO_BEAUTY, 170, SPECIES_MILOTIC}},
    [SPECIES_CARVANHA]   = {{EVO_LEVEL, 30, SPECIES_SHARPEDO}},
    [SPECIES_TRAPINCH]   = {{EVO_LEVEL, 35, SPECIES_VIBRAVA}},
    [SPECIES_VIBRAVA]    = {{EVO_LEVEL, 45, SPECIES_FLYGON}},
    [SPECIES_MAKUHITA]   = {{EVO_LEVEL, 24, SPECIES_HARIYAMA}},
    [SPECIES_ELECTRIKE]  = {{EVO_LEVEL, 26, SPECIES_MANECTRIC}},
    [SPECIES_NUMEL]      = {{EVO_LEVEL, 33, SPECIES_CAMERUPT}},
    [SPECIES_SPHEAL]     = {{EVO_LEVEL, 32, SPECIES_SEALEO}},
    [SPECIES_SEALEO]     = {{EVO_LEVEL, 44, SPECIES_WALREIN}},
    [SPECIES_CACNEA]     = {{EVO_LEVEL, 32, SPECIES_CACTURNE}},
    [SPECIES_SNORUNT]    = {{EVO_LEVEL, 42, SPECIES_GLALIE},
                            {EVO_ITEM, ITEM_SUN_STONE, SPECIES_FROSLASS}},
    [SPECIES_AZURILL]    = {{EVO_FRIENDSHIP, 0, SPECIES_MARILL}},
    [SPECIES_SPOINK]     = {{EVO_LEVEL, 32, SPECIES_GRUMPIG}},
    [SPECIES_MEDITITE]   = {{EVO_LEVEL, 37, SPECIES_MEDICHAM}},
    [SPECIES_SWABLU]     = {{EVO_LEVEL, 35, SPECIES_ALTARIA}},
    [SPECIES_WYNAUT]     = {{EVO_LEVEL, 15, SPECIES_WOBBUFFET}},
    [SPECIES_DUSKULL]    = {{EVO_LEVEL, 37, SPECIES_DUSCLOPS}},
    [SPECIES_DUSCLOPS]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_DUSKNOIR}},
    [SPECIES_ROSELIA]    = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_ROSERADE}},
    [SPECIES_SLAKOTH]    = {{EVO_LEVEL, 18, SPECIES_VIGOROTH}},
    [SPECIES_VIGOROTH]   = {{EVO_LEVEL, 36, SPECIES_SLAKING}},
    [SPECIES_GULPIN]     = {{EVO_LEVEL, 26, SPECIES_SWALOT}},
    [SPECIES_WHISMUR]    = {{EVO_LEVEL, 20, SPECIES_LOUDRED}},
    [SPECIES_LOUDRED]    = {{EVO_LEVEL, 40, SPECIES_EXPLOUD}},
    [SPECIES_CLAMPERL]   = {{EVO_ITEM, ITEM_DEEP_SEA_TOOTH, SPECIES_HUNTAIL},
                            {EVO_ITEM, ITEM_DEEP_SEA_SCALE, SPECIES_GOREBYSS}},
    [SPECIES_SHUPPET]    = {{EVO_LEVEL, 37, SPECIES_BANETTE}},
    [SPECIES_ARON]       = {{EVO_LEVEL, 32, SPECIES_LAIRON}},
    [SPECIES_LAIRON]     = {{EVO_LEVEL, 42, SPECIES_AGGRON}},
    [SPECIES_LILEEP]     = {{EVO_LEVEL, 40, SPECIES_CRADILY}},
    [SPECIES_ANORITH]    = {{EVO_LEVEL, 40, SPECIES_ARMALDO}},
    [SPECIES_RALTS]      = {{EVO_LEVEL, 20, SPECIES_KIRLIA}},
    [SPECIES_KIRLIA]     = {{EVO_LEVEL, 30, SPECIES_GARDEVOIR},
                            EVO_ITEM, ITEM_SUN_STONE, SPECIES_GALLADE},
    [SPECIES_BAGON]      = {{EVO_LEVEL, 30, SPECIES_SHELGON}},
    [SPECIES_SHELGON]    = {{EVO_LEVEL, 50, SPECIES_SALAMENCE}},
    [SPECIES_BELDUM]     = {{EVO_LEVEL, 20, SPECIES_METANG}},
    [SPECIES_METANG]     = {{EVO_LEVEL, 45, SPECIES_METAGROSS}},
    [SPECIES_TURTWIG]    = {{EVO_LEVEL, 18, SPECIES_GROTLE}},
    [SPECIES_GROTLE]     = {{EVO_LEVEL, 32, SPECIES_TORTERRA}},
    [SPECIES_CHIMCHAR]   = {{EVO_LEVEL, 14, SPECIES_MONFERNO}},
    [SPECIES_MONFERNO]   = {{EVO_LEVEL, 36, SPECIES_INFERNAPE}},
    [SPECIES_PIPLUP]     = {{EVO_LEVEL, 16, SPECIES_PRINPLUP}},
    [SPECIES_PRINPLUP]   = {{EVO_LEVEL, 36, SPECIES_EMPOLEON}},
    [SPECIES_STARLY]     = {{EVO_LEVEL, 14, SPECIES_STARAVIA}},
    [SPECIES_STARAVIA]   = {{EVO_LEVEL, 34, SPECIES_STARAPTOR}},
    [SPECIES_BIDOOF]     = {{EVO_LEVEL, 15, SPECIES_BIBAREL}},
    [SPECIES_KRICKETOT]  = {{EVO_LEVEL, 10, SPECIES_KRICKETUNE}},
    [SPECIES_SHINX]      = {{EVO_LEVEL, 15, SPECIES_LUXIO}},
    [SPECIES_LUXIO]      = {{EVO_LEVEL, 30, SPECIES_LUXRAY}},
    [SPECIES_BUDEW]      = {{EVO_FRIENDSHIP, 0, SPECIES_ROSELIA}},
    [SPECIES_CRANIDOS]   = {{EVO_LEVEL, 30, SPECIES_RAMPARDOS}},
    [SPECIES_SHIELDON]   = {{EVO_LEVEL, 30, SPECIES_BASTIODON}},
    [SPECIES_BURMY]      = {{EVO_LEVEL_CASCOON, 20, SPECIES_WORMADAM},
                            {EVO_LEVEL_SILCOON, 20, SPECIES_MOTHIM}},
    [SPECIES_COMBEE]     = {{EVO_LEVEL, 21, SPECIES_VESPIQUEN}},
    [SPECIES_BUIZEL]     = {{EVO_LEVEL, 26, SPECIES_FLOATZEL}},
    [SPECIES_CHERUBI]    = {{EVO_LEVEL, 25, SPECIES_CHERRIM}},
    [SPECIES_SHELLOS]    = {{EVO_LEVEL, 30, SPECIES_GASTRODON}},
    [SPECIES_DRIFLOON]   = {{EVO_LEVEL, 28, SPECIES_DRIFBLIM}},
    [SPECIES_BUNEARY]    = {{EVO_FRIENDSHIP, 0, SPECIES_LOPUNNY}},
    [SPECIES_GLAMEOW]    = {{EVO_LEVEL, 38, SPECIES_PURUGLY}},
    [SPECIES_CHINGLING]  = {{EVO_FRIENDSHIP, 0, SPECIES_CHIMECHO}},
    [SPECIES_STUNKY]     = {{EVO_LEVEL, 34, SPECIES_SKUNTANK}},
    [SPECIES_BRONZOR]    = {{EVO_LEVEL, 33, SPECIES_BRONZONG}},
    [SPECIES_BONSLY]     = {{EVO_LEVEL, 17, SPECIES_SUDOWOODO}},
    [SPECIES_MIME_JR]    = {{EVO_LEVEL, 18, SPECIES_MR_MIME}},
    [SPECIES_HAPPINY]    = {{EVO_ITEM, ITEM_HARD_STONE, SPECIES_CHANSEY}},
    [SPECIES_GIBLE]      = {{EVO_LEVEL, 24, SPECIES_GABITE}},
    [SPECIES_GABITE]     = {{EVO_LEVEL, 48, SPECIES_GARCHOMP}},
    [SPECIES_MUNCHLAX]   = {{EVO_FRIENDSHIP, 0, SPECIES_SNORLAX}},
    [SPECIES_RIOLU]      = {{EVO_FRIENDSHIP, 0, SPECIES_LUCARIO}},
    [SPECIES_HIPPOPOTAS] = {{EVO_LEVEL, 34, SPECIES_HIPPOWDON}},
    [SPECIES_SKORUPI]    = {{EVO_LEVEL, 40, SPECIES_DRAPION}},
    [SPECIES_CROAGUNK]   = {{EVO_LEVEL, 37, SPECIES_TOXICROAK}},
    [SPECIES_FINNEON]    = {{EVO_LEVEL, 31, SPECIES_LUMINEON}},
    [SPECIES_MANTYKE]    = {{EVO_FRIENDSHIP, 0, SPECIES_MANTINE}},
    [SPECIES_SNOVER]     = {{EVO_LEVEL, 40, SPECIES_ABOMASNOW}},
    [SPECIES_SNIVY]      = {{EVO_LEVEL, 17, SPECIES_SERVINE}},
    [SPECIES_SERVINE]    = {{EVO_LEVEL, 36, SPECIES_SERPERIOR}},
    [SPECIES_TEPIG]      = {{EVO_LEVEL, 17, SPECIES_PIGNITE}},
    [SPECIES_PIGNITE]    = {{EVO_LEVEL, 36, SPECIES_EMBOAR}},
    [SPECIES_OSHAWOTT]   = {{EVO_LEVEL, 17, SPECIES_DEWOTT}},
    [SPECIES_DEWOTT]     = {{EVO_LEVEL, 36, SPECIES_SAMUROTT}},
    [SPECIES_PATRAT]     = {{EVO_LEVEL, 20, SPECIES_WATCHOG}},
    [SPECIES_LILLIPUP]   = {{EVO_LEVEL, 16, SPECIES_HERDIER}},
    [SPECIES_HERDIER]    = {{EVO_LEVEL, 32, SPECIES_STOUTLAND}},
    [SPECIES_PURRLOIN]   = {{EVO_LEVEL, 20, SPECIES_LIEPARD}},
    [SPECIES_PANSAGE]    = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SIMISAGE}},
    [SPECIES_PANSEAR]    = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_SIMISEAR}},
    [SPECIES_PANPOUR]    = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_SIMIPOUR}},
    [SPECIES_MUNNA]      = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_MUSHARNA}},
    [SPECIES_PIDOVE]     = {{EVO_LEVEL, 21, SPECIES_TRANQUILL}},
    [SPECIES_TRANQUILL]  = {{EVO_LEVEL, 32, SPECIES_UNFEZANT}},
    [SPECIES_BLITZLE]    = {{EVO_LEVEL, 27, SPECIES_ZEBSTRIKA}},
    [SPECIES_ROGGENROLA] = {{EVO_LEVEL, 25, SPECIES_BOLDORE}},
    [SPECIES_BOLDORE]    = {{EVO_TRADE, 0, SPECIES_GIGALITH}},
    [SPECIES_WOOBAT]     = {{EVO_FRIENDSHIP, 0, SPECIES_SWOOBAT}},
    [SPECIES_DRILBUR]    = {{EVO_LEVEL, 31, SPECIES_EXCADRILL}},
    [SPECIES_TIMBURR]    = {{EVO_LEVEL, 25, SPECIES_GURDURR}},
    [SPECIES_GURDURR]    = {{EVO_TRADE, 0, SPECIES_CONKELDURR}},
    [SPECIES_TYMPOLE]    = {{EVO_LEVEL, 25, SPECIES_PALPITOAD}},
    [SPECIES_PALPITOAD]  = {{EVO_LEVEL, 36, SPECIES_SEISMITOAD}},
    [SPECIES_SEWADDLE]   = {{EVO_LEVEL, 20, SPECIES_SWADLOON}},
    [SPECIES_SWADLOON]   = {{EVO_FRIENDSHIP, 0, SPECIES_LEAVANNY}},
    [SPECIES_VENIPEDE]   = {{EVO_LEVEL, 22, SPECIES_WHIRLIPEDE}},
    [SPECIES_WHIRLIPEDE] = {{EVO_LEVEL, 30, SPECIES_SCOLIPEDE}},
    [SPECIES_COTTONEE]   = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_WHIMSICOTT}},
    [SPECIES_PETILIL]    = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT}},
    [SPECIES_SANDILE]    = {{EVO_LEVEL, 29, SPECIES_KROKOROK}},
    [SPECIES_KROKOROK]   = {{EVO_LEVEL, 40, SPECIES_KROOKODILE}},
    [SPECIES_DARUMAKA]   = {{EVO_LEVEL, 35, SPECIES_DARMANITAN}},
    [SPECIES_DWEBBLE]    = {{EVO_LEVEL, 34, SPECIES_CRUSTLE}},
    [SPECIES_SCRAGGY]    = {{EVO_LEVEL, 39, SPECIES_SCRAFTY}},
    [SPECIES_YAMASK]     = {{EVO_LEVEL, 34, SPECIES_COFAGRIGUS}},
    [SPECIES_TIRTOUGA]   = {{EVO_LEVEL, 37, SPECIES_CARRACOSTA}},
    [SPECIES_ARCHEN]     = {{EVO_LEVEL, 37, SPECIES_ARCHEOPS}},
    [SPECIES_TRUBBISH]   = {{EVO_LEVEL, 36, SPECIES_GARBODOR}},
    [SPECIES_ZORUA]      = {{EVO_LEVEL, 30, SPECIES_ZOROARK}},
    [SPECIES_MINCCINO]   = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_CINCCINO}},
    [SPECIES_GOTHITA]    = {{EVO_LEVEL, 32, SPECIES_GOTHORITA}},
    [SPECIES_GOTHORITA]  = {{EVO_LEVEL, 41, SPECIES_GOTHITELLE}},
    [SPECIES_SOLOSIS]    = {{EVO_LEVEL, 32, SPECIES_DUOSION}},
    [SPECIES_DUOSION]    = {{EVO_LEVEL, 41, SPECIES_REUNICLUS}},
    [SPECIES_DUCKLETT]   = {{EVO_LEVEL, 35, SPECIES_SWANNA}},
    [SPECIES_VANILLITE]  = {{EVO_LEVEL, 35, SPECIES_VANILLISH}},
    [SPECIES_VANILLISH]  = {{EVO_LEVEL, 47, SPECIES_VANILLUXE}},
    [SPECIES_DEERLING]   = {{EVO_LEVEL, 34, SPECIES_SAWSBUCK}},
    [SPECIES_KARRABLAST] = {{EVO_FRIENDSHIP, 0, SPECIES_ESCAVALIER}},
    [SPECIES_FOONGUS]    = {{EVO_LEVEL, 39, SPECIES_AMOONGUSS}},
    [SPECIES_FRILLISH]   = {{EVO_LEVEL, 40, SPECIES_JELLICENT}},
    [SPECIES_JOLTIK]     = {{EVO_LEVEL, 36, SPECIES_GALVANTULA}},
    [SPECIES_FERROSEED]  = {{EVO_LEVEL, 40, SPECIES_FERROTHORN}},
    [SPECIES_KLINK]      = {{EVO_LEVEL, 38, SPECIES_KLANG}},
    [SPECIES_KLANG]      = {{EVO_LEVEL, 49, SPECIES_KLINKLANG}},
    [SPECIES_TYNAMO]     = {{EVO_LEVEL, 39, SPECIES_EELEKTRIK}},
    [SPECIES_EELEKTRIK]  = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_EELEKTROSS}},
    [SPECIES_ELGYEM]     = {{EVO_LEVEL, 42, SPECIES_BEHEEYEM}},
    [SPECIES_LITWICK]    = {{EVO_LEVEL, 41, SPECIES_LAMPENT}},
    [SPECIES_LAMPENT]    = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_CHANDELURE}},
    [SPECIES_AXEW]       = {{EVO_LEVEL, 38, SPECIES_FRAXURE}},
    [SPECIES_FRAXURE]    = {{EVO_LEVEL, 48, SPECIES_HAXORUS}},
    [SPECIES_CUBCHOO]    = {{EVO_LEVEL, 37, SPECIES_BEARTIC}},
    [SPECIES_SHELMET]    = {{EVO_FRIENDSHIP, 0, SPECIES_ACCELGOR}},
    [SPECIES_MIENFOO]    = {{EVO_LEVEL, 50, SPECIES_MIENSHAO}},
    [SPECIES_GOLETT]     = {{EVO_LEVEL, 43, SPECIES_GOLURK}},
    [SPECIES_PAWNIARD]   = {{EVO_LEVEL, 52, SPECIES_BISHARP}},
    [SPECIES_RUFFLET]    = {{EVO_LEVEL, 54, SPECIES_BRAVIARY}},
    [SPECIES_VULLABY]    = {{EVO_LEVEL, 54, SPECIES_MANDIBUZZ}},
    [SPECIES_DEINO]      = {{EVO_LEVEL, 50, SPECIES_ZWEILOUS}},
    [SPECIES_ZWEILOUS]   = {{EVO_LEVEL, 64, SPECIES_HYDREIGON}},
    [SPECIES_LARVESTA]   = {{EVO_LEVEL, 59, SPECIES_VOLCARONA}},
};
