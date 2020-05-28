#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

class Examen{
protected:
    string materie;
    string data;
    double nota_scris;
    static int nr_examene;
public:
    Examen(string, string, double);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    virtual string get_materie(){return materie;}
    Examen& operator=(Examen &);
    friend istream& operator >>(istream &in, Examen&);
    friend ostream& operator <<(ostream &in, Examen&);
    static void afis_nr_examene(){cout<<"Numar de examene: "<<nr_examene;}
};
int Examen::nr_examene;

Examen& Examen:: operator=(Examen &e){
    if(this != &e){
        materie=e.materie;
        data=e.data;
        nota_scris=e.nota_scris;
    }
    return *this;
}

Examen::Examen(string mat="", string d="", double nota=1){
    nr_examene++;
    this->materie=mat;
    this->data=d;
    this->nota_scris=nota;
}

void Examen::citire(istream &in){
    string m,d,n;
    cout<<"Materie: ";
    in >> materie;
    cout<<"Data: ";
    in >> data;
    cout<<"Nota scris: ";
    in >> nota_scris;
}

void Examen::afisare(ostream &out){
    out<<"Materie: "<<materie<<"\n";
    out<<"Data: "<<data<<"\n";
    out<<"Nota scris: "<<nota_scris<<"\n";
}

istream& operator >> (istream &in, Examen &e){
    e.citire(in);
    return in;
}

ostream& operator << (ostream &out, Examen &e){
    e.afisare(out);
    return out;
}

class Partial:public Examen{
    double nota_oral;
    int id;
public:
    Partial(string, string, double, double);
    double nota_finala(){return (2*nota_scris)/3 + nota_oral/3;}
    double get_nota_scris() const{return nota_scris;}
    double get_nota_oral() const{return nota_oral;}
    void set_nota(int ns,int no){
        nota_scris = ns;
        nota_oral = no;
    }
    void set_procent_nota(int ns,int no){ //am presupus ca nota maxima la un examen poate fi diferita de 10
        if(nota_oral > no && nota_scris > ns){//si am calculat nota in functie de nota maxima posibila
            nota_oral=no;
            nota_scris=ns;
            nota_scris=(10*nota_scris)/ns;
            nota_oral=(10*nota_oral)/no;
        }
        else
        if(nota_oral > no){
            nota_oral=no;
            nota_scris=(10*nota_scris)/ns;
            nota_oral=(10*nota_oral)/no;
        }
        else
        if(nota_scris > ns){
            nota_scris=ns;
            nota_oral=(10*nota_oral)/no;
            nota_scris=(10*nota_scris)/ns;
        }
        else
        {
            nota_scris=(10*nota_scris)/ns;
            nota_oral=(10*nota_oral)/no;

        }
    }
    Partial& operator=(Partial&);
    int get_id() const{return id;}
    void citire(istream &in);
    void afisare(ostream &out);
    string get_materie(){return materie;}
    friend istream& operator>>(istream &in, Partial&);
    friend ostream& operator<<(ostream &out, Partial&);
};

Partial::Partial(string m="",string d="",double ns=1, double no=1):Examen(m,d,ns){
    nota_oral=no;
}

Partial& Partial::operator=(Partial& p){
    if(this!=&p){
        Examen::operator=(p);
        nota_oral=p.nota_oral;
    }
    return *this;
}

void Partial::citire(istream &in){
    Examen::citire(in);
    id = nr_examene;
    cout<<"Nota oral: ";
    in>>nota_oral;
}

void Partial::afisare(ostream &out){
    Examen::afisare(out);
    cout<<"Nota oral : "<<nota_oral<<"\n";
}

istream& operator >>(istream &in, Partial &p){
    p.citire(in);
    return in;
}

ostream& operator <<(ostream &out, Partial &p){
    p.afisare(out);
    return out;
}

class ExamenFinal:public Examen{
    double extra_puncte;
public:
    ExamenFinal(string, string, double, double);
    void citire(istream &in);
    void afisare(ostream &out);
    double get_nota_scris(){return nota_scris;}
    double get_extra_puncte(){return extra_puncte;}
    void set_procent_nota(int ns,int extra){
        if(nota_scris > ns && extra_puncte > extra){
            nota_scris = ns;
            extra_puncte = extra;
            nota_scris=(10*nota_scris)/ns;
        }
        else
        if(extra_puncte > extra){
            extra_puncte = extra;
            nota_scris=(10*nota_scris)/ns;
        }
        else
        if(nota_scris > ns){
            nota_scris=ns;
            nota_scris=(10*nota_scris)/ns;
        }

    }
    ExamenFinal& operator=(ExamenFinal&);
    string get_materie() const{return materie;}
    double nota_finala() const{return nota_scris + extra_puncte;}
    friend istream& operator>>(istream &in, ExamenFinal&);
    friend ostream& operator<<(ostream &out, ExamenFinal&);
};

