/** 
 * Author : Shawn Mathew
 * Copyrights reserved
 */


#include <stdio.h>
#include <math.h>
void main()
{
  int n, i, A[50], st[50], sum = 0; //A holds all the positions given by the user.
  printf("Enter the number of positions: ");
  scanf("%d", &n);
  A[0] = 0;                //A[0] is the starting position.
  for (i = 0; i <= n; i++) //Initialise all the seek times as 0
    st[i] = 0;
  printf("\nEnter the positions\n"); //How can I help you, human?
  for (i = 1; i <= n; i++)           //Note that the i value starts from 1, to prevent problems with the A[i]-A[i-1] statement.
  {
    scanf("%d", &A[i]);            //Enter all the positions, human.
    st[i] += abs(A[i] - A[i - 1]); //Finding the difference in position.
  }
  for (i = 1; i <= n; i++)
  {
    sum += st[i]; //Finding the sum.
  }

  printf("The average number of movements is %d\n", sum / n);
  printf("The total number of movements is %d\n", sum);
}
