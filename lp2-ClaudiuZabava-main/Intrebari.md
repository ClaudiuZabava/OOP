### Intrebarea 1:  Daca facem downcasting (dynamic_cast), atunci cu un obiect al clasei Baza putem accesa metodele unei clase Derivate ?

Nu sunt sigur ca am inteles pe deplin procedeul downcasting (dynamic_cast). In consecinta nici la proiectul trimis pentru feedback nu m-am jucat cu aceasta notiune intrucat imi scapa de sub control pe un numar mai mare de clase.
Intrebarea nu este cel mai bine structurata asa ca va pot arata un exemplu: 

```
class A{

protected:
    int x;

public:

    A()
    {
        x=0;
    }

    A(int x1)
    {
        x=x1;
    }

    A(const A &o1)
    {
        x=o1.x;
    }

    A &operator=(const A &o1)
    {
      x=o1.x;
      return *this;
    }

    int get_x() const
    {
        return x;
    }

    virtual ~A() = default;
};


class B: public A{
protected:
    float y=1;

public:

    B(): A()
    {
        y=0.0;
    }

    B(int x1, float y1): A(x1)
    {
        y=y1;
    }

    B(const B &o2): A(o2)
    {
        y=o2.y;
    }

    B &operator=(const B &o2)
    {
        y=o2.y;
        A::operator=(o2);
        return *this;
    }

    float get_y() const
    {
        return y;
    }
};
```
Avem 2 clase diferite, una mostenind pe cealalta.
Am echipat clasele cu constructori, operator= etc..
 Intrebarea mea intervine in momentul in care , din diferite motive, pentru un obiect A o1; as vrea sa apelez metoda get_y din B. (sau prin obiectul o1 sa ajung la parametrul y al clasei B) 
 ###### M-am gandit ca ar merge dynamic_cast, dar nu am reusit sa implementez corect ceea ce voiam: 
 ```
   
    B *o2;
    A* o1 = dynamic_cast<B*>(o2);
    cout << o1->get_y();  /// nu sunt sigur ca asta ar merge exact cum am descris in intrebare.
 ```
 
 ##### Am incercat sa folosesc o functie virtuala pura, pare ca a mers bine, dar nu stiu daca e un good practice:
 
 ```
     In Interiorul clasei A, la sfarsit am definit functia :
     
         virtual float get_y() const = 0;
         .
         .
         .
         
     Apoi am inlocuit-o in clasa B cu:
         float get_y() const override
         {
             return y;
         } 
        
Iar in main apelez ceva de genul: 

A* o1=new B*(constructor..) /// un fel de downcasting
cout << o1->get_y();
 ```
 
##### Este corecta abordarea cu functie virtuala ? sau trebuie obligatoriu un dynamic_cast pentru a face asta ?
 
 
 
 Asemanator, in enuntul temei proiectului mi se cere o clasa 'abonat' ce are ca parametru un obiect din alta clasa (din clasa 'abonament'; clasa abonament este clasa parinte a lui 'abonament_premium')
 
 Clasa 'abonament' are parametrul pret_abonament, iar clasa derivata 'abonament_premium' are parametrul reducere. Mi se cere ca printr-un obiect de tip 'abonament' sa aflu valoarea lui reducere ( care nu e in 'abonament', e in derivata sa).
 
 Am incercat sa aplic dynamic_cast insa nu mi-am dat seama cum ar trebui sa fac asta in conditiile actuale. Cumva , prin niste functii virtuale ,parea ca are acces la reducere, dar pointerul pentru obiectul clasei 'abonament' se pierdea. 
 
Ramanand fara idei in acel moment, am considerat ca , din moment ce abonament_premium este derivat din abonament, el oricum contine to ce e in abonament, asa ca am gasit mai adecvat sa inlocuiesc obiectul de tip abonament cu unul de tip abonament_premium ( pe principiul abonament_premium IS-A abonament)

Explicatia de aici este destul de proasta , o sa vedeti in cod linia cu pricina, e comentata .
 
 
