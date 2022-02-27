#include <iostream>
#include <cmath>
using namespace std;
class multimi{

private:

    int cardinal; /// citeste README: -> Parametrii clasei
    int modulo;
    int *elemente;

    void set_cardinal(int i); /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt1.

    void set_modulo(int i);

    void set_element(int i, int j, int mod);

    void set_new_element(int i);

    void set_new_element_null();

    void set_new_pointer_element(int *new_pointer);

public:

    multimi() /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt2.
    {
        set_cardinal(0);
        set_modulo(0);
        set_new_element_null();
    }


    multimi(int v[10001], int n, int mod){
        int i,j,k;

        for(i=1;i<=n;++i)
        {
            if(v[i]<0)
                v[i]=mod+v[i]%mod;
            else
                v[i]=v[i]%mod;
        }

        for(i=1;i<n;++i)
        {
            for(j=i+1;j<=n;++j)
                if(v[i]==v[j])
                {
                    for(k=j;k<n;++k)
                        v[k]=v[k+1];
                    n--;
                    j--;
                }
        }

        set_cardinal(n);
        set_modulo(mod);
        set_new_element(get_cardinal()+1);
        for(i=1;i<=get_cardinal();++i)
            set_element(i,v[i],mod);
    }


    multimi(const multimi &p2)
    {
        delete[] elemente;
        set_new_pointer_element(p2.elemente);
        set_cardinal(p2.get_cardinal());
        set_modulo(p2.get_modulo());

    }


    multimi &operator=(const multimi &p2)
    {
        int i, *elemente_locale=new int[p2.get_cardinal()+1];

        for(i=1;i<=p2.get_cardinal();++i)
            elemente_locale[i]=p2.get_element(i);
        delete[] elemente;
        set_new_pointer_element(elemente_locale);
        set_cardinal(p2.get_cardinal());
        set_modulo(p2.get_modulo());
        return *this;
    }


    multimi &operator+=(const multimi &p2) /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt3.5
    {
        int i, a[10001],m=0;
        if(get_cardinal()!=p2.get_cardinal())
        {
            cout << '\n';
            cout << "Eroare de operator: ati introdus multimi de cardinale sau modulo diferite" << '\n';
        }
        else
        if(get_modulo()!=p2.get_modulo())
        {
            cout << '\n';
            cout << "Eroare de operator: ati indrodus multimi de cardinale sau modulo diferite" << '\n';
        }
        else
        {
            for(i=1;i<=p2.get_cardinal();++i)
            {
                m++;
                a[m]=get_element(i)+p2.get_element(i);
                a[m]=a[m] % p2.get_modulo();
            }
            *this=multimi(a,m,p2.get_modulo());    /// pentru a evita cazurile in care apar dubluri in urma adunarii din cauza modulo, se recreaza multimea curenta doar cu elemente distincte
        }
        return *this;
    }


    int get_cardinal() const; /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt1.

    int get_modulo() const;

    int get_element(int i) const;

    void afisare(); /// functie pentru afisarea elementelor multimii

    void min3(); /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Metodele clasei.

    void reuniune(const multimi &p2, multimi &p3);

    void intersectie(const multimi &p2, multimi &p3);

    void diferenta(const multimi &p2, multimi &p3);

    ~multimi() /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt4.
    {
        delete[] elemente; /// Este nevoie sa eliberam memoria deoarece am declarat dinamic parametrul elemente pt fiecare obiect.
    }

};

int multimi::get_cardinal() const /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt1.
{
    return cardinal;
}

int multimi::get_modulo() const
{
    return modulo;
}

int multimi::get_element(int i) const
{
    return elemente[i];
}

void multimi::set_cardinal(int i)
{
    cardinal=i;
}

void multimi::set_modulo(int i)
{
    modulo=i;
}

void multimi::set_element(int i, int j, int mod)
{
    if(j<0)
        elemente[i]=mod+j%mod;
    else
        elemente[i]=j%mod;
}

void multimi::set_new_element(int i)
{
    elemente=new int[i];
}

void multimi::set_new_pointer_element(int *new_pointer)
{
    elemente=new_pointer;
}

void multimi::set_new_element_null()
{
    elemente=NULL;
}


void multimi::afisare() /// Functie pentru parcurgerea si afisarea elementelor unui obiect al clasei
{
    int i;
    cout << '\n';
    if(get_cardinal()<=0)
    cout << "{multime vida}" << '\n';
    else
    {
        cout << "{";
        for(i=1;i<get_cardinal();++i)
            cout << get_element(i) << ", ";
        cout << get_element(get_cardinal()) << "}";
        cout << '\n';
    }
}

void multimi::min3() /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt3.1
    {
        int i,minim1,minim2,minim3=9999999;
        cout << '\n';
        cout << "Al 3-lea minim este : ";
        minim1=minim2=minim3;
        if(get_cardinal()<3)
            cout << " Multimea nu are destule elemente" << '\n';
        else
        {
            for(i=1;i<=get_cardinal();++i)
                if(get_element(i)<minim3)
                {
                    minim1=minim2;
                    minim2=minim3;
                    minim3=get_element(i);
                }
                else
                if(get_element(i)<minim2)
                {
                    minim1=minim2;
                    minim2=get_element(i);
                }
                else
                if(get_element(i)<minim1)
                minim1=get_element(i);
            cout << minim1 << '\n';
        }
    }
