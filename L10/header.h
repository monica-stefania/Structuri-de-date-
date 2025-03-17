#ifndef HEADER_H_
#define HEADER_H_
struct Nod{
    int data;
    int bf; //balance factor=h(stg)-h(drt)
    Nod*stg,*drt;
};
void inserare(Nod*&r, int val);
void echilibrare(Nod*&r, int val, bool k);
Nod*make_nod(int val);
void RSD(Nod*&a);
void RSS(Nod*&a);
void RDD(Nod*&a);
void RDS(Nod*&a);
void inordine(Nod*r);
#endif