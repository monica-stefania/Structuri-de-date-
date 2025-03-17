#include <iostream>
#include "header.h"
#include <string.h>
using namespace std;

int main()
{
    Persoana *p=new Persoana;
    p=NULL;
    int n;
    char nume[256], tel[256];
    cout<<"Cititi numarul de persoane: ";
    cin>>n;
    for(int i=1; i<=n;i++){
        cout<<"Cititi numele persoanei: ";
        cin.getline(nume,256);
        cout<<"Introduceti nr de telefon: ";
        cin.getline(tel,256);
        inserare(p,nume,tel);
    }
    afisare(p);
}