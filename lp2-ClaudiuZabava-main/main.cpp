#include <iostream>
#include <cstring>
using namespace std;

class abonament{    /// Ca sa intelegi urmatoarele linii de cod -> Readme: Clasa Nr.1

protected:

    float pret;
    int perioada;
    char *name;

    void set_new_pret(float pr);
    void set_new_perioada(int pd);
    void set_new_name(char ch[10001]);
    void set_new_name_null();

public:

    abonament()
    {
        set_new_pret(0.0);
        set_new_perioada(0);
        set_new_name_null();
    }


    abonament(char ch[10001], float pr, int pd)
    {
        set_new_pret(pr);
        set_new_perioada(pd);
        set_new_name(ch);
    }


    abonament(const abonament &p1)
    {
        char temp[10001];
        strcpy(temp,p1.get_name());

        set_new_pret(p1.get_pret());
        set_new_perioada(p1.get_perioada());
        set_new_name(temp);
    }

    abonament &operator=(const abonament &p1)
    {
        char temp1[10001];

        if( &p1 != this)
        {
            strcpy(temp1,p1.get_name());
            if(name != NULL)
                delete[] name;
            set_new_name(temp1);
            set_new_pret(p1.get_pret());
            set_new_perioada(p1.get_perioada());
        }

        return *this;

    }


    char* get_name() const;
    float get_pret() const;
    int get_perioada() const;

    virtual int get_reducere() const = 0;


    friend istream &operator>>(istream &in, abonament &p1)
    {
        char ch[10001];
        float pr;
        int pd;

        cout << "Se vor introduce datele abonamentului" << '\n';
        cout << "Introduceti numele abonamentului: ";
        in.getline(ch,10001);

        cout << "Introduceti pretul abonamentului: ";
        in >> pr;

        cout << "Introduceti perioada abonamentului: ";
        in >> pd;

        p1.set_new_name(ch);
        p1.set_new_pret(pr);
        p1.set_new_perioada(pd);

        in.get();

        return in;

    }

    friend ostream &operator<<(ostream &out, const abonament &p1)
    {
        out << '\n';
        out << "Numele abonamentului:" << '\n';
        out << p1.get_name() << '\n';
        out << '\n';
        out << "Pret:" << '\n';
        out << p1.get_pret() << '\n';
        out << '\n';
        out << "Perioada" << '\n';
        out << p1.get_perioada() << '\n';
        out << '\n';


        return out;
    }


    virtual ~abonament()
    {
        if(name != NULL)
            delete[] name;
    }

    friend class abonat;
    friend class clienti;

};


void abonament::set_new_pret(float pr)
{
    pret=pr;
}

void abonament::set_new_perioada(int pd)
{
    perioada=pd;
}

void abonament::set_new_name(char ch[10001])
{
    int sz;
    sz=strlen(ch);
    if(name != NULL)
        delete[] name;
    name = new char[sz+1];
    strcpy(name, ch);
}
void abonament::set_new_name_null()
{
    name=NULL;
}

float abonament::get_pret() const
{
    return pret;
}

int abonament::get_perioada() const
{
    return perioada;
}

char* abonament::get_name() const
{
    return name;
}




class abonament_premium : public abonament{   /// Ca sa intelegi urmatoarele linii de cod -> Readme: Clasa Nr.2

protected:

    int reducere;

    void set_reducere(int j);

public:

    abonament_premium(): abonament()
    {
        set_reducere(0);
    }

    abonament_premium(char ch[10001], float pr, int pd, int j): abonament(ch,pr,pd)
    {
        set_reducere(j);

    }

    abonament_premium(const abonament_premium &p2): abonament(p2)
    {
        set_reducere(p2.get_reducere());
    }

    abonament_premium &operator=(const abonament_premium &p2)
    {
        set_reducere(p2.get_reducere());
        abonament::operator=(p2);

        return *this;
    }


    int get_reducere() const override
    {
        return reducere;
    }


    friend istream &operator>>(istream &in, abonament_premium &p2)
    {
        int rd;

        in >> (abonament&) p2; ///to avoid slicing

        cout << "Se vor introduce datele abonamentului premium" << '\n';
        cout << "Introduceti reducerea: ";
        in >> rd;

        p2.set_reducere(rd);

        in.get();

        return in;

    }

