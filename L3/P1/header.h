#ifndef HEADER_H_
#define HEADER_H_

struct Nod{
    int data;
    Nod *succ;
};
void Inserare(Nod*&cap,int val);
void Afisare(Nod*cap);
int Cautare(Nod*cap, int val);
void InserarePoz(Nod*&cap, int val, int poz);
void StergerePoz(Nod*&cap, int poz);
void AfisarePoz(Nod*cap, int poz);
void parcurgere(Nod*cap);
void mijloc(Nod*cap);
Nod*inversare(Nod*cap);
void concatenare(Nod*&cap, Nod*x,Nod*y);
#endif