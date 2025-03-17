#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    Nod *succ, *pred;
};
void inserare(Nod*&cap, int val);
void afisare(Nod*cap);
void inserarepoz(Nod*&cap, int val, int poz);
void stergere(Nod*&cap,int poz);
#endif