     friend ostream &operator<<(ostream &out, const abonament_premium &p2)
     {
         out << (abonament&) p2;
         out << "Reducere de " << p2.get_reducere() << " %" << '\n';
         out << '\n';

         return out;
     }

     friend class abonat; ///

};

void abonament_premium::set_reducere(int j)
{
    reducere=j;
}




class persoana{   /// Ca sa intelegi urmatoarele linii de cod -> Readme: Clasa Nr.3

protected:

    int id;
    char *name1;
    char *cnp;

    void set_new_name1(char ch1[10001]);
    void set_new_name1_null();
    void set_new_cnp(char ch2[14]);
    void set_new_cnp_null();
    void set_new_id(int nr1);

public:

    persoana()
    {
        set_new_name1_null();
        set_new_cnp_null();
        set_new_id(0);
    }

    persoana(char ch1[10001], char ch2[14], int nr1)
    {
        set_new_name1(ch1);
        set_new_cnp(ch2);
        set_new_id(nr1);
    }

    persoana(const persoana &p3)
    {
        char temp2[10001];

        strcpy(temp2,p3.get_name1());

        set_new_name1(temp2);

        strcpy(temp2,p3.get_cnp());

        set_new_cnp(temp2);

        set_new_id(p3.get_id());

    }

    persoana &operator=(const persoana &p3)
    {

        char temp3[10001];

        if( &p3 != this)
        {
            strcpy(temp3,p3.get_name1());

            if(name1 != NULL)
                delete[] name1;
            set_new_name1(temp3);

            strcpy(temp3,p3.get_cnp());

            if(cnp != NULL)
                delete[] cnp;
            set_new_cnp(temp3);

            set_new_id(p3.get_id());
        }

        return *this;

    }

    char* get_name1() const;
    char* get_cnp() const;
    int get_id() const;


    friend istream &operator>>(istream &in, persoana &p3)
    {
        char ch1[10001], ch2[14];
        int nr1;


        cout << "Se vor introduce datele persoanei" << '\n';
        cout << "Introduceti ID-ul persoanei: ";
        in >> nr1;
        in.get();

        cout << "Introduceti numele persoanei: ";
        in.getline(ch1,10001);

        cout << "Introduceti CNP-ul: ";
        in.getline(ch2,14);

        p3.set_new_name1(ch1);
        p3.set_new_cnp(ch2);
        p3.set_new_id(nr1);

        return in;
    }

    friend ostream &operator<<(ostream &out, const persoana &p3)
    {
        out << '\n';
        out << "ID-ul persoanei: " << '\n';
        out << p3.get_id() << '\n';
        out << '\n';
        out << "Numele Persoanei:" << '\n';
        out << p3.get_name1() << '\n';
        out << '\n';
        out << "CNP:" << '\n';
        out << p3.get_cnp() << '\n';
        out << '\n';

        return out;
    }


    virtual ~persoana()
    {
        if(name1 != NULL)
            delete[] name1;

        if(cnp != NULL)
            delete[] cnp;
    }

};

void persoana::set_new_name1(char ch1[10001])
{
    int sz;
    sz=strlen(ch1);
    if(name1 != NULL)
        delete[] name1;
    name1=new char[sz+1];
    strcpy(name1,ch1);
}

void persoana::set_new_cnp(char ch2[14])
{
    int sz;
    sz=strlen(ch2);
    if(cnp != NULL)
        delete[] cnp;
    cnp=new char[sz+1];
    strcpy(cnp,ch2);
}
void persoana::set_new_name1_null()
{
    name1=NULL;
}
void persoana::set_new_cnp_null()
{
    cnp=NULL;
}
void persoana::set_new_id(int nr1)
{
    id=nr1;
}

char* persoana::get_name1() const
{
    return name1;
}

char* persoana::get_cnp() const
{
    return cnp;
}

int persoana::get_id() const
{
    return id;
}




class abonat: public persoana{   /// Ca sa intelegi urmatoarele linii de cod -> Readme: Clasa Nr.4

protected:

