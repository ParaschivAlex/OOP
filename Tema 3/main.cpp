#include <iostream>
#include <cstring>

using namespace std;

class Examen
{
protected:
    static int increment;
    int nr_examen;
    char* materie;
    float nota_scris;
public:
    Examen(char* = "", float = 0);
    Examen(const Examen&);
    virtual void Afisare();
    Examen& operator=(const Examen&);
    friend istream& operator>>(istream&, Examen&);
    friend ostream& operator<<(ostream&, const Examen&);
    virtual ~Examen();
};

int Examen::increment = 0;

Examen::Examen(char* s, float f)
{
    increment++;
    nr_examen = increment;
    materie = new char [strlen(s)];
    strcpy(materie, s);
    nota_scris = f;
}

Examen::Examen(const Examen& c)
{
    nr_examen = c.nr_examen;
    delete materie;
    materie = new char [strlen(c.materie)];
    strcpy(materie, c.materie);
    nota_scris = c.nota_scris;
}

void Examen::Afisare()
{
    cout << "Nr examen: " << nr_examen << endl;
    cout << "Materie: " << materie << endl;
    cout << "Nota la scris: " << nota_scris << endl;
}

Examen& Examen::operator=(const Examen& x)
{
    try
    {
        if (this == &x)
            throw "S-a incercat atribuirea unui obiect catre el insusi";
        nr_examen = x.nr_examen;
        delete materie;
        materie = new char [strlen(x.materie)];
        strcpy(materie, x.materie);
        nota_scris = x.nota_scris;
        return *this;
    }
    catch(...)
    {
        throw;
    }
}

istream& operator>>(istream& in, Examen& x)
{
    cout << "Nota la scris: ";
    in >> x.nota_scris;
    char s[50];
    cout << "Materia: ";
    in.get();
    in.getline(s, 50);
    delete x.materie;
    x.materie = new char [strlen(s)];
    strcpy(x.materie, s);
    return in;
}

ostream& operator<<(ostream& out, const Examen& x)
{
    out << "Nr examen: " << x.nr_examen << endl;
    out << "Materie: " << x.materie << endl;
    out << "Nota la scris: " << x.nota_scris << endl;
    return out;
}

Examen::~Examen()
{
    delete []materie;
}

class Partial : public Examen
{
protected:
    float nota_oral;
public:
    Partial(char* = "", float = 0, float = 0);
    Partial(const Partial&);
    virtual void Afisare();
    Partial& operator=(const Partial&);
    friend istream& operator>>(istream&, Partial&);
    friend ostream& operator<<(ostream&, const Partial&);
    virtual ~Partial();
};

Partial::Partial(char* s, float f1, float f2) : Examen(s, f1)
{
    nota_oral = f2;
}

Partial::Partial(const Partial& c) : Examen(c)
{
    nota_oral = c.nota_oral;
}

void Partial::Afisare()
{
    Examen::Afisare();
    cout << "Nota la oral: " << nota_oral << endl;
}

Partial& Partial::operator=(const Partial& x)
{
    Examen::operator=(x);
    nota_oral = x.nota_oral;
    return *this;
}

istream& operator>>(istream& in, Partial& x)
{
    Examen& ref = static_cast<Examen&>(x);
    in >> ref;
    cout << "Nota la oral: ";
    in >> x.nota_oral;
    return in;
}

ostream& operator<<(ostream& out, const Partial& x)
{
    const Examen& ref = static_cast<const Examen&>(x);
    operator<<(out, ref);
    out << "Nota la oral: " << x.nota_oral << endl;
    return out;
}

Partial::~Partial() {}

class Examen_Final : public Partial
{
protected:
    float puncte_proiect;
public:
    Examen_Final(char* = "", float = 0, float = 0, float = 0);
    Examen_Final(const Examen_Final&);
    virtual void Afisare();
    Examen_Final& operator=(const Examen_Final&);
    friend istream& operator>>(istream&, Examen_Final&);
    friend ostream& operator<<(ostream&, const Examen_Final&);
    virtual ~Examen_Final();
};

Examen_Final::Examen_Final(char* s, float f1, float f2, float f3) : Partial(s, f1, f2)
{
    puncte_proiect = f3;
}

Examen_Final::Examen_Final(const Examen_Final& c) : Partial(c)
{
    puncte_proiect = c.puncte_proiect;
}

