#include "Wektor.h"

using namespace std;

Wektor::Wektor(int r) {
	this->rozmiar = r;
	wspolrzedne = new float[r];
}
Wektor::Wektor(const Wektor & w) { //konstruktor kopiujacy
	wspolrzedne = new float[rozmiar = w.rozmiar]; //tworzenie tablicy dynamicznej o rozmiarze w 
	for (int i = 0; i < rozmiar; i++) {
		wspolrzedne[i] = w.wspolrzedne[i]; //nadanie nowej tablicy takich samych wartosci
	}
}
Wektor::~Wektor() { //destruktor
	delete[] wspolrzedne;
}

Wektor& Wektor::operator+(const Wektor & w) { //operator jako metoda 
	int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
	Wektor * tmp = new Wektor(r); //wektor wynikowy ma rozmiar miejszego z dodawanych wektorów
	for (int i = 0; i < r; i++) {
		tmp->wspolrzedne[i] = wspolrzedne[i] + w.wspolrzedne[i];
	}
	return *tmp;
}

Wektor& Wektor::operator-(const Wektor& w) {
    int r = rozmiar < w.rozmiar ? w.rozmiar : rozmiar;
    Wektor* tmp = new Wektor(r);
    for (int i = 0; i < r; i++) {
        tmp->wspolrzedne[i] = wspolrzedne[i] - w.wspolrzedne[i];
    }
    return *tmp;
}

void Wektor::operator+=(const Wektor& w) {
	int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
	for (int i = 0; i < r; i++) {
		wspolrzedne[i] += w.wspolrzedne[i];
	}
}

void Wektor::operator-=(const Wektor& w) {
	int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
	for (int i = 0; i < r; i++) {
		wspolrzedne[i] -= w.wspolrzedne[i];
	}
}

Wektor& Wektor::operator*(const float& skalar) {
	int r = rozmiar;
    Wektor* tmp = new Wektor(r);
    for (int i = 0; i < r; i++) {
        tmp->wspolrzedne[i] = wspolrzedne[i] * skalar;
    }
    return *tmp;
}

Wektor& Wektor::operator/(const float& skalar) {
	if (skalar == 0) throw runtime_error ("Nie dzielimy przez 0!");
	int r = rozmiar;
    Wektor* tmp = new Wektor(r);
    for (int i = 0; i < r; i++) {
        tmp->wspolrzedne[i] = wspolrzedne[i] / skalar;
    }
    return *tmp;
}

Wektor& Wektor::operator =(const Wektor & w) {
	if (this != &w) {
		if (rozmiar != w.rozmiar) {
			delete[] wspolrzedne;
			wspolrzedne = new float[rozmiar = w.rozmiar];
		}
		for (int i = 0; i < rozmiar; i++)
			wspolrzedne[i] = w.wspolrzedne[i];
	}
	return *this;
}

void Wektor::wpisz() {
	cout << "\nPodaj wspolrzedne (" << rozmiar << "): ";
	for (int i = 0; i < rozmiar; i++) {
		cin >> wspolrzedne[i];
	}

}

ostream & operator<<(ostream & o, const Wektor & w){
	for (int i = 0; i < w.rozmiar; i++)
		o << w.wspolrzedne[i] << " ";
	return o;
}

istream & operator>>(istream & is, const Wektor & w) {
	for (int i = 0; i < w.rozmiar; i++) {
		is >> w.wspolrzedne[i];
	}
	return is;
}

float& Wektor::operator[](int index) {
if (index >= rozmiar) throw out_of_range("Nieprawidlowy indeks!");
return wspolrzedne[index];
}