    abonament* obj;   /// folosim un obiect de tip abonament, il instantiem ca pe un obiect de tip abonament_premium pt a avea acces la met. virtuala
    char *telefon;

    void set_new_telefon(char ch3[11]);
    void set_new_telefon_null();
    void set_new_obj(const abonament &p5);

public:

    abonat(): persoana()
    {
        obj = new abonament_premium();
        set_new_telefon_null();
    }

    abonat(char ch1[10001], char ch2[10001], char ch3[11], int nr1, const abonament &p5): persoana(ch1,ch2, nr1)
    {
        set_new_obj(p5);
        set_new_telefon(ch3);
    }

    abonat(const abonat &p4): persoana(p4)
    {
        char temp6[11];
        strcpy(temp6, p4.get_telefon());

        set_new_obj(*p4.obj);
        set_new_telefon(temp6);
    }

    abonat &operator=(const abonat &p4)
    {
        char temp7[11];
        strcpy(temp7, p4.get_telefon());

        if( &p4 != this)
        {
            if(telefon != NULL)
                delete[] telefon;
            set_new_telefon(temp7);
            set_new_obj(*p4.obj);

            persoana::operator=(p4);
        }

        return *this;

    }


    char* get_telefon() const;

    int get_reducere2() const
    {
        return obj->get_reducere();
    }


    friend istream &operator>>(istream &in, abonat &p4)
    {
        char ch3[11];


        in >> (persoana&) p4;

        cout << "Se vor introduce datele abonatului" << '\n';
        cout << "Introduceti nr de telefon: ";
        in.getline(ch3,11);

        p4.set_new_telefon(ch3);

        in >> (abonament_premium&) *p4.obj;

        return in;
    }

    friend ostream &operator<<(ostream &out, const abonat &p4)
    {
        out << (persoana) p4;
        out << "Numar de telefon:" << '\n';
        out << p4.get_telefon() << '\n';
        out << (abonament_premium&) *p4.obj;
        out << '\n';

        return out;

    }


    friend class clienti;

    ~abonat()
    {
        if(telefon != NULL)
            delete[] telefon;
    }

};

void abonat::set_new_telefon(char ch3[11])
{
    int sz;

    sz=strlen(ch3);
    if(telefon != NULL)
        delete[] telefon;
    telefon=new char[sz+1];
    strcpy(telefon,ch3);
}

void abonat::set_new_telefon_null()
{
    telefon=NULL;
}


void abonat::set_new_obj(const abonament &p5)
{
    char ch[10001];
    float pr;
    int pd,rd;
    strcpy(ch,p5.get_name());
    pr=p5.get_pret();
    pd=p5.get_perioada();
    rd=p5.get_reducere();
    obj=new abonament_premium(ch,pr,pd,rd);
}

char* abonat::get_telefon() const
{
    return telefon;
}




class clienti {   /// Ca sa intelegi urmatoarele linii de cod -> Readme: Clasa Nr.5 (aka. Ultima clasa)

private:

    abonat* v;

    void set_lungime(int nr1);
    void set_new_vector(int nr2);
    void set_new_vector_null();
    void insert_element();
    void sterg_element(int k);
public:

    static int m;

    clienti()
    {
        set_new_vector_null();
    }
    clienti(int nr)
    {
        set_lungime(nr);
        set_new_vector(get_lungime());
    }
    clienti(const clienti &p5)
    {
        if(v!=NULL)
            delete[] v;
        v=new abonat[p5.get_lungime()+1];

        for(int i=1; i<=p5.get_lungime();++i)
            v[i]=p5.v[i];
    }
    clienti &operator=(const clienti &p5)
    {
        if(&p5 != this)
        {
            if(v!=NULL)
                delete[] v;

            v=new abonat[p5.get_lungime()+1];

            for(int i=1; i<=p5.get_lungime();++i)
                v[i]=p5.v[i];
        }

        return *this;
    }

    friend istream &operator>>(istream &in, clienti &p5)
    {

        p5.set_new_vector(p5.get_lungime());

        cout << '\n';

        return in;
    }

    friend ostream &operator<<(ostream &out, clienti &p5)
    {

        for(int i=1; i<=p5.get_lungime();++i)
        out << p5.v[i];

        return out;
    }


