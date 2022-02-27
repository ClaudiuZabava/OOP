#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

class masini{

protected:
    double pret;
    int litraj;
    string denumire;
    string tip;

    void set_pret(double x);
    void set_litraj(int x);
    void set_denumire(char  y[10001]);
    void set_denumire_null();
    void set_tip_masina(char y[10001]);
    void set_tip_necunoscut();

public:

    static int prezent;
    static int luna;

    masini()
    {
        set_pret(0);
        set_litraj(0);
        set_denumire_null();
        set_tip_necunoscut();
    }


    masini(double p, int l, char nume[10001])
    {
        try
        {
            if(p<=0)
                throw " !Pretul introdus este negativ sau 0 (nu vindem masini gratis)";
            else
                set_pret(p);
        }
        catch(const char *e2)
        {
            cout << e2 << '\n';
            cout << " Programul va genera un pert aleatoriu" << '\n';
            p=rand() % 900000 + 500;
            set_pret(p);
        }


        try
        {
            if(l<=0)
                throw " !Litrajul introdus este negativ sau 0 (masinile nu merg pe aer).";
            else
                set_litraj(l);
        }
        catch(const char *e2)
        {
            cout << e2 << '\n';
            cout << " Programul va genera un litraj aleatoriu" << '\n';
            l=rand() % 6000 + 1000;
            set_litraj(l);
        }


        set_denumire(nume);
        set_tip_necunoscut();
    }


    masini(const masini &p1)
    {
        char temp[10001];
        strcpy(temp, p1.get_denumire().c_str());

        set_pret(p1.get_pret());
        set_litraj(p1.get_litraj());
        set_denumire(temp);
        set_tip_necunoscut();


    }

    masini &operator=(const masini &p1)
    {
        char temp[10001];

        if( &p1 != this)
        {
            if(denumire !="")
                denumire.clear();
            strcpy(temp,p1.get_denumire().c_str());

            set_pret(p1.get_pret());
            set_litraj(p1.get_litraj());
            set_denumire(temp);
            set_tip_necunoscut();


        }

        return *this;

    }

    double get_pret() const;

    int get_litraj() const;

    string get_denumire() const;
    string get_tip() const;

    void aplica_reducere1();
    void aplica_reducere2(double rd);


    virtual void afis_masina()
    {
        cout << "undefined car type: trebuie sa apelati aceasta functie asupra unui tip de masina" << '\n';
    }

    virtual void citire_masina()
    {
        cout << "undefined car type: trebuie sa apelati aceasta functie asupra unui tip de masina" << '\n';
    }


    friend istream &operator>>(istream &in, masini &p1)
    {
        char ch[10001];
        double pr;
        int l;


        cout << "Introduceti numele masinii: ";
        in.getline(ch,10001);

        cout << "Introduceti pretul masinii: ";
        try
        {
            in >> pr;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida." ;
        }
        catch(const char *e2)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e2 << '\n';
            cout << " Programul va genera un pret aleatoriu." << '\n';
            pr=rand() % 100000 + 500;
        }
        while (pr <=0)
        {
            cout << "Pretul unei masini nu poate fi negativ sau 0 (nu se dau masini pe gratis)." << '\n';
            cout << "Introduceti din nou pretul:" << '\n';
            try
            {
                in >> pr;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida." ;
            }
            catch(const char *e2)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e2 << '\n';
                cout << " Programul va genera un pret aleatoriu." << '\n';
                pr=rand() % 100000 + 500;
            }

        }


        cout << "Introduceti capacitatea cilindrica / litrajul masinii: ";
        try
        {
            in >> l;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida." ;
        }
        catch(const char *e2)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e2 << '\n';
            cout << " Programul va genera un litraj aleatoriu." << '\n';
            l=rand() % 6000 + 1000;
        }
        while( l<=0 )
        {
            cout << "Litrajul unei masini nu poate fi negativ sau 0 (masinia nu merge pe aer)." << '\n';
            cout << "Introduceti din nou litrajul:" << '\n';
            try
            {
                in >> l;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida." ;
            }
            catch(const char *e2)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e2 << '\n';
                cout << " Programul va genera un litraj aleatoriu." << '\n';
                l=rand() % 6000 + 1000;
            }
        }

        p1.set_pret(pr);
        p1.set_litraj(l);
        p1.set_denumire(ch);
        p1.set_tip_necunoscut();

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const masini &p1)
    {
        out << '\n';
        out << "Denumirea masinii:" << '\n';
        out << p1.get_denumire() << '\n';
        out << '\n';
        out << "Pretul achizitionarii:" << '\n'; /// Dupa vanzare, pretul achizitionarii se poate schimba intrucat se aplica reducerile din enunt.
        out << p1.get_pret() << " EURO" << '\n';
        out << '\n';
        out << "Litrajul:" << '\n';
        out << p1.get_litraj() << '\n';
        out << '\n';


        return out;
    }


/// De ce e destructorul masini virtual?
/*
Mult mai jos, in clasa Vanzare, avem 2 array-uri de pointeri tip 'masini'. In destructorul de acolo, se sterg aceste array-ui.
Conform teoriei, ca sa facem asta trebuie sa stergem vectorul de adrese , dar si continutul de la fiecare adresa.
Astfel, cum indica si compilatorul printr-un warning, a fost nevoie de un destructor virtual al clasei masini.
*/

    virtual ~masini()
    {
        if(denumire != "")
            denumire.clear();
        if(tip != "")
            tip.clear();
        pret=0;
        litraj=0;
    }

};


void masini::set_pret(double x)
{
    pret = x;
}
void masini::set_litraj(int x)
{
    litraj = x;
}
void masini::set_denumire(char  y[10001])
{
    denumire = y;
}
void masini::set_denumire_null()
{
    denumire = "";
}
void masini::set_tip_masina(char y[10001])
{
    if(tip != "")
        tip.clear();
    tip = y;
}
void masini::set_tip_necunoscut()
{
    if(tip!="")
        tip.clear();
    tip = "undefined";
}


double masini::get_pret() const
{
    return pret;
}
int masini::get_litraj() const
{
    return litraj;
}
string masini::get_denumire() const
{
    return denumire;
}
string masini::get_tip() const
{
    return tip;
}


