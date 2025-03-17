#include <iostream>
#include "header.h"
using namespace std;

int main(){
    Queue q;
    int n;
    init(q);
    cin>>n;
    while(n)
    {
        put(q,n);
        cin>>n;
    }
    cout<<"Front: "<<front(q)<<"\n";
    cout<<"Get: "<<get(q)<<"\n";
    cout<<"Front: "<<front(q)<<"\n";
    cout<<"Get: "<<get(q)<<"\n";
}