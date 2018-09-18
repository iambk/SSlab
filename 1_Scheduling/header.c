#include "header.h"
#include <stdio.h>

int partition(struct Process A[], int p, int r, char basis){
  int x;
	if(basis=='s') x = A[r].bt;
  else if(basis=='p') x = A[r].priority;
	int i = p-1,j;
	for (j=p;j<=r-1;j++){
		if((basis=='s' && A[j].bt<=x) || (basis=='p' && A[j].priority<=x)) {
			i += 1;
			struct Process temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	struct Process temp = A[i+1];
	A[i+1] = A[r];
  A[r] = temp;
  return i+1;
}

void quickSort(struct Process A[], int p, int r,  char basis){
	if(p<r){
		int q = partition(A, p, r, basis);
		quickSort(A, p, q-1, basis);
		quickSort(A, q+1, r, basis);
	}
}