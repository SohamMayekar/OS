#include <stdio.h>
 
int main()
{
   int incomingStream[] = {4, 1, 2, 4, 5};
   int frames = 3;
   int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
 
   int temp[frames];
   int pageFaults = 0;
   int i, j, k, found;
 
   // Initialize frames
   for(i = 0; i < frames; i++)
       temp[i] = -1;
 
   int index = 0;
 
   printf("Ref String\tFrames\n");
 
   for(i = 0; i < pages; i++)
   {
       found = 0;
 
       // Check if page already present
       for(j = 0; j < frames; j++)
       {
           if(temp[j] == incomingStream[i])
           {
               found = 1;
               break;
           }
       }
 
       // If not found → page fault
       if(found == 0)
       {
           temp[index] = incomingStream[i];
           index = (index + 1) % frames;
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
