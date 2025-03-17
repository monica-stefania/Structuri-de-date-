#include <iostream>
// #include <fstream>
#include "header.h"
using namespace std;

int main()
{
    // ifstream f;
    // f.open("dataNew.txt");
    int n,m,x,y,c;
    int **a,*M;
    cout<<"n= \n";
    cin>>n;
    a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[n];
        for(int j=0;j<n;j++)
            a[i][j]=0;
    }
    cout<<"m= \n";
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        cin>>y;
        cin>>c;
        a[x-1][y-1]=c;
    }
    cout<<"Matricea este:\n";
    afisare(a,n);
    M=new int[n];//flags
    flags(M,n);
    Nod*p=0;
    DFS_recursiv(a,n,p,M,0);
    afisareLista(p);

    Nod*q=0;
    flags(M,n);
    DFS_iterativ(a,n,q,M,0);
    afisareLista(q);

    flags(M,n);
    Queue t;
    initQ(t);
    put(t,0);//punem nodul de start in coada
    BFS_recursiv(a,n,t,M);
    cout<<"\n";

    flags(M,n);
    BFS_iterativ(a,n,M,0);

}