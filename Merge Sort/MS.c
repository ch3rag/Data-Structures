// MERGE SORT
// CHIRAG SINGH RAJPUT

#include <stdio.h>
#define INFINITY 9999

void Merge(int * A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	int i,j,k;
	
	for(i = 0; i < n1 ; i++) {
	 	L[i] = A[p + i];	
	}
	
	for(i = 0 ; i < n2 ; i++) {
		R[i] = A[q + i + 1];
	}
		
	L[n1] = INFINITY;
	R[n2] = INFINITY;
	
	i = 0, j = 0;
	
	for(k = p ; k <= r ; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int *A, int p, int r) {
	if(p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
} 

int main() {
	
	int a[8] = {1,-10,390,1235,12,199,20,-1};
	MergeSort(a,0,7);
	
	for(int i = 0 ; i < 8 ; i++) {
		printf("%d ", a[i]);
	}
	return 0;	
}
