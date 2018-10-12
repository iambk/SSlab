#include<stdio.h>
#include<stdbool.h>

int main() {
	int n, m;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the number of type of resources: ");
	scanf("%d", &m);

  int Available[m], Max[n][m], Allocation[n][m], Need[n][m], Work[n][m];
	bool Finish[n];

	printf("\nHow much of each resource type is available(Available[A B C...]: ");
	for (int i=0; i<m; i++)
		scanf("%d", &Available[i]);

	printf("\nEnter how much resources each process is currently holding and how much the process may request in the following format =>\n");
	printf("Process\tAllocation[A B C...]\tMax[A B C...]\n");
	for (int i=0; i<n; i++) {
		printf("P%d\t", i);
		for (int j=0; j<m; j++) {
			scanf("%d", &Allocation[i][j]);
		}
		for (int j=0; j<m; j++) {
			scanf("%d", &Max[i][j]);
		}
	}
	for (int i = 0; i<n; i++) {
		Finish[i] = false;
		for (int j = 0; j<m; j++) {
			Work[i][j] = Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
		}
	}

	for (int i = 0; i<n; i++) {
		if (!Finish[i]) {
			for (int j = 0; j<m; j++) {
				if (Need[i][j] <= Work[i][j]) {
					Work[i][j] =
	return 0;

}

