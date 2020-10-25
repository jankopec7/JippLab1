#include <iostream>

using namespace std;

void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
} 

void bubbleSort(int array[], int n){  

    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if (array[j] > array[j+1])  
                swap(&array[j], &array[j+1]);  
}  

int main(){

    int array[] = {100, 2, 30, 5, 8, 34, 56, 78, 90};
    int n = sizeof(array)/sizeof(array[0]); 

    bubbleSort(array, n);
    cout << "Posortowana tablica: \n";  
    for (int i = 0; i < n; i++){  
        cout << array[i] << " ";  
        cout << endl;  
    }
    return 0;
}
