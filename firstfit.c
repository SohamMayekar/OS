#include <stdio.h>
 
int main()
{
   int blockSize[] = {100, 500, 200, 300, 600};
   int processSize[] = {212, 417, 112, 426};
   int m = sizeof(blockSize) / sizeof(blockSize[0]);
   int n = sizeof(processSize) / sizeof(processSize[0]);
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
   return 0;
}
