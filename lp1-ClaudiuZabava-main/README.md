* Recomand copierea si citirea fisierului README in dillinger.io
# Documentatie  : 

## S-au folosit urmatoarele date de intrare:

6

10 5 5 6 8 7

5



7

10 9 9 10 7 8 5

5

## S-au afisat urmatoarele date:

Multimile obtinute sunt:

{0, 1, 3, 2}

{0, 4, 2, 3}

Al 3-lea minim este : 2

Al 3-lea minim este : 3

Reuniunea celor 2 multimi este :
{0, 1, 4, 3, 2}

Intersectia celor 2 multimi este :
{0, 2, 3}

Diferenta celor 2 multimi este:
{1}

Diferenta celor 2 multimi este:
{4}

Rezultatul operatiei '+=' este
{0} 



## Observatii:

- Multimea {0} afisata mai sus nu este multimea vida, este o multime cu un element (elementul 0) obtinuta respectand modulo si proprietatea de elemente distincte ale unei multimi. In cazul multimii vide este afisat mesaj.

- Functiile set_  au fost trecute la private intrucat acestea sunt folosite pentru modificarea parametrilor clasei.

- Functiile get_  sunt functii care returneaza  o valoare, astfel fiind lasate la public pentru a permite utilizatorului sa afiseze mai multe informatii despre  valorile memorate in parametrii clasei. Aceste functii nu pot modifica / rescrie parametrii a caror valoare o returneaza (acesta fiind scopul functiilor set_  care sunt private).

- Au fost scrisi 3 tipuri de constructori( fara parametru, cu parametru si de copiere). A fost nevoie de constructorul de copiere intrucat in program exista apeluri de functii cu obiect ca parametru. Totodata, avand contructor cu parametru, constructor de copiere si destructor este respectata 'Regula celor 3' (' The rule of Three') care spune ca daca este nevoie sa declaram fie un constructor de copiere , fie cu parametru fie un destructor, cel mai probabil trebuie declarati toti 3.

- A fost suprascris si operatorul '=' din cadrul clasei pentru a facilita atribuiri intre 2 obiecte ale clasei, acesta fiind folosit in anumite cazuri si in metodele implementate. 
- In anumite cazuri si in anumite modulo, in urma operatiei '+=' multimea destinatie este recreata pentru a evite aparitia dublurilor
Ex: 
multimea 1 in modulo 12: 10, 4
multimea 2 in modulo 12: 11, 5
multime 1 += multime 2  -> in mod normal multimea 1 va avea {11+10= 9 in modulo 12 , 4+5= 9 in modulo 12} ceea ce incalca principiul ca multimile sa aibe elemente distincte. astfle este rescrisa -> {9}



## Prezentare Cod:

Numelei clasei implementate este multimi. 
#### Parametrii clasei : 
- cardinal (int) -> numarul elementelor multimii
- modulo (int) -> elementele multimii sunt transformate in functie de modulo (ex: 22 = 10 in mod 12)
- elemente -> pointerul "elemente" va memora array ul de elemente prelucrate din vectorul initial pentru fiecare obiect al clasei.
Cei 3 parametrii sunt privati.



#### Metodele clasei:
- al 3-lea minim din multime
- intersectia , reuniunea multimilor
- diferenta dintre 2 multimi ( A\B = A-B)
- suprascrierea operatorului '+=' astfel incat sa realizeze suma element cu element intre multimi de cardinal si modulo egale, rezultatul fiind memorat in prima multime, modificand si cardinalul pentru a nu aparea dubluri.



#### Pt1.  (set & get):

Clasa dispune de mai multi getters:
- get_cardinal() -> returneaza o valoare, cardinalul multimii;
- get_modulo() -> returneaza o valoare, modulo multimii;
- get_element(int i) -> returneaza o valoare, al i-lea element al multimii;



Clasa dispune de mai multi setters:

- set_cardinal(int i) -> initializeaza cardinalul multimii / obiectului cu valoarea i; este folosit doar in constructori si in operatorul de atribuire din cadrul clasei;

- set_modulo(int i) -> initializeaza modulo multimii / obiectului cu valoarea i; este folosit doar in constructori;

- set_element(int i, int j, int mod) -> atribuie elementului de pe pozitia i a multimii valoarea: j modulo mod ; este folosit doar in constructori si in operatorul de atribuire din cadrul clasei;

- set_new_element(int i) - > initializeaza array-ul elemente cu dimeniunea i; este folosit doar in constructori si in operatorul de atribuire din cadrul clasei;

