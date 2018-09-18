/**
 * Hail Commentless programming
 */

#include "header.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
  int n;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);

	if(n==0) {
		printf("Why would you even require an algorithm?");
		return 0;
	}

	int i, rem_bt[n], bt[n], wt[n], tat[n], swt=0, stat=0, quantum;
	float awt=0, atat=0;

	printf("\nEnter the burst time for each process.\n");
	printf("Process\t\tBurst time\n");
	for(i=0; i<n; i++) {
		printf("P[%d]\t\t", i);
		scanf("%d", &bt[i]);
    rem_bt[i] = bt[i];
		printf("\n");
	}
  printf("\nEnter the quantum time: ");
  scanf("%d", &quantum);
  
  int t = 0;

  while(1) {
    bool done = true;
    for (int i=0; i<n; i++) {
      if (rem_bt[i] > 0) {
        done = false;
        if (rem_bt[i] > quantum) {
          t += quantum;
          rem_bt[i] -= quantum;
        } else {
          t = t + rem_bt[i];
          wt[i] = t - bt[i];
          rem_bt[i] = 0;
        }
      }
    }
    if (done == true)
      break;
  }

  for (int i=0; i<n ; i++)
    tat[i] = bt[i] + wt[i];

  for (int i=0; i<n; i++) {
    swt = swt + wt[i];
    stat = stat + tat[i];
  }

  awt = (float)swt / n;
  atat = (float)stat / n;

  printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
  for (i = 0; i < n; i++) {
    printf("P[%d]\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    printf("\n");
  }

  printf("\n\nAverage waiting time: %.2lf", awt);
  printf("\nAverage turnaround time: %.2lf", atat);
  printf("\n");
  return 0;
}
