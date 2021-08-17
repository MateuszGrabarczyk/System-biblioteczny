#pragma once
#include <iostream>
#include <string>
using namespace std;
/**
 * @brief Klasa, ktorej obiektem jest dana ksiazka, a jej atrybutami sa informacje o ksiazce
*/
class Ksiazka {
public:
	string nazwa, autor, gatunek, isbn;
public:
	Ksiazka(string n, string a, string g, string i);
	friend ostream& operator<<(ostream& out, const Ksiazka& ksiazka);
};
