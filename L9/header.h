#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    Nod *stg, *drt;
};
void insert(Nod*&r, int val);
void insert_nerecursiv(Nod*&r, int val);
Nod*make_nod(int val);
void inordine(Nod *r);
int search(Nod*r, int val);
int minim(Nod*r);
int maxim(Nod*r);
void Delete(Nod*&r,int val);
void DeleteRoot(Nod*&r);
Nod*removeGreatest(Nod*&r);
void afisare_indentat(Nod*r, int nivel);
#endif