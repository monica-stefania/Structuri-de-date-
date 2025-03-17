#include <iostream>
#include "header.h"
using namespace std;

int main(){
    Nod*root=0;
    int n;
    cin>>n;
    while(n){
        inserare(root,n);
        cin>>n;
    }
    inordine(root);
    return 0;
}