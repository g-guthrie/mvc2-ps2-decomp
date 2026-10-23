/* Inherit owner presentation state, select facing, and initialize its drawing animation. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s8 D_004BFA78[] __attribute__((section(".sdata")));
typedef signed short s16;
typedef struct {u8 gap0[0x1C];s16 timer;u8 gap1E[2],index,gap21[0x13];V3 position;u8 gap40[0x100];s16 facing;} OffsetActor;
static void func_001CFEA0(u8 *actor) {
 extern s16 D_0044DEF0[],D_0044DEF2[];
 OffsetActor *p=(OffsetActor*)actor;
 f32 x;
 p->position.x=((OffsetActor*)*(u8**)(actor+0x18))->position.x;
 p->position.y=((OffsetActor*)*(u8**)(actor+0x18))->position.y;
 x=1.66666663f*(f32)D_0044DEF0[p->index*2];
 if(p->facing)x=-x;
 p->position.x+=x;
 p->position.y+=(f32)D_0044DEF2[p->index*2];
 if(p->timer)p->position.y-=34.2857132f;
}
extern void func_001D00B0(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_001CFF90(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C]=1;p[0x24]=0;
    *(short*)(p+0x140)=D_004BFA78[p[0x20]]^*(short*)(p+0x140);
    func_001CFEA0(p);
    func_001757E0(p,23,36);
    func_001D00B0(p);
}
