#ifndef HEADER_H_
#define HEADER_H_
#define M 87
struct Nod{
    char *cheie;
    Nod*next;
};
void initializare(Nod*HT[]);
int f(char *key);
void inserare(Nod*HT[],char *key);
Nod*find(Nod*HT[],char*key);
void afisare(Nod*HT[]);
#endif