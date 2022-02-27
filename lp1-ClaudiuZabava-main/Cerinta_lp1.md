Mulțimi finite de numere întregi construite prin transformarea unui vector în mulțime, prin eliminarea duplicatelor din respectivul vector;
<br/>
Are drept parametrii:
- Cardinalul mulțimii (int)
- Elementele prezente în mulțime
<br/>
Metode ce se doresc a fi implementate:
- determinarea celui de-al treilea cel mai mic element prezent în mulțime
- reuniunea a două mulțimi; 
- intersecția a două mulțimi; 
- diferența dintre două mulțimi
<br/>
Bonus:
<br/>
Pentru a putea obține bonusul aș dori să introduci un atribut suplimentar în clasa ta și anume n (intreg pozitiv) astfel incat functionalitatea clasei tale sa se transforme.
<br/>
Astfel, daca pana acum ai implementat o clasa ce descrie multimi finite de numere intregi (care contine numere ce apartin lui Z), acum clasa ta va implementa mulțimi de tip Zn (adică mulțimea claselor de resturi modulo n). 
<br/>
Se considera ca n va fi citit de la tastatura. Vectorul din care tu construiai multimea pana acum putea avea orice fel de elemente numere intregi, astfel incat va trebui sa le transformi pe fiecare in asa fel incat ele sa apartina lui Zn. O sa vreau sa consideri ca operatiile de reuniune, intersectie si diferenta vor avea sens doar intre 2 multimi care au aceeasi valoare pentru n (verifici eventual fie printr-un if in main inainte de apelul functiei respective, fie eventual chiar in cadrul functiei aferente reuniunii/intersectiei/diferentei).

Propriu-zis in acest context, vei avea de implementat pentru bonus suprascrierea ”operatorului +=” în cadrul clasei modificate ca mai sus. 
<br/>
Funcționalitatea operației ”+=” în acest context va fi aceea de a putea obține suma elementelor celor 2 mulțimi și a stoca rezultatul în prima dintre ele. Considera ca faci suma pe perechi adica: suma elementului de pe pozitia 0 din multimea A cu elementul 0 din multimea B, suma elementului de pe pozitia 1 din multimea A cu elementul de pe pozitia 1 din B și așa mai departe. Dacă cele 2 mulțimi nu au același cardinal, afiseaza un mesaj de avertizare (nu ai voie sa verifici tu explicit acest lucru inainte de a decide daca faci sau nu operatia, ci va trebui sa incluzi aceasta conditie in logica operatorului).
