#include <iostream>
#include "header.h"
using namespace std;

void insertMaxHeap(int v[], int &n, int a){
    //v-vectorul in care se insereaza calorile arborului
    //n-pozitia
    //a-valorea
    int fiu, parinte;
    if(n==0){
        n++;
        v[n]=a;
    }
    else{
        n++;
        v[n]=a;
        fiu=n;
        parinte=n/2;
        while(parinte>=1)
        {
            if(v[parinte]<v[fiu]){
                swap(v[parinte],v[fiu]);
                fiu=parinte;
                parinte=parinte/2;
            }
            else 
                parinte=0;
        }
    }
}

void insertMinHeap(int v[], int&n, int a){
    int fiu,parinte;
    if(n==0)
        v[++n]=a;
    else 
        {
            v[++n]=a;
            fiu=n;
            parinte=n/2;
            while(parinte>=1){
                if(v[fiu]<v[parinte]){
                    swap(v[fiu],v[parinte]);
                    fiu=parinte;
                    parinte=parinte/2;
                }
                else    
                    parinte=0;
                }
        }
}
void afisare(int v[], int n){
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}

int remove(int v[], int &n){
    int val,fiu,parinte;
    if(n==0)
        cout<<"Eroare! Nu exista elemente in arbore\n";
    else{
        val=v[1];
        v[1]=v[n];
        n=n-1;
        //retro
        parinte=1;
        fiu=2;
        while(fiu<=n){
            if(fiu+1<=n && v[fiu]<v[fiu+1])
                fiu=fiu+1; //este ales fiul cel mai mare
            if(v[fiu]>v[parinte])
            {
                swap(v[fiu],v[parinte]);
                parinte=fiu;  //coboara
                fiu=fiu*2;
            }
            else 
                fiu=n+1; //pentru parasirea buclei
        }
        return val;
    }
    return 0;
}

// HEAPSORT

void build_Heap(int v[], int n){
    for(int i=n/2;i>=1;i--)
        retro(v,n,i);
}

void retro(int v[], int n, int i){
     int parinte=i;
     int fiu=2*i;
     while(fiu<=n){
            if(fiu+1<=n && v[fiu]<v[fiu+1])
                fiu=fiu+1; //este ales fiul cel mai mare
            if(v[fiu]>v[parinte])
            {
                swap(v[fiu],v[parinte]);
                parinte=fiu;  //coboara
                fiu=fiu*2;
            }
            else 
                fiu=n+1; //pentru parasirea buclei
        }
}