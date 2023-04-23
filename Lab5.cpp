#include "Wektor.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	Wektor a(3), b(2);
	a.wpisz();
	b.wpisz();
	
    Wektor c = a + b; //wywolanie funkcji/metody operator+()
	cout << endl << "c: " << c;
	a += c;       //wywolanie funkcji/metody operator+=()
	cout << endl << "a: " << a;
	b = a;        //wywolanie metody operator=()
	cout << endl << "b: " << b; //wywolanie metody operator<<()
	Wektor d = a + b + c;
	cout << endl << "d: " << d ; //wywolanie metody operator<<()
}

