/* Complete native Sony pad actuator query. */
typedef unsigned char u8;
#include "sony_pad_slot.h"
extern u8 *func_0010D860(int port,int slot);
/* Native 128-byte DMA view, corroborated by historical libpad.
 * The 32-byte payload has overlapping actuator and combination views; the
 * native actuator_count controls valid indices. This declares no data object. */
typedef struct {
 u8 data[32];
 int unknown32[4];
 union {
  struct {u8 function,subfunction,size,current;} actuators[8];
  struct {u8 first16[16]; struct {u8 first,second,third,fourth;} entries[4];} combinations;
 } payload;
 unsigned short mode_table[4];
 int frame,unknown92,length;
 u8 mode_ok,mode_current,unknown102,unknown103,mode_count,mode_offset;
 u8 actuator_count,combination_count,unknown108[4],state,request_state,ok,tail[13];
} PadData;
int func_0010DB30(int port,int slot,int actuator,int term)
{
 PadData *buffer;
 if(!D_004C83D0[port][slot].enabled)return 0;
 buffer=(PadData *)func_0010D860(port,slot);
 if(buffer->ok!=1)return 0;
 if(buffer->mode_ok<2)return 0;
 if(actuator>=buffer->actuator_count)return 0;
 if(actuator==-1)return buffer->actuator_count;
 switch(term){
 case 1:return buffer->payload.actuators[actuator].function;
 case 2:return buffer->payload.actuators[actuator].subfunction;
 case 3:return buffer->payload.actuators[actuator].size;
 case 4:return buffer->payload.actuators[actuator].current;
 default:return 0;
 }
}

int func_0010DC50(int port,int slot,int combination,int term)
{
 PadData *buffer;
 if(!D_004C83D0[port][slot].enabled)return 0;
 buffer=(PadData *)func_0010D860(port,slot);
 if(buffer->ok!=1)return 0;
 if(buffer->mode_ok<2)return 0;
 if(combination==-1)return buffer->combination_count;
 if(combination>=buffer->combination_count)return 0;
 switch(term){
 case -1:return buffer->payload.combinations.entries[combination].first;
 case 0:return buffer->payload.combinations.entries[combination].second;
 case 1:return buffer->payload.combinations.entries[combination].third;
 case 2:return buffer->payload.combinations.entries[combination].fourth;
 default:return 0;
 }
}
int func_0010DD70(int port,int slot,int term,int index)
{
 PadData *buffer;
 if(!D_004C83D0[port][slot].enabled)return 0;
 buffer=(PadData *)func_0010D860(port,slot);
 if(buffer->ok!=1)return 0;
 if(buffer->request_state==2)return 0;
 switch(term){
 case 1:
  if(buffer->mode_current==243)return 0;
  return buffer->mode_current>>4;
 case 2:
  if(buffer->mode_ok==1)return 0;
  return buffer->mode_table[buffer->mode_offset];
 case 3:
  if(buffer->mode_ok==1)return 0;
  return buffer->mode_offset;
 case 4:
  if(buffer->mode_ok==1)return 0;
  if(index==-1)return buffer->mode_count;
  if(index<buffer->mode_count)return buffer->mode_table[index];
  return 0;
 default:return 0;
 }
}

typedef struct {int reserved0,request,length;u8 values[6];} ActuatorCommand;
extern int func_0010D248(int,int);
int func_0010DF60(int port,int slot,const u8 *values)
{
 PadData *buffer=(PadData *)func_0010D860(port,slot);
 ActuatorCommand *command;
 int i,result;
 if(buffer->ok!=1)return 0;
 command=(ActuatorCommand *)D_004C83D0[port][slot].command;
 for(i=0;i<6;i++)command->values[i]=values[i];
 command->request=1;
 command->length=6;
 result=1;
 if(func_0010D248(port,slot)!=1)result=0;
 return result;
}
