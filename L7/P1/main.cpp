#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>
using namespace std;

int main()
{
    Nod*HT[M];
    initializare(HT);
    char x[64];
    ifstream f;
    f.open("dictionar.txt");
    while(f>>x){
        inserare(HT,x);
    }
    afisare(HT);
    f.close();
}