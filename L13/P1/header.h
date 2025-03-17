#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    Nod*next;
};
struct Stiva{
    int val;
    Stiva*next;
};
// struct Element{
//     int data;
//     Element*next;
// };
struct Queue{
    Nod*head,*tail;
};
void afisare(int **a,int n);
void dealocareMatrice(int **a, int n);
void flags(int *&M, int n);

void inserare(Nod*&cap,int val);
void afisareLista(Nod*cap);

void init(Stiva*&s);
void push(Stiva*&s,int a);
int pop(Stiva*&s);
bool isEmpty(Stiva*s);

void initQ(Queue &q);
void put(Queue &q, int a);
int get(Queue &q);
int isEmptyQ(Queue &q);

void DFS_recursiv(int **a, int n, Nod*&L, int *M, int i);
void DFS_iterativ(int **a, int n, Nod*&L, int *M, int i);
void BFS_recursiv(int **a, int n, Queue &q, int *M);
void BFS_iterativ(int **a, int n,int *M, int i);
#endif