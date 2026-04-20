#include <stdio.h>
 
void bestfit(int blockSize[], int m, int processSize[], int n)
{
   int allocation[n];
 
   for(int i = 0; i < n; i++)
       allocation[i] = -1;
 
   for(int i = 0; i < n; i++)
   {
       int bestIdx = -1;
 
       for(int j = 0; j < m; j++)
       {
           if(blockSize[j] >= processSize[i])
           {
               if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                   bestIdx = j;
           }
       }
 
       if(bestIdx != -1)
       {
           allocation[i] = bestIdx;
           blockSize[bestIdx] -= processSize[i];
       }
   }
 
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
