#include <iostream>
#include "header.h"
using namespace std;

int main(){
    int v[100],n,a;
    n=0;
    cout<<"Introduceti valorile dorite: \n";
    // cin>>a;
    // while(a){
    //     insertMaxHeap(v,n,a);
    //     cin>>a;
    // }
    // afisare(v,n);
    // int val;
    // val=remove(v,n);
    // cout<<val<<"\n";
    // afisare(v,n);
    
    //HeapSort

    cin>>a;
    while(a){
        v[++n]=a;
        cin>>a;
    }
    afisare(v,n);
    build_Heap(v,n);
    afisare(v,n);

}