#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    Stiva s;
    int n;
    init(s);
    cin>>n;
    while(n){
        push(s,n);
        cin>>n;
    }
    cout<<"Pop: "<<pop(s)<<endl;
    cout<<"Top: "<<top(s)<<endl;
    cout<<"Pop: "<<pop(s)<<endl;
    cout<<"Top: "<<top(s)<<endl;
    cout<<"Pop: "<<pop(s)<<endl;
    
    if(isEmpty(s))
        cout<<"Stiva este goala"<<"\n";
    else if(isFull(s))
        cout<<"Stiva este plina"<<"\n";
        else
            cout<<"Stiva nu este plina"<<"\n";
    return 0;
}