void masini::aplica_reducere1()
{
    double pret_t;
    pret_t=get_pret() - get_pret() * 0.1;
    set_pret(pret_t);
}
void masini::aplica_reducere2(double rd)
{
    double pret_t = get_pret() - get_pret() * (rd/100 );
    set_pret(pret_t);

}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Mini: public masini{

protected:

    double lungime;
    int an;

    void set_lungime(double x);
    void set_an(int x);

public:

    Mini():masini()
    {
        char temp[10001]="Mini";
        set_lungime(0);
        set_an(0);
        set_tip_masina(temp);
    }


    Mini(double p, int l, char nume[10001], double lg, int anul):masini(p,l,nume)
    {
        char temp[10001]="Mini";


        try
        {
            if(lg > 4 || lg < 1)
                throw " !Lungimea introdusa nu apartine intervalului [1,4]";
            else
                set_lungime(lg);
        }
        catch(const char *e3)
        {
            cout << e3 << '\n';
            cout << " Programul va seta lungimea ca fiind cel ami apropiat capat al intervalului." << '\n';
            if(lg>4)
                lg=4;
            else
                lg=1;
            set_lungime(lg);
        }


        try
        {
            if(prezent-anul > 1 || anul > prezent)
                throw " !Ati introdus un an prea vechi sau inexistent pentru o masina tip Mini.";
            else
                set_an(anul);
        }
        catch(const char *e3)
        {
            cout << e3 << '\n';
            cout << " Programul va seta anul masinii ca fiind anul curent." << '\n';
            set_an(prezent);
        }

        set_tip_masina(temp);
    }


    Mini(const Mini &p2):masini(p2)
    {
        char temp[10001];
        strcpy(temp, p2.get_tip().c_str());

        set_lungime(p2.get_lungime());
        set_an(p2.get_anul());
        set_tip_masina(temp);

    }

    Mini &operator=(const Mini &p2)
    {
        char temp[10001];

        if( &p2 != this)
        {
            masini::operator=(p2);

            set_lungime(p2.get_lungime());
            set_an(p2.get_anul());

            if(tip != "")
                tip.clear();
            strcpy(temp, p2.get_tip().c_str());

            set_tip_masina(temp);

        }

        return *this;

    }

    double get_lungime() const;

    int get_anul() const;

    void afis_masina();
    void citire_masina();


    friend istream &operator>>(istream &in, Mini &p2)
    {
        double lg;
        int anul;
        char temp[10001]="Mini";


        cout << "Se vor introduce datele masinii: "<< '\n';

        in >> (masini&) p2;


        cout << "Introduceti lungimea masinii ( minim 1 , maxim 4): ";
        try
        {
            in >> lg;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
        }
        catch(const char *e3)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e3 << '\n';
            lg=3;
        }
        while (lg > 4 || lg < 1 )
        {
            cout << "Ati introdus dimensiuni necorespunzatoare acestui tip de masina" << '\n';
            cout << "Lungimea unei masini Mini este de maxim 4m si minim 1m. Introduceti din nou lungimea:" << '\n';
            try
            {
                in >> lg;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
            }
            catch(const char *e3)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e3 << '\n';
                lg=3;
            }
        }


        cout << "Introduceti anul de fabricatie al masinii: ";
        try
        {
            in >> anul;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
        }
        catch(const char *e3)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e3 << '\n';
            anul= prezent;
        }
        while(prezent-anul >1 || anul > prezent) // in general, o masina recent fabricata este cumparata in timp de 1 an. Daca diferenta de data este mai mare de 1 ani -> masina e SH , ceeea ce corespunde acestui tip.
        {
            cout << "Ati introdus un an necorespunzator acestui tip de masina" << '\n';
            cout << "Aceasta masina nu poate fi mai veche de 1 an. Introduceti din nou anul: " << '\n';
            try
            {
                in >> anul;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
            }
            catch(const char *e3)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e3 << '\n';
                anul= prezent;
            }
        }

        p2.set_lungime(lg);
        p2.set_an(anul);
        p2.set_tip_masina(temp);

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const Mini &p2)
    {
        out << "Tip masina: " << '\n';
        out << p2.get_tip();
        out << '\n';

        out << (masini&) p2;

        out << "Lungimea" << '\n';
        out << p2.get_lungime() << '\n';
        out << '\n';
        out << "Anul:" << '\n';
        out << p2.get_anul() << '\n';
        out << '\n';


        return out;
    }

    ~Mini() = default;

};


void Mini::set_lungime(double x)
{
   lungime = x;
}
void Mini::set_an(int x)
{
   an = x;
}


double Mini::get_lungime() const
{
    return lungime;
}

int Mini::get_anul() const
{
    return an;
}

void Mini::afis_masina()
{
    cout << *this;
}

void Mini::citire_masina()
{
    cin >> *this;
}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Mica: public masini{

protected:

    double lungime;
    int an;
    double ampatament; // Conform cerintei, la o masina Mica apare ca variabila specifica spatiul interior / ampatamentul.

    void set_lungime(double x);
    void set_an(int x);
    void set_ampatament(double x);

public:

    Mica():masini()
    {
        char temp[10001]="Mica";
        set_lungime(0);
        set_an(0);
        set_ampatament(0);
        set_tip_masina(temp);
    }


    Mica(double p, int l, char nume[10001], double lg, double amp, int anul):masini(p,l,nume)
    {
        char temp[10001]="Mica";

        try
        {
            if(lg > 4.1 || lg < 3.85)
                throw " !Lungimea introdusa nu apartine intervalului [3.85 , 4.1]";
            else
                set_lungime(lg);
        }
        catch(const char *e4)
        {
            cout << e4 << '\n';
            cout << " Programul va seta lungimea ca fiind cel ami apropiat capat al intervalului." << '\n';
            if(lg>4.1)
                lg=4.1;
            else
                lg=3.85;
            set_lungime(lg);
        }


        try
        {
            if(prezent-anul > 1 || anul > prezent)
                throw " !Ati introdus un an prea vechi sau inexistent pentru o masina tip Mica.";
            else
                set_an(anul);
        }
        catch(const char *e4)
        {
            cout << e4 << '\n';
            cout << " Programul va seta anul masinii ca fiind anul curent." << '\n';
            set_an(prezent);
        }


        try
        {
            if((amp >= get_lungime() && get_lungime() != 0 ) || amp <=0)
                throw " !Ampatamentul introdus este negativ / nul / mai mare decat lungimea masinii.";
            else
                set_ampatament(amp);
        }
        catch(const char *e4)
        {
            cout << e4 << '\n';
            cout << " Programul va seta automat un ampatament acceptabil" << '\n';
            if(get_lungime()>=3.85)
                amp=get_lungime()-1;
            else
                amp=0;
            set_ampatament(amp);
        }


        set_tip_masina(temp);
    }


    Mica(const Mica &p3):masini(p3)
    {
        char temp[10001];
        strcpy(temp, p3.get_tip().c_str());

        set_lungime(p3.get_lungime());
        set_an(p3.get_anul());
        set_ampatament(p3.get_ampatament());
        set_tip_masina(temp);

    }

    Mica &operator=(const Mica &p3)
    {
        char temp[10001];

        if( &p3 != this)
        {
            masini::operator=(p3);

            set_lungime(p3.get_lungime());
            set_an(p3.get_anul());
            set_ampatament(p3.get_ampatament());

            if(tip != "")
                tip.clear();
            strcpy(temp, p3.get_tip().c_str());

            set_tip_masina(temp);

        }

        return *this;

    }

    double get_lungime() const;
    double get_ampatament() const;

    int get_anul() const;

    void afis_masina();
    void citire_masina();


    friend istream &operator>>(istream &in, Mica &p3)
    {
        double lg;
        double amp;
        int anul;
        char temp[10001]="Mica";


        cout << "Se vor introduce datele masinii: "<< '\n';

        in >> (masini&) p3;


        cout << "Introduceti lungimea masinii (min 3.85 , max 4.1): ";
        try
        {
            in >> lg;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
        }
        catch(const char *e4)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e4 << '\n';
            lg= 4;
        }
        while (lg > 4.1 || lg < 3.85 )
        {
            cout << "Ati introdus dimensiuni necorespunzatoare acestui tip de masina" << '\n';
            cout << "Lungimea unei masini Mica este de maxim 4.1m si minim 3.85m. Introduceti din nou lungimea:" << '\n';
            try
            {
                in >> lg;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
            }
            catch(const char *e4)
            {
                in.clear();
                string dummy;
                in >> dummy;
                cout << e4 << '\n';
                lg= 4;
            }
        }


        cout << "Introduceti ampatamentul masinii (spatiu interior) : ";
        try
        {
            in >> amp;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat un ampatament acceptabil." ;
        }
        catch(const char *e4)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e4 << '\n';
            amp=lg-1;
        }
        while (amp <=0 || amp >=lg)
        {
            cout << "La o masina MICA, ampatamentul nu poate fi negativa sau mai mare decat intreaga masina" << '\n';
            cout << "Introduceti din nou dimensiunile ampatamentului: " << '\n';
            try
            {
                in >> amp;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat un ampatament acceptabil." ;
            }
            catch(const char *e4)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e4 << '\n';
                amp=lg-1;
            }
        }

        cout << "Introduceti anul de fabricatie al masinii: ";
        try
        {
            in >> anul;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
        }
        catch(const char *e4)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e4 << '\n';
            anul= prezent;
        }
        while(prezent-anul >1 || anul > prezent)
        {
            cout << "Ati introdus un an necorespunzator acestui tip de masina" << '\n';
            cout << "Aceasta masina nu poate fi mai veche de 1 an. Introduceti din nou anul: " << '\n';
            try
            {
                in >> anul;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
            }
            catch(const char *e4)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e4 << '\n';
                anul= prezent;
            }
        }

        p3.set_lungime(lg);
        p3.set_an(anul);
        p3.set_ampatament(amp);
        p3.set_tip_masina(temp);

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const Mica &p3)
    {
        out << "Tip masina: " << '\n';
        out << p3.get_tip();
        out << '\n';

        out << (masini&) p3;

        out << "Lungimea" << '\n';
        out << p3.get_lungime() << '\n';
        out << '\n';
        out << "Ampatamentul:" << '\n';
        out << p3.get_ampatament() << '\n';
        out << '\n';
        out << "Anul:" << '\n';
        out << p3.get_anul() << '\n';
        out << '\n';


        return out;
    }

    ~Mica() = default;

};


