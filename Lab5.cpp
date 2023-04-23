#include "Wektor.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	Wektor a(3), b(2);
	a.wpisz();
	b.wpisz();

	Wektor a2(3), b2(2);
	a2.wpisz();
	b2.wpisz();
	
    Wektor c = a - b;
	cout << endl << "c: " << c;
	system("pause");
}

