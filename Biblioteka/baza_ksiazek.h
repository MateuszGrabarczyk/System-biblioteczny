#pragma once
#include "ksiazka.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief Klasa przechowuje liste ksiazek w vectorze obiektow Ksiazka
*/
class Baza_ksiazek {
public:
	vector <Ksiazka> lista_ksiazek;
};