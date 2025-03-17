#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    Nod*p=NULL;
    int n;
    cin>>n;
    while(n){
        inserare(p,n);
        cin>>n;
    }
    cout<<"Lista este:\n";
    afisare(p);
    cout<<"Permutarile listei sunt: \n";
    permutari(p);
    inversare(p);
    cout<<"Inversa listei este:\n";
    afisare(p);

}