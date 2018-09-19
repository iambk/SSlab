/**
 * Hail Commentless programming
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int head, seekTime = 0, n;
	
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

	for (int i=0; i<n; i++) {
		seekTime += abs(requestQueue[i] - head);
		head = requestQueue[i];
		printf("\nCurrent head -> %d", head);
	}

	avgSeekTime = (float)seekTime/n;

	printf("\n\nThe total seek time is: %d", seekTime);
	printf("\nThe average seek time is : %.3f", avgSeekTime);
	printf("\n");

	return 0;
}

