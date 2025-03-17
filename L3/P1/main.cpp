#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Nod*p=new Nod;
    Nod*q=new Nod;
    Nod*r=new Nod;
    q=NULL;
    r=0;
    //int n,nr,val,poz,poz1,poz2;
    int n,n1;
    p=NULL;
    cin>>n;
    while(n){
        Inserare(p,n);
        cin>>n;
    }
    cout<<"Lista creata este: ";
    Afisare(p);
    //cout<<"Introduceti un nr pentru a afla daca este in lista: ";
    //cin>>nr;
    //if (Cautare(p,nr)==1)
        //cout<<"Se afla in lista"<<"\n";
    //else
       // cout<<"Nu se afla in lista"<<"\n";
    //cout<<"Citire numar si pozitie pe care vreti sa inserati in lista:"<<"\n";
    //cin>>val>>poz;
    //InserarePoz(p,val,poz);
    //cout<<"Lista este: ";
    //Afisare(p);
    //cout<<"Citire pozitie de unde vreti sa stergeti din lista:  ";
    //cin>>poz1;
    //StergerePoz(p,poz1);
   // cout<<"Lista este: ";
   // Afisare(p);
   // cout<<"Inversarea legaturilor:\n";
    //q=inversare(p);
   // Afisare(q);
   // cout<<"Citire pozitia de unde sa se afiseze elementul din lista\n";
   // cin>>poz2;
    //cout<<"Valorea este\n";
    //AfisarePoz(q,poz2);
   // cout<<"Mijlocul este:\n";
   // mijloc(q);
    //cout<<"Parcurgerile dus-intors sunt:\n";
   // parcurgere(q);
    cin>>n1;
    while(n1){
        Inserare(q,n1);
        cin>>n1;
    }
    cout<<"Lista creata este: ";
    Afisare(q);
    concatenare(r,p,q);
    Afisare(r);
    return 0;

}