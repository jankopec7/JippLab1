#include <iostream>

using namespace std;

void swap(int **x, int **y){

    int *temp = *x;
    *x = *y;
    *y = temp;
}

int main() {

    int *a = new int;
    int *b = new int;

    *a = 33 ;
    *b = 78;

    cout << "a i b przed zamianią : " << endl << a << " " << *a << endl << b << " " << *b << endl;

    swap(&a, &b);
 
    cout << "a i b po zamianie : " << endl << a << " " << *a << endl << b << " " << *b << endl;

    return 0;
}