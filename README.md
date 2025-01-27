# Kartoizko zentrifugagailua

## Proiektuaren deskribapena
Proiektu hau Ingenieritza Biomedikoko lehenengo seihileko proiektuaren parte da. Proiektu honetan kartoizko zentrifugagailu bat egin behar dugu eta honen funtzionamendua aztertu. Horretarako bideo bateko datuetatik abiatuz C programa bat garatuko dugu lortutako abiadura maximoa kalkulatzeko.

## Taldekideak
1.-[Eider Andrinua] - [eiderandrinua]

2.-[Maialen Garcia] - [maialen-garcia]

3.-[Nerea Madera] - [nereamadera]

4.-[June Oruna] - [junee963]

5.-[Jokin Sanchez] - [Jokinsanchez]

6.-[Iker Zaitegi] - [IkerZaitegi]

## Proiektuaren garapena
Honako hau izan da guk jarraitu dugun proiektuaren garapenerako prozesua. Hasteko zentrifugagailurako beharrezko materialak aukeratu ditugu, gure kasuan kartoia eta soka. Ondoren zentrifugagailu hainbat erradio tamaina desberdin probatu genituen aproposena zein den erabaki ahal izateko, erabaki honetarako hainbat faktore izan genituen kontuan, xiringen tamaina adibidez.

Proba horien ondoren zentrifugagailuaren tamaina erabakita genuenean abiadura angeluarraren azterketa egiten hasi ginen. Prozesu hori tracker aplikazioaren bidez egin genuen zeinetan guk grabatutako bideo bat sartu genuen eta aplikazioari esker denbora, x eta y koordenatuak lortu genituen. Lortutako datu hauekin fitxategia bat sortu genuen (.txt formatuan) eta fitxategiarekin Visual Studio-n lan egingo dugu.

Datuen tratamenduaren programaren hasierako zatia fitxategia zabaltzeko beharrezko programa sortzea da. Behin programa hori sortuta dagoenean hurrengo azpi-programak sortu ditugu. Programa hauetako bat abiadura angeluarra kalkulatzeko beharrezkoa dena da, honetan x eta y datuetatik tita angeluaren posizoa ateratzea beharrezkoa da eta hori ekuazio matematikoak erabiliz egingo dugu. Kasu honetan kontuan izan behar dugu abiadura angeluarra ebazteko erabili beharreko formula honako hau dela:
w = dtheta/dt zeinen w abiadura angeluarra den radian segunduko unitatean dtheta theta posizioaren aldaketa den radian unitatean eta dt denboraren aldaketa den seguntan neurtua dagoena. 

Beste egin beharrezko atal bat test unitarioak dira, hauen funtzioa programaren funtzionaltasun egokia bermatzea da. Gure kasuan test hauen garapenerak aurrera eramateko adibide bidez egin dugu. Bi test egin ditugu, bat jakiteko ea puntuen irakurtzeko egokia den jakiteko eta beste bat jakiteko abiadura angeluarraren kalkulua modu egokian egin den ziurtatzeko.

Bukatzeko programa osoaren konpilazioa egin behar izan dugu eta hainbat arazo sortu zaizkigu. Lehenengo arazoa fitxategia zabaltzen saiatzean izan da, hasierako probetan ez genuelako lortzen modu egokian zabaltzea fitxategia. Azkenean ikusi genuen gure arazoa fitxategia gordetzeko momentuan ordenagailuko eta bilatzeko momentuan bi toki ezberdinetan zeuden. Arazo hori konpontzen egin beharreko gauza bakarra fitxategia tokiz aldatzea izan zen. 

Fitxategiak lehenego lerroan seinalatuta izan behar ditu zutabe bakoitza zer den(t, x eta y), ondorengo lerroetan dauden datuak koma bidez egon behar dira separatuta, koma bakoitzaren artean dauden zenbakiak datu bat izango da, komek adierazten dute noiz hasi eta bukatu datu bakoitza. Laburbiluz, hiru errenkada izan behar ditu, lehenengo lerroan (t,x eta y), ondorengoetan datu bakoitza (denbora eta koordenatuak). Gainera, hauek desberdintzeko komak erabiltzen dira eta nahi izan beste datu jar ditzazkegu.

Konpilatzeko, Visual Studio 2022-rekin proiektua ireki eta kargatu ondoren (.sln fitxategia), proiektua konpilatzeko, Visual Studio-ko eraikuntza aukerak erabili behar dira. Eraikuntza prozesuak exekutagarri bat sortuko du x64/debug/[proiektuaren izena].exe helbidean, eta aldi berean, test-suitea ere konpilatuko da, x64/debug/[proiektuaren izena]-Tests.exe helbidean. Gogoratu, proiektua Visual Studio 2022-rekin soilik eraiki daitekeela.

Programa exekutatzeko PowerShell-aren bitartez aritu gara, horretarako lehenego terminal bezala zabaldu dugu beheko aldean. Hor barruan idatzi behar dena da; Lehenego proiektua kokatu dagoen lekua erantsi, hau da, proiektuaren ruta. Ondoren, proiektuaren aplikazioa dagoen ruta idatziko dugu, normalean hau izanik: x64/debug/[ProiektuarenIzena].exe. Azkenik, exekutatzeko jarri behar dena, .txt formatuan daukazun datuen (csv estiloan) fitxategiaren kokapena idatzi behar da, ruta idatziz.

Horrela, guk emandako datuen analisia egingo du eta ondoren abiadura angeluar maximoa kalkulatuko du funtzio desberdinak erabiliz. Ondorioz, emaitza pantailaratuko da gure terminalean.
