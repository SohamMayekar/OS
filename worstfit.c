#include <stdio.h>
 
void worstfit(int blockSize[], int m, int processSize[], int n)
{
   int allocation[n];
 
   for(int i = 0; i < n; i++)
       allocation[i] = -1;
 
   for(int i = 0; i < n; i++)
   {
       int worstIdx = -1;
 
       for(int j = 0; j < m; j++)
       {
           if(blockSize[j] >= processSize[i])
           {
               if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                   worstIdx = j;
           }
       }
 
       if(worstIdx != -1)
       {
           allocation[i] = worstIdx;
           blockSize[worstIdx] -= processSize[i];
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
