#pragma padloop on
typedef unsigned char u8;typedef short s16;
typedef struct {u8 pad[0x1C];s16 timer,delay;} Work;
extern u8 D_004D18E6;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004C0E68[] __attribute__((section(".sdata")));
extern u8 D_004C0E70[] __attribute__((section(".sdata")));
extern int func_001757E0(u8*,int,int);
void func_002C7640(u8*p) {
 Work *w=(Work*)p;
 if(D_004D18E6)w->timer=D_004C0E68[*(int*)(D_004C2840+0x1C)&7];
 else w->timer=D_004C0E70[*(int*)(D_004C2840+0x1C)&7];
 switch(w->timer) {
 case 0:p[6]++;w->delay=60;func_001757E0(p,19,0);break;
 case 1:p[6]=3;func_001757E0(p,19,1);break;
 case 2:p[6]=4;func_001757E0(p,21,5);break;
 }
}
