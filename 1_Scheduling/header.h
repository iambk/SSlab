#ifndef HEADER_H
#define HEADER_H

struct Process {
	int pid;
	int bt;
  int priority;
};

int partition(struct Process A[], int p, int r, char basis);
void quickSort(struct Process A[], int p, int r, char basis);

#endif