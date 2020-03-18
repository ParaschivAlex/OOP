#include "Complex.h"
#include <cmath>
#include <bits/stdC++.h>
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

Complex::Complex(double x, double y)///constr. de initializare
{
    real=x;
    imaginar=y;
}

Complex::Complex(const Complex &other)///constr. de copiere
{
    //cout<<"Copiere"<<endl;
    real=other.real;
    imaginar=other.imaginar;
}

Complex operator +(Complex a, Complex b)///fct prieten complex-complex adunare
{
    Complex c;
    c.set_imaginar(a.imaginar+b.imaginar);
    c.set_real(a.real+b.real);
    return c;
}

Complex operator +(double a, Complex b)
{
    Complex c;
    c.set_imaginar(b.imaginar);
    c.set_real(a+b.real);
    return c;
}

Complex operator +(Complex a, double b)
{
    Complex c;
    c.set_imaginar(a.imaginar);
    c.set_real(a.real+b);
    return c;
}

Complex operator +(Complex a)///nr insusi de revazut
{
    Complex c;
    c.set_real(a.real+a.real);
    c.set_imaginar(a.imaginar+a.imaginar);
    return c;
}

Complex operator -(Complex a, Complex b)
{
    Complex c;
    c.set_imaginar(a.imaginar-b.imaginar);
    c.set_real(a.real-b.real);
    return c;
}

Complex operator -(double a, Complex b)
{
    Complex c;
    c.set_imaginar(b.imaginar);
    c.set_real(a-b.real);
    return c;
}

Complex operator -(Complex a, double b)
{
    Complex c;
    c.set_imaginar(a.imaginar);
    c.set_real(a.real-b);
    return c;
}

Complex operator -(Complex a) ///OPUS
{
    Complex c;
    c.set_real(-a.real);
    c.set_imaginar(-a.imaginar);
    return c;
}

Complex operator *(Complex a, Complex b)
{
    Complex c;
    c.set_imaginar(a.real*b.imaginar+a.imaginar*b.real);
    c.set_real(a.real*b.real-a.imaginar*b.imaginar);
    return c;
}

Complex operator *(double a, Complex b)
{
    Complex c;
    c.set_imaginar(a*b.imaginar);
    c.set_real(a*b.real);
    return c;
}

Complex operator *(Complex a, double b)
{
    Complex c;
    c.set_imaginar(a.imaginar*b);
    c.set_real(a.real*b);
    return c;
}

Complex operator /(Complex a, Complex b)
{
    int div=(b.real*b.real) + (b.imaginar*b.imaginar);
    Complex c;
    c.set_real(a.real*b.real+a.imaginar*b.imaginar);
    c.real/=div;
    c.set_imaginar(a.imaginar*b.real-a.real*b.imaginar);
    c.imaginar/=div;
    return c;
}

Complex operator /(Complex a, double b)
{
    Complex c;
    c.set_real(a.real/b);
    c.set_imaginar(a.imaginar/b);
    return c;
}

Complex operator /(double a, Complex b)
{
    int div=(b.real*b.real) + (b.imaginar*b.imaginar);
    Complex c;
    c.set_real(a*b.real);
    c.real/=div;
    c.set_imaginar(a*(-b.imaginar));
    c.imaginar/=div;
    return c;
}

Complex operator ^(Complex a, int b)
{
    Complex c;
    if (b==0)
    {
        c.set_imaginar(0);
        c.set_real(1);
    }
    else if (b==1)
    {
        c.set_imaginar(a.imaginar);
        c.set_real(a.real);
    }
    else
    {
        c.set_imaginar(a.real*a.imaginar+a.imaginar*a.real);
        c.set_real(a.real*a.real-a.imaginar*a.imaginar);
        //cout<<"real: "<<c.real<<"   ----    imaginar: "<<c.imaginar<<endl;
        for(int i=2; i<b; i++)
        {
            Complex aux;
            aux.set_imaginar(c.real*a.imaginar+c.imaginar*a.real);
            aux.set_real(c.real*a.real-c.imaginar*a.imaginar);
            c.set_imaginar(aux.imaginar);
            c.set_real(aux.real);
            //cout<<"real: "<<c.real<<"   ----    imaginar: "<<c.imaginar<<endl;
        }
    }
    return c;
}