- set_new_element_null() -> array-ul elemente devine NULL; este folosit in mod special in constructorul fara parametrii;
- set_new_pointer_element(int *new_pointer) - > folosit atunci cand vrem ca pointerul *elemente sa pointeze spre un alt array deja creat si memorat in new_pointer; Este aplicat in cadrul contructorului de copiere si a operatorului de atribuire din cadrul clasei;

Functiile setters sunt trecute ca fiind private deoarece modifica parametrii obiectului / multimii;



#### Pt2.(constructori):

Pentru inceput, multimi() reprezinta constructorul fara parametrii al clasei noastre. 
Permite crearea si instantierea obiectelor astfel:
clasa ob1;
Acesta atribuie valori nule / zero parametrilor obiectului asupra caruia este apelat.


Mai departe, multimi(v,m,mod) reprezinta constructorul clasei noastre. Primeste ca parametrii vectorul initial, lungimea acestuia si modulo in are se doreste a fi transformate elementel multimii si creeaza obiectul alaturi de parametrii sai ( cardinal, modulo, elemente)
Parametrul "elemente" este alocat dinamic, pastrand multimea creata din vectorul initial prelucrat.


Mai departe, multimi(const multimi &p2) reprezinta constructorul de copiere al clasei noastre. Constructorul de copiere este necesar intrucat in program exista functii cu obiect ca parametru.
Ca parametrii primeste adresa unui obiect folosit pentru a fi copiat de un alt obiect.
Inainte de copiere, se sterge array ul obiectului initial, acel pointer urmad sa arate apoi spre array ul obiectului p2. Cardinal, modulo si elemente sunt modificate cu ajutorul functiilor set_.



Cu scop asemanator constructorului de copiere a fost suprascris si operatorul "=" din cadrul clasei pentru a facilita atribuirea dintre 2 obiecte ale clasei si a rezolva micile probleme cu memoria.


#### Pt3.(metode implementate):

##### Pt3.1 (min3):
Functia min3() reprezinta una din metodele implementate. 
Functia isi declara 4 variabile locale:
- contorul i (folosit pentru parcurgere)
- 3 minime (minim1,minim2,minim3 initializate cu o valoare mare)

Parcurgand elementele unui obiect dat al clasei, functia memoreaza la fiecare pas cele mai mici 3 elemente dintre cele parcurse djea.
Daca obiectul / multimea data nu are minim 3 elemente este afisat un mesaj aferent.



##### Pt3.2 (reuniune):
Functia reuniune(const multimi &p2, multimi &p3) este una din metodele implementate.
Functia are ca parametrii adresa unui obiecta al clasei pentru a se putea apela intre 2 obiecte ale aceleiasi clase si o alta adresa reprezentand multimea destinatie, unde se va salva rezultatul reuniunii.
Ex: multime1.reuniune(multime2, multime3) -> executa reuniunea multimi1 cu multimea 2 si o salveaza in multime3;
Sunt declarate 4 variabile locale: 
- contorii i, j si m 
- vectorul a folosit ca vector initial pentru crearea multimii destinatie. (vectorul este prelucrat la crearea multimii pentru a avea elemente distincte).

Daca una din multimi este vida / nula, lui p3 i se atribuie cealalta multime ( cea nenula) cu ajutorul operatorului de atribuire suprascris anterior.
Se foloseste *this in cazul in care vrem sa ii atribuim lui p3 multimea ce nu este data ca parametru pentru functie.
Daca ambele multimi sunt nule (cardinal=0) se afiseaza multime vida.
Reuniunea are loc doar daca cele 2 multimi au acelasi modulo.
Functia memoreaza cele 2 multimi in vectorul a, apelat mai tarziu ca vector initial din care se creeaza multimea destinatie ( constructorul are grija ca multimea destinatie sa aibe elemente distincte, astfel proprietatile reuniunii sunt respectate)



##### Pt3.3 (intersectie):
Functia intersectie(const multimi &p2, multimi &p3) este una din metodele implementate.
Functia are ca parametrii adresa unui obiecta al clasei pentru a se putea apela intre 2 obiecte ale aceleiasi clase si o alta adresa reprezentand multimea destinatie, unde se va salva rezultatul intersectiei.
Sunt declarate 3 variabile locale 
- contorii i, j, m si ok;
- vectorul a folosit ca vector initial pentru crearea multimii destinatie;

