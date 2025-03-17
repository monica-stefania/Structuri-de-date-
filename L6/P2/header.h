#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    Nod*next;
};
struct Queue{
    Nod*head, *tail;//pointeri la primul si la ultimul element din coada
};
//coada este pasata prin referinta din motive de eficienta
void init(Queue &q);//initializare coada
void put(Queue &q, int val);//un nod este inserat la sfarsitul cozii
int get(Queue &q);//primul nod al cozii este indepartat
int front(Queue &q);//returneaza informatia primul nod. front/top
bool isEmpty(Queue &q);
#endif