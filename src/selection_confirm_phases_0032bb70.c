/* Selection input, timeout confirmation, and the native ready-state handoff. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct {u8 pad0[4],mode,pad5,phase,pad7[0x25];int choice;u8 pad30[0x4AE];s8 costume;u8 pad4DF[0x59];s8 team;} SelectionActor;
extern u8 D_00583BE2[],D_00583B90[];
extern s16 D_00583BDC;
extern u16 D_004C291C[] __attribute__((section(".sdata")));
/* Native input halfwords have a 20-byte stride. No table extent is claimed. */
extern u16 D_004F4482[][10];
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_001E3CE0(int),func_0032BEF0(u8 *);
void func_0032BB70(u8 *actor)
{
 SelectionActor *p=(SelectionActor*)actor;
 switch(p->phase) {
 case 0:
  p->phase++;D_00583BE2[p->team]=0;*(s8*)(D_004C2840+0x8D)=1;
  /* fall through */
 case 1:
  if(D_00583B90[p->team]==4)p->phase++;
  break;
 case 2:
  if(D_00583BDC==0) {D_004C291C[p->team]=0x200;goto confirm;}
  if(D_004C291C[p->team]&0x2000) {
   if(D_004F4482[p->team][0]&0x3FC)goto confirm;
   (*(s8*)(D_004C2840+0x8D))--;func_001E3CE0((u8)(p->team*2+64));
  }
  if(D_004C291C[p->team]&0x1000) {
   if(D_004F4482[p->team][0]&0x3FC)goto confirm;
   (*(s8*)(D_004C2840+0x8D))++;func_001E3CE0((u8)(p->team*2+64));
  }
  *(s8*)(D_004C2840+0x8D)&=1;
  p->costume=*(s8*)(D_004C2840+0x8D);p->choice=*(s8*)(D_004C2840+0x8D);
  if(!(D_004F4482[p->team][0]&0x3FC)||(D_004C291C[p->team]&0x3000))break;
confirm:
  p->phase++;D_00583BE2[p->team]=1;func_001E3CE0((u8)(p->team*2+65));
  break;
 case 3:
  if(D_00583B90[p->team]==5) {func_0032BEF0(actor);p->mode=11;}
  break;
 }
}
