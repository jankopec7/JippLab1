#include <iostream>

using namespace std;

int main(){

    int a, b;
    int sum1 = 0, sum2 = 0;

    cout << "Podaj liczbę a: ";
    cin >> a;
    cout << "Podaj liczbę b: ";
    cin >> b;

    for (int i = 1; i < a; i++)
        if ( a % i == 0 ) { 
        sum1 += i;
        }

    for (int j = 1; j < b; j++)
        if ( b % j == 0 ) {
        sum2 += j;
        }

    if (sum1 == b+1 && sum2 == a+1) 
    cout << " a i b są liczbami skojarzonymi" << endl;
    else 
    cout << " a i b nie są liczbami skojarzonymi " << endl;

    return 0;
    }