void Examen_Final::Afisare()
{
    Partial::Afisare();
    cout << "Puncte bonus pentru proiect: " << puncte_proiect << endl;
}

Examen_Final& Examen_Final::operator=(const Examen_Final& x)
{
    Partial::operator=(x);
    puncte_proiect = x.puncte_proiect;
}

istream& operator>>(istream& in, Examen_Final& x)
{
    Partial& ref = static_cast<Partial&>(x);
    in >> ref;
    cout << "Puncte bonus pentru proiect: ";
    in >> x.puncte_proiect;
    return in;
}

ostream& operator<<(ostream& out, const Examen_Final& x)
{
    const Partial& ref = static_cast<const Partial&>(x);
    out << ref;
    out << "Puncte bonus pentru proiect: " << x.puncte_proiect << endl;
    return out;
}

Examen_Final::~Examen_Final() {}

class Quiz : public Examen_Final
{
protected:
    float bonus;
public:
    Quiz(char* = "", float = 0, float = 0, float = 0, float = 0);
    Quiz(const Quiz&);
    virtual void Afisare();
    float CalculMedie();
    Quiz& operator=(const Quiz&);
    friend istream& operator>>(istream&, Quiz&);
    friend ostream& operator<<(ostream&, const Quiz&);
    virtual ~Quiz();
};

Quiz::Quiz(char* s, float f1, float f2, float f3, float f4) : Examen_Final(s, f1, f2, f3)
{
    bonus = f3;
}

Quiz::Quiz(const Quiz& c) : Examen_Final(c)
{
    bonus = c.bonus;
}

void Quiz::Afisare()
{
    Examen_Final::Afisare();
    cout << "Puncte bonus la quiz: " << bonus << endl;
}

float Quiz::CalculMedie()
{
    return (nota_scris + nota_oral) / 2 + puncte_proiect + bonus;
}

Quiz& Quiz::operator=(const Quiz& x)
{
    Examen_Final::operator=(x);
    bonus = x.bonus;
}

istream& operator>>(istream& in, Quiz& x)
{
    Examen_Final& ref = static_cast<Examen_Final&>(x);
    in >> ref;
    cout << "Puncte bonus la quiz: ";
    in >> x.bonus;
    return in;
}

ostream& operator<<(ostream& out, const Quiz& x)
{
    const Examen_Final& ref = static_cast<const Examen_Final&>(x);
    out << ref;
    out << "Puncte bonus la quiz: " << x.bonus << endl;
    return out;
}

Quiz::~Quiz() {}


template <class T>
class CatalogIndividual;

template <class T>
istream& operator>>(istream&, CatalogIndividual<T>&);

template <class T>
ostream& operator<<(ostream&, CatalogIndividual<T>&);

template <class T>
class CatalogIndividual
{
    static int increment;
    int nr_matricol;
    int nr_elem;
    T* v;
public:
    CatalogIndividual(int = 0);
    CatalogIndividual<T>& operator+=(T&);
    friend istream& operator>> <>(istream&, CatalogIndividual<T>&);
    friend ostream& operator<< <>(ostream&, CatalogIndividual<T>&);
    virtual ~CatalogIndividual();
};

template <class T>
int CatalogIndividual<T>::increment = 0;

template <class T>
CatalogIndividual<T>::CatalogIndividual(int n)
{
    increment++;
    nr_matricol = increment;
    nr_elem = n;
    v = new T [nr_elem];
}

template <class T>
CatalogIndividual<T>& CatalogIndividual<T>::operator+=(T& x)
{
    T* aux = new T [nr_elem + 1];
    if (aux)
    {
        memcpy(aux, v, sizeof(T) * nr_elem);
        aux[nr_elem++] = x;
        delete v;
        v = aux;
    }
    return *this;
}

template <class T>
istream& operator>>(istream& in, CatalogIndividual<T>& x)
{
    cout << "Numarul de elemente: ";
    in >> x.nr_elem;
    x.v = new T [x.nr_elem];
    for (int i = 0; i < x.nr_elem; i++)
    {
        cout << "Obiectul " << i + 1 << ":" << endl;
        in >> x.v[i];
    }
    return in;
}

template <class T>
ostream& operator<<(ostream& out, CatalogIndividual<T>& x)
{
    out << "Numar matricol: " << x.nr_matricol << endl;
    out << "Numar de elemente: " << x.nr_elem << endl << endl;
    for (int i = 0; i < x.nr_elem; i++)
    {
        out << "Obiectul " << i + 1 << ":" << endl;
        out << x.v[i];
    }
}