void Mica::set_lungime(double x)
{
    lungime = x;
}
void Mica::set_an(int x)
{
    an=x;
}
void Mica::set_ampatament(double x)
{
    ampatament = x;
}


double Mica::get_lungime() const
{
    return lungime;
}
double Mica::get_ampatament() const
{
    return ampatament;
}
int Mica::get_anul() const
{
    return an;
}

void Mica::afis_masina()
{
    cout << *this;
}

void Mica::citire_masina()
{
    cin >> *this;
}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Compacta: public masini{

protected:

    double lungime;
    int an;
    string forma;

    void set_lungime(double x);
    void set_an(int x);
    void set_forma(char y[10001]);
    void set_forma_null();

public:

    Compacta():masini()
    {
        char temp[10001]="Compacta";
        set_lungime(0);
        set_an(0);
        set_forma_null();
        set_tip_masina(temp);
    }


    Compacta(double p, int l, char nume[10001], double lg, char y[10001], int anul):masini(p,l,nume)
    {
        char temp[10001]="Compacta";


        try
        {
            if(lg > 4.5 || lg < 4.2)
                throw " !Lungimea introdusa nu apartine intervalului [4.2 , 4.5]";
            else
                set_lungime(lg);
        }
        catch(const char *e5)
        {
            cout << e5 << '\n';
            cout << " Programul va seta lungimea ca fiind cel ami apropiat capat al intervalului." << '\n';
            if(lg>4.5)
                lg=4.5;
            else
                lg=4.2;
            set_lungime(lg);
        }


        try
        {
            if(prezent-anul > 1 || anul > prezent)
                throw " !Ati introdus un an prea vechi sau inexistent pentru o masina tip Compacta.";
            else
                set_an(anul);
        }
        catch(const char *e5)
        {
            cout << e5 << '\n';
            cout << " Programul va seta anul masinii ca fiind anul curent." << '\n';
            set_an(prezent);
        }


        try
        {
            if(strcmp(y,"sedan")!=0 && strcmp(y,"combi")!=0 && strcmp(y,"hatchback")!=0)
                throw " !Forma introdusa nu este compatibila cu o masina tip Compacta";
            else
                set_forma(y);
        }
        catch(const char *e5)
        {
            int j;
            cout << e5 << '\n';
            cout << " Programul va seta o forma aleatorie" << '\n';
            j=rand() % 3 + 1;
            if(j==1)
                strcpy(y,"sedan");
            else
            if(j==2)
                strcpy(y,"combi");
            else
                strcpy(y,"hatchback");
            set_forma(y);
        }

        set_tip_masina(temp);
    }


    Compacta(const Compacta &p4):masini(p4)
    {
        char temp[10001];
        strcpy(temp, p4.get_forma().c_str());

        set_lungime(p4.get_lungime());
        set_an(p4.get_anul());
        set_forma(temp);

        strcpy(temp, p4.get_tip().c_str());

        set_tip_masina(temp);

    }

    Compacta &operator=(const Compacta &p4)
    {
        char temp[10001];

        if( &p4 != this)
        {
            masini::operator=(p4);

            if(forma !="")
                forma.clear();
            strcpy(temp,p4.get_forma().c_str());


            set_lungime(p4.get_lungime());
            set_an(p4.get_anul());
            set_forma(temp);

            if(tip !="")
                tip.clear();
            strcpy(temp,p4.get_tip().c_str());

            set_tip_masina(temp);

        }

        return *this;

    }

    double get_lungime() const;
    string get_forma() const;

    int get_anul() const;

    void afis_masina();
    void citire_masina();


    friend istream &operator>>(istream &in, Compacta &p4)
    {
        double lg;
        char ch[10001];
        char temp[10001]="Compacta";
        int anul;


        cout << "Se vor introduce datele masinii: "<< '\n';

        in >> (masini&) p4;

        cout << "Introduceti forma masinii (sedan / combi / hatchback): ";
        in.getline(ch,10001);
        while (strcmp(ch,"hatchback")!=0 && strcmp(ch,"combi")!=0 && strcmp(ch,"sedan")!=0)
        {
            cout << "Ati introdus o forma invalida a masinii Compact!" << '\n';
            cout << "O masina Compacta se vinde sub formele: combi, hatchback, sedan." << '\n';
            cout << "Verificati majusculele si introduceti din nou forma masinii:" << '\n';
            in.getline(ch,10001);
        }


        cout << "Introduceti lungimea masinii ( minim 4.2 , maxim 4.5): ";
        try
        {
            in >> lg;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
        }
        catch(const char *e5)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e5 << '\n';
            lg=4.4;
        }
        while (lg > 4.5 || lg < 4.2 )
        {
            cout << "Ati introdus dimensiuni necorespunzatoare acestui tip de masina" << '\n';
            cout << "Lungimea unei masini Mini este de maxim 4.5m si minim 4.2m. Introduceti din nou lungimea:" << '\n';
            try
            {
                in >> lg;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta automat o lungime acceptabila." ;
            }
            catch(const char *e5)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e5 << '\n';
                lg=4.4;
            }
        }


        cout << "Introduceti anul de fabricatie al masinii: ";
        try
        {
            in >> anul;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
        }
        catch(const char *e5)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e5 << '\n';
            anul= prezent;
        }
        while(prezent-anul >1 || anul > prezent)
        {
            cout << "Ati introdus un an necorespunzator acestui tip de masina" << '\n';
            cout << "Aceasta masina nu poate fi mai veche de 1 an. Introduceti din nou anul: " << '\n';
            try
            {
                in >> anul;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
            }
            catch(const char *e5)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e5 << '\n';
                anul= prezent;
            }
        }

        p4.set_lungime(lg);
        p4.set_an(anul);
        p4.set_forma(ch);
        p4.set_tip_masina(temp);

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const Compacta &p4)
    {
        out << "Tip masina: " << '\n';
        out << p4.get_tip();
        out << '\n';

        out << (masini&) p4;

        out << "Lungimea" << '\n';
        out << p4.get_lungime() << '\n';
        out << '\n';
        out << "Forma masinii:" << '\n';
        out << p4.get_forma() << '\n';
        out << '\n';
        out << "Anul:" << '\n';
        out << p4.get_anul() << '\n';
        out << '\n';


        return out;
    }

    ~Compacta()
    {
        if(forma != "")
            forma.clear();
        lungime=0;
        an=0;
    }

};


