#pragma once
#include <iostream>
#include "powitanie.h"
using namespace std;

class Admin: public Powitanie {
public:
	string login, haslo;
public:
	Admin();
	~Admin();
	void wypisz();
};