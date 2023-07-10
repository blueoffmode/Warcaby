#include "Gra.h"
using namespace std;
Gra::Gra() : plansza(Plansza()) {
	czyGra = 1;
	tura = Typ::BIALE;
	cout << "zaczynamy" << endl;
	x = y = a = b = -1;
}

void Gra::petlaGry() {
	while (czyGra) {
		//wypisanie tablicy
		plansza.wypisz();
		//podanie kordynatow
		podanieKoordynatow();
		system("cls");
		//sprawdzenie ile pionkow jeszcze zostalo
		if (!ilePionkow()) {
			czyGra = 0;
			break;
		}
	}
}

void Gra::podanieKoordynatow() {
	while (true) {
		x = 0, y = 0;
		string wybor, wyborRuchu;
		//wypisanie czyja tura
		if (tura == Typ::BIALE) {
			cout << "Tura bialych" << endl;
		}
		else {
			cout << "Tura czarnych" << endl;
		}
		cout << "Podaj koordynaty: ";
		cin >> wybor;
		//sprawdzenie i zmiana A1 na 00
		if (wybor.at(0) >= 'A' && wybor.at(0) <= 'H' && wybor.at(1) >= '1' && wybor.at(1) <= '8') {
			x = wybor.at(0) - 65;
			y = wybor.at(1) - 49;
		}
		//jesli zle wartosci przerwij petle
		else {
			cout << "zle wartosci" << endl;
			Sleep(2000);
			break;
		}
		//sprawdzamy czy wybralismy naszego pionka
		if (plansza.sprawdzPionek(x, y, tura)) {
			while (true) {
				a = 0, b = 0;
				cout << "podaj koordynaty ruchu (lub 9 aby wybrac inny): ";
				cin >> wyborRuchu;
				//sprawdzenie i zmiana A1 na 00
				if (wyborRuchu.at(0) >= 'A' && wyborRuchu.at(0) <= 'H' && wyborRuchu.at(1) >= '1' && wyborRuchu.at(1) <= '8') {
					a = wyborRuchu.at(0) - 65;
					b = wyborRuchu.at(1) - 49;
				}
				else if (wyborRuchu.at(0) == '9') {
					break;
				}
				else {
					cout << "zle wartosci" << endl;
					Sleep(2000);
					break;
				}
				//sprawdzamy ruch jaki wykonujemy
				if (plansza.sprawdzPionek(a, b, Typ::PUSTE)) {
					//sprawdz czy ruch nie jest do tylu
					if (a == x - 1 && tura == Typ::BIALE) {
						cout << "nie mozesz sie tu ruszyc" << endl;
						Sleep(2000);
						break;
					}
					else if (a == x + 1 && tura == Typ::CZARNE) {
						cout << "nie mozesz sie tu ruszyc" << endl;
						Sleep(2000);
						break;
					}
					//wykonaj ruch off jako wartosc lewo lub prawo od naszego pola np z pola 0,0 idziemy na off=1 i pole 1,1 lub 1,-1 (w tym przypadku niemozliwe)
					int off;
					if (tura == Typ::BIALE) {
						off = 1;
					}
					else {
						off = -1;
					}
					//ustawiamy pole w zaleznosci od zmiennej off
					if (a == x + off && b == y + 1 || b == y - 1) {
						plansza.setPole(x, y, Typ::PUSTE);
						plansza.setPole(a, b, tura);
						//ustawiamy czuja tura
						if (tura == Typ::BIALE) {
							tura = Typ::CZARNE;
						}
						else {
							tura = Typ::BIALE;
						}
						break;
					}
					else {
						cout << "nie moge wykonac ruchu" << endl;
					}
				}
				//jesli na tym polu jest nasz pionek ustawia komunikat
				else if (plansza.sprawdzPionek(a, b, tura)) {
					cout << "twoj pionek" << endl;
					break;
				}
				//sprawdza czy nastapilo zbicie, wywoluje rekurencje zbijania (powinno)
				else {
					if (plansza.zbicie(x, y, a, b, tura)) {
						if (tura == Typ::BIALE) {
							tura = Typ::CZARNE;
						}
						else {
							tura = Typ::BIALE;
						}
						break;
					}
				}
			}
			break;
		}
		else {
			cout << "podano zle koordynaty" << endl;
		}
	}
}