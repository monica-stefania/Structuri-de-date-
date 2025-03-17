#include <iostream>
#include "header.h"
using namespace std;
int main(){
    Stiva *s;
    int n;
    cin>>n;
    while(n){
        push(s,n);
        cin>>n;
    }
    cout<<"Top: "<<top(s)<<"\n";
    cout<<"Pop: "<<pop(s)<<"\n";
    cout<<"Top: "<<top(s)<<"\n";
    cout<<"Pop: "<<pop(s)<<"\n";
    cout<<"Pop: "<<pop(s)<<"\n";
    cout<<"Top: "<<top(s)<<"\n";
    return 0;
}