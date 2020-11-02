#include <iostream>

using namespace std;


void zamiana(int *x, int *y){  
    
    int temp;

    if(*y < *x){
    temp = *x; 
    *x = *y;  
    *y = temp;  
    }
} 

int main(){

    int a, b;

    cout << "Podaj liczbę a: ";
    cin >> a;
    cout << "Podaj liczbę b: ";
    cin >> b;
   
    zamiana(&a,&b);
    
    cout << " a i b po zamianie : " << a << " " << b << endl;

    return 0;
}

