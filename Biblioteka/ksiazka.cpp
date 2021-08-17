#include "ksiazka.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Ksiazka::Ksiazka(string n, string a, string g, string i) {	
	nazwa = n;
	autor = a;
	gatunek = g;
	isbn = i;
}

ostream& operator<<(ostream& out, const Ksiazka& ksiazka) {
	return out << "Nazwa ksiazki: " << ksiazka.nazwa << endl
		<< "Autor: " << ksiazka.autor << endl
		<< "Gatunek: " << ksiazka.gatunek << endl
		<< "Number ISBN: " << ksiazka.isbn << endl;
}

