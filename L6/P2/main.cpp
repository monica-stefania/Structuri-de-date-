#include <iostream>
#include "header.h"
using namespace std;
int main(){
    Queue q;
    int n;
    init(q);
    cin>>n;
    while(n){
        put(q,n);
        cin>>n;
    }
    if(!isEmpty(q))
    {
        cout<<"Get: "<<get(q)<<"\n";
    }
    cout<<"Front: "<<front(q);
}