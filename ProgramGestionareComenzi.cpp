/**
PARASCHIV ALEXANDRU-ANDREI 134
GNU GCC mingw32-g++
DAVID PACIOIANU
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "stdio.h"
#include <algorithm>

using namespace std;

class Comanda
{
protected:

    static int cnt;
    int id;
    string nume;
    string adresa;
    double pret;
    int timp;
    int nr_produse;
    vector <string> produse;
    vector <int> cantitate_produse;

public:
    Comanda(string nm, string adr, double prt, int tmp);
    virtual ~Comanda() = 0;
    int getid();
    string getnume();
    double getpret();

    virtual void print(ostream & out) const;
    virtual void read(istream & in);

    friend ostream& operator <<(ostream &out, const Comanda & to_print);
    friend istream& operator >>(istream &in, Comanda & to_read);
};
int Comanda::getid()
{
    return id;
}

string Comanda::getnume()
{
    return nume;
}

double Comanda::getpret()
{
    return pret;
}

int Comanda::cnt=0;

Comanda::Comanda(string nm="", string adr="", double prt=0, int tmp=0)
{
    nume=nm;
    adresa=adr;
    pret=prt;
    timp=tmp;
    cnt++;
    id=cnt;
}

Comanda::~Comanda() {}

ostream& operator <<(ostream &out, const Comanda & to_print)
{

    to_print.print(out);
    return out;
}

istream& operator >>(istream &in, Comanda & to_read)
{
    try
    {
        to_read.read(in);

    }
    catch(const char* err)
    {
        cout<<err;
    }
    return in;
}

void Comanda::print(ostream & out) const
{
    out<<"Clasa este pur virtuala, nu ar trebui sa se poata apela aceasta metoda";
}

void Comanda::read(istream & in)
{
    cout<<"Introduceti numele clientului...";
    getline(in, nume);
    cout<<'\n';
    cout<<"Introduceti adresa...";
    getline(in, adresa);
    cout<<'\n';
    cout<<"Introduceti pretul final...";
    cin>>pret;
    cout<<'\n';
    cout<<"Introduceti timpul de livrare...";
    cin>>timp;
    cout<<'\n';
    cout<<"Introduceti numarul de produse...";
    int nr;
    cin>>nr;
    nr_produse=nr;
    cout<<'\n';
    for(int i=1; i<=nr; i++)
    {
        string s;
        cin>>s;
        produse.push_back(s);
    }
    for(int i=1; i<=nr; i++)
    {
        int x;
        cin>>x;
        cantitate_produse.push_back(x);
    }
}

class ComandaMedicamente:public Comanda
{
    vector <bool> antibiotic;
public:
    ComandaMedicamente(string nm, string adr, double prt, int tmp, vector <bool> a);
    ~ComandaMedicamente();
    void read(istream & in);
    void print(ostream & out) const;
};

ComandaMedicamente::ComandaMedicamente(string nm="", string adr="", double prt=0, int tmp=0, vector <bool> a= {}):Comanda(nm,adr,prt,tmp)
{
    antibiotic=a;
}

ComandaMedicamente::~ComandaMedicamente() {}

void ComandaMedicamente::read(istream & in)
{
    Comanda::read(in);
    for(int i=1; i<=nr_produse; i++)
    {
        bool ok_antibiotic;
        cin>>ok_antibiotic;
        antibiotic.push_back(ok_antibiotic);
    }
}

void ComandaMedicamente::print(ostream & out) const
{
    out<<"Comanda medicamente, ID"<<id<<'\n';
    out<<"Nume Client: "<<nume<<'\n';
    out<<"Adresa: "<<adresa<<'\n';
    out<<"Timp livrare: "<<timp<<" min"<<'\n';
    out<<"Produse:";
    for(int i=0; i<nr_produse; i++)
        out<<produse[i]<< " ("<<antibiotic[i]<<")"<<" -> x"<< cantitate_produse[i]<<'\n';
    out<<"Pret final: "<<pret<<" lei"<<'\n';
}


class ComandaTigari:public Comanda
{
    vector <bool> tutun;
public:
    ComandaTigari(string nm, string adr, double prt, int tmp, vector <bool> t);
    void read(istream & in);
    void print(ostream & out) const;

};

ComandaTigari::ComandaTigari(string nm="", string adr="", double prt=0, int tmp=0, vector <bool> t= {}):Comanda(nm,adr,prt,tmp)
{
    tutun=t;
}

void ComandaTigari::read(istream & in)
{
    Comanda::read(in);
    for(int i=1; i<=nr_produse; i++)
    {
        bool ok_tutun;
        cin>>ok_tutun;
        tutun.push_back(ok_tutun);
    }
}

void ComandaTigari::print(ostream & out) const
{
    out<<"Comanda tigari, ID"<<id<<'\n';
    out<<"Nume Client: "<<nume<<'\n';
    out<<"Adresa: "<<adresa<<'\n';
    out<<"Timp livrare: "<<timp<<" min"<<'\n';
    out<<"Produse:";
    for(int i=0; i<nr_produse; i++)
        out<<produse[i]<< " ("<<tutun[i]<<")"<<" -> x"<< cantitate_produse[i]<<'\n';
    out<<"Pret final: "<<pret<<" lei"<<'\n';
}

class ComandaMancare:public Comanda
{
protected:
    string nume_local;
public:
    ComandaMancare(string nm, string adr, double prt, int tmp, string nl);
    ~ComandaMancare()=0;
    void read(istream & in);
    void print(ostream & out) const;

};

ComandaMancare::ComandaMancare(string nm="", string adr="", double prt=0, int tmp=0, string nl=""):Comanda(nm,adr,prt,tmp)
{
    nume_local=nl;
}

ComandaMancare::~ComandaMancare() {}

void ComandaMancare::read(istream & in)
{
    Comanda::read(in);
    cout<<"Introduceti numele localului...";
    cin>>nume_local;
    cout<<'\n';
}

void ComandaMancare::print(ostream & out) const
{
    out<<"Nu ar trebui sa fie afisat ceva";
}

class ComandaFastFood:public ComandaMancare
{
protected:
    int discount;
public:
    ComandaFastFood(string nm, string adr, double prt, int tmp, string nl, int disc);
    void read(istream & in);
    void print(ostream & out) const;

};

ComandaFastFood::ComandaFastFood(string nm="", string adr="", double prt=0, int tmp=0, string nl="", int disc=0):ComandaMancare(nm,adr,prt,tmp,nl)
{
    discount=disc;
}
void ComandaFastFood::print(ostream & out) const
{
    out<<"Comanda mancare, fast-food, ID"<<id<<'\n';
    out<<"Nume Client: "<<nume<<'\n';
    out<<"Adresa: "<<adresa<<'\n';
    out<<"Local: "<<nume_local<<'\n';
    out<<"Timp livrare: "<<timp<<" min"<<'\n';
    out<<"Produse:";
    for(int i=0; i<nr_produse; i++)
        out<<produse[i]<<" -> x"<< cantitate_produse[i]<<'\n';
    out<<"Discount: "<<discount<<"lei"<<'\n';
    out<<"Pret final: "<<pret<<" lei"<<'\n';
}

void ComandaFastFood::read(istream & in)
{
    ComandaMancare::read(in);
    cout<<"Introduceti discountul...";
    cin>>discount;
    cout<<'\n';
}

class ComandaRestaurant:public ComandaMancare
{
protected:
    bool tacamuri;
public:
    ComandaRestaurant(string nm, string adr, double prt, int tmp, string nl, bool tacam);
    void read(istream & in);
    void print(ostream & out) const;
};

ComandaRestaurant::ComandaRestaurant(string nm="", string adr="", double prt=0, int tmp=0, string nl="", bool tacam=0):ComandaMancare(nm,adr,prt,tmp,nl)
{
    tacamuri=tacam;
}

void ComandaRestaurant::print(ostream & out) const
{
    out<<"Comanda mancare, restaurant, ID"<<id<<'\n';
    out<<"Nume Client: "<<nume<<'\n';
    out<<"Adresa: "<<adresa<<'\n';
    out<<"Local: "<<nume_local<<'\n';
    out<<"Timp livrare: "<<timp<<" min"<<'\n';
    out<<"Produse:";
    for(int i=0; i<nr_produse; i++)
        out<<produse[i]<<" -> x"<< cantitate_produse[i]<<'\n';
    out<<"Pret final: "<<pret<<" lei"<<'\n';
}

void ComandaRestaurant::read(istream & in)
{
    ComandaMancare::read(in);
    cout<<"Introduceti daca e neovie de tacamuri...";
    cin>>tacamuri;
    cout<<'\n';
}

bool descrescator (Comanda *i, Comanda *j)
{
    return i->getpret() > j->getpret();
}

int main()
{


    vector <Comanda *> comenzi;

    int op;
    do
    {
        cout << "Introduceti o optiune (1-7) :\n 1.Citire a n comenzi \n 2.Adaugare comanda noua \n 3.Afisare comenzi \n 4.Sterge comanda dupa ID";
        cout<<"\n 5. Cautare comanda dupa ID \n 6.Cautare comanda dupa nume client \n 7. Ordonare comenzi dupa pret in mod descrescator \n";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout<<"Introduceti cate comenzi doriti...\n";
            int n;
            cin>>n;
            for(int i = 0; i < n; i++)
            {
                Comanda* p;

                cout<<"Introduceti tipul comenzii (1-fast food, 2-restaurante, 3-medicamente, 4-tigari)...\n";
                int tip;
                cin>>tip;
                char * enter = new char;
                gets(enter);
                delete enter;
                if(tip==1)
                    p=new ComandaFastFood;
                else if(tip==2)
                    p=new ComandaRestaurant;
                else if(tip==3)
                    p=new ComandaMedicamente;
                else if(tip==4)
                    p=new ComandaTigari;
                cin >> *p;
                comenzi.push_back(p);
            }
            break;
        }
        case 2:
        {
            Comanda* p;
            cin >> *p;
            comenzi.push_back(p);
            break;
        }
        case 3:
        {
            for(unsigned int i=0; i<comenzi.size(); i++)
                cout<<*comenzi[i]<<'\n';
            break;
        }
        case 4:
        {
            int id_to_search;
            cin>>id_to_search;
            for(unsigned int i=0; i<comenzi.size(); i++)
            {
                if(comenzi[i]->getid()==id_to_search)
                    comenzi.erase(comenzi.begin()+i);
            }
            break;
        }
        case 5:
        {
            int id_to_search;
            cin>>id_to_search;
            for(unsigned int i=0; i<comenzi.size(); i++)
            {
                if(comenzi[i]->getid()==id_to_search)
                    cout<<comenzi[i]<<endl;
            }
            break;
        }
        case 6:
        {
            string nume_search;
            cin>>nume_search;
            for(unsigned int i=0; i<comenzi.size(); i++)
            {
                if(comenzi[i]->getnume()==nume_search)
                    cout<<comenzi[i]<<endl;
            }
            break;
        }
        case 7:
        {
            sort(comenzi.begin(), comenzi.end(), descrescator);
            break;
        }

        }
    }
    while (op > 0 && op < 8);
    return 0;
};
