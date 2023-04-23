#include "Wektor.h"
#include<iostream>
#include<string>
#include<exception>

using namespace std;

int main() {
	Wektor a(3), b(2);
	a.wpisz();
	b.wpisz();

// Odejmowania	
    Wektor c = a - b;
	cout << endl << "c: " << c;
	c -= b;
	cout << endl << "(c-=b) c : " << c;

//Mnozenie i dzielenie
	Wektor g = c * 3.5;
	cout << endl << g;
 	
	try {
		Wektor f = c / 0;
		cout << endl << f;
	}
	catch (runtime_error & e){
		cout << endl << "Blad " << e.what() << endl;
	}

//Przeciazenie operatora []
	try {
		cout << endl << a[1] << endl;
	}
	catch (out_of_range & e) {
		cout << "Blad" << e.what() << endl;
	}

//Przeciazenie operatora >>
	cout << endl << "Podaj wartosci wektora a (3): ";
	cin >> a;
	cout << a;
	system("pause");
}

