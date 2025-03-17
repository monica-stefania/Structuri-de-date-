#ifndef ARBORE_H_
#define ARBORE_H_
struct Nod {
	char data;
	Nod* stg, *drt;
};
struct Element{
	Nod*data;
	Element*next;
};
struct Queue{
	Element*head, *tail;
};

Nod* creareArbore();
void inordine(Nod*root);
void postordine(Nod*root);
void preordine(Nod*root);
int adancime(Nod*root);
int frunze(Nod*root);
int noduri(Nod*root);//returneaza nr de noduri interne
char nodMax(Nod*root, char &maxi);
void nodurim(Nod*root);//afiseaza valorile care au radacina mai mare decat toate valorile din subarborii descendenti 
void comutare(Nod *&root);//pt fiecare nod se comuta subarborele stg cu drt
void afisare(Nod *root);//afisare cu paranteze

//coada dinamica
void init(Queue &q);
void put(Queue &q, Nod*root);
Nod* get(Queue &q);
bool isEmpty(Queue q);
void afisare_nivelui(Nod*root);

#endif