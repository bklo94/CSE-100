#include <iostream>
#include <deque>
#include <math.h>
using namespace std;


deque<int> insertion_sort(deque<int> &arr);
deque<int> merge(const deque<int> &left, const deque<int> &right);
deque<int> merge_sort(deque<int> &arr);


deque<int> merge_sort(deque<int> &arr) {
	if(arr.size() == 1 ) {
		return arr;
	}
	else if(arr.size() >= 10) {
		deque<int>::iterator middle = arr.begin() + (arr.size()/2);
		deque<int> left(arr.begin(), middle);
		deque<int> right(middle, arr.end());
		left = merge_sort(left);
		right = merge_sort(right);
		return merge(left, right);
	} else {
        return insertion_sort(arr);
	}
}

deque<int> insertion_sort(deque<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        int j, value = arr[i];
        for(j = i - 1; j >= 0 && value < arr[j]; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = value;
    }
    return arr;
}

deque<int> merge(const deque<int> &left, const deque<int> &right) {
    deque<int> result;
    int left_index = 0, right_index = 0;
    while(left_index < left.size() && right_index < right.size()) {
        if(left[left_index] < right[right_index]) {
            result.push_back(left[left_index]);
            left_index++;
        } else {
            result.push_back(right[right_index]);
            right_index++;
        }
    }
    while(right_index < right.size()) {
        result.push_back(right[right_index]);
        right_index++;
    }
    while(left_index < left.size()) {
        result.push_back(left[left_index]);
        left_index++;
    }
    return result;
}

int main(int argc, char *argv[]) {
	int length, input, i;
	cin >> length;
    	deque<int> arr;
	for(i = 0; i < length; i++) {
		cin >> input;
		arr.push_back(input);
	}
	arr = merge_sort(arr);
	for(i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
