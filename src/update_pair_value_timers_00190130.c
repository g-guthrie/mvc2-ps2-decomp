typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct Actor {
 u8 active;
 u8 reserved1[4];
 u8 disabled;
 u8 reserved6[0x338];
 s16 refill_timer;
 u8 reserved340[0xC7];
 s8 decay_timer;
 u8 reserved408[0x2C];
 s16 value;
 u8 reserved436[2];
 s16 secondary_value;
} Actor;
typedef struct Slot {Actor *actor; int reserved[2];} Slot;
typedef struct State {u8 mode; u8 reserved1[5]; u8 stopped; u8 reserved7[0x11]; Slot slots[2];} State;
extern State *D_004C2794;
extern s8 *D_004C2840;
extern void func_001902F0(Actor *);
void func_00190130(void)
{
 Actor *actor;
 if(!D_004C2794->stopped && D_004C2794->mode==4){
 if(D_004C2840[0xAA]){
  int index=0, offset=0;
  do {
   actor=((Slot *)((u8 *)D_004C2794+0x18+offset))->actor;
   if(actor->refill_timer && actor->active && !actor->disabled){
    if(--actor->refill_timer<=0){
     actor->refill_timer=1;
     if((actor->value+=2)>144)actor->value=144;
     if((actor->secondary_value+=2)>144)actor->secondary_value=144;
     func_001902F0(actor);
    }
   }
   index++; offset+=sizeof(Slot);
  }while(index<2);
 }
 if(D_004C2840[0x54]){
  int offset, index;
  index=0; offset=0;
  do {
   actor=((Slot *)((u8 *)D_004C2794+0x18+offset))->actor;
   if(--actor->decay_timer<0 && actor->value>0){
    actor->decay_timer=100;
    if(--actor->value<=0)actor->value=1;
    if(--actor->secondary_value<=0)actor->secondary_value=1;
    func_001902F0(actor);
   }
   index++; offset+=sizeof(Slot);
  }while(index<2);
 }
 }
}
