typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00443E90[];
extern u8 *D_004C2840;
void func_0014AB60(u8 *p, s32 dir) {
    s32 i;
    s32 t;
    u32 *q;
    i = 0;
    do {
        if (dir != 0) {
            { u32 c = p[5]; p[5] = c - 1; }
            if (p[5] == 0xFF) p[5] = 0x37;
        } else {
            { u32 c = p[5]; p[5] = c + 1; }
            if (p[5] == 0x38) p[5] = 0;
        }
        t = D_00443E90[p[5]];
        if (t >= 0x20) {
            t -= 0x20;
            q = (u32*)(D_004C2840 + 0x34);
        } else {
            q = (u32*)(D_004C2840 + 0x30);
        }
        if (*q & (1 << t)) return;
        i++;
    } while (i < 0x38);
    p[5] = p[6];
}

