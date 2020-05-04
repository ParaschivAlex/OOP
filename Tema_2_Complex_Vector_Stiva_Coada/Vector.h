#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
#include <bits/stdC++.h>
using namespace std;

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

#endif // VECTOR_H_INCLUDED