void Compacta::set_lungime(double x)
{
    lungime = x;
}
void Compacta::set_an(int x)
{
    an = x;
}
void Compacta::set_forma(char y[100001])
{
    forma = y;
}
void Compacta::set_forma_null()
{
    forma="";
}


double Compacta::get_lungime() const
{
    return lungime;
}
string Compacta::get_forma() const
{
    return forma;
}
int Compacta::get_anul() const
{
    return an;
}

void Compacta::afis_masina()
{
    cout << *this;
}

void Compacta::citire_masina()
{
    cin >> *this;
}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Monovolum: public masini{

protected:

    int nr_locuri;
    int an;
    const string forma="van";

    void set_locuri(int x);
    void set_an(int x);


public:

    Monovolum():masini()
    {
        char temp[10001]="Monovolum";
        set_locuri(0);
        set_an(0);
        set_tip_masina(temp);
    }


    Monovolum(double p, int l, char nume[10001], int lc, int anul):masini(p,l,nume)
    {
        char temp[10001]="Monovolum";


        try
        {
            if(lc > 7 || lc < 5)
                throw " !Numarul maxim de locuri introdus nu apartine intervalului [5 , 7]";
            else
                set_locuri(lc);
        }
        catch(const char *e6)
        {
            cout << e6 << '\n';
            cout << " Programul va seta aleatoriu numarul maxim de locuri" << '\n';
            lc=rand() % 7 + 5;
            set_locuri(lc);
        }


        try
        {
            if( anul > prezent || anul <=0)
                throw " !Ati introdus un an inexistent pentru o masina tip Monovolum.";
            else
                set_an(anul);
        }
        catch(const char *e6)
        {
            cout << e6 << '\n';
            cout << " Programul va seta anul masinii ca fiind anul curent." << '\n';
            set_an(prezent);
        }


        set_tip_masina(temp);
    }


    Monovolum(const Monovolum &p5):masini(p5)
    {
        char temp[10001];
        strcpy(temp, p5.get_tip().c_str());

        set_locuri(p5.get_locuri());
        set_an(p5.get_anul());
        set_tip_masina(temp);

    }

    Monovolum &operator=(const Monovolum &p5)
    {
        char temp[10001];

        if( &p5 != this)
        {
            masini::operator=(p5);

            set_locuri(p5.get_locuri());
            set_an(p5.get_anul());

            if(tip != "")
                tip.clear();
            strcpy(temp,p5.get_tip().c_str());

            set_tip_masina(temp);

        }

        return *this;

    }

    int get_locuri() const;
    string get_forma() const;

    int get_anul() const;

    void afis_masina();
    void citire_masina();


    friend istream &operator>>(istream &in, Monovolum &p5)
    {
        int lc;
        int anul;
        char temp[10001]="Monovolum";


        cout << "Se vor introduce datele masinii: "<< '\n';

        in >> (masini&) p5;


        cout << "Introduceti numarul maxim de locuri al masinii (min 5, max 7): ";
        try
        {
            in >> lc;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul maxim de locuri aleatoriu." ;
        }
        catch(const char *e6)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e6 << '\n';
            lc=rand() % 7 + 5;
        }
        while (lc <5 || lc >7)
        {
            cout << "Numar de locuri necorespunzator!" << '\n';
            cout << "O masina Monovolum are intre 5 si 7 locuri. Introduceti din nou nr locuri:" << '\n';
            try
            {
                in >> lc;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul maxim de locuri aleatoriu." ;
            }
            catch(const char *e6)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e6 << '\n';
                lc=rand() % 7 + 5;
            }
        }


        cout << "Introduceti anul de fabricatie al masinii: ";
        try
        {
            in >> anul;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
        }
        catch(const char *e5)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e5 << '\n';
            anul= prezent;
        }
        while(anul > prezent || anul <= 0)
        {
            cout << "Oops! Se pare ca masina nu a fost fabricata inca. Incercati din nou anul:" << '\n';
            try
            {
                in >> anul;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta anul la cel curent." ;
            }
            catch(const char *e5)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e5 << '\n';
                anul= prezent;
            }
        }

        p5.set_locuri(lc);
        p5.set_an(anul);
        p5.set_tip_masina(temp);

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const Monovolum &p5)
    {
        out << "Tip masina: " << '\n';
        out << p5.get_tip();
        out << '\n';

        out << (masini&) p5;

        out << "Nr de locuri al masinii: " << '\n';
        out << p5.get_locuri() << '\n';
        out << '\n';
        out << "Forma masinii:" << '\n';
        out << p5.get_forma() << '\n';
        out << '\n';
        out << "Anul:" << '\n';
        out << p5.get_anul() << '\n';
        out << '\n';


        return out;
    }

    ~Monovolum() = default;

};


void Monovolum::set_locuri(int x)
{
    nr_locuri=x;
}
void Monovolum::set_an(int x)
{
    an=x;
}


int Monovolum::get_locuri() const
{
    return nr_locuri;
}
string Monovolum::get_forma() const
{
    return forma;
}
int Monovolum::get_anul() const
{
    return an;
}

void Monovolum::afis_masina()
{
    cout << *this;
}

void Monovolum::citire_masina()
{
    cin >> *this;
}




/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


template <class T>

class Vanzare{

protected:

