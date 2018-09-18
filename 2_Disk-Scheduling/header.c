#include "header.h"
#include <stdio.h>

int partition (int A[], int p, int r){
  int x = A[r];
	int i = p-1,j;
	for (j=p;j<=r-1;j++){
		if (A[j]<=x) {
			i += 1;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
  A[r] = temp;
  return i+1;
}

void quickSort (int A[], int p, int r){
	if(p<r){
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}