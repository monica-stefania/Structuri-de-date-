#ifndef HEADER_H_
#define HEADER_H_
struct Stiva{
    int data;
    Stiva*next;
};
void init(Stiva *&s);
void push(Stiva*&s, int val);
void pop(Stiva*&s);
int top(Stiva*s);
bool isEmpty(Stiva *s);
bool Operator(char c);
bool Operand(char c);
#endif