#include <iostream>

using namespace std;

int licz(int a, int b, int &suma){

    suma = a + b;
    return a * b;
}

int main(){

    int a, b, suma = 0;

    cout << "Podaj liczbę a: ";
    cin >> a;
    cout << "Podaj liczbę b: ";
    cin >> b;

    cout << "Iloczyn a i b: " << licz(a, b, suma) << endl << "Suma a i b: " << suma << endl;

    return 0;
}