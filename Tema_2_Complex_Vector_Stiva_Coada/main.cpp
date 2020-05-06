#include <iostream>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"
#include "Coada.h"
using namespace std;


int main()
{
    int optiune2=2,optiune=1;
    while(optiune2==2)
    {
        cout<<"Ce operatii doriti sa realizati?\n";
        cout<<"1.Pentru operatii cu stive de numere complexe\n";
        cout<<"2.Pentru operatii cu cozi de numere complexe\n";
        cin>>optiune;
        if(optiune==1)
        {
            /*Stiva S;
            Complex v[4];
            citire_n_obiecte(4,v);
            S.push(v[0]);
            S.push(v[1]);
            S.push(v[2]);
            cout<<S<<endl;
            S.pop();
            cout<<S<<endl;
            S.push(v[3]);
            cout<<S<<endl;*/
            Stiva S;
            Complex a,b,c,d;
            a.set_real(1);
            a.set_imaginar(1);
            b.set_real(2);
            b.set_imaginar(2);
            c.set_real(3);
            c.set_imaginar(3);
            d.set_real(4);
            d.set_imaginar(4);
            S.push(a);
            S.push(b);
            S.push(c);
            cout<<S<<endl;
            S.pop();
            cout<<S<<endl;
            S.pop();
            cout<<S<<endl;
            S.push(d);
            cout<<S<<endl;
            /*bool okstiva=verificarestiva(2,S);
            cout<<okstiva<<endl;*/
        }
        if(optiune==2)
        {
            Coada C;
            Complex v[4];
            citire_n_obiecte(4,v);
            C.push(v[0]);
            C.push(v[1]);
            C.push(v[2]);
            cout<<C<<endl;
            C.pop();
            cout<<C<<endl;
            C.push(v[3]);
            cout<<C<<endl;
            /*bool okc=verificarecoada(2,C);
            cout<<okc<<endl;*/
            /*
            Coada C;
            Complex a,b,c,d;
            a.set_real(1);
            a.set_imaginar(1);
            b.set_real(2);
            b.set_imaginar(2);
            c.set_real(3);
            c.set_imaginar(3);
            d.set_real(4);
            d.set_imaginar(4);
            C.push(a);
            C.push(b);
            C.push(c);
            cout<<C<<endl;
            C.pop();
            cout<<C<<endl;
            C.pop();
            cout<<C<<endl;*/
        }
        cout<<"\nMai doriti alte operatii?\n";
        cout<<"\n1.NU         2.DA\n";
        cin>>optiune2;

    }
    return 0;
}


