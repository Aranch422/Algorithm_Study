#include <iostream>

using namespace std;

int interpolation_search(int* arr,int low, int high, int key) {
	if (high == low) {
		if (arr[high] == key) return high;
		else return -1;
	}
	else {
		int target = arr[low] + (key - arr[low]) / (arr[high] - arr[low]) * (high - low);
		if (arr[target] < key) {
			low = target + 1;
			return interpolation_search(arr, low, high, key);
		}
		else {
			high = target;
			return interpolation_search(arr, low, high, key);
		}
	}
}

int fib_search(int* arr,int* fibarr ,int key) {
	int len = sizeof(arr) / 4;
	
}

int findFib(int* fibarr,int len) {
	for(int i=0;)
}

int main() {
	int fibarr[100];
	fibarr[0] = 0;
	fibarr[1] = 1;
	for (int i = 2; i < 100; i++) {
		fibarr[i] = fibarr[i - 1] + fibarr[i - 2];
	}
}