# objektinio_prog_uzd02

-Leidžia vartotojui įrašyti mokiniu vardus, pavardes, pažymių skaičių, pažymius, egazamino rezultatus.

-Leidžia pažymių skaičių, pažymius ir egzamino rezultatus generuoti atsitiktinai.

-Leidžia vartotojui vesti pažymius nenurodžius pažymių skaičiaus.

-Šitoje programos versijoje naudojami vectors duomenų saugojimui.

Veikimas:

- vartotojas atsako ar žino kiek yra pažymių ir ar nori atsitiktinai pažymius generuoti
- Pagal varotojo atsakymus pažymiai sugeneruojami arba vartotojas ranka juos įveda
- vartotojas pasirenka ar nori matyti pažymių mediana
- Pagal varotojo pasirenkima terminale rodoma mokinių vardas, pavardė, vidurkis ir mediana

v0.2 Nauji pakeitimai:

- Nauja funkcija leidžianti vertotojui atlikti duomenų skaitymą iš tekstinio dokumento
- Skaito iš dokumento studentai10000.txt
- Rezultatai saugomi tekstiniame dokumente rezultatas.txt
- Rezultatai surušiuoti pagal pavardes

v0.3 Nauji pakeitimai:

- jeigu nėra duomenų įvedimo failo išmetama klaida
- funkcijos perkeltos į atskirą failą funkcijos.cpp

v0.4 Nauji pakeitimai:

- Pradinius failus galima generuoti
- Vartotojas gali pasirinkti kokį failą nori nuskaityti nuskaityti
- Sekamas programos vykdymo laikas
- rezultatai skirstomi į du failus pagal mokinio vidurkį (daugiau ar mažiau už 5)

v0.5 Nauji pakeitimai:
- Užduotis padaryta trim skirtingais būdais (vector, list, deque)
- Testavimo sistemos parametrai (CPU i7-9750h, RAM 16 GB, NVME SSD)

Deque v0.5 laikas:

![deque](https://user-images.githubusercontent.com/79286725/114936604-4dcacb00-9e45-11eb-904c-e7847d8b199b.png)

Vector v0.5 laikas:

![vector](https://user-images.githubusercontent.com/79286725/114936662-633ff500-9e45-11eb-8397-adc88199e18f.png)

List v0.5 laikas:

![list](https://user-images.githubusercontent.com/79286725/114936703-6f2bb700-9e45-11eb-9754-692609a352d1.png)

v1.0 Nauji pakeitimai:
- Skirstymo funkcija padaryta naudojant tik du konteinerius ir funkciją partition

Deque v1.0 laikas:

![dequev2](https://user-images.githubusercontent.com/79286725/114937532-93d45e80-9e46-11eb-99f9-4e77ea30b4f4.png)

Vector v1.0 laikas:

![vectorv2](https://user-images.githubusercontent.com/79286725/114937623-b2d2f080-9e46-11eb-9ac1-938de381e45c.png)

List v1.0 laikas:

![listv2](https://user-images.githubusercontent.com/79286725/114937659-bb2b2b80-9e46-11eb-8d96-7054b7e2fc19.png)

Skirstymo laiko (sekundėmis) palyginimas tarp  v0.5 ir v1.0 skirstant 10000000:

| Versija  | Deque | List | Vector |
| ------------- | ------------- | ------------- | ------------- |
| v0.5 | 30.9756  | 7.80584  | 3.13956 | 
| v1.0 | 50.6058 | 9.07976  | 4.52007 |

v1.1 Nauji pakeitimai:

- Vietoj struct studentas realizuota naudojant class studentas

Laiko palyginimas tarp v1.0 ir v1.1 naudojant skirtingus flag'us. Naudojamas vector konteineris 

| flag  | v1.1 100000 | v1.1 1000000 | v1.0 100000 | v1.0 1000000 |
| --------------- | --------------- | --------------- | --------------- | --------------- |
| -o1 | 0.453212  | 4.83038  | 0.444655 | 4.24298 |
| -o2 | 0.466125 | 4.92706  | 0.431455 | 4.1415 |
| -o3 | 0.483002 | 4.88965  | 0.428308| 4.2155|

v1.2 Nauji pakeitimai:

- Realizuota rule of three (destruktorius, priskymo operatorius)
- Padarytos funkcijos perdengiančios '+' ir '<<' operatorius

v1.5 Nauji pakeitimai:

- Sukurta bazinė klasė "zmogus" iš jos padaryta išvestinė klasė "studentas"
- Iš klasės "studentas" į klasė studentas perkeltos šios funkcijos: getVard, getPav, setVard, setPav


v2.0 Nauji pakeitimai:

- Sukurti unit testai kurie testuoja galutinio balo skaičiavimo funkcijos
- Prideda doxygen sukurtą diagramą
- Sukurtas automatinis įdiegimo failas
- stud.exe reikia vykdyti kaip administratorius
- Priminimas: įvesties failų pavadinimai seką šia strukturą "studentas" + n n-studentų skaičius 