/*

#include <iostream>
#include <bits/stdC++.h>
using namespace std;

class Complex
{
private:
    double real;
    double imaginar;

public:
    double get_imaginar() const;
    double get_real() const;

    void set_imaginar(double img);
    void set_real(double rl);

    Complex();///constr.
    Complex(double, double); ///constr. cu parametrii
    Complex(const Complex &other); ///constr. de copiere

    Complex operator=(const Complex &c);///supraincarcare =

    virtual ~Complex();///destr.

    friend ostream &operator <<(ostream &out, const Complex &c);
    friend istream &operator >>(istream &in, Complex &c);

    friend class Vector;
};

double Complex::get_imaginar()const
{
    return imaginar;
}

double Complex::get_real()const
{
    return real;
}

void Complex::set_imaginar(double img)
{
    imaginar=img;
}

void Complex::set_real(double rl)
{
    real=rl;
}

Complex::Complex()///constr.
{
    real=0;
    imaginar=0;

}

Complex::Complex(double re, double im)///constr. de initializare parametrizat
{
    real=re;
    imaginar=im;
}

Complex::Complex(const Complex &other)///constr. de copiere
{
    //cout<<"Copiere"<<endl;
    real=other.real;
    imaginar=other.imaginar;
}

Complex::~Complex()///destr.
{
    ///cout<<"Destructor"<<endl;
}

ostream &operator << (ostream &out,const Complex &c)
{
    if(c.imaginar==0 && c.real==0)///0+0i
        out<<0<<endl;
    else if(c.imaginar==0 && c.real!=0)///a+0i
        out<<c.get_real()<<endl;
    else if(c.imaginar==1 && c.real!=0)///a+i
        out<<c.get_real()<<" +i"<<endl;
    else if(c.imaginar==-1 && c.real!=0)///a-i
        out<<c.get_real()<<" -i"<<endl;
    else if(c.imaginar!=0 && c.real==0)
    {
        if(c.imaginar==-1)///-i
            out<<"-i"<<endl;
        else if(c.imaginar==1)///+i
            out<<"i"<<endl;
        else
            out<<c.imaginar<<"i"<<endl;
    }
    else if(c.imaginar>0)
        out<<c.get_real()<<" +"<<c.get_imaginar()<<"i"<<endl;
    else
        out<<c.get_real()<<" "<<c.get_imaginar()<<"i"<<endl;
    return out;
    return out;
}

istream &operator >> (istream &in, Complex &c)
{
    int partea_reala, partea_imaginara;
    in >> partea_reala>> partea_imaginara;
    c.set_imaginar(partea_imaginara);
    c.set_real(partea_reala);
    return in;
}

Complex Complex::operator=(const Complex &c)///supraincarcare =
{
    real=c.real;
    imaginar=c.imaginar;
    return *this;
}

class Vector
{
    int dim;
    Complex *v;
public:
    Vector();///constr.
    Vector(int, Complex*);///constr cu param.
    virtual ~Vector();///destr
    Vector(const Vector &vec);///constr copiere

    Vector operator=(const Vector &vec);///supraincarcare =

    virtual void push(Complex a, int pos)///adaugare element in vector
    {
        dim++;
        Complex *a2=new Complex[dim];

        for(int i=0;i<dim;i++){
            a2[i]=v[i];
        }
        for(int i=dim-1;i>=pos+1;i--){
            a2[i]=a2[i-1];
        }
        a2[pos]=a;
        delete []v;
        v=a2;
    }

    virtual void pop(int pos, int &dim)///stergere element din vector
    {
        int i;
        for(i=pos;i<dim-1;i++)
        {
            v[i]=v[i+1];
        }
        dim--;
    }

    void citire_n_obiecte(int n, Complex *v);

    friend std::istream& operator>>(std::istream &input, Vector &vec)///Functie de citire dim numere
    {
        cout<<"Introduceti cate numere doriti sa aveti: ";
        input>>vec.dim;
        try
        {
            vec.v=new Complex[vec.dim];
        }
        catch(bad_alloc)
        {
            cout<<"Eroare la alocare"<<endl;
            exit(EXIT_FAILURE);
        }
        for (int i=0;i<vec.dim;i++)
            input>>vec.v[i];
        return input;
    }

    friend std::ostream& operator<<(std::ostream &output, Vector &vec)///Functie de afisare
    {
        for(int i=0;i<vec.dim;i++)
            output << vec.v[i];
        if(vec.dim==0)
            cout<<"Lista este goala"<<endl;
        return output;
    }

    void setter_poz(Complex a,int i);
    Complex getter_poz(int i);
    void setter_dim(int n);
    int getter_dim();

};

void Vector::citire_n_obiecte(int n, Complex *v){
	for (int i=0;i<n;i++)
    {
        Complex c;
		cin>>c;
		v[i]=c;
    }
}


void Vector::setter_poz(Complex a, int i)
{
    v[i]=a;
}

void Vector::setter_dim(int n)
{
    dim=n;
}

int Vector::getter_dim()
{
    return dim;
}

Complex Vector::getter_poz(int i)
{
    return v[i];
}

Vector::Vector()///constr.
{
    dim=0;
    v=NULL;
}

Vector::Vector(int nr, Complex *j)///constr cu param.
{
    dim=nr;
    try
    {
        v=new Complex[dim];
    }
    catch(bad_alloc )///try-catch pentru alocare nereusita
    {
        cout<<"Eroare la alocare"<<endl;
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<dim; i++)
        v[i]=j[i];
}

Vector::~Vector()///destr.
{
    dim=0;
    delete []v;
}

Vector::Vector(const Vector &vec)///constr. de copiere
{
    dim=vec.dim;
    try
    {
        v=new Complex[dim];
    }
    catch(bad_alloc)///try-catch pentru alocare nereusita
    {
        cout<<"Eroare la alocare"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<dim; i++)
        v[i]=vec.v[i];
}

Vector Vector::operator=(const Vector &vec)///supraincarcare =
{
    dim=vec.dim;
    try
    {
        v=new Complex[dim];
    }
    catch(bad_alloc)///try-catch pentru alocare nereusita
    {
        cout<<"Eroare la alocare"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<dim; i++)
        v[i]=vec.v[i];
    return *this;
}

class Stiva: public Vector
{
private:
    int capacitate;
    int dimen;
    Complex *v1;

public:
    Stiva():Vector() {}; ///constr.
    Stiva(int x);
    ~Stiva() {delete[] v1;}
    Stiva(const Stiva &s):Vector(s) {}; ///constr de copiere
    friend istream & operator >>(istream & in, Stiva &v);
    friend ostream & operator <<(ostream & out, Stiva &v);
    using Vector::operator=;
    void push(Complex a); ///fct. adaugare in stiva
    void pop(); ///scoatere element din stiva

    Complex varf();

};

istream & operator >>(istream & in, Stiva &v)
{
    Complex aux;
    int i;
    in>>v.dimen;
    for(i=0;i<v.dimen;i++)
    {
        in>>aux;
        v.push(aux);
    }
    return in;
}

ostream & operator <<(ostream & out, Stiva &v)
{
    for(int i=v.dimen-1;i>=0;i--){
        out<<v.v1[i];
    }
    out<<'\n';
    return out;
}

Stiva::Stiva(int x=10)
{
    dimen=0;
    capacitate=x;
    v1=new Complex[10];
}

Complex Stiva::varf()
{
    if(v1==NULL)
        cout<<"GG";
    return v1[dimen-1];

}

void Stiva::push(Complex a)
{
    if(dimen>capacitate)
    {
        cout<<"Overflow";
        exit(0);
    }
    else
    {
        Complex *v2=new Complex[dimen+1];
        for(int i=0;i<dimen;i++){
            v2[i]=v1[i];
        }
        v2[dimen]=a;
        dimen++;
        delete[]v1;
        v1=v2;
    }
}
void Stiva::pop()
{
    if(dimen==0)
    {
        cout<<"Underflow";
        exit(0);
    }
    else
    {
        Complex *v2=new Complex[dimen-1];
        for(int i=0;i<dimen-1;i++)
        {
            v2[i]=v1[i];
        }
        delete[]v1;
        dimen--;
        v1=v2;
    }
}

class Coada: public Vector
{
private:
    int capacitate;
    int dimen;
    Complex *v1;

public:
    Coada():Vector(){}; ///constr.
    Coada(int x);
    ~Coada(){} ///destr.
    Coada(const Coada &c):Vector(c){}; ///constr. de copiere
    friend istream & operator >>(istream & in, Coada &v);
    friend ostream & operator <<(ostream & out, Coada &v);
    Coada operator=(const Coada &c) ///supraincarcare =
    {
        Vector::operator=(c);
        return *this;
    }
    void push(Complex a); ///la fel
    void pop(); ///pop element

    Complex fata();

};

Coada::Coada(int x=10)
{
    dimen=0;
    capacitate=x;
    v1=NULL;
}

istream & operator >>(istream & in, Coada &v)
{
    Complex aux;
    int i;
    for(i=0;i<v.dimen;i++)
    {
        in>>aux;
        v.push(aux);
    }
    return in;
}
ostream & operator <<(ostream & out,Coada &v)
{
    for(int i=v.dimen-1;i>=0;i--){
        out<<v.v1[i];
    }
    out<<'\n';
    return out;
}

Complex Coada::fata()
{
    return v1[0];
}

void Coada::push(Complex a)
{
    if(dimen==capacitate)
    {
        cout<<"Overflow";
        exit(0);
    }
    else
    {
        Complex *v2=new Complex[dimen+1];
        for(int i=0;i<dimen;i++)
        {
            v2[i]=v1[i];
        }
        v2[dimen]=a;
        dimen++;
        delete[]v1;
        v1=v2;
    }

}
void Coada::pop()
{
    if(dimen==0)
    {
        cout<<"Underflow";
        exit(0);
    }
    else
    {
        Complex *v2=new Complex[dimen-1];
        for(int i=0;i<dimen-1;i++)
        {
            v2[i]=v1[i+1];
        }
        delete[]v1;
        dimen--;
        v1=v2;
    }

int main()
{
   int optiune2=2,optiune=1;
        while(optiune2==2)
            {
            cout<<"Ce operatii doriti sa realizati?\n";
            cout<<"1.Pentru operatii cu stive de numere complexe\n";
            cout<<"2.Pentru operatii cu cozi de numere complexe\n";
            cin>>optiune;
            if(optiune==1)
                {
                   Stiva S;
                   Complex a,b,c,d;
                   a.set_real(1);
                   a.set_imaginar(1);
                   b.set_real(2);
                   b.set_imaginar(2);
                   c.set_real(3);
                   c.set_imaginar(3);
                   d.set_real(4);
                   d.set_imaginar(4);
                   S.push(a);
                   S.push(b);
                   S.push(c);
                   cout<<S;
                   S.pop();
                   cout<<S;
                   S.pop();
                   cout<<S;
                }
            if(optiune==2)
               {
                   Coada C;
                   Complex v[4];
                   citire_n_obiecte(4,v);
                   C.push(v[1]);
                   C.push(v[2]);
                   C.push(v[3]);
                   cout<<C;
                   C.pop();
                   cout<<C;
                   C.push(v[4]);
                   cout<<C;
               }
           else
                {
                    cout<<"\nNu ati inserat 1 sau 2\n";
                }
           cout<<"\nMai doriti alte operatii?\n";
           cout<<"\n1.NU         2.DA\n";
           cin>>optiune2;
           if(optiune2==1)
                {
                    return 0;
                }
           }
}
*/
