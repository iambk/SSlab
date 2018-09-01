#include<stdio.h>

struct Process {
	int pid;
	int bt;
	int priority;
};

int partition(struct Process A[], int p, int r){
	int x = A[r].priority;
	int i = p-1,j;
	for (j=p;j<=r-1;j++) {
		if (A[j].priority<=x) {
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

void quickSort(struct Process A[], int p, int r){
	if (p<r) {
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main() {
	int n, i;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	int wt[n], tat[n], swt=0, stat=0;
	float awt=0, atat=0;
	struct Process P[n];

	printf("\nProcess \t Burst time \t Priority");
	for (i=0;i<n;i++) {
		printf("\nP[%d]\t", i);
		scanf("%d%d", &P[i].bt, &P[i].priority);
	}

  quickSort(P, 0, n-1);

	printf("\nProcess \t Burst time");
	for (i=0; i<n; i++)
		printf("\n%d\t\t%d", P[i].pid, P[i].bt);

	wt[0] = 0;
	P[0].pid = 0;
	tat[0] = P[0].bt;
	swt = 0;
	stat = tat[0];
	
	for (i=1; i<n; i++) {
		P[i].pid = i;
		wt[i] = wt[i-1] + P[i-1].bt;
	 	tat[i] = tat[i-1] + P[i].bt;
	 	swt += wt[i];
	 	stat += tat[i];
 	}
  
	awt = (float)swt/n;
 	atat = (float)stat/n;
  
	printf("\nProcess \t Burst time \t Waiting time \t Turnaround time\n");
 	for (i=0;i<n;i++) {
 		printf("P[%d]\t\t%d\t\t%d\t\t%d", P[i].pid, P[i].bt, wt[i], tat[i]);
   	printf("\n");
 	}
  	
	printf("\n\nAverage waiting time: %.2lf", awt);
 	printf("\nAverage turnaround time: %.2lf", atat);
 	printf("\n");
  
}
