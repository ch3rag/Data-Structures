#include <iostream>

int binarySearch (int arr[], int low, int high, int key) {
	int mid = (low + high) / 2;
	while(low <= high) {

		if(arr[mid] == key) {
			return mid;
		} else if(arr[mid] > key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	return -1;
}

int main() {
	int arr[5] =  {1, 3, 5, 7, 9};
	std :: cout << binarySearch(arr, 0, 4, 3) << std :: endl;
	std :: cout << binarySearch(arr, 0, 4, 9) << std :: endl;
	std :: cout << binarySearch(arr, 0, 4, 34) << std :: endl;
	return 0;
}
