#pragma once
#include "baza_studentow.h"
#include "baza_ksiazek.h"
#include "student.h"
#include "ksiazka.h"
#include "powitanie.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief Klasa, ktora posiada wszystkie dane w bibliotece, czyli liste ksiazke, studentow oraz wypozyczonych ksiazek
*/
class Biblioteka : public Baza_ksiazek, public Baza_studentow, public Powitanie {
public:
	vector<pair<Ksiazka, Student>> wypozyczone_ksiazki;
public:
	Biblioteka();
	~Biblioteka();
	void nadpisz_plik();
	void dodaj_ksiazke();
	void dodaj_studenta();
	void wyswietl_ksiazki();
	void wyswietl_studentow();
	void usun_ksiazke();
	void usun_studenta();
	void wyszukaj_ksiazke();
	void wypozycz_ksiazke(Student S);
	void oddaj_ksiazke(Student S);
	void wypisz();
	void wyswietl_ksiazki_wypozyczone(Student S);
};