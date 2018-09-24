/**
 * Hail Commentless programming
 */

#include "header.h"
#include "header.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int head, seekTime = 0, n, max;
	
	printf("Enter the number of requests: ");
	scanf("%d", &n);

  if(n==0) {
		printf("Why would you even require an algorithm?");
		return 0;
	}

	int requestQueue[n];
	float avgSeekTime = 0.0;

	printf("Enter the request queue (separated by space or newline): ");
	for (int i=0; i<n; i++) {
		scanf("%d", &requestQueue[i]);
	}
	printf("Enter the head position: ");
	scanf("%d", &head);
	printf("Enter the maximum disk size: ");
	scanf("%d", &max);

  quickSort(requestQueue, 0, n-1);


	for (int i=0; i<n; i++) {
    if (head>requestQueue[i] && head<=requestQueue[i+1]) {
      for (int j=i+1; j<n; j++) {
        seekTime += abs(requestQueue[j] - head);
        head = requestQueue[j];
				printf("\nCurrent head -> %d", head);
      }
			seekTime += abs(max-head);
			head = max;
			printf("\nCurrent head -> %d", head);
      head = 0;
			printf("\nCurrent head -> %d", head);
      for (int k=0; k<=i; k++) {
        seekTime += abs(requestQueue[k] - head);
        head = requestQueue[k];
				printf("\nCurrent head -> %d", head);
      }
			break;
    }
	}

	avgSeekTime = (float)seekTime/n;

	printf("\n\nThe total seek time is: %d", seekTime);
	printf("\nThe average seek time is : %.3f", avgSeekTime);
	printf("\n");

	return 0;
}
