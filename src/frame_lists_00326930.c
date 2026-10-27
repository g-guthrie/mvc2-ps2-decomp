/* Provisional: shared frame storage and node lifetimes need ownership proof. */
typedef unsigned char u8;typedef unsigned int u32;
typedef struct N {u8 active;u8 pad1[4];u8 mode;u8 pad6[6];struct N *next; u8 remainder[0x5b8-0x10];} N;
typedef struct {N *v[3];} Row;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern N *D_004C28EC __attribute__((section(".sdata")));
extern N *D_004C28F0 __attribute__((section(".sdata")));
extern N *D_004C28E4 __attribute__((section(".sdata")));
extern N *D_004C28E8 __attribute__((section(".sdata")));
typedef struct {u8 prefix[0x18];Row row[2];u8 remainder[0xc0-0x30];} FrameWorld;
extern FrameWorld D_004D18A0;
void func_00326930(void) {
 N *v,*a,*b;int round,i,side;
 b=0; D_004C28EC=0; a=0; D_004C28F0=0; D_004C28E4=0; D_004C28E8=0;
 side=(*(u32 *)(D_004C2840+0x1c))&1;
 for(round=0;round<2;round++,side^=1) {
  for(i=0;i<3;i++) {
   v=D_004D18A0.row[side].v[i];
   if(v->active) {
    if(v->mode!=2) {if(!D_004C28F0)D_004C28F0=v;else a->next=v;a=v;}
    else {if(!D_004C28E8)D_004C28E8=v;else b->next=v;b=v;}
   }
  }
 }
 D_004C28EC=a;if(a)a->next=0;
 D_004C28E4=b;if(b)b->next=0;
}
