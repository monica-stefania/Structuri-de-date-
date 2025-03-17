#include <iostream>
#include "header.h"
using namespace std;

void afisare(int **a,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<*(*(a+i)+j)<<" ";
        cout<<"\n";
    }
}
void dealocareMatrice(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete a[i];
    }
}
//LISTA
void inserare(Nod*&cap,int val){
    Nod*p=new Nod;
    p->data=val;
    p->next=cap;
    cap=p;
}
void afisareLista(Nod*cap){
    while(cap!=NULL){
        cout<<cap->data<<" ";
        cap=cap->next;
    }
    cout<<"\n";
}
void flags(int *&M, int n){
    for(int i=0;i<n;i++)
        M[i]=0;
}

//STIVA
void init(Stiva*&s){
    s=0;
}
void push(Stiva*&s,int a){
    Stiva*p=new Stiva;
    p->val=a;
    p->next=s;
    s=p;
}
int pop(Stiva*&s){
    Stiva*p=s;
    if(!isEmpty(s))
    {
        int aux=s->val;
        s=s->next;
        delete (p);
        return aux;

    }
    return 0;
}
bool isEmpty(Stiva*s){
    if(s==0)
        return true;
    return false;
}


//COADA

void initQ(Queue&q){
    q.head=0;
    q.tail=0;
}
void put(Queue &q,int a){
    Nod*p=new Nod;
    p->data=a;
    p->next=0;
    if(isEmptyQ(q)){
        q.head=p;
        q.tail=p;
    }
    else{
        q.tail->next=p;
        q.tail=p;
    }
}
int get(Queue &q){
    if(!isEmptyQ(q)){
        Nod*p=q.head;
        int aux=p->data;
        if(q.head==q.tail)
        {
            q.head=0;
            q.tail=0;
            delete p;
        }
        else{
            q.head=q.head->next;
            delete p;
        }
        return aux;
    }
    return 0;
}
int isEmptyQ(Queue &q){
    if(q.head==0 && q.tail==0)
        return 1;
    return 0;
}

//PARCURGERI
void DFS_recursiv(int **a, int n,Nod*&L, int *M, int i){
    //a-matricea de adiacenta
    //L-lista nodurilor care formeaza parcurgea din i
    //M-vector de etichete vizitat/nevizitat
    //i-nodul de start
    inserare(L,i);//sau afisare i;
    M[i]=1; //nodul a fost vizitat
    for(int k=0;k<n;k++){
        if(a[i][k]==1){//daca am muchie
            if(M[k]==0)
                DFS_recursiv(a,n,L,M,k);
        }
    }
}
void DFS_iterativ(int **a, int n, Nod*&L, int *M,int i){
    //S-stiva
    Stiva*s;
    int j;
    init(s);
    push(s,i);
    while(!isEmpty(s)){
        j=pop(s);
        if(M[j]==0){
            inserare(L,j);
            M[j]=1;
            for(int k=0;k<n;k++){
                if(a[j][k]==1)
                    push(s,k);
            }
        }
    }
}

void BFS_recursiv(int **a, int n, Queue &q, int *M){
    if(!isEmptyQ(q)){
        int j=get(q);
        cout<<j<<" ";
        for(int k=0;k<n;k++){
            if(a[j][k]==1 && M[k]==0)
                put(q,k);
                M[k]=1;
        }
        BFS_recursiv(a,n,q,M);
    }
}
void BFS_iterativ(int **a, int n,int *M, int i){
    Queue q;
    initQ(q);
    put(q,i);
    while(!isEmptyQ(q)){
        int j=get(q);
        cout<<j<<" ";
        for(int k=0;k<n;k++){
            if(a[j][k]==1 && M[k]==0)//nodul k se adauga in coada daca este vecin al lui j si nu a fost vizitat
                put(q,k); 
                M[k]=1;
        }
    }
}