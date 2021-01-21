#include <iostream>
#include <time.h>

using namespace std;


#include "macierz.hpp"


int main(){


	srand(time(NULL));

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

    return 0;
}