    int get_lungime() const;

    int returnme_reducere(int k) const;

    char* returnme_nume_abonament(int k) const;
    char* returnme_cnp(int k) const;

    void clienti_premium();

    void castig_total();

    void unicitate(int i, int &ok);

    void intermediar()
    {
        insert_element();
    }

    void intermediar2(int k)
    {
        if(k<=get_lungime())
            sterg_element(k);
        else
        {
            cout << '\n';
            cout << "Imposibil" << '\n';
        }
    }

    ~clienti()
    {
        if(v != NULL)
            delete[] v;
    }


};
void clienti::set_new_vector(int nr2)
{
    int i,ok=0;

    if(v!=NULL)
        delete[] v;
    v=new abonat[nr2+1];

    for(i=1; i<=nr2;++i)
    {
        cout <<'\n';
        cout << "Clientul nr." << i << '\n';
        cin >> v[i];
        unicitate(i,ok);
        if(ok==1)
        {
            delete[] v[i].obj->name;
            v[i].obj->set_new_name_null();
            delete[] v[i].name1;
            v[i].set_new_name1_null();
            delete[] v[i].cnp;
            v[i].set_new_cnp_null();
            delete[] v[i].telefon;
            v[i].set_new_telefon_null();
            delete &v[i];
            i--;
            ok=0;
        }
    }
}

void clienti::set_new_vector_null()
{
    v= NULL;
}

void clienti::set_lungime(int nr1)
{
    m=nr1;
}

void clienti::insert_element()
{
    int i,k,done=0,finish=0;

    abonat* v2;
    set_lungime(get_lungime()+1);
    v2=new abonat[get_lungime()+1];

    for(i=1;i<=get_lungime()-1;++i)
        v2[i]=v[i];
    delete[] v;

    k=get_lungime();

    v=new abonat[k+1];
    for(i=1;i<=k-1;++i)
        v[i]=v2[i];

    delete[] v2;

    while(finish != 1)
    {
        done=0;
        cout <<'\n';
        cout << "Clientul nr." << k << '\n';
        cin >> v[k];
        unicitate(k,done);
        if(done==1)
        {
            delete[] v[i].obj->name;
            v[i].obj->set_new_name_null();
            delete[] v[i].name1;
            v[i].set_new_name1_null();
            delete[] v[i].cnp;
            v[i].set_new_cnp_null();
            delete[] v[i].telefon;
            v[i].set_new_telefon_null();
            delete &v[k];
            finish=0;
        }
        else
        {
            finish=1;
            break;
        }
    }
}

void clienti::sterg_element(int k)
{
    int i,n,contor=0,j=0;

    abonat* v2;
    n=get_lungime()-1;
    v2=new abonat[n+1];

    for(i=1;i<=get_lungime();++i)
    {
        contor++;
        if(contor!=k)
        {
            j++;
            v2[j]=v[i];
        }
    }
    delete[] v;

    set_lungime(n);

    v=new abonat[n+1];
    for(i=1;i<=n;++i)
        v[i]=v2[i];

    delete[] v2;

}

int clienti::get_lungime() const
{
    return m;
}

int clienti::returnme_reducere(int k) const
{
    return v[k].obj->get_reducere();
}

char* clienti::returnme_nume_abonament(int k) const
{
    return v[k].obj->get_name();
}

