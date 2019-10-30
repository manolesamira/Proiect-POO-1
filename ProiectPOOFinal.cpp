#include <iostream>
///PROIECT POO
using namespace std;

class Numar_Complex
{
    double re;
    double im;
public:
    Numar_Complex(double,double);
    Numar_Complex(const Numar_Complex& );
    ~Numar_Complex();
    Numar_Complex& operator+(const Numar_Complex& );
    Numar_Complex& operator*(const Numar_Complex& );
    Numar_Complex& operator=(const Numar_Complex& );


    friend class Matrice_Complexa;
    friend ostream& operator<<(ostream&, const Numar_Complex&);
    friend istream& operator>>(istream&, Numar_Complex&);

};
Numar_Complex::Numar_Complex(double r=0, double i=0)
{
    re=r;
    im=i;
    cout<<endl<<"A fost apelat constructorul pt numarul complex;";
}
Numar_Complex::~Numar_Complex()
{
    cout<<endl<<"Destructor chemat";
}
Numar_Complex::Numar_Complex(const Numar_Complex& ob)
{
    re=ob.re;
    im=ob.im;
}
Numar_Complex& Numar_Complex::operator=(const Numar_Complex& ob)
{
    if(this!=&ob)
    {
        re=ob.re;
        im=ob.im;
    }
    return *this;
}
Numar_Complex& Numar_Complex::operator+(const Numar_Complex& ob)
{
    re=re+ob.re;
    im=im+ob.im;
    return *this;
}
Numar_Complex& Numar_Complex::operator*(const Numar_Complex& ob)
{
    //(a +bi)(c+di)=ac+ a*di + c*bi - bd = ac-bd + i(ad+cb)
    re=re*ob.re - im*ob.im;
    im=re*ob.im + ob.re*im;
    return *this;
}
ostream& operator<<(ostream& out,const Numar_Complex& ob)
{
    out<<ob.re<<" + "<<ob.im<<"i";
    out<<endl;
    return out;
}
istream& operator>>(istream &in,  Numar_Complex &ob)
{
    cout <<endl<< "Partea reala si imaginara: ";
    in>>ob.re;
    in>>ob.im;
    return in;
}
class Matrice_Complexa
{
    unsigned int rowSize;
    unsigned int colSize;
    Numar_Complex **p;

public:

    //Matrice_Complexa();
    Matrice_Complexa(double,double,unsigned int,unsigned int);
    Matrice_Complexa(const Matrice_Complexa&);
    ~Matrice_Complexa();
    friend ostream& operator<<(ostream& out,const Matrice_Complexa& );
    friend istream& operator>>(istream &in,  Matrice_Complexa &);
    Matrice_Complexa& operator=(const Matrice_Complexa&);
    Matrice_Complexa& operator+(const Matrice_Complexa&);
    Matrice_Complexa& operator*(const Matrice_Complexa&);



};
/*Matrice_Complexa::Matrice_Complexa()
{

    rowSize=0;
    colSize=0;
    p=NULL;
}*/
Matrice_Complexa::Matrice_Complexa(double x=0,double y=0,unsigned int n=0,unsigned int m=0)
{
    int i,j;
    rowSize=n;
    colSize=m;
    p=new Numar_Complex*[rowSize];
    for( i=0; i<colSize; i++)
    {
        p[i]=new Numar_Complex[colSize];
        for(i=0; i<rowSize; i++)
            for(j=0; j<colSize; j++)
            {
                p[i][j].re=x;
                p[i][j].im=y;
            }
    }
}
Matrice_Complexa::Matrice_Complexa(const Matrice_Complexa& ob)
{
    rowSize=ob.rowSize;
    colSize=ob.colSize;

    p=new Numar_Complex*[rowSize];
    int i,j;
    for(i=0; i<rowSize; i++)
    {
        p[i]=new Numar_Complex[colSize];
        for(j=0; j<colSize; j++)
        {
            p[i][j].re=ob.p[i][j].re;
            p[i][j].im=ob.p[i][j].im;

        }
    }
    cout<<endl<<"Copy constructor;";
}
Matrice_Complexa::~Matrice_Complexa()
{
    int i=0;
    for(i=0; i<rowSize; i++)
        delete []p[i];
    delete []p;
}

