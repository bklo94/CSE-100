#include <iostream>
using namespace std;

void swap(int *x, int *y);
void heapsort(int arr[], int size);
void max_heapify(int arr[], int k, int size);

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void heapsort(int arr[], int size) {
	for(int k = size/2; k >= 0; k--) {
		max_heapify(arr, k, size);
	}
	while(size - 1 > 0) {
		swap(arr[size - 1], arr[0]);
		max_heapify(arr, 0, size - 1);
		size--;
	}
}

void max_heapify(int arr[], int k, int size) {
	while(k*2 + 1 < size) {
 		int child = 2*k + 1;
		if((child + 1 < size) && (arr[child] < arr[child + 1])) {
			child++;
		}
		if(arr[k] < arr[child]) {
			swap(arr[child], arr[k]);
			k = child;
		} else {
			return;
		}
	}
}

int main() {
	int i, size;
	cin >> size;
	int arr[size];
	for(i = 0; i < size; i++) {
		cin >> arr[i];
	}

	heapsort(arr, size);

	for (i = 0; i < size; i++) {
		cout << arr[i] <<endl;
	}
	return 0;
}