ExamenFinal::ExamenFinal(string m="",string d="",double ns=1, double extra=0):Examen(m,d,ns)
{
    extra_puncte = extra;
}

ExamenFinal& ExamenFinal::operator=(ExamenFinal& e){
    if(this!=&e){
        Examen::operator=(e);
        extra_puncte=e.extra_puncte;
    }
    return *this;
}

void ExamenFinal::citire(istream &in){
    Examen::citire(in);
    cout<<"Extra puncte pe proiect: ";
    in >> extra_puncte;
}

void ExamenFinal::afisare(ostream &out){
    Examen::afisare(out);
    cout<<"Extra puncte pe proiect: "<<extra_puncte<<"\n";
}

istream& operator>>(istream& in, ExamenFinal &e){
    e.citire(in);
    return in;
}


ostream& operator<<(ostream& out, ExamenFinal &e){
    e.afisare(out);
    return out;
}

class Quiz{
    string materie;
    int nr_grile;
    int nr_grile_corecte;
public:
    //Quiz(string, int, int);
    double punctaj();
    string get_materie() const{return materie;}
    int get_nr_grile() const{return nr_grile;}
    int get_nr_grile_corecte() const{return nr_grile_corecte;}
    void set_val(string m, int n1, int n2){
        materie=m;
        nr_grile=n1;
        nr_grile_corecte=n2;
    }
};
/*Quiz::Quiz(string mat, int nr, int nrc){
    materie=mat;
    nr_grile=nr;
    nr_grile_corecte=nrc;
}
*/
double Quiz::punctaj(){
    double nota;
    nota = double(nr_grile_corecte)/double(nr_grile);
    return nota;
}

