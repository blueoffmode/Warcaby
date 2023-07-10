#include "Plansza.h"

//konstruktor, w ktorym pionki sa przypisywane na dane pole w planszy
Plansza::Plansza() {
	a = b = x = y = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i < 3 && (i + j) % 2 == 0) {
				plansza[i][j] = Pole(Typ::BIALE);
			}
			else if (i > 4 && (i + j) % 2 == 0) {
				plansza[i][j] = Pole(Typ::CZARNE);
			}
			else {
				plansza[i][j] = Pole(Typ::PUSTE);
			}
		}
	}
}


//wypisuje plansze w konsoli
void Plansza::wypisz() {
	string litery = "ABCDEFGH";
	cout << endl;
	cout << " 12345678" << endl;
	for (int i = 0; i < 8; i++) {
		cout << litery.at(i);
		for (int j = 0; j < 8; j++) {
			if (plansza[i][j].getTyp() == Typ::BIALE) {
				cout << "B";
			}
			else if (plansza[i][j].getTyp() == Typ::CZARNE) {
				cout << "C";
			}
			else {
				cout << "#";
			}
		}
		cout << endl;
	}
}


//sprawdza czy wybralismy nasz pionek
bool Plansza::sprawdzPionek(int x, int y, Typ typ)
{
	if (plansza[x][y].getTyp() == typ) {
		return true;
	}
	return false;
}


//ustawia pole danemu pionkowi/pole luste
void Plansza::setPole(int x, int y, Typ typ)
{
	plansza[x][y] = Pole(typ);
}


//rekurancja zbijaj¹ca pionki po ukosie (zawsze zaczyna od lewego gorego pola)
bool Plansza::zbicie(int x, int y, int a, int b, Typ typ)
{
	//biale pionki
	if (typ == Typ::BIALE)
	{
		if (b > y && a > x) {
			if (plansza[a + 1][b + 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a + 1][b + 1] = Pole(Typ::BIALE);
				if (plansza[a][b + 2].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b + 1, a, b + 2, typ);
					return true;
				}
				else if (plansza[a + 2][b + 2].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b + 1, a + 2, b + 2, typ);
					return true;
				}
				else if (plansza[a + 2][b].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b + 1, a + 2, b, typ);
					return true;
				}
			}
		}
		else if (b < y && a > x)
		{
			if (plansza[a + 1][b - 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a + 1][b - 1] = Pole(Typ::BIALE);
				if (plansza[a][b - 2].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b - 1, a, b - 2, typ);
					return true;
				}
				else if (plansza[a + 2][b].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b - 1, a + 2, b, typ);
					return true;
				}
				else if (plansza[a + 2][b - 2].getTyp() == Typ::CZARNE) {
					zbicie(a + 1, b - 1, a + 2, b - 2, typ);
					return true;
				}
			}
		}
		else if (b < y && a < x)
		{
			if (plansza[a - 1][b - 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a - 1][b - 1] = Pole(Typ::BIALE);
				if (plansza[a - 2][b - 2].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b - 1, a - 2, b - 2, typ);
					return true;
				}
				else if (plansza[a - 2][b].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b - 1, a - 2, b, typ);
					return true;
				}
				else if (plansza[a][b - 2].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b - 1, a, b - 2, typ);
					return true;
				}
			}
		}
		else if (b > y && a < x)
		{
			if (plansza[a - 1][b + 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a - 1][b + 1] = Pole(Typ::BIALE);
				if (plansza[a - 2][b].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b + 1, a - 2, b, typ);
					return true;
				}
				else if (plansza[a - 2][b + 2].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b + 1, a - 2, b + 2, typ);
					return true;
				}
				else if (plansza[a][b + 2].getTyp() == Typ::CZARNE) {
					zbicie(a - 1, b + 1, a, b + 2, typ);
					return true;
				}
			}
		}
	}
	//czarne pionki
	else
	{
		if (b > y && a < x) {
			if (plansza[a - 1][b + 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a - 1][b + 1] = Pole(Typ::CZARNE);
				if (plansza[a - 2][b].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b + 1, a - 2, b, typ);
					return true;
				}
				else if (plansza[a - 2][b + 2].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b + 1, a - 2, b + 2, typ);
					return true;
				}
				else if (plansza[a][b + 2].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b + 1, a, b + 2, typ);
					return true;
				}
			}
		}
		else if (b > y && a > x) {
			if (plansza[a + 1][b + 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a + 1][b + 1] = Pole(Typ::CZARNE); {
					if (plansza[a][b + 2].getTyp() == Typ::BIALE) {
						zbicie(a + 1, b + 1, a, b + 2, typ);
						return true;
					}
					else if (plansza[a + 2][b + 2].getTyp() == Typ::BIALE) {
						zbicie(a + 1, b + 1, a + 2, b + 2, typ);
						return true;
					}
					else if (plansza[a + 2][b].getTyp() == Typ::BIALE) {
						zbicie(a + 1, b + 1, a + 2, b, typ);
						return true;
					}
				}
			}
		}
		else if (b < y && a < x)
		{
			if (plansza[a - 1][b - 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a - 1][b - 1] = Pole(Typ::CZARNE);
				if (plansza[a - 2][b - 2].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b - 1, a - 2, b - 2, typ);
					return true;
				}
				else if (plansza[a - 2][b].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b - 1, a - 2, b, typ);
					return true;
				}
				else if (plansza[a][b - 2].getTyp() == Typ::BIALE) {
					zbicie(a - 1, b - 1, a, b - 2, typ);
					return true;
				}
			}
		}
		else if (b < y && a > x) {
			if (plansza[a + 1][b - 1].getTyp() == Typ::PUSTE) {
				plansza[x][y] = Pole(Typ::PUSTE);
				plansza[a][b] = Pole(Typ::PUSTE);
				plansza[a + 1][b - 1] = Pole(Typ::CZARNE);
				if (plansza[a][b - 2].getTyp() == Typ::BIALE) {
					zbicie(a + 1, b - 1, a, b - 2, typ);
					return true;
				}
				else if (plansza[a + 2][b].getTyp() == Typ::BIALE) {
					zbicie(a + 1, b - 1, a + 2, b, typ);
					return true;
				}
				else if (plansza[a + 2][b - 2].getTyp() == Typ::BIALE) {
					zbicie(a + 1, b - 1, a + 2, b - 2, typ);
					return true;
				}
			}
		}
	}
	return false;
}


//sprawdza ile pionkow zostalo kazdemu graczowi
bool Plansza::ilePionkow() {
	int ileB = 12, ileC = 12;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (plansza[i][j].getTyp() == Typ::BIALE) {
				ileB--;
			}
			else if (plansza[i][j].getTyp() == Typ::CZARNE) {
				ileC--;
			}
		}
	}
	if (ileB == 0) {
		return true;
		cout << "Wygraly pionki czarne" << endl;
	}
	else if (ileC == 0) {
		return true;
		cout << "Wygraly pionki biale" << endl;
	}
	else {
		return false;
	}
}