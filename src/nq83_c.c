#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct {u8 prefix[0x7c];s16 counters[];} CounterState;
typedef struct {u8 prefix[0x24];s8 mode;u8 gap25[0xf];f32 x,y,z;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define RESET_PLAYER(p,code,player) do {CounterState *counterState;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterState=(CounterState *)D_004C2794;counterState->counters[*(player)]++;}while(0)

void residual_00346850(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    Motion *m = (Motion *)p;
    u8 *player;
    s32 count;
    s32 *d, *s;
    p[4]++;
    d = (s32 *)(p + 0xec); s = (s32 *)(q + 0xec); count = 49;
    do { *d = *s; count--; s++; d++; } while (count > 0);
    p[0x13C] = 1;
    player = p + 2;
    *player = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    ((s8 *)p)[0x30] = ((s8 *)q)[0x30];
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    m->mode = ((Motion *)q)->mode;
    m->x = *(f32 *)(q + 0x34);
    m->y = *(f32 *)(q + 0x38);
    p[0x1B7] = q[0x1B7];
    *(u16 *)(p + 0x1E) = *(u16 *)(q + 0x168);
    *(s8 *)(p + 0x31) = -2;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    func_001757E0(p, 0x17, 0);
    RESET_PLAYER(p, *(s8 *)(p + 0x1B7) + 0x30, player);
}
