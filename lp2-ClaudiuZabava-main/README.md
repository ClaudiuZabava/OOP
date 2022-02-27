# Proiect 2
##### Acest README text exista in cazul in care primul README.md nu functioneaza. Recomand citirea pe dillinger.io
### Acest proiect cuprinde 5 clase ( 2 mosteniri, 2 compuneri). 

##  Folosirea meniului:

Meniul vine cu 8 optiuni:
- (1) adaugarea lungimii listei (vitala, fara ea nu se va crea lista)
- (2) adaugarea obiectelor listei (vitala, fara ea nu se vor apela metodele)
- (3) Afisarea obiectelor din lista
- (4) se apeleaza una dintre metodele clasei.
- (5) se apeleaza una dintre metodele clasei.
- (6) se insereaza / adauga un element in lista ( dimensiunile listei alocate dinamic se extind)
- (7) se sterge al n-lea element al listei
- (0) se termina programul 

Programul nu va functiona si va afisa mesaj corespunzator daca:
- este selectata una din optiunile 3,4,5,6,7 fara a fi selectate optiunile 1 si 2 precedent: [exemplu](https://pasteboard.co/JXaipq3.jpg )
- este selectata optiunea 2 fara a se selecta optiunea 1: [exemplu](https://pasteboard.co/JXakIMm.jpg)
- la stergerea celui de-al n-lea element este introdus un indice inexistent : [exemplu](https://pasteboard.co/JXamdEN.jpg)

Exista si alte mesaje afisate , legate de modul gestiunii informatiilor transmise (codul este usor modificat a.i. sa isi pastreze conditiile de unicitate in lista de obiecte) :
- atat la inserare folosind optiunea (6) cat si in modul normal de citire al elementelor listei, daca introducem 2 abonati cu ID-uri diferite dar acelasi CNP sau acelasi Telefon: elementul introdus nu se salveaza si se afiseaza mesaj de atentionare alaturi de numarul de elemente ce mai pot fi introduse: [exemplu persoane cu id diferite si cnp egal](https://pasteboard.co/JXaqGv5.jpg)
- in cazul de mai sus exista exceptia: in lista avem 2 obiecte cu acelasi credentiale (CNP, ID, Telefon, eventual nume) , dar numele abonamentului difera sau au acelasi nume al abonamentului dar unul este premium altul nu ( in acest caz se salveaza respectivul obiect intrucat o persoana poate alege sa aibe mai multe abonamente cu denumiri diferite (hbo, netflix) sau cu aceeasi denumire dar de tipuri diferite (unul premium si celalalt non-premium) )
- atat la inserare folosind optiunea (6) cat si in modul normal de citire al elementelor listei, daca se introduc abonati cu acelasi ID dar se constata ca cnp-urile , telefonul sau numele sunt diferite: elementul introdus nu e salvat si se afiseaza mesaj corespunzator alaturi de numarul de elemente ce mai pot fi introduse: [exemple](https://pasteboard.co/JXav5QY.jpg)

Cazuri speciale:
- dupa citirea unei liste, atunci cand utilizatorul doreste (din diverse motive) initializarea imediata a altei liste, programul afiseaza mesaj de atentionare intrucat urmeaza sa abandoneze obiectul creat recent (alaturi de instructiunile necesare inaintarii operatiei) [exemplu](https://pasteboard.co/JXayLav.jpg)
- dupa citirea unei liste , utilizatorul alege optiunea 1) de modificare a lungimii. In acest caz, primeste mesaj de atentionare (+ instructiuni) intrucat se percepe crearea unei noi liste de lungimea nou introdusa: [exemplu](https://pasteboard.co/JXaw2dn.jpg)


## Exemplu - input ( ! pentru acest exemplu de input/output au fost tastate optiunile in ordinea: 1, 2, 2, 4, 5, 6, 6, 4, 7, 7, 4, 5, 3) :

1 - Precizati lungimea listei de clienti.

 2 - Doresc sa introduc o lista de clienti.
 
 3 - Doresc sa previzualizez lista introdusa.
 
 4 - Doresc sa vad numarul de clienti cu abonament premium.
 
 5 - Doresc sa aflu castigul total pe baza abonamentelor (se ia in calcul reducerea).
 
 6 - Doresc sa inserez / adaug un element in lista curenta.
 
 7 - Doresc sa sterg al n-lea element din lista curenta.
 
 0 - Exit.
 
 Scrieti aici optiunea dumneavoastra: 1

Introduceti lungimea mai jos
2

-------------------------------------------------------
##### meniul apare din nou aici . ..
-------------------------------------------------------

 Scrieti aici optiunea dumneavoastra: 2

-------------------------------------------------------

Clientul nr.1

Se vor introduce datele persoanei

Introduceti ID-ul persoanei: 1

Introduceti numele persoanei: ana

Introduceti CNP-ul: 50101

Se vor introduce datele abonatului

Introduceti nr de telefon: 0721

Se vor introduce datele abonamentului

Introduceti numele abonamentului: netflex

Introduceti pretul abonamentului: 59.9

Introduceti perioada abonamentului: 10

Se vor introduce datele abonamentului premium

Introduceti reducerea: 2


-------------------------------------------------------

Clientul nr.2

Se vor introduce datele persoanei

Introduceti ID-ul persoanei: 2

Introduceti numele persoanei: dan

Introduceti CNP-ul: 50102

Se vor introduce datele abonatului

Introduceti nr de telefon: 0722

Se vor introduce datele abonamentului

Introduceti numele abonamentului: hgo

Introduceti pretul abonamentului: 60

Introduceti perioada abonamentului: 12

Se vor introduce datele abonamentului premium

Introduceti reducerea: 5

-------------------------------------------------------

##### S-au apelat metodele 4, 5, dupa care s-a apelat de 2 ori optiunea 6, folosind inputul: 
-------------------------------------------------------

Clientul nr.3

Se vor introduce datele persoanei

Introduceti ID-ul persoanei: 3

Introduceti numele persoanei: maria

Introduceti CNP-ul: 50103

Se vor introduce datele abonatului

Introduceti nr de telefon: 0723

Se vor introduce datele abonamentului

Introduceti numele abonamentului: disnep

Introduceti pretul abonamentului: 100.9

Introduceti perioada abonamentului: 3

Se vor introduce datele abonamentului premium

Introduceti reducerea: 5

-------------------------------------------------------

Clientul nr.4

Se vor introduce datele persoanei

Introduceti ID-ul persoanei: 4

Introduceti numele persoanei: mihai

Introduceti CNP-ul: 50104

Se vor introduce datele abonatului

Introduceti nr de telefon: 0724

Se vor introduce datele abonamentului

Introduceti numele abonamentului: b1tv

Introduceti pretul abonamentului: 59

Introduceti perioada abonamentului: 12

Se vor introduce datele abonamentului premium

Introduceti reducerea: 0

-------------------------------------------------------

##### S-a apelat metoda 4 pentru a 2-a  oara (afisul este in output ) 
-------------------------------------------------------

##### S-a apelat metoda 7 de 2 ori avand ca input: 4 , 1 

Scrieti aici optiunea dumneavoastra: 7

Introduceti indicele elementului:
1

-------------------------------------------------------

Scrieti aici optiunea dumneavoastra: 7

Introduceti indicele elementului:
1

-------------------------------------------------------
##### S-au apelat metodele 4 si 5 din nou ( vezi outputul mai jos)

-------------------------------------------------------
##### S-a apelat metoda 3 ( vezi outputul mai jos)

## Output ( din meniu au fost selectate optiunile in ordinea precizata la inceput)

Sunt 2 de clienti premium    ///* afisat in urma selectarii optiunii 4 pentru prima data.

Castigul total este: 1271.02 lei    ///* afisat in urma selectarii optiunii 5 pentru prima data.

-------------------------------------------------------

##### optiunea 6 a fost apelata de 2 ori (vezi input), dupa care s-au afisat urmatoarele: 

Sunt 3 de clienti premium   ///* afisat in urma selectarii optiunii 4 pentru a doua oara.


-------------------------------------------------------
##### optiunea 7 a fost apelata de 2 ori (vezi in input)
-------------------------------------------------------
##### sunt apelate optiunile 4 si 5 si se afiseaza :

Sunt 2 de clienti premium   ///* afisat in urma selectarii optiunii 4

Castigul total este: 971.565 lei ///* afisat in urma selectarii optiunii 5

-------------------------------------------------------

##### optiunea 3 a fost selectata si se afiseaza :

ID-ul persoanei:
2

Numele Persoanei:
dan

CNP:
50102

Numar de telefon:
0722

Numele abonamentului:
hgo

Pret:
60

Perioada
12

Reducere de 5 %



ID-ul persoanei:
3

Numele Persoanei:
maria

CNP:
50103

Numar de telefon:
0723

Numele abonamentului:
disnep

Pret:
100.9

Perioada
3

Reducere de 5 %

-------------------------------------------------------

##### se incheie programul prin selectarea optiunii 0;


### output -ul poate sa difere in functie de ce doriti sa apelati in meniu.
### Daca gasiti dificila intelegerea acestui text, [aici](https://pastebin.com/c0LUb5hh) aveti un link catre datele de intrare direct din consola

## Scurta Prezentare a Codului: 

### Clasa nr1:  Abonament -> clasa parinte (devine clasa abstracta):

In cadrul acestei avem 3 tipuri de parametrii:
- un char alocat dinamic, reprezinta numele abonamentului
- un float , reprezinta pretul abonamentului
- un int, reprezinta perioada abonamentului(in luni de zile).

-------------------------------------------------------
Au fost definiti 3 constructori:
- constructorul fara parametrii ( initializeaza parametrii clasei cu null sau 0)
- constructorul cu parametrii (initializeaza parametrii clasei cu datele introduse)
- constructorul de copiere (initializeaza parametrii unui obiect al clasei pe baza altui obiect deja existent) 

-------------------------------------------------------
Au fost suprascrisi urmatorii operatori:
- operatoru= , faciliteaza copierea unui obiect in altul (obiect de tipul abonament).
- operatorul >>, faciliteaza citirea mai usoara a unui obiect de tipul clasei. La baza este o functie friend, folosita si in suprascrierea operatorului din clasa derivata.
-  operatorul <<, faciliteaza afisarea mai usoara a unui obiect de tipul clasei. La baza este o functie friend, folosita si in suprascrierea operatorului din clasa derivata.

In suprascrierea operatorului de citire, valorile parametrilor au fost modificate prin functiile set_.
In suprascrierea operatorului de afisare, valorile parametrilor au fost afisare prin functiile get_ care sunt de tip const.

Pe langa asta, clasa contine metoda virtuala pura numita get_reducere. Acesteia ii este aplicat override in clasa derivata. Scopul metodei aici este facilitarea 'accesului' la valoarea unui atribut al clasei derivata printr-un pointer al clasei de baza.

-------------------------------------------------------
Clasa dispune si de o serie de functii set_ si get_ :
- set_new_name folosita pentru a initializa char* -ul clasei cu un string. Conform feedbackului anterior, inainte de crearea unui nume nou se sterge cel vechi.
-  set_new_name_null folosit pentru a face char*-ul clasei sa pointeze spre ceva NULL in constructorul fara parametrii
-  set_pret si set_perioada folosite pentru a initializa cele 2 valori numerice.
-  get_name de tip char* , returneaza continutul stringul memorat
-  get_pret si get_perioada returneaza valoarea pretului, respectiv a perioadei 
-  Functiile set sunt trecute la protected, cele get sunt publice dar sunt functii const.

-------------------------------------------------------
Destructorul este virtual

-------------------------------------------------------
sunt trecute aici 2 clase prietene (clienti si abonat) intrucat in vederea construirii unui obiect clienti ce are un array dinamic de obiecte abonat, sunt modificate perioadele, preturile si numele abonamentelor ( in functie de ce metode sunt apelate din meniu)

### Clasa nr2:  Abonament_premium -> clasa copil, mosteneste clasa Abonament:

In cadrul acestei avem 1 parametru declarat explicit, alte 3 tipuri de parametrii mosteniti implicit de la parinte:
- un int ( reducere) ce face diferenta intre un abonament normal si unul premium; 
-  toti parametrii clasei Abonament (mosteniti)

-------------------------------------------------------
Au fost definiti 3 constructori:
- constructorul fara parametrii ( initializeaza parametrii clasei cu null sau 0). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului reducere
- constructorul cu parametrii (initializeaza parametrii clasei cu datele introduse). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului reducere cu o valoare intreaga transmisa
- constructorul de copiere (initializeaza parametrii unui obiect al clasei pe baza altui obiect deja existent). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului reducere folosind un alt obiect deja creat.

-------------------------------------------------------
Au fost suprascrisi urmatorii operatori:
- operatoru= , faciliteaza copierea unui obiect in altul. Dupa copierea parametrului explicit al clasei derivate, se apeleaza operatorul specific parintelui.
- operatorul >>, faciliteaza citirea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Odata cu citirea parametrilor expliciti ai clasei, sunt cititi si parametrii clasei parinte.
-  operatorul <<, faciliteaza afisarea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Odata cu afisarea parametrilor expliciti ai clasei, sunt afisati si parametrii clasei parinte.

Operatorii de input si output functioneaza cu ajutorul unor linii de cod ce implica upcasting.

-------------------------------------------------------
In suprascrierea operatorului de citire, valorile parametrilor au fost modificate prin functiile set_.
In suprascrierea operatorului de afisare, valorile parametrilor au fost afisare prin functiile get_ de tip const.

-------------------------------------------------------
Clasa dispune si de o serie de functii set_ si get_ :
- set_new_reducere folosita pentru a initializa valoarea intregului reducere
-  get_reducere (de tip int, de origine din clasa parinte abonament) returneaza valoarea reducerii. Acestei functii ii este aplicat procedeul de overriding.
-  Functiile set sunt trecute la protected, cele get sunt publice dar sunt functii const.


#### Conform regulilor de mostenire ale claselor, abonament_premium IS-A abonament.

### Clasa nr3:  Persoana -> clasa parinte:

In cadrul acestei avem 2 tipuri de parametrii:
- un char alocat dinamic, reprezinta numele persoanei
- un char alocat dinamic, reprezinta cnp-ul persoanei

-------------------------------------------------------
Au fost definiti 3 constructori:
- constructorul fara parametrii ( initializeaza parametrii clasei cu null)
- constructorul cu parametrii (initializeaza parametrii clasei cu datele introduse)
- constructorul de copiere (initializeaza parametrii unui obiect al clasei pe baza altui obiect deja existent) 

-------------------------------------------------------
Au fost suprascrisi urmatorii operatori:
- operatoru= , faciliteaza copierea unui obiect in altul.
- operatorul >>, faciliteaza citirea mai usoara a unui obiect de tipul clasei. La baza este o functie friend, folosita si in suprascrierea clasei derivata.
-  operatorul <<, faciliteaza afisarea mai usoara a unui obiect de tipul clasei. La baza este o functie friend, folosita si in suprascrierea clasei derivata.

Operatorul= si copy-constructorul folosesc un string intermediar pentru initializarea parametrilor obiectului clasei.

-------------------------------------------------------
In suprascrierea operatorului de citire, valorile parametrilor au fost modificate prin functiile set_.
In suprascrierea operatorului de afisare, valorile parametrilor au fost afisare prin functiile get_.

-------------------------------------------------------
Clasa dispune si de o serie de functii set_ si get_ :
- set_new_name1 folosita pentru a initializa numelui persoanei cu un string.  Conform feedbackului anterior, inainte de crearea unui name1 nou se sterge cel vechi.
- set_new_name1_null folosit pentru a face numele persoanei sa pointeze spre ceva NULL in constructorul fara parametrii.
- set_new_cnp folosita pentru a initializa cnp-ul cu un string.   Conform feedbackului anterior, inainte de crearea unui cnp nou se sterge cel vechi.
-  set_new_cnp_null folosit pentru a face cnp-ul sa pointeze spre ceva NULL in constructorul fara parametrii.
-  get_name1 de tip char* , returneaza continutul stringul memorat in name1.
-  get_cnp de tip char* , returneaza continutul stringul memorat in cnp.
-  Functiile set_ sunt trecute la protected, cele get_ sunt publice dar sunt functii const.

-------------------------------------------------------
Functia virtuala prezenta in clasa aceasta este destructorul;

### Clasa nr4:  Abonat -> clasa copil, mosteneste clasa Persoana:

In cadrul acestei avem 2 parametii declarati explicit, alte 2 tipuri de parametrii mosteniti implicit de la parinte:
- un char* ( nr_telefon) ce reprezinta numarul de telefon al unei persoane; 
-  un obiect te tipul clasei abonament ( mai exact un pointer, la initializare folosindu-se =new abonament_premium() intrucat clasa abonat este una abstracta.)
-  toti parametrii clasei Persoana (mosteniti)

-------------------------------------------------------

Au fost definiti 3 constructori:
- constructorul fara parametrii ( initializeaza parametrii clasei cu null sau 0). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului nr_telefon. De asemenea , este folosit aici pointerul de tipul clasei abonament, el pointeaza spre un obiect de tip abonament_premium. Cu scrierea respectiva, putem folosi pointerul ca pe un obiect derivat.
- constructorul cu parametrii (initializeaza parametrii clasei cu datele introduse). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului nr_telefon cu un string transmis.  De asemenea , este folosit aici si unul din constructorii obiectului abonament_premium( in set_new_object).
- constructorul de copiere (initializeaza parametrii unui obiect al clasei pe baza altui obiect deja existent). Este folosit codul din constructorul parintelui caruia i se adauga initializarea parametrului nr_telefon folosind un alt obiect deja creat.  De asemenea , este folosit aici si unul din constructorii obiectului abonament_premium( in set_new_object).

-------------------------------------------------------
Au fost suprascrisi urmatorii operatori:
- operatoru= , faciliteaza copierea unui obiect in altul. Dupa copierea parametrului explicit al clasei derivate, se apeleaza operatorul specific parintelui.
- operatorul >>, faciliteaza citirea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Odata cu citirea parametrilor expliciti ai clasei, sunt cititi si parametrii clasei parinte.
-  operatorul <<, faciliteaza afisarea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Odata cu afisarea parametrilor expliciti ai clasei, sunt afisati si parametrii clasei parinte.

-------------------------------------------------------
Operatorii de input si output functioneaza cu ajutorul unor linii de cod ce implica upcasting.
Mai mult, operatorii de input respectiv output ai acestei clase se folosec de operatorii de input & output ai clasei cu care este compusa, pentru citirea mai usoara a obiectului in cauza.

In suprascrierea operatorului de citire, valorile parametrilor au fost modificate prin functiile set_.
In suprascrierea operatorului de afisare, valorile parametrilor au fost afisare prin functiile get_.

-------------------------------------------------------
Clasa dispune si de o serie de functii set_ si get_ :
- set_new_telefon folosita pentru a initializa valoarea stringului nr_telefon
- set_new_telefon_null, face ca nr_telefon sa pointeze spre ceva NULL
- set_new_obj , foloseste functiile get si constructorul specific obiectului catre care pointeaza pointerul de tip abonament. (De ce este putin mai diferit acest set? In cadrul clasei clienti, la stergerea / adaugarea obiectelor in arrayul de obiecte abonat, in unele situati existau probleme de copiere proaste a datelor abonamentului (numele si pretul uneori ramaneau la fel.). Astfel folosind acest set_ si in operatorul= al clasei si in alte locuri cheie, se asigura copierea corecta si independenta intra obiectele arrayului)
- get_telefon de tipul char* ce returneaza stringul continut in nr_telefon.
-  Functiile set sunt trecute la protected, cele get sunt publice dar sunt functii const.

-------------------------------------------------------

O metoda publica a clasei este cea get_reducere2() de tip const. 
Aceasta este folosita in aditie metodei get_reducere deja existente. Ea poate fi folosita pe un obiect de tip abonat a.i. sa ii reintoarca reducerea unui abonament.

-------------------------------------------------------
Clasa dispune si de un destructor.

-------------------------------------------------------
Clasa sa prietena este clienti intrucat, in lista de abonati construita in clienti pot aparea schimbari asupra unui abonat.


### Ultima clasa, class Clienti ( intitulata si clasa de acces deoarece metodele din cerintele acestui proiect sunt apelate prin intermediul acestei clase): in compunere cu clasele abonat, abonament(clienti e clasa prietena a acesteia);

In cadrul acestei avem:
- o lista de obiecte de tipul clasei abonat;

In plus, ca o variabila statica, apare 'm' reprezentand lungimea listei. Variabila statica este de tip clienti, este modificata pentru inceput in main iar mai apoi, in unele cazuri, si in metodele clasei.

-------------------------------------------------------
Au fost definiti 3 constructori:
- constructorul fara parametrii ( initializeaza arrayul de obiecte abonat cu null)
- constructorul cu parametrii (initializeaza parametrii clasei folosind datele introduse)Constructorul primeste doar lungimea listei dorite, de restul se ocupa functia set_new_vector
- constructorul de copiere (initializeaza parametrii unui obiect al clasei pe baza altui obiect deja existent) 

-------------------------------------------------------
Au fost suprascrisi urmatorii operatori:
- operatoru= , faciliteaza copierea unui obiect in altul.
- operatorul >>, faciliteaza citirea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Se foloseste de functia set_new_vector care creaza si citeste elementele arrayului, elemente de tip abonat. Printr-ul element de tip abonat se ajunge la pointerul abonament* obj prin care se apeleaza functii (constructori / operatori) specifici clasei abonament si abonament_premium. Prin elementul de tip abonat se apeleaza si functii specifice clasei abonat si persoana.
-  operatorul <<, faciliteaza afisarea mai usoara a unui obiect de tipul clasei. La baza este o functie friend. Acest operator se foloseste de operatorul obiectelor de tip abonat.

-------------------------------------------------------
Functia dispune si de destructor.

-------------------------------------------------------
#### Metodele din aceasta clasa :

##### Metoda unicitate(int i, int &ok):

Este o metoda vitala clasei. Atunci cand este creat array-ul, folosind aceasta metoda in functia set_new_vector, se va tine cont de unele restrictii impuse ( nu pot exista 2 persoane cu id diferit si cnp egale, nu pot exita perosane ceu id egal dar alt cnp ( la fel si pt telefon), o persoana cu un anumit id nu poate avea 2 abonamente la acelasi furnizor ( netflix) ambele de acelasi tip (premium / non-premium)( sa zicem ca o persoana cu id x are un abonament premium de la furnizor y, daca doreste un alt abonament premium de la furnizorul y nu poate folosi credentialele sale deoarece sunt deja asociate unui abonament. exceptie: poate avea un abonament premium si unul simplu pe aceleasi credentiale).

Aceasta metoda este folosita si in metoda 'inserare element' din motive evidente.

Pentru a vedea toate exceptiile recomand citirea mesajelor afisate in aceasta metoda.

-------------------------------------------------------
##### Metoda returnme_nume_abonament(int k):

Este folosita in metoda unicitate. Prin ea , un obiect al clasei clienti poate determina valoare numelui abonamentului pentru elementul k din arrayul sau de tip abonat.

-------------------------------------------------------
##### Metoda returnme_reducere(int k):

Este folosita in metoda unicitate. Prin ea , un obiect al clasei clienti poate determina valoare reducerii abonamentului pentru elementul k din arrayul sau de tip abonat.

-------------------------------------------------------
##### Metoda returnme_cnp(int k):

Nu este puas in functiune intrucat pentru un obiect v[i] se poate apela functia deja existenta v[i].get_cnp(), dar scopul ei este acelasi.

-------------------------------------------------------
##### Metoda clienti_premium:

Se parcurge lista de obiecte de tip abonat. 'Trecem' prin toate clasele implicate pana 'ajungem' la obiectul din clasa abonament asupra caruia ese apelata o metoda get_.

-------------------------------------------------------
##### Metoda castig_total: 

Se parcurge lista si pentru fiecare abonat este calculata suma de plata in functie de reducere si perioada, dupa care este adunata la suma totala.

-------------------------------------------------------
##### Metoda insert_element(): 

Este o metoda protected intrucat 'modifica' unele atribute ale clasei sale si ale unor clase prietene. Este apelata prin intermediul metodei intermediare 'intermediar()'. Aceasta modifica lungimea arrayului. Il recopiaza in alt array mai mare pentru a avea loc sa fie citit noul element. Se citeste noul element si se testeaza unicitatea cu metoda mentionata mai sus. Cand totul este gata, se recopiaza in arrayul original iar arrayul temporar e sters.

-------------------------------------------------------
##### Metoda sterg_element(int k): 

Este asemanatoare cu metoda de mai sus. Si ea este apelata printr-un intermediar ('intermediar2(int k)'). Lungimea arrayului este micsorata de data aceasta, in arrayul temporar copiindu-se toate obiectele mai putin cel ce se doreste a fi sters. Se recopiaza totul in arrayul original care are acum o dimensiune mai mica. Arrayul temporar se sterge.

-------------------------------------------------------
##### Metoda set_new_vector(int nr2): 

Metoda vitala a clasei. Prin ea se creeaza lista de obiecte de tip abonat. Nr2 reprezinta lungimea pe care se vrea sa se construiasca lista. 
Procedeul implica citirea elementelor de tip abonat prin operatorul suprascris in clasa acestora. In urma conditiei de unicitate (apel catre metoda 'unicitate'), exista 2 optiuni:
- Elementul actual este considerat 'unic' si se potriveste in acest array, citirea mergand mai departe
- Elementul nu e considerat 'unic'. Astfel, pentru acest element stergem toate atributele declarate dinamic (toate char* urile), le initializam cu NULL ( este mai mult o siguranta ca la citirea urmatoare pentru acest element, aceste campuri sunt NULL si nu trebuie resterse), se 'sterge' pointerul curent, se face un pas in spate si se reia citirea pana cand gasim un element potrivit.

-------------------------------------------------------

Desigur, clasa are si destructor.


-------------------------------------------------------


### Comentarii: 

In rezolvarea temei, nu am regasit un loc in interiorul claselor sau o cerinta care ,din perspectiva mea, sa aibe nevoie de dynamic_cast (downcasting) Singurul loc unde m-am apropiat de downcasting a fost in declararea pointerului obj a.i. el sa pointeze spre un obiect de tip abonament_premium. Cu scrierea respectiva, putem folosi pointerul ca pe un obiect derivat.


De asemenea imi pare foarte rau ca nu am reusit sa duc cerinta bonus pana la capat. AStfel, acest cod nu contine si cerinta bonus, este tema pura.
