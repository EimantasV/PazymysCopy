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
pas mane kažkodėl yra vector ~8700000 elementų limitas, nenaudoju indeksų<br>
<br>
==============================================================<br>
===== List =====<br>
====10000000 studentų:<br>
<br>
cpu: ~16%<br>
ram: 1.1GB<br>
sdd: 2.4MB/s<br>
<br>
Naudoti vector(1), list(2), deque(3): 2<br>
Failo pavadinimas: Studentai10000000.txt<br>
Failas nuskaitytas per: 68.2924 S <br>
Studentai surikuoti pagal rezultatus per: 56.3695 S <br>
Studentai atskirti pagal rezultatus per: 0.536122 S <br>
Vykeliai surasyti i faila per: 177.685 S <br>
Nevykeliai surasyti i faila per: 123.914 S <br>
Uzduotis atlikta per: 426.8 S<br>
<br>
====================================<br>
<br>
====1000000 studentų:<br>
<br>
cpu: ~13%<br>
ram: 0.1GB<br>
sdd: 2.4MB/s<br>
<br>
Naudoti vector(1), list(2), deque(3): 2<br>
Failo pavadinimas: Studentai1000000.txt<br>
Failas nuskaitytas per: 9.08936 S <br>
Studentai surikuoti pagal rezultatus per: 4.09188 S <br>
Studentai atskirti pagal rezultatus per: 0.052012 S <br>
Vykeliai surasyti i faila per: 17.7053 S <br>
Nevykeliai surasyti i faila per: 12.4573 S <br>
Uzduotis atlikta per: 43.3978 S<br>
<br>
====================================<br>
<br>
====100000 studentų:<br>
<br>
Failas nuskaitytas per: 0.907155 S <br>
Studentai surikuoti pagal rezultatus per: 0.070016 S <br>
Studentai atskirti pagal rezultatus per: 0.003001 S<br>
Vykeliai surasyti i faila per: 1.79367 S <br>
Nevykeliai surasyti i faila per: 1.24128 S <br>
Uzduotis atlikta per: 4.01712 S<br>
<br>
====================================<br>
<br>
====10000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 2<br>
Failo pavadinimas: Studentai10000.txt<br>
Failas nuskaitytas per: 0.098013 S <br>
Studentai surikuoti pagal rezultatus per: 0.005 S<br>
Studentai atskirti pagal rezultatus per: 0.001002 S<br>
Vykeliai surasyti i faila per: 0.18204 S <br>
Nevykeliai surasyti i faila per: 0.135698 S <br>
Uzduotis atlikta per: 0.423754 S<br>
<br>
====================================<br>
<br>
====1000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 2<br>
Failo pavadinimas: Studentai1000.txt<br>
Failas nuskaitytas per: 0.011003 S <br>
Studentai surikuoti pagal rezultatus per: 0.001 S<br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 0.02836 S <br>
Nevykeliai surasyti i faila per: 0.020004 S<br>
Uzduotis atlikta per: 0.060367 S<br>
==============================================================<br>
===== Deque =====<br>
====10000000 studentų:<br>
<br>
cpu: ~16%<br>
ram: 1.0GB<br>
sdd: 2.4MB/s<br>
<br>
Naudoti vector(1), list(2), deque(3): 3<br>
Failo pavadinimas: Studentai10000000.txt<br>
Failas nuskaitytas per: 67.8647 S <br>
Studentai surikuoti pagal rezultatus per: 56.2896 S <br>
Studentai atskirti pagal rezultatus per: 0.038009 S <br>
Vykeliai surasyti i faila per: 181.959 S <br>
Nevykeliai surasyti i faila per: 124.984 S <br>
Uzduotis atlikta per: 431.138 S<br>
<br>
====================================<br>
<br>
====1000000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 3<br>
Failo pavadinimas: Studentai1000000.txt<br>
Failas nuskaitytas per: 9.29239 S <br>
Studentai surikuoti pagal rezultatus per: 4.50965 S <br>
Studentai atskirti pagal rezultatus per: 0.003001 S<br>
Vykeliai surasyti i faila per: 18.0668 S <br>
Nevykeliai surasyti i faila per: 12.785 S <br>
Uzduotis atlikta per: 44.6609 S<br>
<br>
====================================<br>
<br>
====100000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 3<br>
Failo pavadinimas: Studentai100000.txt<br>
Failas nuskaitytas per: 0.906216 S <br>
Studentai surikuoti pagal rezultatus per: 0.087018 S <br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 1.80696 S <br>
Nevykeliai surasyti i faila per: 1.27492 S <br>
Uzduotis atlikta per: 4.07812 S<br>
<br>
====================================<br>
<br>
====10000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 3<br>
Failo pavadinimas: Studentai10000.txt
Failas nuskaitytas per: 0.092022 S <br><br>
Studentai surikuoti pagal rezultatus per: 0.007002 S<br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 0.180032 S <br>
Nevykeliai surasyti i faila per: 0.176802 S <br>
Uzduotis atlikta per: 0.457867 S<br>
<br>
====================================<br>
<br>
====1000 studentų:<br>
<br>
Naudoti vector(1), list(2), deque(3): 3<br>
Failo pavadinimas: Studentai1000.txt<br>
Failas nuskaitytas per: 0.010002 S <br>
Studentai surikuoti pagal rezultatus per: 0 S<br>
Studentai atskirti pagal rezultatus per: 0 S<br>
Vykeliai surasyti i faila per: 0.026006 S <br>
Nevykeliai surasyti i faila per: 0.020004 S <br>
Uzduotis atlikta per: 0.058012 S<br>
<br>
====================================<br>
<br>
====Vector strategija 1:<br>
====1000000 studentų:<br>
<br>
memory: 90MB<br>
<br>
Naudoti strategija pirma(1), antra(2), mano sena(3): 1<br>
Naudoti vector(1), list(2), deque(3): 1<br>
Failo pavadinimas: Studentai1000000.txt<br>
Failas nuskaitytas per: 7.26474 S<br>
Studentai atskirti pagal rezultatus per: 1.11125 S<br>
Vykeliai surasyti i faila per: 18.1669 S<br>
Nevykeliai surasyti i faila per: 12.1691 S<br>
Uzduotis atlikta per: 38.714 S<br>
<br>
====================================<br>
<br>
====List strategija 1:<br>
====1000000 studentų:<br>
<br>
memory: 300MB<br>
<br>
Naudoti strategija pirma(1), antra(2), mano sena(3): 1<br>
Naudoti vector(1), list(2), deque(3): 2<br>
Failo pavadinimas: Studentai1000000.txt<br>
Failas nuskaitytas per: 7.37775 S <br>
Studentai atskirti pagal rezultatus per: 1.26528 S <br>
Vykeliai surasyti i faila per: 18.2877 S <br>
Nevykeliai surasyti i faila per: 12.4456 S <br>
Uzduotis atlikta per: 39.3783 S<br>
<br>