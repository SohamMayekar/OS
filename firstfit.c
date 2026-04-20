#include <stdio.h>
 
void firstfit(int blockSize[], int m, int processSize[], int n)
{
   int allocation[n];
 
   // Initialize allocation
   for(int i = 0; i < n; i++)
       allocation[i] = -1;
 
   // First Fit logic
   for(int i = 0; i < n; i++)
   {
       for(int j = 0; j < m; j++)
       {
           if(blockSize[j] >= processSize[i])
           {
               allocation[i] = j;
               blockSize[j] -= processSize[i];
               break;
           }
       }
   }
 
   // Display result
   printf("\nProcess No.\tProcess Size\tBlock No.\n");
   for(int i = 0; i < n; i++)
   {
       printf("%d\t\t%d\t\t", i+1, processSize[i]);
 
       if(allocation[i] != -1)
           printf("%d", allocation[i] + 1);
       else
           printf("Not Allocated");
 
       printf("\n");
   }
}
