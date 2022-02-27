Dintr-un parc auto se poate cumpăra o gamă variatăde automobile de următoareletipuri: 
- MINI (mașină de oraș, de mic litraj, de obiceisub 4m lungime), 
- MICA (mașină de oraș, cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1), 
- COMPACTA(mașină ușor de folosit, atât în oraș, cât și la drumlung, de dimensiune 4.2 – 4.5m;acest tip de mașini are formă de hatchback, combisau sedan),
- MONOVOLUME(automobile sub formă de van, ce pot transporta 5-7persoane). 

<br/>

Monovolumele pot fiachiziționate atât noi cât și second hand. La celeachiziționate second hand, se percepeun discount proporțional cu numărul de ani vechimeai mașinii.
<br/>
Pentru toate automobilele, în lunile de vară, se beneficiazăde zile promoționale cureducere fixă de 10% din preț. 
<br/>
Structura de date: set<pair<tip_automobil, bool nou>>(nou = false pentru cele sh)
<br/>
Să se construiască clasa template Vanzare care saconțină:
- numărul total de mașiniaflate pe stoc (decrementat automat la vânzarea uneimașini), 
- numărul de mașinivândute (incrementat automat)
- două structuri deobiecte, alocate dinamic, prin caresă se gestioneze automobilele din stoc și cele vândute.
<br/>
Să se supraîncarce operatorul-= care să actualizeze datele din clasă la vanzareaunei mașini.Să se adauge toate câmpurile relevante pentru modelareaacestei probleme.
<br/>
Cerința suplimentară:- Să se construiască o specializare pentru tipul MONOVOLUMcare sa conțină și săafișeze/gestioneze doar MONOVOLUMELE
