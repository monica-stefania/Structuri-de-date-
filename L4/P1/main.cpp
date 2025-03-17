#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    Nod*p=0;
    p=NULL;
    int n,x,poz,val,poz1;
    cout<<"Introduceti cate elemente doriti sa aiba lista: \n";
    cin>>n;
    cout<<"Introduceti valorile din lista: \n";
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==0)
            {
                cout<<"Eroare";
            }
        else
            inserare(p,x);
    }
    cout<<"Lista creata este: \n";
    afisare(p);
    cout<<"Introduceti valoarea pe care vreti sa o adaugati in lista:\n";
    cin>>val;
    cout<<"Introduceti si pozitia:\n";
    cin>>poz;
    inserarepoz(p,val,poz);
    cout<<"Noua lista este:\n";
    afisare(p);
    cout<<"Introduceti pozitia de unde stergeti un element\n";
    cin>>poz1;
    stergere(p,poz1);
    cout<<"Noua lista este:\n";
    afisare(p);
    return 0;
}