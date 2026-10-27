/* Provisional: script shift count bounds and callback table ABI remain unresolved. */
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef int s32;
typedef struct {u8 a[0x20e];s16 h20e;u8 b[0x244];u8 mode;u8 c[0x6a];u8 f4bf;s16 h4c0,h4c2;u8 d[4];s32 w4c8;u8 e[0x24];u16 h4f0;} Actor;
struct Object;
typedef struct SA37_J0 SA37_J0; typedef struct SA37_R SA37_R;
extern void func_0016B0C0(SA37_J0 *,SA37_R *,s32);
extern unsigned int func_0016B240(struct Object *,int);
s32 func_00168690(u8 *p,u8 *q){
 Actor *a=(Actor *)p; u16 mask;
 func_0016B0C0((SA37_J0 *)p,(SA37_R *)q,0);
 func_0016B0C0((SA37_J0 *)p,(SA37_R *)q,1);
 a->h20e=0;
 a->h4c0=0;
 mask = 0x240 >> a->w4c8;
 if (a->mode==0x4a) { mask &= 0x380; a->f4bf=0; }
 else { mask &= 0x70; a->f4bf=1; }
 if (a->h4c2 & mask) return 0;
 a->h4c2 |= mask;
 if (func_0016B240((struct Object *)p,2)==0) return 0;
 a->h4f0 |= mask;
 a->f4bf |= 0x80;
 p[0x4be] = *(s8 *)(p+0x4c8);
 return 0;
}
