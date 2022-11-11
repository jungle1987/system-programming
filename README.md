# Galutinio balo skaiciuokle v0.1

Programa priima studento varda ir pavarde, pazymius, bei egzamino rezultata ir pagal formule apskaiciuoja bendra vidurki ir yra isvedama mediana i ekrana.
Duomenis i programa galima ikelti 2 budais:

1. Rankiniu budu.
2. Failo ikelimu.

## Rankinio budo instrukcija

Paleidus programa i atsidariusi langa suveskite siuos duomenis:

1. Iveskite savo varda. 
2. Iveskite savo pavarde.
3. Iveskite pazymius.
4. Iveskite savo egzamino rezultata.

Suvedus duomenis programa sugeneruos galutini vertinima.

## Failo ikelimo instrukcija

1. Atsidarykite 'kuriokai.txt' faila. 
2. Suveskite duomenis i sablona.
3. Paleiskite programa.

Paleidus programa sugeneruos galutini vertinima.

# Galutinio balo skaiciuokle v.02

Programa priima studento varda ir pavarde, pazymius, bei egzamino rezultata ir pagal formule apskaiciuoja bendra vidurki, mediana. Programa duomenis skaito is failo, juos apskaiciuoja atsitiktiniais skaiciais ir rezultata iraso i nauja faila. Programa geba generuoti 1000, 10 000, 100 000, ir 1000 000 studentu sarasa. Vartotojas pats nusprendzia kokio studentu kiekio jam ar jai reikia. 

Baigus darba programa i ekrana isveda siuos duomenis:
- Kiek eiluciu sugeneravo i faila.
- Kiek laiko uztruko nuskaityti ir apdoroti duomenis.
- Kiek laiko uztruko apdorotus duomenis ikelti i nauja faila.


## Vartotojo Instrukcija

1. Paleiskite programa.
2. Iveskite duomenu generavimo varianta.

Programa sugeneravo faila su galutiniu vidurkiu ir mediana.

# Galutinio balo skaiciuokle v1.0

Programa priima studento varda ir pavarde, pazymius, bei egzamino rezultata ir pagal formule apskaiciuoja bendra vidurki, mediana. Programa duomenis skaito is failo, juos apskaiciuoja atsitiktiniais skaiciais ir rezultata iraso i nauja faila. Programa geba generuoti 1000, 10 000, 100 000, ir 1000 000 studentu sarasa. Vartotojas pats nusprendzia kokio studentu kiekio jam ar jai reikia. Papildomai buvo inicijuota greitaveikos testavimas.

Baigus darba programa i ekrana isveda siuos duomenis:
- Kiek eiluciu sugeneravo i faila.
- Kiek laiko uztruko nuskaityti ir apdoroti duomenis.
- Kiek laiko uztruko apdorotus duomenis ikelti i nauja faila.

## Vartotojo Instrukcija

1. Atsidarykite programos direktorija ..\1\1\kursiokai1000000.zip direktorija ir isskleiskite faila. Failas turi buti randamas pagrindines programos direktorijoje ..\1\1\kursiokai1000000.txt.
2. Paleiskite programa.
3. Iveskite duomenu generavimo varianta.

Programa sugeneravo faila su galutiniu vidurkiu ir mediana.

## Programos testavimas
Buvo atliktas programos greitaveikos testavimas pasitelkiant skirtingus konteineriu tipus: std::deque, std::list, std::vector

Testo rezultatai parode, kad std::list konteineris greiciausiai apdoroja duomenis ir iraso i faila, tuo tarpi std::deque veikia nedaug leciau ir leciausiai veikia naudojant std::vector konteineri.

### Testo rezultatai:

#### Test 1 (1 000 eiluciu)

**Vector**
1. Failo duomenu apdorojimas uztruko: 0.0505745 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 0.0343117 s   
- Programa sugeneravo 1000 eiluciu kieki   

**List:**
1. Failo duomenu apdorojimas uztruko: 0.0524816 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 0.0316935 s   
- Programa sugeneravo 1000 eiluciu kieki   

**Deque:**
1. Failo duomenu apdorojimas uztruko: 0.0964247 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 0.0833037 s   
- Programa sugeneravo 1000 eiluciu kieki   

#### Test 2 (100 000 eiluciu)

**Vector:**    
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 4.93976 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 2.64934 s   
- Programa sugeneravo 100000 eiluciu kieki   

**List:**    
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 4.65223 s    
2. Apdorotu duomenu irasymas i nauja faila uztruko: 2.18231 s    
- Programa sugeneravo 100000 eiluciu kieki   

**Deque:**    
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 3.98958 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 2.65578 s   
- Programa sugeneravo 100000 eiluciu kieki   

#### Test 3 (1 000 000 eiluciu)

**Vector:**   
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 47.3206 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 23.4715 s   
- Programa sugeneravo 1000000 eiluciu kieki

**List:**     
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 37.7581 s  
2. Apdorotu duomenu irasymas i nauja faila uztruko: 22.1248 s   
- Programa sugeneravo 1000000 eiluciu kieki

**Deque:**   
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 37.0522 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 23.9693 s   
- Programa sugeneravo 1000000 eiluciu kieki   

#### Test 4 (1 000 000 eiluciu)

**Vector:**    
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 56.9063 s    
2. Apdorotu duomenu irasymas i nauja faila uztruko: 33.031 s    
- Programa sugeneravo 1000000 eiluciu kieki

**List:**  
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 35.3502 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 23.2959 s   
- Programa sugeneravo 1000000 eiluciu kieki    

**Deque:**
1. Failo duomenu nukaitymas ir apdorojimas uztruko: 39.507 s   
2. Apdorotu duomenu irasymas i nauja faila uztruko: 24.3993 s   
- Programa sugeneravo 1000000 eiluciu kieki   
=======
# Galutinio balo skaiciuokle
Programa priima studento varda ir pavarde, pazymius, bei egzamino rezultata ir pagal formule apskaiciuoja bendra vidurki, mediana. Programa duomenis skaito is failo, juos apskaiciuoja atsitiktiniais skaiciais ir rezultata iraso i nauja faila. Programa geba generuoti 1000, 10 000, 100 000, ir 1000 000 studentu sarasa. Vartotojas pats nusprendzia kokio studentu kiekio jam ar jai reikia. 

Baigus darba programa i ekrana isveda siuos duomenis:
- Kiek eiluciu sugeneravo i faila.
- Kiek laiko uztruko nuskaityti ir apdoroti duomenis.
- Kiek laiko uztruko apdorotus duomenis ikelti i nauja faila.


## Vartotojo Instrukcija

1. Paleiskite programa.
2. Iveskite duomenu generavimo varianta.

Programa sugeneravo faila su galutiniu vidurkiu ir mediana.

