#pragma once
#pragma once
#include "Pole.h"
#include "Plansza.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Gra :public Plansza
{
private:
	Plansza plansza;
	bool czyGra;
	Typ tura;
public:
	Gra();
	void petlaGry();
	void podanieKoordynatow();
};


