#include <iostream>
#include "header.h"

using namespace std;

int main(){
    // int v[100], n, x;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     v[i]=x;
    // }
    // if(palindrom(v,n))
    //     cout<<"Sirul este palindrom\n";
    // else 
    //     cout<<"Sirul nu este palindrom\n";

    // char c[10]="ana";
    // if(palindromStiva(c))
    //     cout<<"Sirul este palindrom\n";
    // else 
    //     cout<<"Sirul nu este palindrom\n";
    Lista*p=0;
    int n;
    cin>>n;
    while(n){
        inserare(p,n);
        cin>>n;
    }
    afisareLista(p);
    cout<<endl;
   // listaMaxim(p);
    //afisareLista(p);
    listaMinim(p);
    afisareLista(p);

}