    T* *vandute;
    T* *stock;
    int nr_stock;
    int nr_vandute;

    void set_nr_stock(int nr1);
    void set_nr_vandute(int nr2);
    void set_stock(int nr3);
    void set_vandute(int nr4);
    void set_stock_null();
    void set_vandute_null();




public:


    Vanzare()
    {
        set_nr_stock(0);
        set_nr_vandute(0);
        set_stock_null();
        set_vandute_null();
    }
    Vanzare(int nr1)
    {
        int i;
        char ch[10001];

        try
        {
            if(nr1<0)
                throw " !Se pare ca nu ati introdus o dimensiune valida.";
            else
                set_nr_stock(nr1);
        }
        catch(const char *e7)
        {
            cout << e7 << '\n';
            cout << "Dimensiunea stock-ului va fi setata la 0" << '\n';
            set_nr_stock(0);
        }

        set_nr_vandute(0);

        set_vandute_null();

        set_stock(get_nr_stock());

        for(i=1;i<=get_nr_stock();++i)
        {
            try
            {
                cout << '\n';
                cout << "Introduceti tipul autovehiculului (Compacta / Mini / Mica ): " << '\n';
                cin.getline(ch,10001);
                if(strcmp(ch,"Mini")==0)
                {
                    stock[i]=new Mini();
                    stock[i]->citire_masina();

                }
                else
                if(strcmp(ch,"Mica")==0)
                {
                    stock[i]=new Mica();
                    stock[i]->citire_masina();

                }
                else
                if(strcmp(ch,"Compacta")==0)
                {
                    stock[i]=new Compacta();
                    stock[i]->citire_masina();

                }
                else
                throw "Nu exista acest tip de autovehicul.";
            }
            catch(const char *e1)
            {
                cout << '\n';
                cout << e1 << '\n';
                cout << "Tipurile de autovehicule gestionabile aici sunt: " << '\n';
                cout << "  Mini, Mica, Compacta" << '\n';
                i--;
            }

        }

    }

    Vanzare(const Vanzare &p6)
    {
        int i;


        set_nr_stock(p6.get_nr_stock());

        set_nr_vandute(p6.get_nr_vandute());

        set_vandute_null();

        set_stock(get_nr_stock());

        if(p6.stock != NULL)
            {
                for(i=1;i<=get_nr_stock();++i)
                {

                        copiere_masini(stock[i], p6.stock[i]);


                }
            }
            else
                stock=NULL;


            if(p6.vandute != NULL)
            {
                for(i=1;i<=get_nr_vandute();++i)
                {

                        copiere_masini(vandute[i], p6.vandute[i]);

                }
            }
            else
                vandute=NULL;

    }


    Vanzare &operator=(const Vanzare &p6)
    {
        int i;

        if( &p6 != this)
        {
            if(stock != NULL)
                delete[] stock;

            if(vandute != NULL)
                delete[] vandute;

            set_nr_stock(p6.get_nr_stock());

            set_nr_vandute(p6.get_nr_vandute());

            set_vandute_null();

            set_stock(get_nr_stock());

            if(p6.stock != NULL)
            {
                for(i=1;i<=get_nr_stock();++i)
                {

                        copiere_masini(stock[i], p6.stock[i]);

                }
            }
            else
                stock=NULL;


            if(p6.vandute != NULL)
            {
                for(i=1;i<=get_nr_vandute();++i)
                {

                        copiere_masini(vandute[i], p6.vandute[i]);


                }
            }
            else
                vandute=NULL;

        }

        return *this;

    }



    int get_nr_stock() const;
    int get_nr_vandute() const;

    void afisare_stock() const;

    void istoric_vanzari() const;

    void vinde(string v);

    void make_this_set();

    /// Daca puneam T compilatorul imi spune : " error:  shadows template parm ‘class T’ ... ". De ce ?
    static void copiere_masini(T *&c6,  T *p6);

    Vanzare &operator-=(int n)
    {
        int i;
        string vect[n];

        cout <<"Se doreste a se vinde " << n << " masini de tipuri diverse.";
        cout << '\n';
        for(i=0;i<n;++i)
        {
            cout << '\n';
            cout << "Introduceti tipul masinii " << i+1 << " mai jos (Compacta / Mini / Mica): " << '\n';
            cin >> vect[i];
            cin.get();
            vinde(vect[i]);
        }

        return *this;


    }


    friend istream &operator>>(istream &in, Vanzare &p5)
    {
        int nr;
        cout << '\n';
        cout << "Cate masini de diverse tipuri doriti sa aveti?" << '\n';

        try
        {
            in >> nr;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
        }
        catch(const char *e11)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e11 << '\n';
            nr=0;
        }
        while (nr<0)
        {
            cout << '\n';
            cout << "Ati introdus un nr negativ. Introduceti din nou numarul:";
            try
            {
                in >> nr;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
            }
            catch(const char *e11)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e11 << '\n';
                nr=0;
            }
        }

        in.get();

        p5 = Vanzare(nr);
        return in;
    }

    friend ostream &operator<<(ostream &out, const Vanzare &p5)
    {
        out << "Numarul de masini de tipuri diverse de pe stock este: " << '\n';
        out << p5.get_nr_stock();
        out << '\n';

        p5.afisare_stock(); // nu mergea daca nu era const
        out << '\n';
        out << "Numarul de masini de tipuri diverse vandute este:" << '\n';
        out << p5.get_nr_vandute() << '\n';
        out << '\n';
        p5.istoric_vanzari(); // nu mergea daca nu era const
        out << '\n';

        return out;
    }



    ~Vanzare()
    {
        int i;
        if(stock != NULL)
        {
            for(i=1;i<=get_nr_stock();++i)
                delete stock[i];
            delete[] stock;
        }

        if(vandute != NULL)
        {
            for(i=1;i<=get_nr_vandute();++i)
                delete vandute[i];
            delete[] vandute;
        }
    }


};

template <class T>
void Vanzare<T>::set_nr_stock(int nr1)
{
    nr_stock=nr1;
}
template <class T>
void Vanzare<T>::set_nr_vandute(int nr2)
{
    nr_vandute=nr2;
}
template <class T>
void Vanzare<T>::set_stock(int nr3)
{
    if(nr3 <= 0)
        set_stock_null();
    else
        stock=new T*[nr3+1];
}
template <class T>
void Vanzare<T>::set_vandute(int nr4)
{
    if(nr4 <= 0)
        set_vandute_null();
    else
        vandute=new T*[nr4+1];
}
template <class T>
void Vanzare<T>::set_stock_null()
{
    stock=NULL;
}
template <class T>
void Vanzare<T>::set_vandute_null()
{
    vandute=NULL;
}


template <class T>
int Vanzare<T>::get_nr_stock() const
{
    return nr_stock;
}
template <class T>
int Vanzare<T>::get_nr_vandute() const
{
    return nr_vandute;
}


