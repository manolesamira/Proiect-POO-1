#include <iostream>

using namespace std;
class Nod
{
protected:
    int info,nr_copii;
    Nod* leg[10];
public:
    Nod():info(0),nr_copii(0),leg(NULL){}
    Nod(int ,int );
    Nod(const Nod&);
    virtual ~Nod();
    Nod& operator=(const Nod&);
    friend ostream& operator<<(ostream&,const Nod&);
    friend istream& operator>>(istream&, Nod&);
    friend class Arbore;
};
Nod::Nod(int i, int nr)
{
    info=i;
    nr_copii=nr;
    leg=new Nod*[nr_copii];

}
Nod::Nod(const Nod& ob)
{
    if(ob!=(*this))
    {
        info=ob.info;
        nr_copii=ob.nr_copii;
        leg=new Nod*[nr_copii];
        for(int i=0;i<nr_copii;i++)
            leg[i]=ob.leg[i];
    }
    return (*this);
}
Nod::~Nod(){delete []leg;}
Nod& Nod::operator=(const Nod& ob)
{
    //varianta 1 : lucrez cu this, var2: fac un ob nou si returnez ob nou
    info=ob.info;
    if(nr_copii!=ob.nr_copii)
    {nr_copii=ob.nr_copii;
    delete []leg;
    leg=new Nod*[nr_copii];}
    for(int i=0;i<nr_copii;i++)
        leg[i]=ob.leg[i];
}
ostream& operator<<(ostream& out,const Nod& ob)
{
    out<<endl<<"Valoarea din nod este: "<<ob.info;
    out<<endl<<"Numarul de copii din nod este: "<<ob.nr_copii;
    //ar trebui sa scot si din vector fii?
    return out;

}
istream& operator>>(istream& in, Nod& ob )
{
    cout<<endl<<"Valoarea din nod: ";
    in>>ob.info;
    cout<<endl<<"Numarul de copii al nodului: "
    in>>ob.nr_copii;
    leg=new Nod*[nr_copii];

}
class Arbore
{
protected:
    int nr_noduri;
    Nod* rad;

public:
    Arbore():nr_noduri(0){rad=NULL;}
    Arbore(int)
    Arbore(const Arbore&)
    ~Arbore();
    void afisare()=0;
    void inserez(int&,nod*);
    void sterge(Nod*);

};
Arbore::Arbore(int nr):nr_noduri(nr)
{
    inserez(nr,rad);
}
void Arbore::inserez(int& nr,Nod* &rad)
{
    int i;
    if(rad==NULL&&nr>0)
        {cin>>(*rad); nr--;}
    while(nr>0)
    {
            for(i=0;i<rad->nr_copii;i++)
                if(rad->leg[i]!=NULL&&nr>0)
                        inserez(nr,rad->leg[i]);
                else {
                        cin>>(*rad->leg[i]);
                        nr--;
                     }

    }

}
Arbore::~Arbore()
{
    sterge(rad);
    delete rad;
}
void Arbore::sterge(Nod* nod)
{
        if(nod!=NULL)
        {
            for(int i=0;i<nod->nr_copii;i++)
            sterge(nod->leg[i]);
            delete nod;
        }
}

Arbore::Arbore(const Arbore& ob)
{
    if(nr_noduri!=ob.nr_noduri)
    {
        nr_noduri=ob.nr_noduri
            sterge(rad);
            rad=ob.rad;
            /*
            nod* p=rad;
            nr_noduri--;
            while(nr_noduri>0)
            {

         for(i=0;i<p->nr_copii;i++)
            if(p->leg[i]==NULL&&nr>0)
            {
                p->leg[i]=ob.leg[i];
            }
            ...
            */


}

class Arbore_oarecare:public Arbore
{
public:
    Arbore_oarecare():Arbore(){numar_ob++;}
     Arbore_binar(int);
    ~Arbore_oarecare():Arbore(){}
    Arbore_oarecare afisare_ob(int n){return Arbore_oarecare::numar_ob;}
    friend ostream& operator<<(ostream&,const Arbore_binar&);
    friend istream& operator>>(istream&,Arbore_binar&);
    Arbore_binar& operator=(const Arbore_binar&);
    static int numar_ob;
    void adancime(Nod* );
    void latime(Nod* );
    void afisare()
    {
         adancime(rad);
         cout<<endl;
         latime(rad);

    }

};
void adancime(Nod* nod)
{
    if(nod!=NULL)
    {
        for(i=0;i<nod->nr_copii;i++)
                if(nod->leg[i]!=NULL)
                        {adancime(nod->leg[i]);
                        cout<<nod->info;}
    }
}
void latime(Nod* nod)
{
    if(nod!=NULL)
    {
        for(i=0;i<nod->nr_copii;i++)
                {cout<<nod->info;

                    if(nod->leg[i]!=NULL)
                        adancime(nod->leg[i]);
    }
}
int Arbore_oarecare::numar_ob=0;

class Arbore_binar:public Arbore_oarecare
{
public:
    static int numar_ob2;
    Arbore_binar():Arbore(){};
    Arbore_binar(int)
    Arbore_binar(int);
    Arbore_binar(const Arbore_binar&);
    Arbore_binar afisare_ob2(int n){return Arbore_binar::numar_ob2;}
    ~Arbore_binar():Arbore_oarecare(){}
    friend ostream& operator<<(ostream&,const Arbore_binar&);
    friend istream& operator>>(istream&,Arbore_binar&);
    Arbore_binar& operator=(const Arbore_binar&);
    friend afisare_ob2();
    void SRD();
    void RSD();
    void SDR();
    void afisare(){
    SRD();
    RSD();
    SDR();
    }

};
Arbore_binar(int nr)
{

}
afisare_ob2()
{
        cout<<Arbore_binar::numar_ob2;
}
class management
{
    Arbore_oarecare *v;
    Arbore_binar *w
    int n;
    int m;
public:
    management(int, int)
    void afisare(int ,int);
};

management::management(int n=0,int m=0)
{
    int i,j;
    if(n<=Arbore_oarecare::numar_ob)
    v=new Arbore_oarecare[n];
    for(i=0;i<n;i++)
        v[i]=afisare_ob(i);
    if(m<=Arbore_binar::numar_ob2)
    w=new Arbore_binar[m];
    for(j=0;j<n;j++)
        w[j]=afisare_ob2[j];

}
int main()
{
    Arbore_binar B;
    Arbore_oarecare C;
    return 0;
}
