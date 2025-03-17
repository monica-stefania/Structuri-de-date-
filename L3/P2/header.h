#ifndef HEADER_H_
#define HEADER_H_
struct Persoana
{
    char *nume;
    char *tel;
    Persoana *next;
};
void inserare(Persoana *&cap, char *n, char *t);
void afisare(Persoana *cap);
#endif