Daca oricare dintre multimi este vida, rezultatul intersectiei este multime vida.
Intersectia are loc doar daca cele 2 multimi au acelasi modulo.
In cazul in care nu sunt intalnite exceptiile de mai sus, se parcurge una din cele 2 multimi, memorandu-se in vector doar elementele comune, contorul ok tinand minte daca s-a memorat macar un element.
In cazul in care nu s-a memorat nimic, se afiseaza multime vida. Altfel, se rescrie multimea destinatie data ca parametru folosind vectorul initial.



##### Pt3.4 (diferenta):
Functia diferenta(const multimi &p2, multimi &p3) este una din metodele implementate.
Functia are ca parametrii adresa unui obiecta al clasei pentru a se putea apela intre 2 obiecte ale aceleiasi clase si o alta adresa reprezentand multimea destinatie, unde se va salva rezultatul diferentei.
Sunt declarate 6 variabile locale: 
- contorii i, j, m, ok1 si ok2;
- vectorul a folosit ca vector initial pentru crearea multimii destinatie;

Daca prima multime este vida , diferenta dintre multime vida - multime 2 este tot multime vida.
Daca cea de a doua multime este vida, diferenta este reprezentata de prima multime (multime 1 - nimic = multime 1). Lui p3 i se atribuie prima multime cu ajutorul lui *this si al operatorului de atribuire suprascris in cadrul clasei.
Diferenta are loc doar intre multimi cu acelasi modulo.
In cazul in care nu sunt intalnite exceptiile de mai sus, se parcurge una dintre liste, initializand la fiecare element contorul ok1 cu 1.
Daca un element din prima lista se gaseste in a doua , contorul ok1 devine 0 indicand faptul ca elementul nu trebuie memorat.
Contorul ok2 tine minte daca s-a memorat macar un element, fiind folosit pentru afisarea mesajului "multime vida" atunci cand diferenta este nula.



##### Pt3.5 (operatorul +=):
Suprascrierea operatorului "+=" in cadrul clasei. 
Functia de suprascriere a operatorului primeste ca parametru adresa celui de al 2-lea obiect folosit in cadrul operatiei.
Functia verifica mai intai daca operatia se poate executa corect (intre 2 multimi de cardinale si modulo egale)
Ca variabile locale avem:
- contorii i si m;
- vectorul a folosit ca vector initial pentru rescrierea / recrearea primei multimi;

Se parcurge una dintre multimi si se aduna in vector elementul de pe pozitia i din multimea 1 cu elementul de pe pozitia i din multimea 2.
Prima multime este recreata / rescrisa folosindu-se vectorul a ca vector initial in cadrul constructorului.
Rescrierea primei multimi are loc cu ajutorul pointerului *this ce specifica in cadrul functiei ca rezultatul operatiei sa fie salvat in prima multime. 



#### Pt4. (Destructorul):
~multimi() reprezinta destructorul clasei.
Este nevoie de acest destructor datorita array ului declarat dinamic pentru fiecare obiect.



Metodele descrise mai sus sunt apelate apoi manual in main ( mai putin destructorul care se apeleaza automat).

## Alte Input si Output:
### Input2:
10

10 16 18 5 9 20 9 7 14 8

12


8

11 5 28 6 8 9 7 26

12

### Output2:
Multimile obtinute sunt:

{10, 4, 6, 5, 9, 8, 7, 2}

{11, 5, 4, 6, 8, 9, 7, 2}

Al 3-lea minim este : 5

Al 3-lea minim este : 5

Reuniunea celor 2 multimi este :
{10, 4, 6, 5, 9, 8, 7, 2, 11}

Intersectia celor 2 multimi este:
{5, 4, 6, 8, 9, 7, 2}

Diferenta celor 2 multimi este:
{10}

Diferenta celor 2 multimi este:
{11}

Rezultatul operatiei '+=' este
{9, 10, 11, 5, 2, 4}

### Input3:
5

8 3 12 6 9

10


0

### Output3:
Multimile obtinute sunt:

{8, 3, 2, 6, 9}

{multime vida}

Al 3-lea minim este : 6

Al 3-lea minim este :  Multimea nu are destule elemente

Reuniunea celor 2 multimi este :
{8, 3, 2, 6, 9}

Intersectia celor 2 multimi este: { multime vida }

Diferenta celor 2 multimi este:
{8, 3, 2, 6, 9}

Diferenta celor 2 multimi este: { multime vida }

Rezultatul operatiei '+=' este
Eroare de operator: ati introdus multimi de cardinale sau modulo diferite
 
 
