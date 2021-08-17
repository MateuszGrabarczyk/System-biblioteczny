#include "admin.h"
#include "powitanie.h"
#include <iostream>
using namespace std;

Admin::Admin() {
	login = "admin";
	haslo = "admin1";
}
Admin::~Admin() {

}

void Admin::wypisz()
{
	cout << "Dzien dobry adminie! Witamy w systemie." << endl;
}