Complex &operator +=(Complex &a, const Complex &b)
{
    a.real+=b.real;
    a.imaginar+=b.imaginar;
    return a;
}

Complex &operator +=(Complex &a, double b)
{
    a.real+=b;
    return a;
}

Complex &operator -=(Complex &a, const Complex &b)
{
    a.real-=b.real;
    a.imaginar-=b.imaginar;
    return a;
}

Complex &operator -=(Complex &a, double b)
{
    a.real-=b;
    return a;
}

Complex &operator *=(Complex &a, const Complex &b)
{
    a.real=a.real*b.imaginar+a.imaginar*b.real;
    a.imaginar=a.real*b.real-a.imaginar*b.imaginar;
    return a;
}

Complex &operator *=(Complex &a, double b)
{
    a.real=a.real*b;
    a.imaginar=a.imaginar*b;
    return a;
}

Complex &operator /=(Complex &a, const Complex &b)
{
    int div=(b.real*b.real) + (b.imaginar*b.imaginar);
    a.real=a.real*b.real+a.imaginar*b.imaginar;
    a.real/=div;
    a.imaginar=a.imaginar*b.real-a.real*b.imaginar;
    a.imaginar/=div;
    return a;
}

Complex &operator /=(Complex &a, double b)
{
    a.real=a.real/b;
    a.imaginar=a.imaginar/b;
    return a;
}

bool operator ==(const Complex &a, const Complex &b)
{
    if (a==b)
        return 1;
    return 0;
}

bool operator ==(double a, const Complex &b)
{
    if (a==b.real)
        if(b.imaginar==0)
            return 1;
    return 0;
}

bool operator ==(const Complex &a, double b)
{
    if (a.real==b)
        if(a.imaginar==0)
            return 1;
    return 0;
}

bool operator !=(const Complex &a, const Complex &b)
{
    if (a!=b)
        return 1;
    return 0;
}

bool operator !=(double a, const Complex &b)
{
    if (a!=b.real)
        return 1;
    if(b.imaginar!=0)
        return 1;
    return 0;
}

bool operator !=(const Complex &a, double b)
{
    if (a.real==b)
        return 1;
    if(a.imaginar!=0)
        return 1;
    return 0;
}

double abs(Complex a)
{
    return sqrt(a.real*a.real+a.imaginar*a.imaginar);

}

Complex sqrt(Complex a)
{
    complex<double> aux=sqrt(complex <double>(a.real,a.imaginar));
    double real=aux.real();
    double imag=aux.imag();
    return Complex(real,imag);
}

ostream &operator << (ostream &out,const Complex &c)
{
    if(c.imaginar==0 && c.real!=0)///a+0i
        out<<c.get_real()<<endl;
    else if(c.imaginar==1 && c.real!=0)///a+i
        out<<c.get_real()<<" +i"<<endl;
    else if(c.imaginar==-1 && c.real!=0)///a-i
        out<<c.get_real()<<" -i"<<endl;
    else if(c.imaginar!=0 && c.real==0)
    {
        if(c.imaginar==-1)///-i
            out<<"-i"<<endl;
        if(c.imaginar==1)///+i
            out<<"i"<<endl;
    }
    else if(c.imaginar>0)
        out<<c.get_real()<<" +"<<c.get_imaginar()<<"i"<<endl;
    else
        out<<c.get_real()<<" "<<c.get_imaginar()<<"i"<<endl;
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

void rezolvare(Complex a, Complex b, Complex c)
{
    Complex x1;
    Complex x2;
    x1=(-b+sqrt(b*b-4*a*c))/2*a;
    x2=(-b-sqrt(b*b-4*a*c))/2*a;
    cout<<"x1= "<<x1<<endl<<"x2= "<<x2<<endl;///nu stiu cum se rezolva ecuatia
    ///dar am rezolvat toate cerintele. rezolvarea ecuatiei am facut-o la fel
    ///ca rezolvarea ecuatiei cu coef. reali :)
}


void citire_n_obiecte(int n, Complex *v){
	for (int i=0;i<n;i++){
		Complex c1(1,1);
		cin>>c1;
		v[i]=c1;
		cout<<v[i]<<endl;
	}
}
