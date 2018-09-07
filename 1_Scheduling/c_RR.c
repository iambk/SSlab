/** 
 * Author : Shawn Mathew
 * Copyrights reserved
 */


#include <stdio.h>

struct process //I thought a process needed the rights of an individual
{
  int pid, burst, done; //I'll burst any moment
};                      //Do I need a semicolon here?

void main()
{
  int c = 0, n, f, i, quantum, offset = 0; //'n' for the number of processes, 'i' for general purpose and offset to handle the extra quantum time
  struct process processes[10];
  printf("Enter the time quantum: "); //Obtain the time quantum from the user
  scanf("%d", &quantum);
  printf("Enter the number of processes: "); //Demand the number of processes from the user
  scanf("%d", &n);
  f = n;
  printf("\nYou will be asked the details of the processes now.\n");
  for (i = 0; i < n; i++) //Get all the processes and their details
  {
    printf("\nEnter the pid of the process: ");
    scanf("%d", &processes[i].pid); //As far as I remember, the dot operator is used for these things
    printf("Enter the burst time: ");
    scanf("%d", &processes[i].burst);
  }
  printf("\n");
  while (f)
  {
    c++; //'c' sees the number of cycles

    printf("\nRunning at %d cycle", c);

    for (i = 0; i < n; i++)
    {
      if (!processes[i].done)
      {
        processes[i].burst -= quantum - offset; //The offset would be negative. Play of signs here
        offset = 0;
        if (processes[i].burst <= 0)
        {
          offset = processes[i].burst; //The offset is used to take the remaining quantum time into consideration
          processes[i].done = 1;
          f--; //One down, 'f' more to go! (oh, the innuendo)
          c++;
          printf("\nProcess with ID %d has been executed ]------(:P)<-== [  at the cycle %d T_T", processes[i].pid, c);
        }
      }
    }
  }
  printf("\n");
}
