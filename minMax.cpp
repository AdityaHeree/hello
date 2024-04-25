#include <iostream>
#include <omp.h>
#include <climits>

using namespace std;

void min_reduction(int *arr, int size) {
    int min_value = INT_MAX;
    
    // OpenMP parallel reduction for finding the minimum value
    #pragma omp parallel for reduction(min:min_value)
    for (int i = 0; i < size; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    
    cout << "Minimum Value: " << min_value << endl;
}

void max_reduction(int *arr, int size) {
    int max_value = INT_MIN;
    
    // OpenMP parallel reduction for finding the maximum value
    #pragma omp parallel for reduction(max:max_value)
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    
    cout << "Maximum Value: " << max_value << endl;
}

int sum_reduction(int *arr, int size) {
    int sum = 0;
    
    // OpenMP parallel reduction for calculating the sum
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    cout << "Sum value: " << sum << endl;
    
    return sum;
}

void average_reduction(int *arr, int size) {
    int sum = sum_reduction(arr, size);
    double average = static_cast<double>(sum) / size;
    
    cout << "Average value: " << average << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Allocate memory for the dynamic array
    int *arr = new int[size];

    // Input array elements from the user
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Call reduction functions
    min_reduction(arr, size);
    max_reduction(arr, size);
    sum_reduction(arr, size);
    average_reduction(arr, size);

    // Deallocate memory for the dynamic array
    delete[] arr;

    return 0;
}
