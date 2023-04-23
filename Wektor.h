#pragma once

//E. Figielska, Metody programowania, 2019
//Edit: M. Klak, 2023

#include<iostream>
class Wektor {
	friend std::ostream & operator<<(std::ostream &, const Wektor &);
	friend std::istream & operator>>(std::istream &, const Wektor &);
	float * wspolrzedne{};
	int rozmiar{};
public:
	Wektor() {}
	Wektor(int rozmiar);
	Wektor(const Wektor &);
	~Wektor();
	
	Wektor& operator+(const Wektor &);
	void operator+=(const Wektor&);
	void operator-=(const Wektor&);
	Wektor& operator*(const float&);
	Wektor& operator/(const float&);
	Wektor& operator =(const Wektor&);
	Wektor& operator-(const Wektor &);
	float& operator[](int);
    void wpisz();
};