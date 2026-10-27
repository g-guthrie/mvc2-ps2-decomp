#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned int u32;
typedef struct {u8 pad[0x10];void (*callback)(u8 *);u8 pad14[0xBC];u32 bits[2];} Actor;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u32 D_00583BCC[],D_00583BD0[],D_00583BD4[],D_00583BD8[];
extern void *func_003DA750(void*,int,int);
extern void func_0013CC50(u8*),func_0013CB50(u8);
void func_0013CA00(void) {
 u8 bit,word;
 Actor *p;
 if((p=(Actor*)func_003DA750(0,6,1))!=0) {
  p->callback=func_0013CC50;p->bits[1]=0;p->bits[0]=0;
  if(*(s8*)(D_004C2840+0x18)&1) {p->bits[0]|=(int)D_00583BCC[0];p->bits[1]|=(int)D_00583BD0[0];}
  if(*(s8*)(D_004C2840+0x18)&2) {p->bits[0]|=(int)D_00583BD4[0];p->bits[1]|=(int)D_00583BD8[0];}
  for(word=0;word<2;word++) {
   for(bit=0;bit<32;bit++) {
    if(p->bits[word]&(1u<<bit))func_0013CB50(bit+word*32);
   }
  }
 }
}
