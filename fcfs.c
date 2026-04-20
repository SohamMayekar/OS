#include <stdio.h>

int main() {
  int n, i;
  printf("Enter no. of processes\n");
  scanf("%d", &n);

  int at[n], bt[n], ct[n], tat[n], wt[n];
  int sumtat = 0, sumwt = 0;
  float avgtat = 0.0, avgwt = 0.0;

  printf("Enter arrival time\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &at[i]);
  }

  printf("Enter burst time\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }

  ct[0] = bt[0] + at[0];

  for (i = 1; i < n; i++) {
    if (ct[i - 1] < at[i])
      ct[i] = at[i] + bt[i];
    else
      ct[i] = ct[i - 1] + bt[i];
  }

  for (i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    sumtat = sumtat + tat[i];
    sumwt = sumwt + wt[i];
  }

  avgtat = (float)sumtat / n;
  avgwt = (float)sumwt / n;

  printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
  }

  printf("Average TAT = %.2f\n", avgtat);
  printf("Average WT = %.2f\n", avgwt);
  return 0;
}
