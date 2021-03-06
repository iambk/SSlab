#include<stdio.h>
#include<stdbool.h>

int main() {
	int n, m;

	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the number of type of resources: ");
	scanf("%d", &m);

	int Available[m], Max[n][m], Allocation[n][m], Need[n][m], Work[m], safeSeq[n], count=0;
	bool Finish[n], flag;

	printf("\nHow much of each resource type is available(Available[A B C...]: ");
	for (int i=0; i<m; i++)
		scanf("%d", &Available[i]);

	printf("\nEnter how much resources each process is currently holding and how much the process may request in the following format =>\n");
	printf("Process\tAllocation[A B C...]\tMax[A B C...]\n");
	for (int i=0; i<n; i++) {
		printf("P%d\t", i);
		Finish[i] = false;
		Work[i] = Available[i];
		for (int j=0; j<m; j++) {
			scanf("%d", &Allocation[i][j]);
		}
		for (int k=0; k<m; k++) {
			scanf("%d", &Max[i][k]);
			Need[i][k] = Max[i][k] - Allocation[i][k];
		}
	}

	while (count < n) {
		bool found = false;
		for (int i = 0; i<n; i++) {
			if (!Finish[i]) {
				flag = true;
				for (int j = 0; j<m; j++) {
					if (Need[i][j] > Work[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int j=0; j<m; j++) {
						Work[j] += Allocation[i][j];
					}
					Finish[i] = true;
					safeSeq[count++] = i;
					found = true;
				}
			}
		}
		if (found == false) {
			printf("\nSystem is not in safe state..\n");
			return 0;
		}
	}
	printf("\nThe system is in safe state and the safe state is: ");
	for (int i=0; i<n; i++) printf("P%d  ", safeSeq[i]);
  printf("\n");
	return 0;
}