template <class T>
void Vanzare<T>::afisare_stock() const
{
    int i;
    cout << '\n';
    cout << "La momentul actual in parcul auto se afla urmatoarele masini de tipuri diverse: "<< '\n';
    cout << '\n';
    if(get_nr_stock()<=0)
    {
        cout << "Parcul este gol!" << '\n';
        cout << '\n';
    }
    else
    {
        for(i=1;i<=get_nr_stock();++i)
        {
            cout << '\n';
            stock[i]->afis_masina();
        }
    }
}

template <class T>
void Vanzare<T>::istoric_vanzari() const
{
    int i;
    cout << '\n';
    cout << "In total, s-au vandut urmatoarele masini de tipuri diverse: "<< '\n';
    cout << '\n';
    if(get_nr_vandute()<=0)
    {
        cout << "Nu s-a vandut nimic!" << '\n';
        cout << '\n';
    }
    else
    {
        for(i=1;i<=get_nr_vandute();++i)
        {
            cout << '\n';
            vandute[i]->afis_masina();
        }
    }
}


template <class T>
void Vanzare<T>::vinde(string v)
{
    int i,k=0,ok=0;
    if (v != "Compacta" && v!= "Mica" && v!= "Mini")
        cout << "Acest tip de masina nu exista -> nu poate fi vandut" << '\n';
    else
    {
        for(i=1;i<=get_nr_stock();++i)
            if(stock[i]->get_tip() == v)
            {
                k=i;
                ok=1;
                break;
            }
        if(ok == 1)
        {

            if(get_nr_vandute()<=0)
            {
                set_nr_vandute(1);
                set_vandute(get_nr_vandute());

                if(masini::luna == 6 || masini::luna == 7 || masini::luna == 8)
                    stock[k]->aplica_reducere1();

                copiere_masini(vandute[1],stock[k]);
            }
            else
            {
                int m=0;

                if(masini::luna == 6 || masini::luna == 7 || masini::luna == 8)
                    stock[k]->aplica_reducere1();

                T* *vandute_temp;
                vandute_temp=new T*[get_nr_vandute()+2];
                for(i=1;i<=get_nr_vandute();++i)
                {
                    m++;
                    copiere_masini(vandute_temp[m],vandute[i]);
                }
                m++;
                copiere_masini(vandute_temp[m], stock[k]);
                if(vandute != NULL)
                {
                    delete[] vandute;
                    vandute=NULL;
                }
                set_nr_vandute(m);
                set_vandute(get_nr_vandute());
                for(i=1;i<=get_nr_vandute();++i)
                    copiere_masini(vandute[i],vandute_temp[i]);
                if(vandute_temp != NULL)
                {
                     delete[] vandute_temp;
                     vandute_temp=NULL;
                }
            }

            T* *stock_temp;
            stock_temp=new T*[get_nr_stock()];
            int j=0;
            for(i=1;i<=get_nr_stock();++i)
            {
                if(i!=k)
                {
                    j++;
                    copiere_masini(stock_temp[j],stock[i]);
                }
                else
                if(i==k && get_nr_stock() == 1)
                {
                    stock_temp=NULL;
                    set_nr_stock(0);
                }

            }


            if(stock != NULL)
            {
                delete[] stock;
                stock=NULL;
            }

            if(stock_temp != NULL)
            {

                set_nr_stock(j);
                set_stock(get_nr_stock());
                for(i=1;i<=get_nr_stock();++i)
                    copiere_masini(stock[i],stock_temp[i]);

                delete[] stock_temp;
                stock_temp=NULL;
            }

            cout << '\n';
            cout << " Tranzactie efectuata cu succes!" << '\n';
            cout << '\n';
        }
        else
        {
            cout << '\n';
            cout << "Se pare ca masina respectiva nu mai este pe stock-ul parcului auto sau parcul este deocamdata gol!" << '\n';
            cout << " Tranzactia nu s-a putut efectua!" << '\n';
            cout << '\n';
        }
    }

}


template <class T>
void Vanzare<T>::copiere_masini(T *&c6,  T *p6)
{
    char ch[10001], temp[10001];

    strcpy(ch, p6->get_tip().c_str());

    if(strcmp(ch,"Mini")==0)
    {
        strcpy(temp, p6->get_denumire().c_str());
        c6=new Mini(p6->get_pret(), p6->get_litraj(), temp, static_cast<Mini*>(p6)->get_lungime(), static_cast<Mini*>(p6)->get_anul());

    }
    else
    if(strcmp(ch,"Mica")==0)
    {
        strcpy(temp, p6->get_denumire().c_str());
        c6=new Mica(p6->get_pret(), p6->get_litraj(), temp, static_cast<Mica*>(p6)->get_lungime(), static_cast<Mica*>(p6)->get_ampatament(), static_cast<Mica*>(p6)->get_anul());

    }
    else
    if(strcmp(ch,"Compacta")==0)
    {
        char temp1[11];

        strcpy(temp, p6->get_denumire().c_str());
        strcpy(temp1, static_cast<Compacta*>(p6)->get_forma().c_str());

        c6=new Compacta(p6->get_pret(), p6->get_litraj(), temp, static_cast<Compacta*>(p6)->get_lungime(), temp1, static_cast<Compacta*>(p6)->get_anul());

    }
}


template <class T>
void Vanzare<T>::make_this_set()
{
    int i;

    typedef pair< T*, bool> pairs;
    std::set < pairs > s1;
    pairs p1;

    for(i=1;i<=get_nr_stock();++i)
    {

        p1 = make_pair(stock[i],true); // programul e construit de asa maniera incat nu se poate introduce o masina mai veche de 1 an ( cele ma ivechi de un an sunt SH)
        s1.insert(p1);
    }

    cout << "_________________________________________________" <<'\n';
    cout << "Setul cu masini de tipuri diverse din stock este:" << '\n';
    cout << '\n';

    if(get_nr_stock()<=0)
    {
        cout << "Set GOL ! Se pare ca parcul nu are nimic pe stock." << '\n';
        cout << '\n';
    }
    else
    {
        for (auto const &var : s1)
        {
            var.first->afis_masina();

            if(var.second == true)
                cout << "Autovehicul Nou" << '\n';
            else
                cout << "Autovehicul SH" << '\n';
            cout << '\n';
        }
    }

}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


template<>
class Vanzare<Monovolum>
{

private:
    Monovolum *vandute;
    Monovolum *stock;
    int nr_stock;
    int nr_vandute;

    void set_nr_stock(int nr1);
    void set_nr_vandute(int nr2);
    void set_stock(int nr3);
    void set_vandute(int nr4);
    void set_stock_null();
    void set_vandute_null();

public:

    Vanzare()
    {
        set_nr_stock(0);
        set_nr_vandute(0);
        set_stock_null();
        set_vandute_null();
    }
    Vanzare(int nr1)
    {
        int i;

        try
        {
            if(nr1<0)
                throw " !Se pare ca nu ati introdus o dimensiune valida.";
            else
                set_nr_stock(nr1);
        }
        catch(const char *e7)
        {
            cout << e7 << '\n';
            cout << "Dimensiunea stock-ului va fi setata la 0" << '\n';
            set_nr_stock(0);
        }

        set_nr_vandute(0);

        set_vandute_null();

        set_stock(get_nr_stock());

        for(i=1;i<=get_nr_stock();++i)
        {
            cout << '\n';
            cout << "Introduceti datele unui Monovolum: " << '\n';
            stock[i].citire_masina();

        }

    }

