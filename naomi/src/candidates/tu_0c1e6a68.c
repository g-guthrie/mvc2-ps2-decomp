/* Complete paired slot scans, not exact: P links at 260 bytes, the shared pool
 * is 16/16 exact, first function 123/140 and second 26/104. Loop-entry
 * scheduling and live-register choices remain different from retail. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct DeviceSlot60 dat_0c312834[];
#define DEVICE_INFO(out,index) ((*(out)=(struct DeviceSlot60 *)((char *)dat_0c312834+(unsigned long)(index)*60UL)),(*(out))->type)
int func_0c1e6a68(void)
{
 struct DeviceSlot60 *scan,*slot,*end;
 int i,mask,type;
 if(!dat_0c2d6f84->b47)return -1;
 end=dat_0c312834+8;
 for(scan=dat_0c312834;scan<end;scan++){
  if(scan->type==18&&scan->id==(int)0xffff0000u)return -1;
 }
 i=mask=0;
 while(i<8){
  type=DEVICE_INFO(&slot,i);
  if(type==18||type==1){
   if(((struct DeviceSlot60 *)((char *)dat_0c312834+(unsigned long)i*60UL))->id!=(int)0xffff0000u)mask|=1<<i;
  }
  i++;
 }
 return mask;
}
int func_0c1e6af4(void)
{
 int i,mask,type;
 struct DeviceSlot60 *slot;
 if(!dat_0c2d6f84->b47)return -1;
 mask=0;
 for(i=0;i<8;i++){
  if((type=DEVICE_INFO(&slot,i))==18||type==1){
   if(slot->id!=(int)0xffff0000u)mask|=1<<i;
  }
 }
 return mask;
}
