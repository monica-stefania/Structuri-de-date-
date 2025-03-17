#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    Nod*next;
};
void inserare(Nod*&cap,int val);
void afisare(Nod*cap);
void permutari(Nod*cap);
void inversare(Nod*&cap);
#endif