ostream& operator<<(ostream& out,const Matrice_Complexa& ob)
{
    out<<"Numarul de linii este: "<<ob.rowSize<<endl;
    out<<"Numarul de coloane este: "<<ob.colSize<<endl;
    out<<"Matricea este: ";
    for(int i=0; i<ob.rowSize; i++)
    {
        for(int j=0; j<ob.colSize; j++)
            out<<ob.p[i][j]<<" ";
        out<<endl;
    }
    return out;
}
istream & operator >> (istream &in,  Matrice_Complexa &ob)
{
    int i=0,j=0;
    cout<<"Introduceti numarul de coloane: ";
    in >> ob.colSize;
    cout<<"Introduceti numarul de linii: ";
    in >> ob.rowSize;
    cout<<endl<<"Elementele matricei vor fi: ";
            ob.p=new Numar_Complex*[ob.rowSize];
    for( i=0; i<ob.rowSize; i++)
    {
        ob.p[i]=new Numar_Complex[ob.colSize];

            for(j=0; j<ob.colSize; j++)
            {
                in>>ob.p[i][j];
                //in>>p[i][j].re;
                //in>>p[i][j].im;
            }}
    return in;
}

Matrice_Complexa& Matrice_Complexa::operator=(const Matrice_Complexa& ob)
{
    if(this!=&ob)
    {
        int i,j;
        for(i=0; i<rowSize; i++)
            delete []p[i];
        delete []p;
        rowSize=ob.rowSize;
        colSize=ob.colSize;

        p=new Numar_Complex*[rowSize];
        for( i=0; i<rowSize; i++)
        {
            p[i]=new Numar_Complex[colSize];
            for(j=0; j<colSize; j++)
            {
                p[i][j].re=ob.p[i][j].re;
                p[i][j].im=ob.p[i][j].im;
            }
        }

    }
    return *this;
}
Matrice_Complexa& Matrice_Complexa::operator+(const Matrice_Complexa& ob)
{
    if(ob.colSize>colSize)
        colSize=ob.colSize;

    if(ob.rowSize>rowSize)
        rowSize=ob.rowSize;

    Matrice_Complexa u;
    u.p=new Numar_Complex*[rowSize];

    for(int i = 0; i < rowSize; i++)
    {
        u.p[i]=new Numar_Complex[colSize];
        for(int j = 0; j < colSize; j++)
            u.p[i][j]=p[i][j]+ob.p[i][j];
    }
    return u;
}
Matrice_Complexa& Matrice_Complexa::operator*(const Matrice_Complexa& ob)
{
    int i,j,k;
    Matrice_Complexa mult;
    if(rowSize!=ob.colSize||ob.rowSize!=colSize)
    {
        cout<<endl<<"Nu se pot inmulti cele doua matrici!";
    }
    else
    {
        mult.p=new Numar_Complex*[rowSize];
        for(i = 0; i < rowSize; i++)
        {
            mult.p[i]=new Numar_Complex[ob.colSize];
            for(j = 0; j < ob.colSize; j++)
                for(k = 0; k < colSize; k++)


                    mult.p[i][j]=mult.p[i][j]+(p[i][k]*ob.p[k][j]);
        }
    }
    return mult;

}



int main()

{
    //Matrice_Complexa A(1,1,2,2);
    //cout<<A;
    Matrice_Complexa A;
    Matrice_Complexa B;
    cin>>A;
    cout<<endl<<"Gata A! urmeaza B: "<<endl;
    cin>>B;
    cout<<endl<<"A si B au fost citite!;"<<endl;
    Matrice_Complexa C;
    cout<<endl<<"Am declarat C;";
    C=A+B;
    cout<<endl<<"Am facut C=A+B, urmeaza afisarea: "<<endl;
    cout<<endl<<"Incercarea 1: Adunarea de matrici: A+B"<<endl<<C;
    C=A*B;
    cout<<"Incercarea 2: Inmultirea de matrici: A*B"<<endl<<A*B;


}
