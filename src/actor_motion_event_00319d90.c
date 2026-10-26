typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;
typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
typedef struct {u8 pad[0x34];float x,y;u8 pad3c[0x20];float vx,vy;u8 pad64[4];float ax,ay;} Motion;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_0045D8F0[];
extern int func_00175700(u8*);
static void func_00319D40(u8 *p, float *src)
{
    *(float *)(p + 92) = src[0];
    *(float *)(p + 104) = src[1];
    *(float *)(p + 96) = src[2];
    *(float *)(p + 108) = src[3];
    if (*(s16 *)(p + 320) != 0) {
        *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 104) = -*(float *)(p + 104);
    }
    p[525] = 2;
}

void func_00319D90(u8*p){
 Motion*m=(Motion*)p;
 func_00175700(p);
 m->x+=m->vx;m->vx+=m->ax;m->y+=m->vy;m->vy+=m->ay;
 if(*(s8*)(p+0x151)) {
  p[0x151]=0;++p[6];p[0x1B5]=p[0x1B7]?86:84;
  p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
  ++D_004C2794->count[p[2]];func_00319D40(p,(float *)(D_0045D8F0+((unsigned)p[0x1B7]<<4)));
 }
}
