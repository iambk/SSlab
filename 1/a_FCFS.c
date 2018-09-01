#include<stdio.h>

int main() {
	int n;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	if(n==0) {
		printf("Why would you even require an algorithm?");
		return 0;
	}
	int i, bt[n], wt[n], tat[n], swt=0, stat=0;
	float awt=0, atat=0;
	printf("\nEnter the burst time for each process.\n");
	printf("Process\t\tBurst time\n");
	for(i=0; i<n; i++) {
		printf("P[%d]\t\t", i);
		scanf("%d", &bt[i]);
		printf("\n");
	}
	wt[0] = 0;
	tat[0] = bt[0];
	stat = tat[0];

	for(i=1; i<n; i++) {
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		swt += wt[i];
		stat += tat[i];
	}

	awt = (float)swt/n;
	atat = (float)stat/n;

	printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
	for(i=0;i<n;i++) {
		printf("P[%d]\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
		printf("\n");
	}

	printf("\n\nAverage waiting time: %.2lf", awt);
	printf("\nAverage turnaround time: %.2lf", atat);
	printf("\n");
	return 0;
}
