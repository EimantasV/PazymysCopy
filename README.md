# Pazymys

v0.1:<br>
Yra C_Masyvai.cpp ir Vectors.cpp, jie daro tą patį, bet veikia truputi kitaip.<br>
Paleidimas:<br>
--------------<br>
g++ -o main C_Masyvai.cpp<br>
./main<br>
--------------<br>
g++ -o main Vectors.cpp<br>
./main<br>
--------------<br>
Naudojimas:<br>
Atsakyti į klausymus su 'y' arba 'n'.<br>
Rašyti mokinių vardus, pavardes ir jų pažymius.<br>
Tada programa išveda galutinius pažymius.<br>
<br>
<br>
v0.2:<br>
C_Masyvai.cpp nebe atnaujinamas.<br>
Vectros.cpp dabar papildomai gali nuskaityti duomenis iš failo.<br>
Duomenų pavyzdys: data.txt.<br>
<br>
<br>
v0.3:<br>
Programa išskirstyta i kelis failus:<br>
Funkcijos.cpp, Funkcijos.h, Strukturos.h, Vectors.cpp.<br>
Pridėtas 'Exception Handling' prie failų nuskaitymo.<br>
Programos paleidimas atnaujintas:<br>
-----------------<br>
Windows10:<br>
'mingw32-make compile'<br>
'./main' arba 'main'<br>
-----------------<br>
kitoms OS paleidimas neišbandytas.<br>
v0.4:<br>
Programa gali sugeneruoti faila ir<br>
išanalizuoti per kiek laiko atlieka užduotis<br>
<br>
====Atlikimas:<br>
<br>
====1000 studentų:<br>
Ar sugeneruoti duomenis? (y/n): n<br>
Ar analizuoti duomenis? (y/n): y<br>
Failo pavadinimas: Studentai1000.txt<br>
Failas nuskaitytas per: 0.012001 S <br>
Studentai surikuoti pagal rezultatus per: 0.005001 S<br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 0.029006 S <br>
Nevykeliai surasyti i faila per: 0.022005 S <br>
Uzduotis atlikta per: 0.068013 S<br>
=====================<br>
<br>
====10000 studentų:<br>
Ar analizuoti duomenis? (y/n): y<br>
Failo pavadinimas: Studentai10000.txt<br>
Failas nuskaitytas per: 0.101023 S <br>
Studentai surikuoti pagal rezultatus per: 0.055012 S <br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 0.182042 S <br>
Nevykeliai surasyti i faila per: 0.143031 S <br>
Uzduotis atlikta per: 0.482108 S<br>
=====================<br>
<br>
====100000 studentų:<br>
Ar sugeneruoti duomenis? (y/n): n<br>
Ar analizuoti duomenis? (y/n): y<br>
Failo pavadinimas: Studentai100000.txt<br>
Failas nuskaitytas per: 0.995225 S <br>
Studentai surikuoti pagal rezultatus per: 0.711159 S <br>
Studentai atskirti pagal rezultatus per: 0.001001 S<br>
Vykeliai surasyti i faila per: 1.7824 S <br>
Nevykeliai surasyti i faila per: 1.3223 S <br>
Uzduotis atlikta per: 4.81308 S<br>
=====================<br>
<br>
====1000000 studentų:<br>
Ar sugeneruoti duomenis? (y/n): n<br>
Ar analizuoti duomenis? (y/n): y<br>
Failo pavadinimas: Studentai1000000.txt<br>
Failas nuskaitytas per: 9.87656 S <br>
Studentai surikuoti pagal rezultatus per: 12.0967 S <br>
Studentai atskirti pagal rezultatus per: 0.003 S<br>
Vykeliai surasyti i faila per: 17.87 S <br>
Nevykeliai surasyti i faila per: 12.8196 S <br>
Uzduotis atlikta per: 52.6679 S<br>
=====================<br>
<br>
====10000000 studentų:<br>
std::bad_alloc<br>
----patasysiu veliau<br>