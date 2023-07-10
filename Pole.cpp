#include "Pole.h"

//przypisywanie danego pionka do danego miejsca na planszy
Pole::Pole(Typ typ_) {
	typ = typ_;
}

//przypisywanie pola pustego na planszy
Pole::Pole() {
	typ = Typ::PUSTE;
}

//zwracanie danego typu na plansze
Typ Pole::getTyp() {
	return typ;
}