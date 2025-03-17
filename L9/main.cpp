#include <iostream>
#include "header.h"
using namespace std;

int main(){
    Nod*r=0;
    int n,val,x;
    cout<<"Introduceti valorile: \n";
    cin>>n;
    while(n){
        insert(r,n);
        cin>>n;
    }
    cout<<"\nAfisare in inordine: \n";
    inordine(r);
    cout<<"\nIntroduceti o valoare pentru a afla daca este in arbore sau nu\n";
    cin>>val;
    if(search(r,val))
        cout<<"\nValoarea se afla in arbore\n";
    else 
        cout<<"\nValoarea nu se afla in arbore\n";
    cout<<"\nNodul maxim din arbore este: "<<maxim(r)<<"\n";
    cout<<"\nNodul minim din arbore este: "<<minim(r)<<"\n";
    cout<<"\nIntroduceti o valorea pe care sa o stergeti din arbore\n";
    cin>>x;
    Delete(r,x);
    cout<<"\nAfisare in inordine: \n";
    inordine(r);
    //afisare_indentat(r,1);
}