void clienti::unicitate(int i, int &ok)
{
    int j;
    for (j=1;j<i;++j)
        {
            if(v[j].get_id() == v[i].get_id() )
            {
                cout << '\n';
                if(strcmp(v[j].get_cnp(), v[i].get_cnp())==0)
                {
                    if( strcmp(v[j].get_name1(), v[i].get_name1())==0 && i!=j)
                    {

                        if( strcmp(returnme_nume_abonament(i), returnme_nume_abonament(j))==0)
                        {

                            if( (returnme_reducere(i)!=0 && returnme_reducere(j)!=0) || (returnme_reducere(i) == returnme_reducere(j) && returnme_reducere(j) == 0))
                            {
                                ok=1;
                                cout << "Eroare: Tocmai ati introdus 2 persoane ce au acelasi credentiale si acelasi tip de abonament ( premium / non-premium)." << '\n';
                                cout << "Acest client nu a fost salvat. Mai raman de introdus " << get_lungime()-i+1 << " clienti."<< '\n';
                                cout << '\n';
                                break;
                            }
                        }
                        else
                            ok=0;
                    }
                    else
                    if( strcmp(v[j].get_name1(), v[i].get_name1())!=0 )
                    {
                        ok=1;
                        cout << "Eroare: Tocmai ati introdus 2 persoane ce au acelasi ID si CNP, dar nume diferite" << '\n';
                        cout << "Acest client nu a fost salvat. Mai raman de introdus " << get_lungime()-i+1 << " clienti."<< '\n';
                        cout << '\n';
                        break;
                    }
                }
                else
                if(strcmp(v[j].get_cnp(), v[i].get_cnp())!=0)
                {
                    ok=1;
                    cout << "Eroare: Tocmai ati introdus 2 persoane ce au acelasi ID dar CNP-uri diferite" << '\n';
                    cout << "Acest client nu a fost salvat. Mai raman de introdus " << get_lungime()-i+1 << " clienti."<< '\n';
                    cout << '\n';
                    break;
                }
            }
            else
            if(v[j].get_id() != v[i].get_id() )
            {
                cout << '\n';

                if(strcmp(v[j].get_cnp(), v[i].get_cnp())==0)
                {
                    ok=1;
                    cout << "Eroare: CNP-ul pe care l-ati introdus apartine deja unei persoane cu alt ID" << '\n';
                    cout << "Acest client nu a fost salvat. Mai raman de introdus " << get_lungime()-i+1 << " clienti."<< '\n';
                    cout << '\n';
                    break;
                }
                else
                if(strcmp(v[j].get_telefon(), v[i].get_telefon())==0)
                {
                    ok=1;
                    cout << "Eroare: Numarul de telefon introdus apartine deja unei persoane cu alt ID" << '\n';
                    cout << "Acest client nu a fost salvat. Mai raman de introdus " << get_lungime()-i+1 << " clienti."<< '\n';
                    cout << '\n';
                    break;
                }
            }
        }
}

void clienti::clienti_premium()
{
    int nra=0;
    for(int i=1;i<=get_lungime();++i)
        if(v[i].obj->get_reducere()!=0)
            nra++;

    cout << "Sunt " << nra << " de clienti premium" << '\n';
}

void clienti::castig_total()
{
    float cash=0;
    for(int i=1;i<=get_lungime();++i)
        cash=cash + (v[i].obj->get_pret() - (v[i].obj->get_pret() * v[i].obj->get_reducere())/100) * v[i].obj->get_perioada();

    cout << "Castigul total este: " << cash << " lei" << '\n';
}

int clienti::m;

void afis_op()
{
    cout << endl
        << " 1 - Precizati lungimea listei de clienti.\n"
        << " 2 - Doresc sa introduc o lista de clienti.\n"
        << " 3 - Doresc sa previzualizez lista introdusa.\n"
        << " 4 - Doresc sa vad numarul de clienti cu abonament premium.\n"
        << " 5 - Doresc sa aflu castigul total pe baza abonamentelor (se ia in calcul reducerea).\n"
        << " 6 - Doresc sa inserez / adaug un element in lista curenta.\n"
        << " 7 - Doresc sa sterg al n-lea element din lista curenta.\n"
        << " 0 - Exit.\n"
        << " Scrieti aici optiunea dumneavoastra: ";
}

