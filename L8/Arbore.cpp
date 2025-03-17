#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "Arbore.h"
#include <iostream>
using namespace std;
static void eroare();
static char readchar();
static char citesteNume();
static Nod *citesteArbore();

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do
		c = getchar();
	while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car))
		eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod *citesteArbore()
{
	Nod *rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else
		{
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')
				eroare();
			car = readchar();
		}
	}
	return rad;
}

Nod *creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void inordine(Nod *root)
{
	if (root != 0)
	{
		inordine(root->stg);
		cout << (char)(root->data) << " ";
		inordine(root->drt);
	}
}
void postordine(Nod *root)
{
	if (root != 0)
	{
		postordine(root->stg);
		postordine(root->drt);
		cout << (char)(root->data) << " ";
	}
}
void preordine(Nod *root)
{
	if (root != 0)
	{
		cout << (char)(root->data) << " ";
		preordine(root->stg);
		preordine(root->drt);
	}
}

int adancime(Nod *root)
{
	int a = 1, b = 1;
	if (root)
	{
		a = a + adancime(root->stg);
		b = b + adancime(root->drt);
	}
	else
		return 0;
	if (a > b)
		return a;
	else
		return b;
}
int frunze(Nod *root)
{
	int nr = 0;
	if (root)
	{
		if (root->stg == 0 && root->drt == 0)
			return 1;
		else
			return nr + frunze(root->stg) + frunze(root->drt);
	}
	return 0;
}
int noduri(Nod *root)
{
	int a = 1;
	if (root)
	{
		if (root->stg != NULL || root->drt != NULL)
		{
			return a + noduri(root->stg) + noduri(root->drt);
		}
		else
			return 0;
	}
	else
		return 0;
}
char nodMax(Nod *root, char &maxi)
{
	if (root != 0)
	{
		if (root->data > maxi)
		{
			maxi = root->data;
			nodMax(root->stg, maxi);
			nodMax(root->drt, maxi);
		}
	}
	return maxi;
}
void nodurim(Nod *root)
{
	if (root != 0)
	{
		char m = 0;
		char maxim = nodMax(root, m);
		cout << maxim << " ";
		nodurim(root->stg);
		noduri(root->drt);
	}
}
void comutare(Nod *&root)
{
	if (!root)
	{
		return;
	}
	swap(root->stg, root->drt);
	comutare(root->stg);
	comutare(root->drt);
}

void afisare(Nod *root)
{
	if (root)
	{
		putchar(root->data);
		if (root->stg != 0 || root->drt != 0)
		{
			putchar('(');
			if (root->stg == NULL)
				putchar('-');
			else
				afisare(root->stg);
			putchar(',');
			if (root->drt == NULL)
				putchar('-');
			else
				afisare(root->drt);
			putchar(')');
		}
	}
}

void init(Queue &q)
{
	q.head = 0;
	q.tail = 0;
}
void put(Queue &q, Nod *root)
{
	if(root){
	Element *p = new Element;
	p->data = root;
	if (isEmpty(q))
	{
		p->next=0;
		q.tail = p;
		q.head = p;
	
	}
	else
	{
		p->next=0;
		q.tail->next = p;
		q.tail = p;
	}
	}
}
Nod *get(Queue &q)
{
	Element *p;
	Nod*val=0;
	if (!isEmpty(q))
	{
		p = q.head;
		val = p->data;
		if (q.tail == q.head)
		{
			q.head = 0;
			q.tail = 0;
			delete p;
		}
		else
		{
			q.head = q.head->next;
			delete p;
		}
		return val;
	}
	else 
	 return 0;
}

bool isEmpty(Queue q)
{
	if (q.head == 0 && q.tail == 0)
		return true;
	return false;
}

void afisare_nivelui(Nod *root)
{
	if (root != NULL)
	{
		Queue q;
		Nod *p=0;
		init(q);
		put(q, root);
		while (!isEmpty(q))
		{
			p = get(q);
			cout <<(char)(p->data)<< " ";
			if (p->stg != NULL)
				put(q, p->stg);
			if (p->drt != NULL)
				put(q, p->drt);
		}
	}
	else 
		 return;
}
