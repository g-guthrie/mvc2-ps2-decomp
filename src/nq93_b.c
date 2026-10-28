typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[3]; } Q12_nq93b;
typedef struct { Q12_nq93b q[3]; } R36_nq93b;
extern R36_nq93b D_0043FBE0[];
extern u8 D_00583BC3[];
extern u8 D_00583BC6[];

void func_00139BA0(u8 *p) {
    extern void func_0032D450(u8 *, s32, u8, f32);
    s32 m;

    if (D_00583BC6[0] != 0) return;
    switch (p[6]) {
    case 0:
        m = *(s8 *)D_00583BC3;
        m = (u8)(*(s8 *)(p + 0xDC) ^ m);
        if (m == 0) return;
        p[6]++;
        *(s16 *)(p + 0x1E) = 0x1E;
        if (D_00583BC3[0] == 3) {
            func_0032D450(p, *(s16 *)(p + 0x1E), 0, D_0043FBE0[p[0x20]].q[0].f[0]);
        } else {
            func_0032D450(p, *(s16 *)(p + 0x1E), 0, D_0043FBE0[p[0x20]].q[(u8)m].f[0]);
        }
        *(u32 *)(p + 0xDC) |= (u8)m;
        break;
    case 1:
        {
            s16 v = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = v;
        }
        if (*(s16 *)(p + 0x1E) <= 0) {
            p[6] = 0;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        break;
    }
}
