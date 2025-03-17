#ifndef HEADER_H_
#define HEADER_H_
#define DIM_MAX 10
struct Queue{
    int head, tail;
    int v[DIM_MAX];
};
void init(Queue &q); //initializare coada
void put(Queue &q, int val);//un nod este inserat la sfarsitul cozii
int get(Queue &q); //primul nod al cozii este indepartat
int front(Queue &q);//returneaza informatia primului nod din coada, fara sa-l stearga
bool isEmpty(Queue &q);
int nextPoz(int index);//pt cozi circulare
bool isFull(Queue &q);
#endif