    Vanzare(const Vanzare &p6)
    {
        int i;


        set_nr_stock(p6.get_nr_stock());

        set_nr_vandute(p6.get_nr_vandute());

        set_vandute_null();

        set_stock(get_nr_stock());

        if(p6.stock != NULL)
            {
                for(i=1;i<=get_nr_stock();++i)
                    stock[i]=p6.stock[i];
            }
            else
                stock=NULL;


            if(p6.vandute != NULL)
            {
                for(i=1;i<=get_nr_vandute();++i)
                    vandute[i]=p6.vandute[i];
            }
            else
                vandute=NULL;

    }


    Vanzare &operator=(const Vanzare &p6)
    {
        int i;

        if( &p6 != this)
        {
            if(stock != NULL)
                delete[] stock;

            if(vandute != NULL)
                delete[] vandute;

            set_nr_stock(p6.get_nr_stock());

            set_nr_vandute(p6.get_nr_vandute());

            set_vandute_null();

            set_stock(get_nr_stock());

            if(p6.stock != NULL)
            {
                for(i=1;i<=get_nr_stock();++i)
                    stock[i]=p6.stock[i];
            }
            else
                stock=NULL;


            if(p6.vandute != NULL)
            {
                for(i=1;i<=get_nr_vandute();++i)
                    vandute[i]=p6.vandute[i];
            }
            else
                vandute=NULL;

        }

        return *this;

    }



    int get_nr_stock() const;
    int get_nr_vandute() const;


    void afisare_stock() const;

    void istoric_vanzari() const;

    void vinde();

    void make_this_set();

    Vanzare &operator-=(int n)
    {
        int i;

        cout << '\n';
        cout <<"Se doreste a se vinde " << n << " masini de tip Monovolum." << '\n';
        cout << '\n';
        for(i=0;i<n;++i)
            vinde();

        return *this;


    }

