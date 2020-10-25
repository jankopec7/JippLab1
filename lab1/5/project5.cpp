#include <iostream>
#include <stdlib.h>
#include <time.h>

#define W 2
#define K 3

using namespace std;

void print_matrix(int m[W][K]){
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){

    int matrix[W][K], matrix1[W][K], matrix2[W][K];

    srand(time(NULL));

    for(int i = 0; i < W; i++)
            for(int j = 0; j < K; j++){
            matrix1[i][j]=rand()%6;
            matrix2[i][j]=rand()%6;
            matrix[i][j]=matrix1[i][j]+matrix2[i][j];
            }

    cout << "Macierz 1: " << endl;
    print_matrix(matrix1);

    cout << "Macierz 2: " << endl;
    print_matrix(matrix2);

    cout << "Macierz wynikowa: " << endl;
    print_matrix(matrix);

    return 0;
}
