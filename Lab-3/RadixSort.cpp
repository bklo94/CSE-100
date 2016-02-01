#include <iostream>
#include <stdlib.h>
using namespace std;

class record{
	public:
		int key[11];
		record() {
			for(int i = 1; i <= 10; i++) {
				key[i] = 0;
			}
		}
};
record** arr;
record** arr1;

void Count_Sort(int i, int size) {
	int x, j, y, c[4];
	for(x = 0; x < 4; x++) {
		c[x] = 0;
	}
	for(j = 1; j <= size; j++) {
		c[arr[j]->key[i]] = c[arr[j]->key[i]]+1;
	}
	for(x = 1; x < 4; x++) {
		c[x] = c[x]+c[x-1];
	}
	for(j = size; j >= 1; j--) {
		arr1[c[arr[j]->key[i]]] = arr[j];
		c[arr[j]->key[i]] = c[arr[j]->key[i]]-1;
	}
	for (y = 1; y <= size; y++) {
		arr[y] = arr1[y];
	}
}

void Radix_Sort(int size) {
	for(int i = 10; i >= 1; i--) {
		Count_Sort(i, size);
	}
}

int main() {
	int i, j, size;
	cin >> size;
	arr = new record * [size + 1];
	arr1 = new record * [size + 1];

	for(i = 1; i <= size; i++) {
		arr[i] = new record();
		for(int j = 1; j <= 10; j++) {
			cin >> arr[i]->key[j];
		}
	}
	Radix_Sort(size);
	for(i = 1; i <= size; i++) {
		for(j = 1; j <= 10; j++) {
			cout << arr[i]->key[j] << ";";
		}
		cout << "\n";
	}
	for(i = 1; i <= size; i++) {
		delete arr[i];
	}
	delete[] arr;
	delete[] arr1;
	return 0;
}
