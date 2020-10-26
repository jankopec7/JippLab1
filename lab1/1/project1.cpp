#include <iostream>

using namespace std;

void printArray(int arr[], int size){  

    for (int i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
} 

void bubbleSort(int array[], int n){

    for (int i = 1; i < n; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if (array[j] > array[j+1])  
                swap(&array[j], &array[j+1]);  
}

int main(int argc, char **argv){

    int *array = new int[argc - 1];

    for (int i = 0; i < argc - 1; i++)
        array[i] = atoi(argv[i + 1]);

    cout << "sort.exe ";
    printArray(array, argc - 1); 

    bubbleSort(array, argc);

    cout << "out = ";
    printArray(array, argc - 1); 

    delete[] array;
    return 0;
}
