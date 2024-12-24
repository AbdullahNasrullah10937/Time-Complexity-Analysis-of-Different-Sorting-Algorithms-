#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>   
#include <algorithm> 

using namespace std;

void populateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; 
    }
}

void countingSort(int arr[], int size) {
    
    int maxValue = *max_element(arr, arr + size);

    int* count = new int[maxValue + 1](); 

    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxValue; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count; 
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int size;

    while (true) {
        cout << "\nEnter the size of the array (or 0 to exit): ";
        cin >> size;

        if (size == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        int* arr = new int[size]; 
        populateArray(arr, size);

        cout << "Unsorted array: ";
        printArray(arr, size);

      
        auto start = chrono::high_resolution_clock::now();
        countingSort(arr, size);
        auto end = chrono::high_resolution_clock::now();
        // Calculate execution time
        chrono::duration<double> duration = end - start;

        cout << "Sorted array: ";
        printArray(arr, size);

        // Output runtime
        cout << "Time taken by counting sort: " << duration.count() << " seconds" << endl;

        delete[] arr; 
    }

    return 0;
}