template <class T> class CatalogIndividual{//clasa template
    static int nr_matricol;
    int nr_examene_elev;
    list<string> observatii;
    double *note;
    T *examen;
public:
    T* get_exam(){return examen;}
    void set_exam(T* e){examen=e;}
    void set_nota(double *nt){note=nt;}
    double* get_note(){return note;}
    void afis_observatii(){
        list<string>::iterator i;
        for(i=observatii.begin();i!=observatii.end();i++)
            cout<<*i<<" ";
        cout<<"\n";
    }
    CatalogIndividual operator +=(string mesaj){
        observatii.push_back(mesaj);
        return *this;
    }
    CatalogIndividual(int nr=0,T *ex = NULL){
        nr_matricol++;
        nr_examene_elev=nr;
        if(nr_examene_elev){
            examen = new T[nr_examene_elev];
            for(int i=0;i<nr_examene_elev;++i)
                examen[i] = ex[i];
        }
    }
    CatalogIndividual(CatalogIndividual &a){
        nr_matricol++;
        nr_examene_elev=a.nr_examene_elev;
        examen = new T[nr_examene_elev];
        for(int i=0;i<nr_examene_elev;++i)
                examen[i] = a.examen[i];
    }
    friend istream& operator>>(istream& in, CatalogIndividual &c){
        nr_matricol++;
        cout<<"Dati numarul de examene pe care le-a sustinut elevul: ";
        in >> c.nr_examene_elev;
        c.examen = new T[c.nr_examene_elev];
        for(int i=0;i<c.nr_examene_elev;++i){
            in>>c.examen[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out,const CatalogIndividual &c){
        for(int i=0;i<c.nr_examene_elev;++i)
            out<<c.examen[i].get_materie()<<" "<<c.examen[i].nota_finala()<<"\n";
        return out;
    }

    ~CatalogIndividual(){
        delete []examen;
        delete []note;
    }
};
template <class T> int CatalogIndividual<T>::nr_matricol;

template <> class CatalogIndividual <Quiz>{
    Quiz *q;
    int nr;
public:
    CatalogIndividual(Quiz* p=NULL,int n=0){
        q = new Quiz[n];
        nr = n;
        for(int i=0;i<n;++i){
            q[i].set_val(p[i].get_materie(),p[i].get_nr_grile(),p[i].get_nr_grile_corecte());
        }
    }
    void set_q_nr(Quiz *p,int n){
        q=p;
        nr=n;
    }
    int get_nr(){return nr;}
    Quiz* get_quiz(){return q;}
    ~CatalogIndividual(){delete []q;}
};

void tip(Examen *&e){
    string examen;
    cout<<"Dati tipul examenului: (partial/examenfinal)\n";
    cin>>examen;
    cout<<"\n";
    try{
    if(examen == "partial"){
        e = new Partial;
        cin>>*e;
    }
    else
    if(examen == "examenfinal"){
        e = new ExamenFinal;
        cin>>*e;
    }
    else
        throw 10;
    }
    catch(int x){
        cout<<"Nu ati introdus un examen valid\n";
    }
}

void menu(){
  cout<<"-----MENIU------\n\n";
  cout<<"1. Introduceti examenele(partial+ex final) si notele maxime pt acestea\n";
  cout<<"2. Afiseaza examenele\n";
  cout<<"3. Introduceti elevii\n";
  cout<<"4. Afiseaza catalogul\n";
  cout<<"5. Afiseaza fisele de observatie\n";
  cout<<"6. Introduceti elevii care vor sa dea quiz\n";
  cout<<"7. Afiseaza elevii care au dat cel putin 2 quiz-uri\n";
  cout<<"8. Afiseaza elevii restantieri\n";
  cout<<"0. Exit\n\n";
}
int main()
{
    int n,nr_elevi;
    Examen **ex;
    CatalogIndividual <double> *elev;
    CatalogIndividual <Partial> *elevp;
    CatalogIndividual <ExamenFinal> *elevef;
    CatalogIndividual <Quiz> *quiz;
    unordered_map<string, vector<int>> restanta;

    menu();
    int ok;
    cin>>ok;
    while(ok != 0){
        if(ok == 1){
            cout<<"Dati numarul de materii: ";
            cin>>n;
            ex = new Examen*[2*n];
            map<string,int> verif1;
            map<string,int> verif2;
            for(int i=0;i<2*n;++i){
                cout<<"Se citeste examenul cu numarul "<<i+1<<"\n";
                tip(ex[i]);
                Partial *p1 = dynamic_cast<Partial*>(ex[i]);
                ExamenFinal *p2 = dynamic_cast<ExamenFinal*>(ex[i]);
                if(p1){
                    if(verif1[p1->get_materie()] == 1){ // verific sa nu fie citit de 2 ori acelasi partial/ex final
                        cout<<"Partialul la aceasta materie a fost introdus deja\n";
                        tip(ex[i]);
                        Partial *p1 = dynamic_cast<Partial*>(ex[i]);
                        verif1[p1->get_materie()]=1;
                    }
                    else
                        verif1[p1->get_materie()]=1;
                }
                if(p2){
                    if(verif2[p2->get_materie()] == 1){
                        cout<<"Examenul final la aceasta materie a fost introdus deja\n";
                        tip(ex[i]);
                        ExamenFinal *p2 = dynamic_cast<ExamenFinal*>(ex[i]);
                        verif2[p2->get_materie()]=1;
                    }
                    else
                        verif2[p2->get_materie()]=1;
                }
            }
        }
        else
        if(ok == 2){
            for(int i=0;i<2*n;++i)
                cout<<*ex[i]<<"\n";
        }
        else
        if(ok == 3){
            cout<<"Dati numarul de elevi: ";
            cin>>nr_elevi;
            elevp = new CatalogIndividual<Partial>[nr_elevi];
            elevef = new CatalogIndividual<ExamenFinal>[nr_elevi];
            for(int i=0;i<nr_elevi;++i){
                cout<<"Se citesc partialele date de elevul "<<i+1<<"\n";
                cin>>elevp[i];
                Partial *pp;
                pp=elevp[i].get_exam();
                for(int j=0;j<n;++j){
                    for(int k=0;k<2*n;++k){
                        string materie_ex = ex[k]->get_materie();
                        string materie_curenta = pp[j].get_materie();
                        Partial *p1 = dynamic_cast<Partial*>(ex[k]);
                        if(materie_ex == materie_curenta && p1)
                            pp[j].set_procent_nota(p1->get_nota_scris(),p1->get_nota_oral());

                    }
                    int nota=pp[j].nota_finala();
                    string materie=pp[j].get_materie();
                    if(nota < 5){
                        cout<<"Se reface nota din partialul la materia: "<<materie<<"\n";
                        cout<<"Dati noile note de la examenul scris si cel oral: ";
                        int ns,no;
                        cin>>ns>>no;
                        pp[j].set_nota(ns,no);
                    }
                }
                cout<<"Se citesc examenele finale date de elevul "<<i+1<<"\n";
                elevp[i].set_exam(pp);
                cin>>elevef[i];
                ExamenFinal *e;
                e = elevef[i].get_exam();
                for(int j=0;j<n;++j)
                for(int k=0;k<2*n;++k){
                    ExamenFinal *p2 = dynamic_cast<ExamenFinal*>(ex[k]);
                    if(ex[k]->get_materie()==e[j].get_materie() && p2)
                            e[j].set_procent_nota(p2->get_nota_scris(),p2->get_extra_puncte());
                }
                elevef[i].set_exam(e);
            }
            elev = new CatalogIndividual<double>[nr_elevi];
            for(int i=0;i<nr_elevi;++i){
                double* note;
                note=new double[n];
                Partial *pp;
                pp=elevp[i].get_exam();
                ExamenFinal *pe;
                pe=elevef[i].get_exam();
                for(int j=0;j<n;++j)
                    note[j]=(pp[j].nota_finala()+pe[j].nota_finala())/2;
                elev[i].set_nota(note);
            }
        }
        else
        if(ok == 4){
        for(int i=0;i<nr_elevi;++i){
            double *note=elev[i].get_note();
            Partial *pp;
            pp=elevp[i].get_exam();
            for(int j=0;j<n;++j)
                cout<<pp[j].get_materie()<<" "<<note[j]<<" ";
            cout<<"\n";
        }
        }
        else
        if(ok == 5){
            elev[0]+="m - nu ai invatat suficient";
            elev[0]+="q - felicitari";
            //elev[1]+="abcd";
            for(int i=0;i<nr_elevi;++i)
                elev[i].afis_observatii();
        }
        else
        if(ok == 6){
            quiz = new CatalogIndividual<Quiz>[nr_elevi];
            for(int i=0;i<nr_elevi;++i){
                cout<<"Da quiz elevul "<<i+1<<" ?(0/1)\n";
                int q;
                cin>>q;
                if(q){
                    cout<<"Introduceti numarul de quiz-uri: ";
                    Quiz* grile;
                    int nrq;
                    cin>>nrq;
                    grile=new Quiz[nrq];
                    for(int j=0;j<nrq;++j){
                        cout<<"Dati materia: ";
                        string mat;
                        cin>>mat;
                        cout<<"Dati numarul total de grile si numarul de grile corecte: ";
                        int gr,grc;
                        cin>>gr>>grc;
                        grile[j].set_val(mat,gr,grc);
                    }
                    quiz[i].set_q_nr(grile,nrq);
                }
                else
                    quiz[i].set_q_nr(NULL,0);
            }
            for(int i=0;i<nr_elevi;++i)
                if(quiz[i].get_nr()){
                    Quiz* q1;
                    q1 = quiz[i].get_quiz();
                    for(int j=0;j<quiz[i].get_nr();++j){
                        string mat;
                        mat = q1[j].get_materie();
                        double puncte;
                        puncte = q1[j].punctaj();
                        double *note=elev[i].get_note();
                        Partial *pp;
                        pp=elevp[i].get_exam();
                        for(int k=0;k<n;++k)
                            if(pp[k].get_materie() == mat)
                                note[k]+=puncte;
                        elev[i].set_nota(note);
                    }
                }
        }
        else
        if(ok == 7){
            for(int i=0;i<nr_elevi;++i)
                if(quiz[i].get_nr() > 1)
                    cout<<"Elevul "<<i+1<<" a dat cel putin 2 quiz-uri\n";
            cout<<"\n";
        }
        else
        if(ok == 8){
            for(int i=0;i<2*n;++i){
                string materie;
                materie=ex[i]->get_materie();
                Partial *p1 = dynamic_cast<Partial*>(ex[i]);
                if(p1){
                    vector<int> rest;
                    int vf=0;
                    for(int j=0;j<nr_elevi;++j){
                        double *note=elev[j].get_note();
                        Partial *pp;
                        pp=elevp[j].get_exam();
                        for(int k=0;k<n;++k)
                            if(pp[k].get_materie() == materie && note[k] < 5)
                                {
                                    vf=1;
                                    rest.push_back(j+1);
                                    break;
                                }
                    }
                    if(vf==0){
                        vector<int> q;
                        q.push_back(-1);
                        restanta[p1->get_materie()]=q;
                    }
                    else
                        restanta[p1->get_materie()]=rest;
                }
            }
            unordered_map<string,vector<int>>::iterator itr;
            for(itr=restanta.begin();itr!=restanta.end();++itr){
                cout<<itr->first<<" : ";
                vector<int> q;
                q=itr->second;
                vector<int>::iterator i;
                for(i=q.begin();i!=q.end();++i){
                    if(*i == -1)
                        cout<<"Nu exista elevi restantieri";
                    else
                    cout<<*i<<" ";
                }
                cout<<"\n";
            }
        }
        menu();
        cin>>ok;
    }

    return 0;
}
