#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED
#include <iostream>
#include <bits/stdC++.h>
#include "Complex.h"
#include "Vector.h"
using namespace std;

class Stiva: public Vector
{
private:
    int capacitate;
    int dimen;
    Complex *v1;

public:

    Stiva(int x);
    ~Stiva() {delete[] v1;}
    Stiva(const Stiva &s):Vector(s) {}; ///constr de copiere
    friend istream & operator >>(istream & in, Stiva &v);
    friend ostream & operator <<(ostream & out, Stiva &v);
    using Vector::operator=;
    void push(Complex a); ///fct. adaugare in stiva
    void pop(); ///scoatere element din stiva

    Complex varf();
    friend bool verificarestiva();

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

bool verificarestiva(int dimen, Complex *v1)
{
    for(int i=0;i<dimen;i++)
        if (v1[i].get_real()!=0)
            return 0;
    return 1;
}

#endif // STIVA_H_INCLUDED
