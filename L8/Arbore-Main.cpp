#include <iostream>
#include "Arbore.h"
using namespace std;

int main()
{
	Nod *root = creareArbore();

	cout<<"Inordine: "<<endl;
    inordine(root);
    cout<<endl;
    cout<<"Postordine: "<<endl;
    postordine(root);
	cout<<"Preordine: "<<endl;
    preordine(root);
    cout<<endl;
    cout<<"Adancimea arborelui este: "<<adancime(root)<<endl;
    cout<<"Nr de frunze este: "<<frunze(root)<<endl;
	cout<<"Nr de noduri interne: "<<noduri(root)<<endl;
	afisare_nivelui(root);
	cout<<"\n";
	char m=0;
	cout<<nodMax(root,m)<<" ";//afiseaza nodul maxim din arbore
	nodurim(root);
	cout<<endl;
	comutare(root);
	afisare(root);
	//A(B(-,C),D(E(F,-),G(H,-)))
	return 0;
}