int main()
{
    int op,ok1=0,ok2=0,ok3=0,nr;

    afis_op();
    cin >> op;
    cin.get();

    clienti o1;

    while(op!=0)
    {
        ok3=0;
        if(op==1)
        {
            ok1=1;
            cout << '\n';
            cout << "Introduceti lungimea mai jos" << '\n';
            cin >> clienti::m;
            cin.get();
        }
        else
        if(op==2 && ok1!=0)
        {
            ok2=1;

            cout << '\n';

            cin >> o1;
            afis_op();
            cin>> op;
            cin.get();
            while(op>2)
            {
                if(op==3)
                {
                    if(ok1==0 || ok2==0)
                        cout << "Nu se poate afisa, lista e goala sau nedefinita" << '\n';
                    else
                    cout << o1;
                }
                else
                if(op==4)
                {
                    cout << '\n';
                    o1.clienti_premium();
                }
                else
                if(op==5)
                {
                    cout << '\n';
                    o1.castig_total();
                }
                else
                if(op==6)
                {
                    cout << '\n';
                    o1.intermediar();
                }
                else
                if(op==7)
                {
                    cout << '\n';
                    cout << "Introduceti indicele elementului:" << '\n';
                    cin >> nr;
                    cin.get();
                    o1.intermediar2(nr);
                }
                else
                if(op>7 || op<0)
                {
                    cout << "Ati apasat un buton gresit" << '\n';
                }
                else
                if(op<=2)
                {
                   break;
                }

                afis_op();
                cin>> op;
                cin.get();
            }

            if(op==0)
            {
                cout << "Exit";
                break;
            }
            else
            if(op==1)
            {
                ok3=1;
                ok2=ok1=0;
                cout << '\n';
                cout << "Atentie!: Lungimea unei liste de clienti a fost deja introdusa" << '\n';
                cout << "Va rog alegeti din nou optiunea 1 pentru a reintroduce lungimea sau orice altceva pentru resetarea programului" << '\n';
            }
            else
            if(op==2)
            {
                ok3=1;
                ok2=ok1=0;
                cout << '\n';
                cout << "Atentie!: O lista de clienti a fost deja creata" << '\n';
                cout <<  "Va rog alegeti din nou optiunea 2 pentru a recrea lista, 1 pentru a-i modifica inainte lungimea sau orice altceva pentru resetarea programului" << '\n';
            }
            else
            if(op>7 || op<0)
            {
                cout << '\n';
                cout << "Ati apasat un buton gresit" << '\n';
            }
        }
        else
        if(op==2 && ok1==0)
        {
            cout << " Nu ati introdus inca lungimea listei" << '\n';
        }
        else
        if(op>7 || op<0)
        {
            cout << '\n';
            cout << "Ati apasat un buton gresit" << '\n';
        }
        else
        if(op==0)
        {
            cout << "Exit" << '\n';
            break;
        }

        if(op==3)
        {
            if(ok3==1)
            {
                cout << " Exit" << '\n';
                break;
            }
            else
            {
                if(ok1==0 || ok2==0)
                    cout << "Nu se poate afisa, lista e goala sau nedefinita" << '\n';
                else
                cout << o1;
            }
        }
        if(op==4)
        {
            if(ok3==1)
            {
                cout << "Exit" << '\n';
                break;
            }
            else
            {
                if(ok1==0 || ok2==0)
                    cout << "Nu se poate afisa, lista este goala sau nedefinita " << '\n';
                else
                {
                    cout << '\n';
                    o1.clienti_premium();
                }
            }
        }
        if(op==5)
        {
            if(ok3==1)
            {
                cout << "Exit" << '\n';
                break;
            }
            else
            {
                if(ok1==0 || ok2==0)
                    cout << "Nu se poate afisa, lista este goala sau nedefinita " << '\n';
                else
                {
                    cout << '\n';
                    o1.castig_total();
                }
            }
        }
        if(op==6)
        {
            if(ok3==1)
            {
                cout << "Exit" << '\n';
                break;
            }
            else
            {
                if(ok1==0 || ok2==0)
                    cout << "Nu se poate insera, lista este goala sau nedefinita " << '\n';
                else
                {
                    cout << '\n';
                    o1.intermediar();
                }
            }
        }
        if(op==7)
        {
            if(ok3==1)
            {
                cout << "Exit" << '\n';
                break;
            }
            else
            {
                if(ok1==0 || ok2==0)
                    cout << "Nu se poate sterge, lista este goala sau nedefinita " << '\n';
                else
                {
                    cout << '\n';
                    cout << "Introduceti indicele elementului:" << '\n';
                    cin >> nr;
                    cin.get();
                    o1.intermediar2(nr);
                }
            }
        }

        afis_op();
        cin>>op;
        cin.get();

        if(op==0)
            break;

    }
    return 0;
}
