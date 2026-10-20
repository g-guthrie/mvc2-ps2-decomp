/* Reconstructed complete Sony CD/DVD DMA read completion callback. */
extern void func_0010E6D0(const int *);
extern volatile int D_004399D4;
typedef struct {
 int first_count,second_count;
 unsigned char *first_destination,*second_destination;
 unsigned char first_bytes[64],second_bytes[64];
} CdReadCompletion;
void func_0010E908(void *argument)
{
 CdReadCompletion *completion=(CdReadCompletion *)((unsigned int)argument|0x20000000);
 int i;
 unsigned char *destination;
 if(completion->first_count>0){
  destination=completion->first_destination;
  for(i=0;i<completion->first_count;i++)destination[i]=completion->first_bytes[i];
 }
 if(completion->second_count>0){
  destination=completion->second_destination;
  for(i=0;i<completion->second_count;i++)destination[i]=completion->second_bytes[i];
 }
 func_0010E6D0((const int *)&D_004399D4);
}
