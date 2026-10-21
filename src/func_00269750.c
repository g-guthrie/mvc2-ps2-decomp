typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern void (*const D_00454430[])(u8 *, void *);
extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern s32 func_0016D130(void);
extern void func_00176160(u8 *, s32, s32, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00154470(u8 *, s32, s32, f32, f32);

void func_00269750(u8 *p, u8 *timerContext)
{
    s16 timer;

    D_00454430[p[7]](p, p + 0x2B8);
    if (D_004C2794[0] >= 5 && func_0016D130() == 0)
        *(s16 *)(timerContext + 0xA) = 0;

    timer = *(s16 *)(timerContext + 0xA);
    timer--;
    *(s16 *)(timerContext + 0xA) = timer;
    if (timer <= 0) {
        p[6]++;
        p[7] = 0;
        func_00176160(p, 0, p[0x25] + 6, 1);
        func_001757E0(p, 0x16, 0x25);
        return;
    }

    if ((*(u32 *)(D_004C2840 + 0x1C) & 1) == 0)
        func_00176160(p, 0, p[0x25] * 2 + 0x14, 1);
    else
        func_00176160(p, 0, p[0x25] * 2 + 0x15, 1);

    if ((*(u32 *)(D_004C2840 + 0x1C) & 3) == 0)
        func_00154470(p, 0, 0, 3.799999952316284f, 0.4000000059604645f);
}
