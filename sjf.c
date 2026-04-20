#include <stdio.h>

int main() {
  int n, i, j;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int bt[n], wt[n], tat[n], ct[n];
  int sumwt = 0, sumtat = 0;
  float avgwt, avgtat;

  printf("Enter burst time:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }

  // Sorting burst time (SJF)
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (bt[i] > bt[j]) {
        int temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
      }
    }
  }

  wt[0] = 0;
  ct[0] = bt[0];

  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    ct[i] = ct[i - 1] + bt[i];
  }

  for (i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    sumwt += wt[i];
    sumtat += tat[i];
  }

  avgwt = (float)sumwt / n;
  avgtat = (float)sumtat / n;

  printf("\nProcess\tBT\tWT\tTAT\tCT\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i], ct[i]);
  }

  printf("\nAverage Waiting Time = %f", avgwt);
  printf("\nAverage Turnaround Time = %f\n", avgtat);
}
