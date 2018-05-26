class BinarySearch {
	public static int binarySearch(int arr[], int key) {
		int low = 0;
		int high = arr.length - 1;
		int mid = (high + low) / 2;
		while(low <= high) {
			if(arr[mid] == key) {
				return mid;
			} else if (arr[mid] > key) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}

			mid = (high + low) / 2;
		}
		return -1;
	}

	public static void main(String[] args) {
		int arr[] = {1, 3, 5, 7, 9};
		System.out.println(binarySearch(arr, 3));
		System.out.println(binarySearch(arr, 9));
		System.out.println(binarySearch(arr, 34));
		}
}
