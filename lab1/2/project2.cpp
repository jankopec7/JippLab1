#include <iostream>
#include <string>
 
using namespace std;

int main(){

    string wyraz;
    int i, j;
 
    cout << "Podaj wyraz: ";
    cin >> wyraz;

    j = wyraz.length()-1;

    for (i = 0; i < j; i++){
        if (wyraz[i] != wyraz[j])
        break;
        j--;
        }

    if (i == j)
    cout << "Podany wyraz to palindrom" << endl;
    else 
    cout << "Podany wyraz nie jest palindromem" << endl;

    return 0;
}