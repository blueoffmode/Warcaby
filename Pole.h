#pragma once

//pionki/pole puste
enum class Typ
{
	PUSTE, BIALE, CZARNE
};

class Pole
{
private:
	Typ typ;
public:
	Pole(Typ typ_);
	Pole();
	Typ getTyp();
};