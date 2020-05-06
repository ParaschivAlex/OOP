#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include <iostream>
#include <bits/stdC++.h>
#include "Complex.h"
#include "Vector.h"
using namespace std;

class Coada: public Vector
{
private:
    int capacitate;
    int dimen;
    Complex *v3;

public:

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

    friend bool verificarecoada();

};

Coada::Coada(int x=10)
{
    dimen=0;
    capacitate=x;
    v3=NULL;
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
        out<<v.v3[i];
    }
    out<<'\n';
    return out;
}

Complex Coada::fata()
{
    return v3[0];
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
            v2[i]=v3[i];
        }
        v2[dimen]=a;
        dimen++;
        delete[]v3;
        v3=v2;
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
            v2[i]=v3[i+1];
        }
        delete[]v3;
        dimen--;
        v3=v2;
    }
}

bool verificarecoada(int dimen, Complex *v3)
{
    for(int i=0;i<dimen;i++)
        if (v3[i].get_real()!=0)
            return 0;
    return 1;
}

#endif // COADA_H_INCLUDED
