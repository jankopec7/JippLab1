#include <iostream>
#include <algorithm>

using namespace std;


void my_swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int main(){

    int a1 = 17, b1 = 31;


    cout << " a i b przed zamianią : " << a1 << " " << b1 << endl;

    swap(a1,b1);

    cout << " a i b po zamianie : " << a1 << " " << b1 << endl;

    double a2 = 1.17, b2 = 5.311;

    cout << " a i b przed zamianią : " << a2 << " " << b2 << endl;

    swap(a1,b1);

    cout << " a i b po zamianie : " << a2 << " " << b2 << endl;

    float a3 = 3.33, b3 = 15.7;

    cout << " a i b przed zamianią : " << a3 << " " << b3 << endl;

    swap(a3,b3);

    cout << " a i b po zamianie : " << a3 << " " << b3 << endl;

    char a4 = 'a', b4 = 'b';

    cout << " a i b przed zamianią : " << a4 << " " << b4 << endl;

    swap(a4,b4);

    cout << " a i b po zamianie : " << a4 << " " << b4 << endl;
}