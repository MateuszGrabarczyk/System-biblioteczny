#include "biblioteka.h"
#include "powitanie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;
/**
 * @brief Konstrukor, ktory odczytuje z plikow informacje i zapisuje je do atrybutów klasy Biblioteka
*/
Biblioteka::Biblioteka() {
	// Najpierw zczytujemy nasze ksi¹¿ki do vectora z ksi¹¿kami
	ifstream plik("ksiazki.txt");
	string linia; //pomocniczna zmienna w której bêdzie zapisywana ka¿da linia w pliku txt
	vector <string> linie_w_pliku; // tutaj znajdzie siê ca³a zawartoœæ naszego pliku tekstowego KSIAZKI
	if (plik) {
		while (getline(plik, linia)) {
			linie_w_pliku.push_back(linia); 
		}
	}
	else {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
	plik.close();
	for (auto w : linie_w_pliku) {
		string slowa[4]; // przechowuje nasze informacje o ksiazce 
		stringstream  ss(w);
		string str;
		int i = 0;
		while (getline(ss, str, ',')) {
			slowa[i] = str;
			i++;
		}
		
		string n = slowa[0]; // element o indeksie 0 przechowuje nazwe ksiazki
		string a = slowa[1];// element o indeksie 1 przechowuje autora ksiazki
		string g = slowa[2]; // element o indeksie 2 przechowuje gatunek ksiazki
		string ib = slowa[3]; // element o indeksie 3 przechowuje kod ISBN ksiazki
		Ksiazka pom(n, a, g, ib);
		lista_ksiazek.push_back(pom); // dodanie ksiazki do naszej listy ksiazek
		
	}
	////////////////////////////////////////////////////////////////////
	
	// Zczytujemy informacje do listy studentow
	ifstream plik1("studenci.txt");
	string linia1; //pomocniczna zmienna w której bêdzie zapisywana ka¿da linia w pliku txt
	vector <string> linie_w_pliku1; // tutaj znajdzie siê ca³a zawartoœæ naszego pliku tekstowego STUDENCI
	if (plik1) {
		while (getline(plik1, linia1)) {
			linie_w_pliku1.push_back(linia1);
		}
	}
	else {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
	plik1.close();
	for (auto w : linie_w_pliku1) {
		string slowa[4]; // przechowuje nasze informacje o studencie 
		stringstream  ss(w);
		string str;
		int i = 0;
		while (getline(ss, str, ',')) {
			slowa[i] = str;
			i++;
		}
		string id_pom = slowa[0]; // element o indeksie 0 przechowuje ID studenta
		string i_pom = slowa[1]; // element o indeksie 1 przechowuje imie studenta
		string n_pom = slowa[2]; // element o indeksie 2 przechowuje nazwisko studenta
		string h_pom = slowa[3]; // element o indeksie 3 przechowuje haslo studenta
		Student pom(id_pom, i_pom, n_pom, h_pom);
		lista_studentow.push_back(pom); // dodanie studenta do naszej listy studentow
	}
	////////////////////////////////////////////////////////////////////////////
	
	// Zczytujemy informacje do listy wypozyczonych ksiazek
	ifstream plik2("ksiazki_wypozyczone.txt");
	string linia2; //pomocniczna zmienna w której bêdzie zapisywana ka¿da linia w pliku txt
	vector <string> linie_w_pliku2; // tutaj znajdzie siê ca³a zawartoœæ naszego pliku tekstowego KSIAZKI_WYPOZYCZONE
	if (plik2) {
		while (getline(plik2, linia2)) {
			linie_w_pliku2.push_back(linia2);
		}
	}
	else {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
	plik2.close();
	for (auto w : linie_w_pliku2) {
		string slowa[8];
		stringstream ss(w);
		string str;
		int i = 0;
		while (getline(ss, str, ',')) {
			slowa[i] = str;
			i++;
		}
		string t_pom = slowa[0]; // element o indeksie 0 przechowuje nazwe ksiazki
		string a_pom = slowa[1]; // element o indeksie 1 przechowuje autora ksiazki
		string g_pom = slowa[2]; // // element o indeksie 2 przechowuje gatunek ksiazki
		string isbn_pom = slowa[3]; // element o indeksie 3 przechowuje kod ISBN ksiazki
		Ksiazka k_zmienna(t_pom, a_pom, g_pom, isbn_pom);

		string id_pom = slowa[4]; // element o indeksie 4 przechowuje ID studenta
		string imie_pom = slowa[5]; // element o indeksie 5 przechowuje imie studenta
		string nazwisko_pom = slowa[6]; // element o indeksie 6 przechowuje nazwisko studenta
		string haslo_pom = slowa[7]; // // element o indeksie 7 przechowuje haslo studenta
		Student s_zmienna(id_pom, imie_pom, nazwisko_pom, haslo_pom); 

		wypozyczone_ksiazki.push_back(make_pair(k_zmienna, s_zmienna)); 
		// dodanie do listy ksiazek wypozyczonej pary KSIAZKA-STUDENT
		// do kazdej ksiazki jest przyporzadkowany dany student
	}

}

/**
 * @brief Dekonstruktor
*/
Biblioteka::~Biblioteka()
{
}

/**
 * @brief Metoda nadpisuj¹ca nasze pliki zaaktualizowanymi ju¿ informacjami 
*/
void Biblioteka::nadpisz_plik()
{	// Nadpisanie pliku z ksiazkami
	ofstream plik("ksiazki.txt");
	if (plik) {
		for (auto i : lista_ksiazek) {
			string linia = i.nazwa + "," + i.autor + "," + i.gatunek + "," + i.isbn + "\n";
			plik << linia;
		}
	}
	else {
		cout << "Nie udalo sie nadpisac pliku" << endl;
	}
	plik.close();

	// Napisanie pliku ze studentami
	ofstream plik1("studenci.txt");
	if (plik1) {
		for (auto i : lista_studentow) {
			string linia = i.id + "," + i.imie + "," + i.nazwisko + "," + i.haslo + "\n";
			plik1 << linia;
		}
	}
	else {
		cout << "Nie udalo sie nadpisac pliku" << endl;
	}
	plik1.close();

	// Nadpisanie pliku z wypozyczonymi ksiazkami
	ofstream plik2("ksiazki_wypozyczone.txt");
	if (plik2) {
		for (auto pair : wypozyczone_ksiazki) {
			string linia = pair.first.nazwa + "," + pair.first.autor + "," + pair.first.gatunek + "," + pair.first.isbn
				+ "," + pair.second.id + "," + pair.second.imie + "," + pair.second.nazwisko + "," + pair.second.haslo + "\n";
			plik2 << linia;
		}
	}
	else {
		cout << "Nie udalo sie nadpisac pliku" << endl;
	}
	plik2.close();
}

/**
 * @brief Metoda dodaj¹ca ksi¹¿kê do vectora ksi¹¿ek dostêpnych w bibliotece
*/
void Biblioteka::dodaj_ksiazke()
{
	string nazwa, autor, gatunek, isbn;
	bool czy_istnieje = false;
	bool czy_ma_litery = false; // zmienna mowi nam czy podane ISBN zawiera litery
	string litery = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM,./!@#$%^&*()-_=+|\'\":;`[]{}<>?";
	cout << "Podaj nazwe ksiazki: ";
	cin.ignore();
	getline(cin, nazwa);
	cout << "Podaj autora: ";	
	getline(cin, autor);
	cout << "Podaj gatunek: ";
	getline(cin, gatunek);
	cout << "Podaj isbn: ";
	getline(cin, isbn);

	// Sprawdzenie czy istnieje ju¿ ksi¹¿ka o takim kodzie ISBN
	for (auto k : lista_ksiazek) {
		if (isbn == k.isbn) {
			czy_istnieje = true;
		}
	}
	// Sprawdzenie czy kod ISBN zawiera tylko cyfry
	for (auto i : isbn) {
		for (auto c : litery) {
			//string s(1, i); // konwertowanie chara do stringa na potrzeby ifa
			//string z(1, c); // konwertowanie chara do stringa na potrzeby ifa
			if (c == i) {
				czy_ma_litery = true; // Jesli ktorys ze znakow ISBN jest litera, zaznacz jako true
			}
		}
	}

	if (czy_istnieje == false and isbn.length() == 4 and czy_ma_litery == false) { // Sprawdzamy czy taka ksi¹¿ka nie istnieje oraz czy kod ISBN ma dok³adnie 4 znaki
		Ksiazka zmienna(nazwa, autor, gatunek, isbn); // tworzymy obiekt z konstruktorem 
		lista_ksiazek.push_back(zmienna); // dodajemy stworzon¹ ksi¹¿kê do vectora ksi¹¿ek
	}
	else {
		cout << "Ksiazka o danym kodzie ISBN juz isnieje lub podales niepoprawny kod ISBN, wrocisz teraz do menu glownego." << endl;
		system("pause");
	}
}

/**
 * @brief Metoda dodaj¹ca studenta do vectora studentow (kart studentow) w bibliotece
*/
void Biblioteka::dodaj_studenta()
{
	string id, imie, nazwisko, haslo;
	bool czy_istnieje = false;
	bool czy_ma_litery = false; // zmienna mowi nam czy podane ID zawiera litery 
	string litery = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM,./!@#$%^&*()-_=+|\'\":;`[]{}<>?"; 
	// string w którym sprawdzamy czy dany znak ID sie w nim znajduje
	cout << "Podaj id: ";
	cin.ignore();
	getline(cin, id);
	cout << "Podaj imie studenta: ";
	getline(cin, imie);
	cout << "Podaj nazwisko studenta: ";
	getline(cin, nazwisko);
	cout << "Podaj haslo przypisane do studenta: ";
	getline(cin, haslo);
	// Sprawdzenie czy student o podanym ID lub hasle juz istnieje
	for (auto k : lista_studentow) {
		if (id == k.id or haslo == k.haslo) {
			czy_istnieje = true;
		}
	}
	// Sprawdzenie czy podane ID zawiera litery
	for (auto i : id) {
		for (auto c : litery) {
			if (c == i) {
				czy_ma_litery = true; // Jesli ktorys ze znakow ID jest litera, zaznacz jako true
			}
		}
	}
	// Jesli student o podanym ID nie istnieje, kod ma 4 znaki 
	// oraz nie ma w sobie liter ani znakow specjalnych, dodaj do listy studentow
	if (czy_istnieje == false and id.length() == 4 and czy_ma_litery == false) {
		Student zmienna(id, imie, nazwisko, haslo); // tworzymy obiekt z konstruktorem 
		lista_studentow.push_back(zmienna);
	}
	else {
		cout << "Student o danym ID/hasle juz istnieje lub podano niepoprawnie ID/haslo, wrocisz teraz do menu glownego." << endl;
		system("pause");
	}

}

/**
 * @brief Metoda wyœwietlaj¹ca w konsoli wszystkie ksi¹¿ki dostêpne w bibliotece
*/
void Biblioteka::wyswietl_ksiazki()
{
	for (auto i : lista_ksiazek) {
		cout << i;
		cout << "------------------" << endl;
	}
}

/**
 * @brief Metoda wyœwietlaj¹ca w konsoli wszystkich studentów dostêpnych w bibliotece
*/
void Biblioteka::wyswietl_studentow()
{
	for (auto i : lista_studentow) {
		cout << i;
		cout << "------------------" << endl;
	}
}

/**
 * @brief Metoda usuwaj¹ca ksi¹¿ke z vectora ksi¹¿ek dostêpnych w bibliotece
*/
void Biblioteka::usun_ksiazke()
{
	int i = 0; // indeks elementu, który bêdziemy usuwaæ
	string kod;
	string tytul;
	bool czy_usunieto = false;
	for (auto i : lista_ksiazek) {
		cout << i.nazwa << " | " << i.autor << " | " << i.gatunek << " | " << i.isbn << endl; // Wyswietlamy na ekranie dostepne ksiazki w bibliotece
	}
	cout << "Podaj kod ISBN ksiazki, ktora chcesz usunac: ";
	cin >> kod;
	for (auto k : lista_ksiazek) {
		if (k.isbn == kod) { // Sprawdzamy czy podany kod pasuje do ktorejs z ksiazek
			tytul = k.nazwa;
			lista_ksiazek.erase(lista_ksiazek.begin() + i);
			czy_usunieto = true;			
			break;
		}
		i++;
	}
	if (czy_usunieto == false) {
		system("CLS");
		cout << "Nie znaleziono ksiazki o danym kodzie ISBN." << endl;
		system("pause");
	}
	
}

/**
 * @brief Metoda usuwaj¹ca studenta z vectora studentów (kart studentów) dostêpnych w bibliotece
*/
void Biblioteka::usun_studenta()
{
	int i = 0;
	string id;
	string nr;
	bool czy_istnieje = false;
	for (auto i : lista_studentow) {
		cout << i.id << " | " << i.imie << " | " << i.nazwisko << " | " << i.haslo << endl;
	}
	cout << "Podaj ID studenta, ktorego karte biblioteczna chcesz usunac: ";
	cin >> id;
	for (auto s : lista_studentow) {
		if (s.id == id) { // Sprawdzamy czy podane ID pasuje to ktoregos ze studentow
			nr = s.id;
			lista_studentow.erase(lista_studentow.begin() + i); // usuniecie studenta z vectora studentow
			czy_istnieje = true;
			break;
		}
		i++;
	}
	if (czy_istnieje == false) {
		system("CLS");
		cout << "Nie znaleziono studenta o danym ID." << endl;
		system("pause");
	}

}

/**
 * @brief Metoda dziêki której mo¿emy wyszukaæ ksi¹¿kê po jej tytule, autorze, gatunku lub kodzie ISBN
*/
void Biblioteka::wyszukaj_ksiazke()
{
	int odp;
	string zmienna;
	cout << "Po jakim kryterium chcesz wyszukac ksiazke:" << endl;
	cout << "1. Tytul" << endl;
	cout << "2. Autor" << endl;
	cout << "3. Gatunek" << endl;
	cout << "4. ISBN" << endl;
	cout << "Podaj odpowiedz: ";
	cin >> odp;
	system("CLS");
	if (odp == 1) {
		bool czy_znaleziono = false; // zmienna przechowuje informacje o tym czy ksiazka zostala znaleziona
		cout << "Podaj tytul ksiazki: ";
		cin.ignore();
		getline(cin, zmienna);
		for (auto k : lista_ksiazek) {
			if (k.nazwa == zmienna) {
				czy_znaleziono = true;
				cout << k;
			}
		}
		if (czy_znaleziono == false) {
			system("CLS");
			cout << "Nie znaleziono ksiazki o tym tytule. " << endl;
			system("pause");
			system("CLS");
		}
	}
	else if (odp == 2) {
		bool czy_znaleziono = false; // zmienna przechowuje informacje o tym czy ksiazka zostala znaleziona
		cout << "Podaj autora ksiazki: ";
		cin.ignore();
		getline(cin, zmienna);
		for (auto k : lista_ksiazek) {
			if (k.autor == zmienna) {
				czy_znaleziono = true;
				cout << k;
			}
		}
		if (czy_znaleziono == false) {
			system("CLS");
			cout << "Nie znaleziono ksiazki, ktorej autorem jest " << zmienna << endl;
			system("pause");
			system("CLS");
		}
	}
	else if (odp == 3) {
		bool czy_znaleziono = false; // zmienna przechowuje informacje o tym czy ksiazka zostala znaleziona
		cout << "Podaj gatunek ksiazki: ";
		cin.ignore();
		getline(cin, zmienna);
		for (auto k : lista_ksiazek) {
			if (k.gatunek == zmienna) {
				czy_znaleziono = true;
				cout << k;
			}
		}
		if (czy_znaleziono == false) {
			system("CLS");
			cout << "Nie znaleziono zadnej ksiazki/ksiazek o gatunku/tematyce " << zmienna << endl;
			system("pause");
			system("CLS");
		}
	}
	else if (odp == 4) {
		bool czy_znaleziono = false;
		cout << "Podaj kod ISBN ksiazki: ";
		cin.ignore();
		getline(cin, zmienna);
		for (auto k : lista_ksiazek) {
			if (k.isbn == zmienna) {
				czy_znaleziono = true;
				cout << k;
			}
		}
		if (czy_znaleziono == false) {
			system("CLS");
			cout << "Nie znaleziono zadnej ksiazki/ksiazek o kodzie ISBN " << zmienna << endl;
			system("pause");
			system("CLS");
		}
	}
	else {
		cout << "Wystapil blad, zostaniesz przeniesiony do menu studenta." << endl;
	}
}

/**
 * @brief Metoda umo¿liwiaj¹ca wypo¿yczenie danej ksi¹¿ki z biblioteki
 * @param S Student, który wypo¿ycza ksi¹¿kê
*/
void Biblioteka::wypozycz_ksiazke(Student S)
{
	int i = 0; // indeks elementu, ktory musimy usunac jesli ksiazka zostanie wypozyczona
	string odp;
	string tytul, autor, gatunek, isbn;
	bool czy_istnieje = false;
	cout << "Podaj tytul ksiazki, ktora chcesz wypozyczyc: ";
	cin.ignore();
	getline(cin, odp);
	for (auto k : lista_ksiazek) {
		if (odp == k.nazwa) {
			czy_istnieje = true;
			tytul = k.nazwa;
			autor = k.autor;
			gatunek = k.gatunek;
			isbn = k.isbn;
			Ksiazka zmienna(tytul, autor, gatunek, isbn);
			wypozyczone_ksiazki.push_back(make_pair(zmienna, S)); // utworzenie pary KSIAZKA-STUDENT
			// Do danej ksiazki jest przypisany dany student
			cout << "Wypozyczono ksiazke pt.\"" << tytul << "\"" << endl;
			system("pause");
			system("CLS");
		}
	}
	if (czy_istnieje == false) {
		system("CLS");
		cout << "Nie znaleziono ksiazki o danym tytule." << endl;
		system("pause");
		system("CLS");
	}
	else {
		// proces usuwania ksiazki zaczyna sie tutaj:
		for (auto k : lista_ksiazek) {
			if (k.nazwa == tytul) {
				lista_ksiazek.erase(lista_ksiazek.begin() + i);
				break;
			}
			i++;
		}
	}
}

/**
 * @brief Metoda umo¿liwiaj¹ca oddanie danej ksi¹¿ki przez studenta
 * @param S Student, który oddaje ksi¹¿kê
*/
void Biblioteka::oddaj_ksiazke(Student S)
{
	int ilosc_wyp_ksiazek = 0;
	// Wyswietlenie wszystkich ksiazek wypozyczonych przez danego studenta
	for (auto pair : wypozyczone_ksiazki) {
		if (pair.second.id == S.id) {
			ilosc_wyp_ksiazek++;
			cout << pair.first << endl;
		}
	}

	if (ilosc_wyp_ksiazek == 0) {
		cout << "Nie ma zadnej wypozyczonej ksiazki przypisanej do " << S.imie << " " << S.nazwisko
			<< "\nAby przejsc dalej kliknij ENTER" << endl;
		system("pause");
		system("CLS");
	}
	else {
		// oddanie danej ksiazki
		int i = 0; // indeks elementu, ktory musimy usunac jesli ksiazka zostanie oddana
		string odp;
		bool czy_istnieje = false;
		cout << "Podaj tytul ksiazki, ktora chcesz oddac: ";
		cin.ignore();
		getline(cin, odp);
		for (auto pair : wypozyczone_ksiazki) {
			if (odp == pair.first.nazwa and pair.second.id == S.id) { // pair.first to KSIAZKA, a pair.second to STUDENT
				czy_istnieje = true;
				string tytul, autor, gatunek, isbn;
				tytul = pair.first.nazwa;
				autor = pair.first.autor;
				gatunek = pair.first.gatunek;
				isbn = pair.first.isbn;
				Ksiazka zmienna(tytul, autor, gatunek, isbn);
				lista_ksiazek.push_back(zmienna); // Ta ksiazka wraca nam na liste ksiazek dostepnych w bibliotece
				wypozyczone_ksiazki.erase(wypozyczone_ksiazki.begin() + i); // usuniecie tej ksiazki z listy wypozyczonych ksiazek
				system("CLS");
				cout << "Oddano ksiazke pt.\"" << tytul << "\"" << endl;
				system("pause");
				system("CLS");
				break;
			}
			i++;
		}
		if (czy_istnieje == false) {
			system("CLS");
			cout << "Nie znaleziono ksiazki o danym tytule wypozyczonej przez " << S.imie << " " << S.nazwisko << endl;
			system("pause");
			system("CLS");
		}
	}
}

/**
 * @brief Metoda wypisujaca powitanie studenta w menu
*/
void Biblioteka::wypisz()
{
	cout << "Dzien dobry studencie. Wybierz jedna z opcji ponizej: " << endl;
}

/**
 * @brief Metoda wyswietlajaca wszystkie ksiazki wypozyczone przez danego studenta
 * @param S Student, ktorego wypozyczone ksiazki wyswietlamy
*/
void Biblioteka::wyswietl_ksiazki_wypozyczone(Student S)
{	
	int ilosc_wyp_ksiazek = 0;
	for (auto pair : wypozyczone_ksiazki) {
		if (pair.second.id == S.id) {
			ilosc_wyp_ksiazek++;
			cout << pair.first << endl;
		}
	}
	if (ilosc_wyp_ksiazek == 0) {
		cout << "Aktualnie nie masz zadnych wypozyczonych ksiazek." << endl;
	}
	system("pause");
	system("CLS");
}





