typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct { s32 w[0x31]; } SW;
typedef struct {u8 prefix[0x7c];s16 counters[];} CounterState;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))

void residual_00377930(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *owner; u8 *player; f32 c;
    CounterState *cs;
    p[4]++;
    owner = OWNER(p);
    *(SW *)(p + 0xec) = *(SW *)(owner + 0xec);
    p[0x13c] = 1;
    p[2] = owner[2];
    p[1] = owner[1];
    *(f32 *)(p + 0x50) = *(f32 *)(owner + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(owner + 0x54);
    p[0x1b7] = owner[0x1b7];
    p[0x1b8] = owner[0x1b8];
    ((s8 *)p)[0x30] = ((s8 *)owner)[0x30];
    *(V3 *)(p + 0x50) = *(V3 *)(owner + 0x50);
    ((s8 *)p)[0x24] = ((s8 *)owner)[0x24];
    *(V3 *)(p + 0x34) = *(V3 *)(owner + 0x34);
    player = p + 2;
    c = -106.66666412353516f;
    if (*(s16 *)(owner + 0x140) != 0) c = -c;
    *(f32 *)(p + 0x34) += c;
    p[0x1b0] = 0x46;
    p[0x1b1] = 0;
    p[0x1b5] = 0x3b;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(u32 *)(p + 0x1d8) = 0;
    cs = (CounterState *)D_004C2794;
    cs->counters[*player]++;
    p[0x14f] = 0x20;
    p[0x14e] = 0x20;
    p[0x24] = 0;
    func_001757E0(p, 0x17, 0xe);
}
