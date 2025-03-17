#ifndef HEADER_H_
#define HEADER_H_
struct Stiva{
    int data;
    Stiva *next;
};
struct Element{
    int data;
    Element *next;
};
struct Queue{
    Element *head, *tail;
};

struct StivaChar{
    char data;
    StivaChar *next;
};

void initS(Stiva *&s);
void push(Stiva*&s, int val);
int pop(Stiva*&s);
bool isEmptyS(Stiva*s);

void initSChar(StivaChar *&s);
void pushChar(StivaChar*&s, char val);
char popChar(StivaChar*&s);
bool isEmptySChar(StivaChar*s);

void initQ(Queue &q);
void put(Queue &q, int val);
int get(Queue &q);
bool isEmptyQ(Queue &q);

bool palindromStiva(char c[]);
bool palindrom(int v[], int n);
void pushMax(Stiva*&s, int val);

struct Lista{
    int data;
    Lista *next;
};
void inserare(Lista*&cap, int val);
void afisareLista(Lista*cap);
void listaMaxim(Lista*&cap);
void listaMinim(Lista*&cap);
#endif