void multimi::reuniune(const multimi &p2, multimi &p3) /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt3.2
    {
        int i,j,a[10001],m=0;
        cout << '\n';
        cout << "Reuniunea celor 2 multimi este :";
        i=1;
        j=1;
        if(get_cardinal()==0)
        {
            p3=p2;
            p3.afisare();
        }
        else
        if(p2.get_cardinal()==0)
        {
            p3=*this;
            p3.afisare();
        }
        else
        if(get_modulo()!=p2.get_modulo())
            cout << " Nu se poate realiza reuniune intre multimi cu modulo diferite" << '\n';
        else
        if(get_cardinal()==0 && p2.get_cardinal()==0)
            cout << "{ multime vida }" << '\n';
        else
        {
            while(i<=get_cardinal())
            {
                m++;
                a[m]=get_element(i);
                i++;
            }
            while(j<=p2.get_cardinal())
            {
                m++;
                a[m]=p2.get_element(j);
                j++;
            }
            p3=multimi(a,m,get_modulo());
            p3.afisare();
        }
    }
void multimi::intersectie(const multimi &p2, multimi &p3) /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt3.3
    {
        int i,j,a[10001],m=0,ok=0;
        cout << '\n';
        cout << "Intersectia celor 2 multimi este: ";
        if(get_cardinal()==0)
            cout <<"{ multime vida }" << '\n';
        else
        if(p2.get_cardinal()==0)
            cout <<"{ multime vida }" << '\n';
        else
        if(get_modulo()!=p2.get_modulo())
            cout << " Nu se poate realiza intersectia intre multimi cu modulo diferite" << '\n';
        else
        {
            for(i=1;i<=get_cardinal();++i)
            {
                for(j=1;j<=p2.get_cardinal();++j)
                    if(get_element(i)==p2.get_element(j))
                    {
                        ok=1;
                        m++;
                        a[m]=get_element(i);
                        break;
                    }
            }
            if(ok==0)
                cout <<"{ multime vida }" << '\n';
            else
            {
                p3=multimi(a,m,get_modulo());
                p3.afisare();
            }
        }
    }
void multimi::diferenta(const multimi &p2, multimi &p3) /// Pentru a intelege urmatoarele linii de cod, citeste README: -> Pt3.4
    {
        int i,j,a[10001],m=0,ok1,ok2=0;
        cout << '\n';
        if(get_cardinal()==0)
            cout << "Diferenta celor 2 multimi este: { multime vida }" << '\n';
        else
        if(p2.get_cardinal()==0)
        {
            cout << "Diferenta celor 2 multimi este:";
            p3=*this;
            p3.afisare();
        }
        else
        if(get_modulo()!=p2.get_modulo())
            cout << " Nu se poate realiza diferenta intre multimi cu modulo diferite" << '\n';
        else
        {
            cout << "Diferenta celor 2 multimi este:";
            for(i=1;i<=get_cardinal();++i)
            {
                ok1=1;
                for(j=1;j<=p2.get_cardinal();++j)
                    if(get_element(i)==p2.get_element(j))
                    {
                        ok1=0;
                        break;
                    }
                if(ok1==1)
                {
                    ok2=1;
                    m++;
                    a[m]=get_element(i);
                }
            }
            if(ok2==0)
                cout << "{ multime vida }" << '\n';
            else
            {
                p3=multimi(a,m,get_modulo());
                p3.afisare();
            }
        }
    }

void citire(int v[10001], int &n, int &mod, int indice) /// functie de citire interactiva
    {
        int i;
        cout << " Lungimea vectorului initial asociat multimii "<<indice<<" este:" << '\n';
        cin >> n;
        if(n<=0)
            cout << " Elementele vectorului initial asociat multimii "<<indice<<" sunt: 0 elemente" << '\n';
        else
            cout << " Elementele vectorului initial asociat multimii "<<indice<<" sunt:" << '\n';
        for(i=1;i<=n;++i)
            cin >> v[i];
        cout << " Modulo: "<< '\n';
        if(n<=0)
            cout << " multimea este vida, nu este necesar"<< '\n';
        else
            cin >> mod;
        cout << '\n';
    }
int main()
{
    int i,v[10001],n,mod,x,y;

    citire(v,n,mod,1);
    multimi multime1;
    multime1=multimi(v,n,mod);

    citire(v,n,mod,2);
    multimi multime2(v,n,mod);

    cout << "Multimile obtinute sunt:" << '\n';
    multime1.afisare();
    multime2.afisare();

    multime1.min3();
    multime2.min3();

    multimi multime3;
    multime1.reuniune(multime2, multime3);

    multimi multime4;
    multime2.intersectie(multime1, multime4);

    multimi multime5;
    multime1.diferenta(multime2, multime5);

    multimi multime6;
    multime2.diferenta(multime1, multime6);


    cout << '\n';
    cout << "Rezultatul operatiei '+=' este";
    multime1+=multime2;
    multime1.afisare(); /// afisam multimea1 in urma operatiei '+=' pentru a vedea rezultatul (daca operatia nu s-a putut desfasura, multimea1 e intacta)

    return 0;
}