    friend istream &operator>>(istream &in, Vanzare &p5)
    {
        int nr;

        cout << '\n';
        cout << "Cate masini tip Monovolum doriti sa aveti?" << '\n';

        try
        {
            in >> nr;
            if(in.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
        }
        catch(const char *e11)
        {
            in.ignore(256,'\n');
            in.clear();
            string dummy;
            in >> dummy;
            cout << e11 << '\n';
            nr=0;
        }
        while (nr<0)
        {
            cout << '\n';
            cout << "Ati introdus un nr negativ. Introduceti din nou numarul:";
            try
            {
                in >> nr;
                if(in.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
            }
            catch(const char *e11)
            {
                in.ignore(256,'\n');
                in.clear();
                string dummy;
                in >> dummy;
                cout << e11 << '\n';
                nr=0;
            }
        }

        in.get();

        p5 = Vanzare(nr);
        return in;
    }


    friend ostream &operator<<(ostream &out, const Vanzare &p5)
    {
        out << "Numarul de masini tip Monovolum de pe stock este: " << '\n';
        out << p5.get_nr_stock();
        out << '\n';
        p5.afisare_stock();
        out << '\n';
        out << "Numarul de masini tip Monovolum vandute este:" << '\n';
        out << p5.get_nr_vandute() << '\n';
        out << '\n';
        p5.istoric_vanzari();
        out << '\n';

        return out;
    }



    ~Vanzare()
    {
        if(stock != NULL)
            delete[] stock;
        if(vandute != NULL)
            delete[] vandute;
    }


};


void Vanzare<Monovolum>::set_nr_stock(int nr1)
{
    nr_stock=nr1;
}

void Vanzare<Monovolum>::set_nr_vandute(int nr2)
{
    nr_vandute=nr2;
}

void Vanzare<Monovolum>::set_stock(int nr3)
{
    if(nr3 <= 0)
        set_stock_null();
    else
        stock=new Monovolum[nr3+1];
}

void Vanzare<Monovolum>::set_vandute(int nr4)
{
    if(nr4 <= 0)
        set_vandute_null();
    else
        vandute=new Monovolum[nr4+1];

}

void Vanzare<Monovolum>::set_stock_null()
{
    stock=NULL;
}

void Vanzare<Monovolum>::set_vandute_null()
{
    vandute=NULL;
}


int Vanzare<Monovolum>::get_nr_stock() const
{
    return nr_stock;
}

int Vanzare<Monovolum>::get_nr_vandute() const
{
    return nr_vandute;
}


void Vanzare<Monovolum>::afisare_stock() const
{
    int i;
    cout << '\n';
    cout << "La momentul actual in parcul auto se afla urmatoarele masini tip Monovolum: "<< '\n';
    cout << '\n';
    if(get_nr_stock()<=0)
    {
        cout << "Parcul este gol!" << '\n';
        cout << '\n';
    }
    else
    {
        for(i=1;i<=get_nr_stock();++i)
        {
            cout << '\n';
            stock[i].afis_masina();
        }
    }
}

void Vanzare<Monovolum>::istoric_vanzari() const
{
    int i;
    cout << '\n';
    cout << "In total, s-au vandut urmatoarele masini tip Monovolum: "<< '\n';
    cout << '\n';
    if(get_nr_vandute()<=0)
    {
        cout << "Nu s-a vandut nimic!" << '\n';
        cout << '\n';
    }
    else
    {
        for(i=1;i<=get_nr_vandute();++i)
        {
            cout << '\n';
            vandute[i].afis_masina();
        }
    }
}


void Vanzare<Monovolum>::vinde()
{
    int i,k=0,ok=0;
        for(i=1;i<=get_nr_stock();++i)
        {
            k=i;
            ok=1;
            break;
        }
        if(ok == 1)
        {

            if(get_nr_vandute()<=0)
            {
                set_nr_vandute(1);
                set_vandute(get_nr_vandute());

                double rd=0;
                Monovolum stock_t;
                stock_t = stock[k];
                rd=masini::prezent - static_cast<Monovolum*>(&stock_t)->get_anul();

                if(rd>1)
                    stock[k].aplica_reducere2(rd);  /// Am considerat ca masinile noi sa nu fie mai vechi de 1 an. Masinile mai vechi de un an sunt SH.

                if(masini::luna == 6 || masini::luna == 7 || masini::luna == 8)
                    stock[k].aplica_reducere1();

                vandute[1]=stock[k];
            }
            else
            {
                int m=0;
                double rd=0;

                Monovolum stock_t;
                stock_t = stock[k];
                rd=masini::prezent - static_cast<Monovolum*>(&stock_t)->get_anul();
                if(rd>1)
                     stock[k].aplica_reducere2(rd);

                if(masini::luna == 6 || masini::luna == 7 || masini::luna == 8)
                    stock[k].aplica_reducere1();

                Monovolum *vandute_temp;
                vandute_temp=new Monovolum[get_nr_vandute()+2];
                for(i=1;i<=get_nr_vandute();++i)
                {
                    m++;
                    vandute_temp[m]=vandute[i];
                }
                m++;
                vandute_temp[m]=stock[k];
                if(vandute != NULL)
                {
                    delete[] vandute;
                    vandute=NULL;
                }
                set_nr_vandute(m);
                set_vandute(get_nr_vandute());
                for(i=1;i<=get_nr_vandute();++i)
                    vandute[i]=vandute_temp[i];
                if(vandute_temp != NULL)
                {
                     delete[] vandute_temp;
                     vandute_temp=NULL;
                }
            }

            Monovolum *stock_temp;
            stock_temp=new Monovolum[get_nr_stock()];
            int j=0;
            for(i=1;i<=get_nr_stock();++i)
            {
                if(i!=k)
                {
                    j++;
                    stock_temp[j]=stock[i];
                }
                else
                if(i==k && get_nr_stock() == 1)
                {
                    stock_temp=NULL;
                    set_nr_stock(0);
                }

            }


            if(stock != NULL)
            {
                delete[] stock;
                stock=NULL;
            }

            if(stock_temp != NULL)
            {

                set_nr_stock(j);
                set_stock(get_nr_stock());
                for(i=1;i<=get_nr_stock();++i)
                    stock[i]=stock_temp[i];

                delete[] stock_temp;
                stock_temp=NULL;
            }

            cout << '\n';
            cout << " Tranzactie efectuata cu succes!" << '\n';
            cout << '\n';
        }
        else
        {
            cout << '\n';
            cout << "Se pare ca masina respectiva nu mai este pe stock-ul parcului auto sau parcul este deocamdata gol!" << '\n';
            cout << " Tranzactia nu s-a putut efectua!" << '\n';
            cout << '\n';
        }

}

void Vanzare<Monovolum>::make_this_set()
{
    int i, an_t;

    typedef pair< Monovolum*, bool> pairs;
    std::set < pairs > s2;
    pairs p2;

    for(i=1;i<=get_nr_stock();++i)
    {
        Monovolum stock_t;
        stock_t = stock[i];
        an_t=static_cast<Monovolum*>(&stock_t)->get_anul();

        if(masini::prezent - an_t >1)
            p2 = make_pair(&stock[i],false);
        else
            p2 = make_pair(&stock[i],true);

        s2.insert(p2);
    }

    cout << "_____________________________________________" <<'\n';
    cout << "Setul cu masini tip Monovolum din stock este:" << '\n';
    cout << '\n';
    if(get_nr_stock()<=0)
    {
        cout << "Set GOL ! Se pare ca parcul nu are nimic pe stock." << '\n';
        cout << '\n';
    }
    else
    {
        for (auto const &var : s2)
        {
            var.first->afis_masina();

            if(var.second == true)
                cout << "Autovehicul Nou" << '\n';
            else
                cout << "Autovehicul SH" << '\n';
            cout << '\n';
        }
    }

}


// -- Data curenta --
time_t timp=time(0);
struct tm* point = localtime(&timp);
int masini::luna=1 + point->tm_mon;
int masini::prezent=1900 + point->tm_year;

/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{


    int choice, nr_op;
    bool status = true;

    Vanzare<masini> o1;
    Vanzare<Monovolum> o2;

    while (status != false)
    {
        cout << "***************************************************************************************************\n";
        cout << " 1 - Introduceti masini de tip diverse in parcul auto (Se citesc n obiecte tip Compacta/Mini/Mica ).\n";
        cout << " 2 - Afisati stock-ul si istoricul de vanzari de masini tip diverse.\n";
        cout << " 3 - Introduceti masini tip Monovolum in parcul auto (Se citesc n obiecte de tip Monovolum ).\n";
        cout << " 4 - Afisati stock-ul si istoricul de vanzari de masini tip Monovolum.\n";
        cout << " 5 - Vindeti una sau mai multe masini tip Compacta / Mini / Mica. \n";
        cout << " 6 - Vindeti una sau mai multe masini tip Monovolum.\n";
        cout << " 7 - Sa sa creeze si afiseze structura Set<pairs> cu masinile tip diverse din stock.\n";
        cout << " 8 - Sa se creeze si afiseze structura Set<pairs> cu masinile tip Monovolum din stick.\n";
        cout << " 9 - END.\n";
        cout << "***************************************************************************************************\n";
        cout << " Introduceti optiunea si apasati tasta enter: ";

        try
        {
            cin >> choice;
            if(cin.fail())
                throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta optiunea la valoarea 9." ;
        }
        catch(const char *e10)
        {
            cin.ignore(256,'\n');
            cin.clear();
            string dummy;
            cin >> dummy;
            cout << e10 << '\n';
            choice=9;
        }

        switch (choice)
        {
            case 1:
            cin >> o1;
            break;
            case 2:
            cout << o1;
            break;
            case 3:
            cin >> o2;
            break;
            case 4:
            cout << o2;
            break;
            case 5:
            nr_op=0;
            cout << '\n';
            cout << "Cate masini tip diverse doriti sa vindeti?" << '\n';
            try
            {
                cin >> nr_op;
                if(cin.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
            }
            catch(const char *e10)
            {
                cin.ignore(256,'\n');
                cin.clear();
                string dummy;
                cin >> dummy;
                cout << e10 << '\n';
                nr_op=0;
            }
            while (nr_op<0)
            {
                cout << '\n';
                cout << "Ati introdus un nr negativ. Introduceti din nou numarul:";
                try
                {
                    cin >> nr_op;
                    if(cin.fail())
                        throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
                }
                catch(const char *e10)
                {
                    cin.ignore(256,'\n');
                    cin.clear();
                    string dummy;
                    cin >> dummy;
                    cout << e10 << '\n';
                    nr_op=0;
                }
            }
            o1-=nr_op;
            break;
            case 6:
            nr_op=0;
            cout << '\n';
            cout << "Cate masini tip Monovolum doriti sa vindeti?" << '\n';
            try
            {
                cin >> nr_op;
                if(cin.fail())
                    throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
            }
            catch(const char *e10)
            {
                cin.ignore(256,'\n');
                cin.clear();
                string dummy;
                cin >> dummy;
                cout << e10 << '\n';
                nr_op=0;
            }
            while (nr_op<0)
            {
                cout << '\n';
                cout << "Ati introdus un nr negativ. Introduceti din nou numarul:";
                try
                {
                    cin >> nr_op;
                    if(cin.fail())
                        throw " !Se pare ca nu ati introdus o valoare numerica valida. Programul va seta numarul la 0." ;
                }
                catch(const char *e10)
                {
                    cin.ignore(256,'\n');
                    cin.clear();
                    string dummy;
                    cin >> dummy;
                    cout << e10 << '\n';
                    nr_op=0;
                }
            }
            o2-=nr_op;
            break;
            case 7:
            o1.make_this_set();
            break;
            case 8:
            o2.make_this_set();
            break;
            case 9:
            cout << "Sfarsitul programului! \n";
            status = false;
            break;
            default:
            cout << "Ati introdus o optiune invalida. \n";
            cout << "Alegeti optiunea din nou:\n";
            cin >> choice;
            break;
        }

    }
    return 0;
}
