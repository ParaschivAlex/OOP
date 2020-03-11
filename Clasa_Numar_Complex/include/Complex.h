#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double imaginar;

public:
    double get_imaginar();
    double get_real();

    void set_imaginar(double img);
    void set_real(double rl);

    Complex();///constr.
    Complex(double real, double imaginar); ///constr. de initializare
    Complex(const Complex &other); ///constr. de copiere
    const Complex &operator=(const Complex &other);///constr. de atribuire
    void show();

    friend ostream &operator <<(ostream &out, const Complex &c);
    friend istream &operator >>(istream &in, const Complex &c);

    friend Complex operator +(Complex a, Complex b);///fct prieten complex-complex adunare
    friend Complex operator +(double a, Complex b);///fct prieten double-complex adunare
    friend Complex operator +(Complex a, double b);///fct prieten complex-double adunare

    friend Complex operator +(Complex a);///fct prieten complex numarul insusi

    friend Complex operator -(Complex a, Complex b);///fct prieten complex-complex scadere
    friend Complex operator -(double a, Complex b);///fct prieten double-complex scadere
    friend Complex operator -(Complex a, double b);///fct prieten complex-double scadere

    friend Complex operator -(Complex a);///fct prieten complex opus

    friend Complex operator *(Complex a, Complex b);///fct prieten complex-complex inmultire
    friend Complex operator *(double a, Complex b);///fct prieten double-complex inmultire
    friend Complex operator *(Complex a, double b);///fct prieten complex-double inmultire

    friend Complex operator /(Complex a, Complex b);///fct prieten complex-complex impartire
    friend Complex operator /(double a, Complex b);///fct prieten double-complex impartire
    friend Complex operator /(Complex a, double b);///fct prieten complex-double impartire


    friend Complex &operator +=(Complex &a, const Complex &b);///fct prieten complex-complex
    friend Complex &operator +=(Complex &a, double b);///fct prieten complex-double

    friend Complex &operator -=(Complex &a, const Complex b);///fct prieten complex-complex
    friend Complex &operator -=(Complex &a, double b);///fct prieten complex-double

    friend Complex &operator *=(Complex &a, const Complex b);///fct prieten complex-complex
    friend Complex &operator *=(Complex &a, double b);///fct prieten complex-double

    friend Complex &operator /=(Complex &a, const Complex b);///fct prieten complex-complex
    friend Complex &operator /=(Complex &a, double b);///fct prieten complex-double

    friend Complex operator ^(Complex a, int b);///fct prieten rdicare la putere naturala

    friend bool operator ==(Complex a, Complex b);///fct prieten complex-complex egalitate
    friend bool operator ==(double a, Complex b);///fct prieten double-complex egalitate
    friend bool operator ==(Complex a, double b);///fct prieten complex-double egalitate

    friend bool operator !=(Complex a, Complex b);///fct prieten complex-complex neegalitate
    friend bool operator !=(double a, Complex b);///fct prieten double-complex neegalitate
    friend bool operator !=(Complex a, double b);///fct prieten complex-double neegalitate

    friend double abs(Complex a);

    friend void sqrt(Complex a);

    friend void rezolvare(Complex a, Complex b, Complex c);
};

#endif // COMPLEX_H
