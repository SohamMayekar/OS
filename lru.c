#include <stdio.h>
 
int main()
{
   int incomingStream[] = {4, 1, 2, 4, 5};
   int frames = 3;
   int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
 
   int temp[frames], used[frames];
   int pageFaults = 0;
   int i, j, found, lruIndex;
 
   // Initialize
   for(i = 0; i < frames; i++)
   {
       temp[i] = -1;
       used[i] = -1;
   }
 
   printf("Ref String\tFrames\n");
 
   for(i = 0; i < pages; i++)
   {
       found = 0;
 
       // Check if page already exists
       for(j = 0; j < frames; j++)
       {
           if(temp[j] == incomingStream[i])
           {
               found = 1;
               used[j] = i;
               break;
           }
       }
 
       if(found == 0)
       {
           // Find LRU index
           lruIndex = 0;
           for(j = 1; j < frames; j++)
           {
               if(used[j] < used[lruIndex])
                   lruIndex = j;
           }
 
           temp[lruIndex] = incomingStream[i];
           used[lruIndex] = i;
           pageFaults++;
       }
 
       // Print frames
       printf("%d\t\t", incomingStream[i]);
       for(j = 0; j < frames; j++)
       {
           if(temp[j] != -1)
               printf("%d ", temp[j]);
           else
               printf("- ");
       }
       printf("\n");
   }
 
   printf("\nTotal Page Faults = %d\n", pageFaults);
 
   return 0;
}