template <class T>
CatalogIndividual<T>::~CatalogIndividual()
{
    delete []v;
}

/**Specializare pentru Examen*/

template <>
class CatalogIndividual<Examen*>;

template <>
istream& operator>>(istream&, CatalogIndividual<Examen*>&);

template <>
ostream& operator<<(ostream&, CatalogIndividual<Examen*>&);

template <>
class CatalogIndividual<Examen*>
{
    static int increment;
    int nr_matricol;
    int nr_elem;
    Examen** v;
public:
    CatalogIndividual(int = 0);
    void operator+=(Examen*&);
    friend istream& operator>> <>(istream&, CatalogIndividual<Examen*>&);
    friend ostream& operator<< <>(ostream&, CatalogIndividual<Examen*>&);
    virtual ~CatalogIndividual();
};

int CatalogIndividual<Examen*>::increment = 0;

CatalogIndividual<Examen*>::CatalogIndividual(int n)
{
    increment++;
    nr_matricol = increment;
    nr_elem = n;
    v = new Examen* [nr_elem];
    for (int i = 0; i < nr_elem; i++)
    {
        v[i] = new Examen;
    }
}

void CatalogIndividual<Examen*>::operator+=(Examen*& x)
{
    Examen** aux = new Examen* [nr_elem];
    if (aux)
    {
        for (int i = 0; i < nr_elem; i++)
        {
            aux[i] = v[i];
        }
        delete []v;
        v = new Examen* [nr_elem + 1];
        for (int i = 0; i < nr_elem; i++)
        {
            v[i] = aux[i];
        }
        delete []aux;
        Partial* p = dynamic_cast <Partial*> (x);
        Examen_Final* p2 = dynamic_cast <Examen_Final*>(x);
        Quiz* p3 = dynamic_cast <Quiz*>(x);
        if (p3)
        {
            v[nr_elem] = new Quiz;
            (*static_cast <Quiz*>(v[nr_elem])) = *p3;
        }
        else if (p2)
        {
            v[nr_elem] = new Examen_Final;
            (*static_cast <Examen_Final*>(v[nr_elem])) = *p2;
        }
        else if (p)
        {
            v[nr_elem] = new Partial;
            (*static_cast <Partial*>(v[nr_elem])) = *p;
        }
        else
        {
            v[nr_elem] = new Examen;
            (*v[nr_elem]) = *x;
        }
        nr_elem++;
    }
}

template <>
istream& operator>>(istream& in, CatalogIndividual<Examen*>& x)
{
    for (int i = 0; i < x.nr_elem; i++)
    {
        delete x.v[i];
    }
    delete []x.v;
    cout << "Numarul de elemente: ";
    in >> x.nr_elem;
    x.v = new Examen* [x.nr_elem];
    int val;
    for (int i = 0; i < x.nr_elem; i++)
    {
        cout << "Obiectul " << i + 1 << ":" << endl;
        cout << "Se alege tipul obiectului:" << endl;
        cout << "Examen: 1" << endl;
        cout << "Partial: 2" << endl;
        cout << "Examen_Final: 3" << endl;
        cout << "Quiz: 4" << endl;
        cin >> val;
        if (val == 1)
        {
            x.v[i] = new Examen;
            in >> (*x.v[i]);
        }
        else if (val == 2)
        {
            x.v[i] = new Partial;
            in >> (*static_cast <Partial*>(x.v[i]));
        }
        if (val == 3)
        {
            x.v[i] = new Examen_Final;
            in >> (*static_cast <Examen_Final*>(x.v[i]));
        }
        if (val == 4)
        {
            x.v[i] = new Quiz;
            in >> (*static_cast <Quiz*>(x.v[i]));
        }
        cout << endl;
    }
    return in;
}

template<>
ostream& operator<<(ostream& out, CatalogIndividual<Examen*>& x)
{
    out << endl;
    out << "Numar matricol: " << x.nr_matricol << endl;
    out << "Numar de elemente: " << x.nr_elem << endl << endl;
    for (int i = 0; i < x.nr_elem; i++)
    {
        out << "Obiectul " << i + 1 << ":" << endl;

        Partial* p = dynamic_cast <Partial*> (x.v[i]);
        Examen_Final* p2 = dynamic_cast <Examen_Final*>(x.v[i]);
        Quiz* p3 = dynamic_cast <Quiz*>(x.v[i]);
        if (p3)
        {
            out << (*p3);
        }
        else if (p2)
        {
            out << (*p2);
        }
        else if (p)
        {
            out << (*p);
        }
        else
        {
            out << (*x.v[i]);
        }
        out << endl;
    }
    return out;
}


