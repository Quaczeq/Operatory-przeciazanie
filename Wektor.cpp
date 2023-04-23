#include "Wektor.h"
using namespace std;
Wektor::Wektor(int r) {
	this->rozmiar = r;
	wspolrzedne = new float[r];
}
Wektor::Wektor(const Wektor & w) {//definicja konstruktora kopiujacego
	wspolrzedne = new float[rozmiar = w.rozmiar];//utworzenie tablicy dynamicznej o rzmiarze jak w w 
	for (int i = 0; i < rozmiar; i++) {
		wspolrzedne[i] = w.wspolrzedne[i]; //przepisanie wartosci z w
	}
}
Wektor::~Wektor() {
	delete[] wspolrzedne;
}

Wektor& Wektor::operator+(const Wektor & w) {//operator+ jako metoda 
	int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
	Wektor * tmp = new Wektor(r);//wektor wynikowy ma rozmiar miejszego z dodawanych wektorów
	for (int i = 0; i < r; i++) {
		tmp->wspolrzedne[i] = wspolrzedne[i] + w.wspolrzedne[i];
	}
	return *tmp;
}

Wektor& Wektor::operator-(const Wektor& w) {
    int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
    Wektor* tmp = new Wektor(r);
    for (int i = 0; i < r; i++) {
        tmp->wspolrzedne[i] = wspolrzedne[i] - w.wspolrzedne[i];
    }
    return *tmp;
}

void  Wektor::operator+=(const Wektor& w) {//operator+ jako metoda 
	int r = rozmiar < w.rozmiar ? rozmiar : w.rozmiar;
	for (int i = 0; i < r; i++) {
		wspolrzedne[i] += w.wspolrzedne[i];
	}
}

Wektor& Wektor::operator =(const Wektor & w) {
	if (this != &w) {
		if (rozmiar != w.rozmiar) {
			delete[] wspolrzedne;
			wspolrzedne = new float[rozmiar = w.rozmiar]; //tworzymy wektor o rozmiarze wektora w
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