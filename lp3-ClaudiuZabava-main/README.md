# PROIECT : TEMA4 

-------------------------------------------------------

# Prezentare Meniu:

Asa cum a fost cerut in barem, proiectul dispune de un [meniu](https://pasteboard.co/K2ctrO7.png) interactiv cu 9 optiuni:

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
  
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
  
 9 - END.
***************************************************************************************************
Fiecare optiune executa cate o actiune asupra celor 2 stock-uri din parcul auto ( stockul de masini diverse (Compacta / Mini / Mica) si stockul de masini Monovolum).
Avem doua tipuri de stockuri intrucat enuntul solicita gestiunea separata a Monovolumelor
### Previzualizare executie cap - coada cu ajutorul meniului:
-[iamginea1](https://pasteboard.co/K2ctdE9.png) utilizatorul introduce date aiurea pt.1;

-[iamginea2](https://pasteboard.co/K2ctCnH.png) vindem ceva ce nu avem;

-[iamginea3](https://pasteboard.co/K2cugYr.png) vindem ceva ce avem;

-[iamginea4](https://pasteboard.co/K2cuzei.png) afis stock tipuri diverse;

-[iamginea5](https://pasteboard.co/K2cuRbd.png) afisare ce s-a vandut din tipuri diverse;

-[iamginea6](https://pasteboard.co/K2cvaMG.png) citire monovolume + utilizatorul citeste din nou cateva date aiurea;

-[iamginea7](https://pasteboard.co/K2cw6m8.png) vinde cateva monovolume;

-[iamginea8](https://pasteboard.co/K2cwlKI.png) sa vedem ce am vandut din Monovolume;

-[iamginea9](https://pasteboard.co/K2cwCSK.png) crearea si afisarea Setului de stock pentru masini tip diverse, dupa cum s-a solicitat;

-[iamginea10](https://pasteboard.co/K2cx8Sq.png) crearea si afisarea Setului de stock pentru masini tip Monovolum, dupa cum s-a solicitat;

In functie de ordinea apelarii optiunilor, outputul poate sa fie diferit.
Pentru a vedea exact outputul din poze, verificati fisierul 'input si output'.
### Functionalitatea meniului si modul in care acesta se descurca cu Exceptiile:

Asa cum cerea si problema, proiectul reuseste sa gestioneze cu succes o buna parte din exceptiile care pot aparea din cauza unui utilizator neexperimentat.
Printre acestea se innumara :
- utilizatorul doreste sa citeasca / introduca in parc mai multe masini , dar greseste unele caracteristici specifice masinilor sau introduce date aiurea (ex. in `imaginea1` la precizarea lungimii masinii tip Mica si a formei masinii tip Compacta )
- utilizatorul introduce intentionat un string in locul unde trebuia introdusa o valoare numerica ( ex. in `imaginea1` la precizarea pretului si a litrajului masinii tip Mica, dar si in alte locuri)
- utilizatorul introduce valori negative sau ireal de mari ( in cazul unui an, acesta sa introduca anul 3033) ( ex. in `imaginea6` la a doua masina tip Monovolum la precizarea anului de fabricatie, dar si in `imaginea1` in diferit locuri)

Aceste exceptii sunt tratate / rezolvate / evitate in cod cu ajutorul procedurilor **try - throw - catch**. Acestea sunt intens folosite acolo unde se citesc sau se transmit valori / variabile de la tastatura / de la utilizator catre program, intrucat acest utilizator poate incerca sa compromita programul introducand date necorespunzatoare.

Pe langa clasicele verificari cu if-uri pentru ca datele transmise sa corespunda caracteristicilor masinilor, o exceptie diferita care este tratata este aceea din operatorul de citire , supraincarcat in toate clasele ce definesc msini. 
Acolo se incearca prin try citirea corespunzatoare a unor valori numerice. Daca esueaza, ceea ce s-a citit se ignora, se sterge ultimul continut din operatorul istream `in`, se citeste un dummy string pentru a evita ca programul sa sara peste anumiti pasi dupa citirea a ceva necorespunzator, si se continua / reincearca citirea corecta a unor valori.

Ceva similar se petrece si in constructorii parametrizati ai claselor tip masini, doar ca in cazul acela nu se citeste o valoare, se transmite prin parametrul constructorului. Astfel, daca valoarea transmisa prin parametru nu e corespunzatoare, programul corecteaza asta si alege ( fie la intamplare fie ceva predefinit ) o valoare acceptabila caracteristicilor masinii.

Toate aceste verificari de exceptii sunt folosite pentru variabilele membre ale claselor. Chiar daca try-catch nu se aplica direct asupra lor, se aplica asupra altor variabile intermediare care ajung intr-un final sa modifice / atribuie valori celor membre. Astfel, programul se asigura ca le sunt atribuite valori ok.


# Prezentare Cod

In cadrul acestui proiect se doreste gestiunea ( vanzarea si afisarea srtockului) unui parc auto care contine 4 tipuri de masini cu diferite specificatii.

#### Au fost create 6 clase :
##### Pt1) Clasa Masini (clasa parinte):
Clasa masini a fost creata ca si claza de baza pentru cele 4 tiprui de masini prezente in parc. 
Aceasta clasa contine variabile ce sunt comune si celorlalte clase: 
- tipul masinii ( se re-defineste separat in cadrul fiecarei clase): de tip string;
- denumirea masinii : de tip string 
- pretul: de tip float;
- capacitatea cilindrica/litraj : de tip int;

Cu toate ca si variabila `an` ( anul de fabricatie) ar parea ceva general pentru toate tipurile de masini, nu tuturor tipurilor de masini li se permit sa aibe un anumit an de fabricatie ( unele nu pot fii second hand), astfel aceasta variabila nu este trecuta aici.


Clasa dispune si de o sumedenie de metode :
- functiile set_ ( protected), get_ ( publice, dar const) specifice oricarei clase;
- Constructorii ( cu parametru, fara parametru, de copiere) care construiesc obiectul. Cei cu parametru se ocupa si de verificarea unor exceptii.;
- Destructor ( virtual, intrucat in una din urmatoarele clase se creeaza un array de pointeri care trebuie eliberat stergand date de la fiecare adresa).;
- Operatorii de citire si afisare si operatorul= ( supraincarcati);
- Metoda virtuala de citire, respectiv de afisare a unei masini. Aceasta metoda este inactiva in clasa de baza, dar este rescrisa in clasele sale derivate.
- Functiile de reducere `aplica_reducere1(nr)` si  `aplica_reducere2()`. Aceste 2 functii sunt folosite pentru a aplica cele 2 reduceri mentionate de enunt :
. Reducere pentru lunile de vara
. Reducere raportata la vechimea masinii ( aplicata doar celos SH, adica Monovolumelor).
Aceste reduceri sunt vizibile / se aplica asupra pretului doar la vanzarea masinii. Astfel, dupa ce vindem o masina si verificam istoricul de vanzari, putem observa avolo pretul final cu care aceasta a ajuns sa se vande ( fiindu-i aplicate reducerile).

Nu in ultimul rand , trebuie sa mentionam prezenta variabilelor statice `luna` si `prezent`. Acestea tin de libraria `<ctime>` si sunt folosite in unele locuir in cod pentru a ne raporta la timpul actual ( ex: unele reduceri au loc doar in lunile de vara, asadar, doar cand data calendarisitca va fii o luna de vara se vor aplica acele reduceri).
- prezent = reprezinta anul curent. 
- luna = reprezinta luna curenta.
Aceste 2 variabile sunt initializate in exteriorul oricarei clase / functii, cu ajutorul librariei `ctime` si al structuri `tm` ( exemplul concert inainte de inceputul main-ului)

-------------------------------------------------------

##### P1.1) Clasa Mini: clasa derivata din Masini:
Mini este primul tip de autovehicul mentionat in problema.
A fost creata o clasa separata pentru aces tip deoarece contine variabile specifice precum :
- anul: Prin conventie, in aceasta structura de clase , o masina este considerata fie noua daca anul favbricatiei nu depaseste cu 1 anul curent ( nu e mai veche de un an), fie SH in caz contrar.
- lungimea: In cazul unei masini Mini, lungimea este specifica ( minim 1 si maxim 4)

Clasa dispune si de o serie de metode :
- functiile set_ ( protected), get_ ( publice, dar const) specifice oricarei clase;
- Constructorii ( cu parametru, fara parametru, de copiere) care construiesc obiectul:
  Aici putem mentiona faptul ca in constructorul cu parametrii, daca user-ul ii transmite lungime sau anul de fabricatie necorespunzator, acesta ii va seta valoarea prezent.
- Destructor ( default, intrucat nu alocam dinamic nimic in aceasta clasa);
- Operatorii de citire si afisare si operatorul= ( supraincarcati):
  In cadrul operatorului de citire, din nou se pune accentul pe datele ce diferentiaza clasa Mini de celelalte tipuri. AStfel, utilizatorul nu poate introduce lungimi sau ani de fabricatie necorespunzatori.
  
  Operatorul de afisare ruleaza pe baza unor linii de cod care implica **upcasting**
  
- Metoda virtuala de citire, respectiv de afisare a unei masini. Acestea sunt rescrise aici si permit parcurgerea unui array de obiecte de tip Mini si afisarea sau citirea acestora.

-------------------------------------------------------

##### P1.2) Clasa Mica: clasa derivata din Masini:
Mica este al doilea tip de autovehicul mentionat in problema.
A fost creata o clasa separata pentru aces tip deoarece contine variabile specifice (sau cu valori specifice doar acestui tip) precum :
- anul: Prin conventie, in aceasta structura de clase , o masina este considerata fie noua daca anul favbricatiei nu depaseste cu 1 anul curent ( nu e mai veche de un an), fie SH in caz contrar.
- lungimea: In cazul unei masini tip Mica, lungimea este specifica ( minim 3.85 si maxim 4.1)
- ampatamentul / spatiul interior , alta variabila specifica doar acestei clase ( conform enuntului) , care nu poate depasi lungimea masinii.

Clasa dispune si de o serie de metode :
- functiile set_ ( protected), get_ ( publice, dar const) specifice oricarei clase;
- Constructorii ( cu parametru, fara parametru, de copiere) care construiesc obiectul:
  Aici putem mentiona faptul ca in constructorul cu parametrii, daca user-ul ii transmite lungime, ampatament sau anul de fabricatie necorespunzator, acesta ii va seta automat o valoare corespunzatoare.
- Destructor ( default, intrucat nu alocam dinamic nimic in aceasta clasa);
- Operatorii de citire si afisare si operatorul= ( supraincarcati):
  In cadrul operatorului de citire, din nou se pune accentul pe datele ce diferentiaza clasa Mica de celelalte tipuri. AStfel, la folosirea operatorului de citire utilizatorul nu poate introduce lungimi, ampatament sau an de fabricatie necorespunzatori.
   
  Operatorul de afisare ruleaza pe baza unor linii de cod care implica **upcasting**.
  
- Metoda virtuala de citire, respectiv de afisare a unei masini. Acestea sunt rescrise aici si permit parcurgerea unui array de obiecte de tip Mica si afisarea sau citirea acestora.

-------------------------------------------------------

##### P1.3) Clasa Compacta: clasa derivata din Masini:
Compacta este al treilea tip de autovehicul mentionat in problema.
Acest tip de autovehicul vine cu si mai multe variabile specifice doar lui.
A fost creata o clasa separata pentru aces tip deoarece contine variabile specifice (sau cu valori specifice doar acestui tip) precum :
- anul: Prin conventie, in aceasta structura de clase , o masina este considerata fie noua daca anul favbricatiei nu depaseste cu 1 anul curent ( nu e mai veche de un an), fie SH in caz contrar.
- lungimea: In cazul unei masini tip Compacta, lungimea este specifica ( minim 4.2 si maxim 4.5)
- forma masinii: aceasta poate fi combi, sedan sau hatchback

Clasa dispune si de o serie de metode :
- functiile set_ ( protected), get_ ( publice, dar const) specifice oricarei clase;
- Constructorii ( cu parametru, fara parametru, de copiere) care construiesc obiectul
- Destructor ( asemanator unuia defaul, doar ca am ales sa curatam automat stringurile);
- Operatorii de citire si afisare si operatorul= ( supraincarcati):
  In cadrul operatorului de citire, din nou se pune accentul pe datele ce diferentiaza clasa Compacta de celelalte tipuri. Astfel, la folosirea operatorului de citire, utilizatorul nu poate introduce lungimi, forme sau an de fabricatie necorespunzatori.
   
  Operatorul de afisare ruleaza pe baza unor linii de cod care implica **upcasting**.
  
- Metoda virtuala de citire, respectiv de afisare a unei masini. Acestea sunt rescrise aici si permit parcurgerea unui array de obiecte de tip Compacta si afisarea sau citirea acestora.

-------------------------------------------------------

##### P1.4) Clasa Monovolum: clasa derivata din Masini:
Monovolum este al treilea tip de autovehicul mentionat in problema.
Acest tip de autovehicul vine cu inca o variabila / caracteristica specifica doar ei ( nr maxim de locuri), iar in schimb nu este mentionat nimic despre lungime + anul de fabricatie poate fii si unul mai vechi.
Clasa Monovolum este tratata separat , printr-o specializare.
De semenea , monovolumele au doar forma ' van', astfel ca am setat aceasta forma inca de la inceputul clasei, fiind const.
A fost creata o clasa separata pentru aces tip deoarece contine variabile specifice (sau cu valori specifice doar acestui tip) precum :
- anul: Prin conventie, in aceasta structura de clase , o masina este considerata fie noua daca anul favbricatiei nu depaseste cu 1 anul curent ( nu e mai veche de un an), fie SH in caz contrar.
- nr_locuri: Numarul masim de locuri al unui monovolum sunt intre 5 si 7.
- forma masinii: aceasta este setata automat la 'van' pentru masinile tip Monovolum

Clasa dispune si de o serie de metode :
- functiile set_ ( protected), get_ ( publice, dar const) specifice oricarei clase;
- Constructorii ( cu parametru, fara parametru, de copiere) care construiesc obiectul
- Destructor ( default, intrucat nu alocam dinamic nimic in aceasta clasa);
- Operatorii de citire si afisare si operatorul= ( supraincarcati):
  In cadrul operatorului de citire, din nou se pune accentul pe datele ce diferentiaza clasa Compacta de celelalte tipuri. Astfel, la folosirea operatorului de citire, utilizatorul nu poate introduce nr de locuri, forme sau an de fabricatie necorespunzatori.
   
  Operatorul de afisare ruleaza pe baza unor linii de cod care implica **upcasting**
  
- Metoda virtuala de citire, respectiv de afisare a unei masini. Acestea sunt rescrise aici si permit parcurgerea unui array de obiecte de tip Monovolum si afisarea sau citirea acestora.

-------------------------------------------------------

#### P2) Clasa template Vanzare: se afla in compunere cu clasa masini

In cele din urma ajungem la clasa specificata in enuntul problemei: clasa `Vanzare`;

Prin intermediul acestei clase se gestioneaza numarul de masini vandute si din stock, care au fost cele vandute si care sunt pe stock in momentul actual.
 ##### Enuntul problemei cerea ca aceasta clasa sa vina la pachet cu 2 structuri de date alocate dinamic, folosite la gestiune. Structurile alese au fost array-uri de pointeri de tipul `masini` alocate dinamic, ci anume `stock[]` si `vandute[]`;
 Alaturi de aceste doua structuri , apar si 2 valori intregi reprezentand un contor al numarului de elemente la fiecarui array.
 
 Metodele de baza ale unei clase sunt prezente si aici, alaturi si de alte metode speciale:
 - functiile set_ ( protected) care definesc marimea array urilor si le initializeaza
 - functiile get_ (publice, dar const) care afiseaza anumite valori;
 - functiile afis_stock si istoric_vanzari, de tip const, care parcurg cele 2 array uri si afiseaza element cu element continutul acestora.
 -
 - Funcita **vinde** este o functie importanta a clasei deoarece prin ea se creeaza si se actualizeaza array-ul vandute (care se ocupa de masinile vandute). Arrayul vandute nu este creat si populat cu elemente in construcotri , odata cu celalalt array ( stock[]) intrucat la inceput parcul are stockul complet. In timp, insa, masinile se vand iar array ul `vandute` se populeaza ( invers proportional, stock[] scade);
 Atunci cand este apelata functia Vinde(), se va vinde un automobil din tipul celui transmis (Ex: daca in parc sunt 3 Compacte si dorim sa vindem o compacta, se alege una din cele trei, se muta in vandute[], se scoate din stoc[] iar in parc vor mai ramane doar 2 masini tip Compacta).
 Pentru a actualiza stock[] si vandute[] este necesara copierea in alte 2 array-uri temporare. Copierea se face cu ajutorul altei functii, copiere_masina, care are grija de modul in care sunt copiate elementele intrucat se lucreaza cu pointeri.
- Functia friend **copiere_masina** este alta functie care joaca un rol important. Functia primeste ca parametrii 2 pointeri de tip masini, si are ca scop copierea in obiectul catre care pointeaza primul pointer a obiectului catre care pointeaza al doilea pointer. Ca sa faca acest lucru fara sa incurce adresele, obiectul unde se vrea sa se copieze este recreat dupa obiectul care se vrea sa se copieze ( prin apel explicit de copy constructor).
Tot aici se observa si conceptul de **downcasting**, intrucat printr-un pointer de tip `masina` se apeleaza o metoda specifica uneia dintre clasele sale derivate, folosind **static_cast**.
Obiectul recreat aici a fost inainte null sau neinitializat intrucat aceasta functie se apeleaza doar asupra obiectelor temporare.
 - Constructorul cu parametrii este folosit pentru citirea obiectelor din stock[]. Aici este evidentiat si un concept de throw - > catch , care testeaza tipurile de masini introduse.
 - Operatorul -= a fost suprascris pentru a vinde masini din parc, a scadea numarul masinilor din stock si a creste numarul masinilor vandute. Ex: daca pentru un obiect tip Vanzare vom scrie o1-=2, atunci se intelege ca din parcul auto se vrea sa se stearga 2 tipuri de masini care urmeaza sa fie specificate.
 - Functia `make_this_set` : Aceasta functie se ocupa in deosebi de structura de date precizata in enunt ( un set de perechi). Intrucat in enunt nu specifica clar nde sa fie creata aceasta structura, de ce sa fie creata si cu ce scop, am ales sa creez o funcite separata in clasa Vanzare care sa se ocupe de acest set.
 - Operatrul de citire se foloseste in mare de construcotri.
 - Operatorul de afisare afiseaza atat arrayul de masini de pe stock cat si arrayul de masini vandute pana acum.
 
 -------------------------------------------------------

#### P3) Specializarea clasei Vanzare pentru Monovolume: 
Intrucat clasa Vanzare este clasa template si in Vanzare exista pointeri spre obiecte tip `masini`, am reusit sa creem o specializare pentru `Monovolum`, clasa derivata din clasa masini;
Functiile si metodele se aseamana in proportii de 90% ce cele din clasa template Vanzare, singura diferenta fiind faptul ca aici se abordeaza doar array uri de obiecte de tipul Monovolum.

Cateva diferenta apar la functia **vinde**. Nu mai este nevoie de o functie ajutatoare ( copiere_masini) intrucat aici lucram cu obiectul masini in sine si deci putem folosi operatorul sau =. 
Tot aici reapare conceptul de **downcasting** prin care se apeleaza prin obiectul de tip masini o metode specifica derivatelor.

# INPUT & OUTPUT din meniu:

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
 
***************************************************************************************************
 Introduceti optiunea si apasati tasta enter: 1

Cate masini de diverse tipuri doriti sa aveti?
2

Introduceti tipul autovehiculului (Compacta / Mini / Mica ):
Mica
Se vor introduce datele masinii:

Introduceti numele masinii: ford fiesta

Introduceti pretul masinii: -1

Pretul unei masini nu poate fi negativ sau 0 (nu se dau masini pe gratis).

Introduceti din nou pretul:
ssffft

 !Se pare ca nu ati introdus o valoare numerica valida.
 
 Programul va genera un pret aleatoriu.
 
Introduceti capacitatea cilindrica / litrajul masinii: sttrr

 !Se pare ca nu ati introdus o valoare numerica valida.
 
 Programul va genera un litraj aleatoriu.
 
Introduceti lungimea masinii (min 3.85 , max 4.1): 3

Ati introdus dimensiuni necorespunzatoare acestui tip de masina

Lungimea unei masini Mica este de maxim 4.1m si minim 3.85m. Introduceti din nou lungimea:
4

Introduceti ampatamentul masinii (spatiu interior) : 6

La o masina MICA, ampatamentul nu poate fi negativa sau mai mare decat intreaga masina

Introduceti din nou dimensiunile ampatamentului:
f

 !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat un ampatament acceptabil.
 
Introduceti anul de fabricatie al masinii: 2020


Introduceti tipul autovehiculului (Compacta / Mini / Mica ):

Compacta

Se vor introduce datele masinii:

Introduceti numele masinii: audi

Introduceti pretul masinii: 12000

Introduceti capacitatea cilindrica / litrajul masinii: -1

Litrajul unei masini nu poate fi negativ sau 0 (masinia nu merge pe aer).

Introduceti din nou litrajul:
2200

Introduceti forma masinii (sedan / combi / hatchback): sec

Ati introdus o forma invalida a masinii Compact!

O masina Compacta se vinde sub formele: combi, hatchback, sedan.

Verificati majusculele si introduceti din nou forma masinii:

sedan

Introduceti lungimea masinii ( minim 4.2 , maxim 4.5): 4.4

Introduceti anul de fabricatie al masinii: 2001

Ati introdus un an necorespunzator acestui tip de masina

Aceasta masina nu poate fi mai veche de 1 an. Introduceti din nou anul:

2020
***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 5

Cate masini tip diverse doriti sa vindeti?

1

Se doreste a se vinde 1 masini de tipuri diverse.

Introduceti tipul masinii 1 mai jos (Compacta / Mini / Mica):

mini

Acest tip de masina nu exista -> nu poate fi vandut

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 5

Cate masini tip diverse doriti sa vindeti?

1

Se doreste a se vinde 1 masini de tipuri diverse.

Introduceti tipul masinii 1 mai jos (Compacta / Mini / Mica):

Mica


 Tranzactie efectuata cu succes!

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 2
 
Numarul de masini de tipuri diverse de pe stock este:

1

La momentul actual in parcul auto se afla urmatoarele masini de tipuri diverse:


Tip masina:

Compacta

Denumirea masinii:

audi

Pretul achizitionarii:

12000 EURO

Litrajul:

2200

Lungimea

4.4

Forma masinii:

sedan

Anul:

2020


Numarul de masini de tipuri diverse vandute este:

1


In total, s-au vandut urmatoarele masini de tipuri diverse:


Tip masina:

Mica

Denumirea masinii:

ford fiesta

Pretul achizitionarii:

541 EURO

Litrajul:

1467

Lungimea

4

Ampatamentul:

3

Anul:

2020


***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 3

Cate masini tip Monovolum doriti sa aveti?

3

Introduceti datele unui Monovolum:

Se vor introduce datele masinii:

Introduceti numele masinii: honda

Introduceti pretul masinii: 12200

Introduceti capacitatea cilindrica / litrajul masinii: string

 !Se pare ca nu ati introdus o valoare numerica valida.
 
 Programul va genera un litraj aleatoriu.
 
Introduceti numarul maxim de locuri al masinii (min 5, max 7): 5

Introduceti anul de fabricatie al masinii: 2018


Introduceti datele unui Monovolum:

Se vor introduce datele masinii:

Introduceti numele masinii: skoda

Introduceti pretul masinii: 3200

Introduceti capacitatea cilindrica / litrajul masinii: 1900

Introduceti numarul maxim de locuri al masinii (min 5, max 7): 4

Numar de locuri necorespunzator!

O masina Monovolum are intre 5 si 7 locuri. Introduceti din nou lungimea:

6

Introduceti anul de fabricatie al masinii: -2

Oops! Se pare ca masina nu a fost fabricata inca. Incercati din nou anul:

2001

Introduceti datele unui Monovolum:

Se vor introduce datele masinii:

Introduceti numele masinii: bmw

Introduceti pretul masinii: 22000

Introduceti capacitatea cilindrica / litrajul masinii: 2300


Introduceti numarul maxim de locuri al masinii (min 5, max 7): 5
Introduceti anul de fabricatie al masinii: 2020

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 4
 
Numarul de masini tip Monovolum de pe stock este:

3

La momentul actual in parcul auto se afla urmatoarele masini tip Monovolum:


Tip masina:

Monovolum

Denumirea masinii:

honda

Pretul achizitionarii:

12200 EURO

Litrajul:

1334

Nr de locuri al masinii:

5

Forma masinii:

van

Anul:

2018


Tip masina:

Monovolum

Denumirea masinii:

skoda

Pretul achizitionarii:

3200 EURO

Litrajul:

1900

Nr de locuri al masinii:

6

Forma masinii:

van

Anul:

2001


Tip masina:

Monovolum

Denumirea masinii:

bmw

Pretul achizitionarii:

22000 EURO

Litrajul:
2300

Nr de locuri al masinii:

5


Forma masinii:

van

Anul:

2020


Numarul de masini tip Monovolum vandute este:

0


In total, s-au vandut urmatoarele masini tip Monovolum:

Nu s-a vandut nimic!


***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 6
 

Cate masini tip Monovolum doriti sa vindeti?

2

Se doreste a se vinde 2 masini de tip Monovolum.


 Tranzactie efectuata cu succes!


 Tranzactie efectuata cu succes!

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 4
 
Numarul de masini tip Monovolum de pe stock este:

1

La momentul actual in parcul auto se afla urmatoarele masini tip Monovolum:


Tip masina:

Monovolum

Denumirea masinii:

bmw

Pretul achizitionarii:

22000 EURO

Litrajul:

2300

Nr de locuri al masinii:

5

Forma masinii:

van

Anul:

2020


Numarul de masini tip Monovolum vandute este:

2


In total, s-au vandut urmatoarele masini tip Monovolum:



Tip masina:

Monovolum

Denumirea masinii:

honda

Pretul achizitionarii:

11834 EURO

Litrajul:

1334

Nr de locuri al masinii:

5

Forma masinii:

van

Anul:

2018


Tip masina:

Monovolum

Denumirea masinii:

skoda

Pretul achizitionarii:

2560 EURO

Litrajul:

1900

Nr de locuri al masinii:

6

Forma masinii:

van

Anul:

2001


***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 7
 
_________________________________________________
Setul cu masini de tipuri diverse din stock este:

Tip masina:
Compacta

Denumirea masinii:
audi

Pretul achizitionarii:
12000 EURO

Litrajul:
2200

Lungimea 
4.4

Forma masinii:
sedan

Anul:
2020

Autovehicul Nou

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 8
 
_____________________________________________

Setul cu masini tip Monovolum din stock este:

Tip masina:
Monovolum

Denumirea masinii:
bmw

Pretul achizitionarii:
22000 EURO

Litrajul:
2300

Nr de locuri al masinii:
5

Forma masinii:
van

Anul:
2020

Autovehicul Nou

***************************************************************************************************
 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).
 
 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.
 
 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).
 
 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.
 
 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica.
 
 6 - Vindeti una sau mai multe masini tip Monovolum.
 
 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.
 
 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.
 
 9 - END.
***************************************************************************************************

 Introduceti optiunea si apasati tasta enter: 9
Sfarsitul programului!







