#include <iostream>
#include <time.h>

using namespace std;


#include "macierz.hpp"


int main(){


	srand(time(NULL));

    //Przeciążanie operatorów

    Matrix m1(4,4);
    m1.wyp_macierz();
    cout << "Macierz m1:" << endl;
    m1.print();

    Matrix m2(4,4);
    m2.wyp_macierz();
    cout << "Macierz m2:" << endl;
    m2.print();

	Matrix *dodawanie = m1 + m2;
	cout << "Operacja dodawania:" << endl;
	dodawanie->print();

    Matrix *odejmowanie = m1 - m2;
	cout << "Operacja odejmowania:" << endl;
	odejmowanie->print();

    Matrix m3(4);
    m3.wyp_macierz();
    cout << "Macierz m3:" << endl;
    m3.print();
	Matrix *mnozenie = m3 * m3;
    cout << "Operacja mnożenia" << endl;
	mnozenie->print();

    bool wynik1, wynik2;
	wynik1 = m1 == m2;

	cout << "Porownanie macierzy m1 i m2:" << endl;
    cout << "Czy macierz m1 == m2? " << endl;
	if(wynik1 == true){
        cout << "Prawda" << endl;
    }
    else{
        cout << "Fałsz" << endl;
    }

	wynik2 = m1!= m2;
    cout << "Porownanie macierzy m1 i m2:" << endl;
    cout << "Czy macierz m1 != m2?:" << endl;
	if(wynik2 == false){
        cout << "Prawda" << endl;
    }
    else{
        cout << "Fałsz" << endl;
    }

    Matrix m4(3,4);
    m4.wyp_macierz();
    cout << "Macierz m4" << endl;
	m4.print();
	cout << "m4 po operacji ++ (do kazdego elementu macierzy dodano 1):" << endl;
	(m4)++;
	m4.print();

    Matrix m5(5,3);
    m5.wyp_macierz();
    cout << "Macierz m5:" << endl;
	m4.print();
	cout << "m5 po operacji -- (do kazdego elementu macierzy odjęto 1):" << endl;
	(m5)--;
	m5.print();

    Matrix m6(3,4);
    m6.wyp_macierz();
    cout << "Macierz m6:" << endl;
	m6.print();

	double* wsk = m6[0];
	int rozmiar = sizeof(wsk)/2;
	cout << "Lista zawierająca elementy 1 wiersza macierzy m6:" << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << wsk[i] << " ";
	}
    cout << endl;
    
/*
	double* ptr = m5[0];
	rozmiar = _msize(ptr) / sizeof(double);

	cout << "[] operator ([0]) returns:\n";
	for (size_t i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	cout << "\n\n";
*/
/*
    cout << "Tworze dwie macierze 4x4:" << endl;
    Matrix m1 = Matrix(4);  
    m1.wyp_macierz();
    cout << "Macierz m1: " << endl;
    m1.print();

    Matrix m2 = Matrix(4);  
    m2.wyp_macierz();
    cout << "Macierz m2: " << endl;
    m2.print();

    m1.set(1, 1, 7);
    cout << "Wartosc m1[1][1] ustawiam na " << m1.get(1, 1) << endl;
    m1.print();
    cout << "Tworze kolejna macierz m3:" << endl;

    Matrix m3 = Matrix(3,7);
    m3.wyp_macierz();
    m3.print();
    cout << "Macierz m3 ma " << m3.rows() << " wiersze i " << m3.cols() << " kolumn." << endl;

    Matrix *m4 = m1.add(m2);
    cout << "Macierz m4 to suma macierzy m1 i m2 ktorą zapisze do macierzy m5 oraz do pliku." <<endl;
    m4->print();
    m4->store("wynik.txt", "./Files/");

    cout << "Macierz m5 to roznica macierzy 1 i 2:" <<endl;
    Matrix *m5 = m1.subtract(m2);
    m5->print();

    cout << "Macierz m6 to iloczyn macierzy 1 i 2:" << endl;
    Matrix *m6 = m1.multiply(m2);
    m6->print();
*/
    return 0;
}
