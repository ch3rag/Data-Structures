#include <iostream>
#include <vector>

int binarySearch (std :: vector <int> &arr, int key) {
	int low = 0;
	int high = arr.size() - 1;
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
	std :: vector <int> array = {1, 3, 5, 7, 9};
	std :: cout << binarySearch(array, 3) << std :: endl;
	std :: cout << binarySearch(array, 9) << std :: endl;
	std :: cout << binarySearch(array, 34) << std :: endl;
	return 0;
}
