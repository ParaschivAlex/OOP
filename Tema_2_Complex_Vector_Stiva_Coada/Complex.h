#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
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


#endif // COMPLEX_H_INCLUDED