CatalogIndividual<Examen*>::~CatalogIndividual()
{
    for (int i = 0; i < nr_elem; i++)
    {
        delete v[i];
    }
    delete []v;
}

///Specializare pentru Quiz

template <>
class CatalogIndividual<Quiz>;

template <>
istream& operator>>(istream&, CatalogIndividual<Quiz>&);

template <>
class CatalogIndividual<Quiz>
{
    Quiz object;
    float medie;
public:
    CatalogIndividual<Quiz>(char* s = "", float f1 = 0, float f2 = 0, float f3 = 0, float f4 = 0) : object(s, f1, f2, f3, f4) {}
    void AfiseazaMedie()
    {
        medie = object.CalculMedie();
        if (medie > 10.0)
            medie = 10.0;
        cout << "Media este: " << medie << " (Media se calculeaza dupa formula: (nota scris + nota oral) / 2 + puncte proiect + puncte quiz)" << endl;
    }
    friend istream& operator>>(istream& in, CatalogIndividual<Quiz>& x)
    {
        in >> x.object;
        return in;
    }
    ~CatalogIndividual<Quiz>() {}
};

void Citire_Quizuri(int n, Quiz*& v)
{
    v = new Quiz [n];

    for (int i = 0; i < n; i++)
    {
        cout << "Quiz-ul " << i + 1 << ":" << endl;
        cin >> v[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Quiz-ul " << i + 1 << ":" << endl;
        cout << v[i];
    }
}

int main()
{
    int choice, val, n, n2;
    CatalogIndividual<Quiz> spec_pe_quiz;
    Quiz obiect_quiz;
    Quiz* v;
    CatalogIndividual<Examen*> vector_generic;
    Examen* o2;
    cout << " 0). Iesirea din executie." << endl;
    cout << " 1). Citirea a n Quiz-uri." << endl;
    cout << " 2). Utilizarea specializarii pentru Quiz." << endl;
    cout << " 3). Exception handling (Consideram exceptie atribuirea unui obiect la el insusi. Throw-ul se face in functia Examen::operator=() )." << endl;
    cout << " 4). Citirea unui vector de obiecte de tip Examen*." << endl;
    cout << " 5). Adaugarea prin operatorul += a unui obiect la vectorul de la punctul 4." << endl;
    cout << " 6). dynamic_cast este folosit in specializarea pentru Examen* in cadrul operatorului += si << ." << endl;
    cout << " 7). static_cast este folosit in ierarhia de clase in cadrul operatorilor << si >> ." << endl;
    do
    {
        cout << "Sa se execute:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "n = ";
            cin >> n;
            Citire_Quizuri(n, v);
            break;

        case 2:
            cout << "Se citeste obiectul de tip Quiz: " << endl;
            cin >> spec_pe_quiz;
            spec_pe_quiz.AfiseazaMedie();
            break;

        case 3:
            try
            {
                obiect_quiz = obiect_quiz;
            }
            catch(const char* s)
            {
                cout << s << endl;
            }
            break;

        case 4:
            cin >> vector_generic;
            cout << "Vectorul este:" << endl << vector_generic;
            break;

        case 5:
            cout << "Se alege tipul obiectului:" << endl;
            cout << "Examen: 1" << endl;
            cout << "Partial: 2" << endl;
            cout << "Examen_Final: 3" << endl;
            cout << "Quiz: 4" << endl;
            cin >> val;
            if (val == 1)
            {
                o2 = new Examen;
                cin >> (*o2);
            }
            else if (val == 2)
            {
                o2 = new Partial;
                cin >> (*static_cast <Partial*>(o2));
            }
            else if (val == 3)
            {
                o2 = new Examen_Final;
                cin >> (*static_cast <Examen_Final*>(o2));
            }
            else if (val == 4)
            {
                o2 = new Quiz;
                cin >> (*static_cast <Quiz*>(o2));
            }
            vector_generic += o2;
            cout << vector_generic;
            break;
        }
    }
    while (choice > 0 && choice < 6);
    return 0;
}
