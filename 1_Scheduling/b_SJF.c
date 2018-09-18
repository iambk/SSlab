/**
 * Hail Commentless programming
 */

#include "header.h"
#include "header.c"
#include <stdio.h>

int main() {
	int n;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);

  if(n==0) {
		printf("Why would you even require an algorithm?");
		return 0;
	}

	struct Process P[n];
	int  wt[n], tat[n], swt=0, stat=0;
	float awt = 0, atat=0;

	printf("\nProcess \t Burst time\n");
  
	int i;
	for(i=0; i<n; i++) {
		printf("P[%d]\t\t", i);
		P[i].pid = i;
		scanf("%d", &P[i].bt);
		printf("\n");
	}

	quickSort(P, 0, n-1, 's');

	wt[0] = 0;
	tat[0] = P[0].bt;
	swt = 0;
	stat = tat[0];
	
	for(i=1; i<n; i++) {
		wt[i] = wt[i-1] + P[i-1].bt;
	 	tat[i] = tat[i-1] + P[i].bt;
	 	swt += wt[i];
	 	stat += tat[i];
 	}
  
	awt = (float)swt/n;
 	atat = (float)stat/n;
  
	printf("\nProcess \t Burst time \t Waiting time \t Turnaround time\n");
 	for(i=0;i<n;i++) {
 		printf("P[%d]\t\t%d\t\t%d\t\t%d", P[i].pid, P[i].bt, wt[i], tat[i]);
   	printf("\n");
 	}
  	
	printf("\n\nAverage waiting time: %.2lf", awt);
 	printf("\nAverage turnaround time: %.2lf", atat);
 	printf("\n");

	return 0;
}
