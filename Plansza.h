#pragma once
#include <iostream>
#include "Pole.h"

using namespace std;

class Plansza
{
private:
	Pole plansza[8][8];
public:
	int x, y, a, b;
	Plansza();
	void wypisz();
	bool sprawdzPionek(int x, int y, Typ typ);
	void setPole(int x, int y, Typ typ);
	bool zbicie(int x, int y, int a, int b, Typ typ);
	bool ilePionkow();
};