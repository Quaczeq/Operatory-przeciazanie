#include "Wektor.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	Wektor a(3), b(2);
	a.wpisz();
	b.wpisz();
	
    Wektor c = a - b;
	cout << endl << "c: " << c;
	c -= b;
	cout << endl << "(c-=b) c : " << c;

	system("pause");
}

