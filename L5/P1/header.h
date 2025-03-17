#ifndef HEADER_H_
#define HEADER_H_
#define DIM_MAX 10
    struct Stiva{
        int vf;
        int v[DIM_MAX];
    };
void init(Stiva &s);
void push(Stiva &s, int val);
int pop(Stiva &s);
int top(Stiva s);
bool isEmpty(Stiva s);
bool isFull(Stiva s);
#endif