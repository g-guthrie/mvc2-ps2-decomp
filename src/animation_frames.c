/* Five-word animation records carry packed controls as well as frame data.
 * Float-word block copies preserve the retail transfer instructions. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef struct FloatWords4 { float a,b,c,d; } FloatWords4;
typedef struct FrameRecord { FloatWords4 words; float last_word; } FrameRecord;
extern void func_001E3370(u8 *);
int func_00175700(u8 *p) {
 int result=0;
 FrameRecord *record;
 if (--*(s8 *)(p+0x152) == 0) {
  do {
   ++*(FrameRecord **)(p+0x164);
   result=(s8)(*(s8 *)(p+0x153)&0x80);
   if (result) {
    record=*(FrameRecord **)(p+0x164);
    record=(FrameRecord *)(*(u8 **)(p+0x178)+*(int *)record);
    *(FrameRecord **)(p+0x164)=record;
   }
   record=*(FrameRecord **)(p+0x164);
   *(FloatWords4 *)(p+0x150)=record->words;
   *(float *)(p+0x160)=record->last_word;
  } while (*(s8 *)(p+0x152) == 0);
  record=*(FrameRecord **)(p+0x164);
  *(u8 **)(p+0x1d4)=*(u8 **)(p+0x17c)+(*(u16 *)((u8 *)record+0x12)<<4);
  if (p[0x15c]) func_001E3370(p);
 }
 return result;
}
int func_001757E0(u8 *p,int animation,int strength) {
 u8 *base;
 int animation_offset;
 int strength_offset;
 int *table;
 int *group;
 FrameRecord *record;
 animation_offset=(u8)animation*4;
 p[0x169]=animation;
 strength_offset=(u8)strength*4;
 p[0x168]=strength;
 base=*(u8 **)(p+0x178);
 table=(int *)(base+*(u16 *)(p+0x142));
 group=(int *)(base+*(int *)((u8 *)table+animation_offset));
 *(FrameRecord **)(p+0x164)=(FrameRecord *)(base+*(int *)((u8 *)group+strength_offset));
 record=*(FrameRecord **)(p+0x164);
 *(FloatWords4 *)(p+0x150)=record->words;
 *(float *)(p+0x160)=record->last_word;
 if (*(s8 *)(p+0x152) == 0) {
 do {
  ++*(FrameRecord **)(p+0x164);
  if (*(s8 *)(p+0x153)&0x80) {
   record=*(FrameRecord **)(p+0x164);
   *(FrameRecord **)(p+0x164)=(FrameRecord *)(*(u8 **)(p+0x178)+*(int *)record);
  }
  record=*(FrameRecord **)(p+0x164);
  *(FloatWords4 *)(p+0x150)=record->words;
  *(float *)(p+0x160)=record->last_word;
 } while (*(s8 *)(p+0x152) == 0);
 }
 record=*(FrameRecord **)(p+0x164);
 *(u8 **)(p+0x1d4)=*(u8 **)(p+0x17c)+(*(u16 *)((u8 *)record+0x12)<<4);
 if (p[0x15c]) func_001E3370(p);
 return 0;
}

/* Dispatch the encoded command in the supported low and high ranges. */
extern void func_001E24E0(u8 *,int);
extern void func_001E3710(u8 *,int);
void func_001E3370(u8 *p) {
 int command=p[0x15c];
 if (command) {
  int value=(u8)command;
  if (value < 128) {
   if (value < 64) func_001E24E0(p,command);
  } else {
   value-=128;
   if (value <= 80) func_001E3710(p,(u8)value);
  }
 }
}

/* Select an indexed frame without dispatching its command. */
int func_00175910(u8 *p,int animation,int strength,int frame) {
 u8 *base;
 int animation_offset;
 int strength_offset;
 int frame_offset;
 int *table;
 int *group;
 FrameRecord *record;
 animation_offset=(u8)animation*4;
 p[0x169]=animation;
 strength_offset=(u8)strength*4;
 p[0x168]=strength;
 base=*(u8 **)(p+0x178);
 frame_offset=frame*sizeof(FrameRecord);
 table=(int *)(base+*(u16 *)(p+0x142));
 group=(int *)(base+*(int *)((u8 *)table+animation_offset));
 *(FrameRecord **)(p+0x164)=(FrameRecord *)(base+*(int *)((u8 *)group+strength_offset));
 *(u8 **)(p+0x164)+=frame_offset;
 record=*(FrameRecord **)(p+0x164);
 *(FloatWords4 *)(p+0x150)=record->words;
 *(float *)(p+0x160)=record->last_word;
 if (*(s8 *)(p+0x152) == 0) {
 do {
  ++*(FrameRecord **)(p+0x164);
  if (*(s8 *)(p+0x153)&0x80) {
   record=*(FrameRecord **)(p+0x164);
   *(FrameRecord **)(p+0x164)=(FrameRecord *)(*(u8 **)(p+0x178)+*(int *)record);
  }
  record=*(FrameRecord **)(p+0x164);
  *(FloatWords4 *)(p+0x150)=record->words;
  *(float *)(p+0x160)=record->last_word;
 } while (*(s8 *)(p+0x152) == 0);
 }
 record=*(FrameRecord **)(p+0x164);
 *(u8 **)(p+0x1d4)=*(u8 **)(p+0x17c)+(*(u16 *)((u8 *)record+0x12)<<4);
 return 0;
}

