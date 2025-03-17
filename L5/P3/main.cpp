#include <iostream>
#include "header.h"
#include <string.h>
using namespace std;

int main()
{
    Stiva *s;
    init(s);
    char c[256];
    cin.getline(c, 256);
    int i, x, y,rez=0;
    for (i = 0; i < strlen(c); i++)
    {
        if (Operand(c[i]))
            push(s, c[i]-'0');
        else if (Operator(c[i]))
        {
            x = top(s);
            pop(s);
            y = top(s);
            pop(s);
            if (x == 0 || y == 0)
            {
                cout << "eroare";
                return 0;
            }
            switch (c[i])
            {
            case '+':
                rez=x+y;
                break;
            case '-':
                rez=y-x;
                break;
            case '*':
                rez= y* x;
                break;
            case '/':
                rez= y / x;
                break;
            default:
                cout << "eroare";
            }
            push(s,rez);
        }
    }
    cout << top(s); //calcul in forma postfixa EX: 43+
}