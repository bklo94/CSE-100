#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

int partion(int arr[], int p, int r) {
        int pivot_num = p + rand()%(r - p + 1);
        int pivot;
        int i = p - 1;
        int j;
        pivot = arr[pivot_num];
        swap(&arr[pivot_num], &arr[r]);
        for(j = p; j < r; j++) {
            if(arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[r]);
        return i + 1;
}

void quick_sort(int arr[], int p, int r) {
        if(p < r) {
            int q = partion(arr, p, r);
            quick_sort(arr, p, q-1);
            quick_sort(arr, q+1, r);
        }
}

int main() {
        int i, size, input;
		cin >> size;
        int arr[size];
        for(i = 0; i < size; i++) {
            cin >> arr[i];
		}

        quick_sort(arr, 0, size-1);

        for(i = 0; i < size; i++) {
             cout << arr[i] <<endl;
		}
        return 0;
}
