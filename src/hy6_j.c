typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G314;
extern G314 *D_004C2794;

void func_00314C90(u8 *p, u8 *q)
{
    extern void func_00185490();
    extern void func_00175700(u8 *);
    extern void func_00314F40(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, u8);
    extern void func_0015EF10(f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    u8 x;
    s16 h;
    func_00185490(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[0x1B5] = 0x4C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_00314F40(p, q);
    if ((*(u16 *)(p + 0x362) & 0x360) != 0) {
        s32 t = *(s8 *)(q + 0x20);
        q[0x20] = t + 1;
    }
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        if (*(s8 *)(q + 0x20) >= 8) {
            s32 t = q[0x1F];
            if (t < 3) {
                q[0x1F] = t + 1;
                func_001757E0(p, 0x14, (u8)(q[0x1F] + 4));
                switch (q[0x1F]) {
                case 1:
                    x = 4;
                    break;
                case 2:
                    x = 6;
                    break;
                case 3:
                    x = 0x14;
                    break;
                }
                func_001E3210(p, x);
            }
            q[0x20] = 0;
            *(s16 *)(p + 0x1C) = 0x3C;
        } else {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
    if (q[0x1F] >= 3) {
        f32 v[4];
        v[0] = 53.33333206176758f;
        if (*(s16 *)(p + 0x140) != 0) v[0] = -v[0];
        v[0] += *(f32 *)(p + 0x34);
        v[1] = 171.42855834960938f + *(f32 *)(p + 0x38);
        v[2] = 0;
        if ((*(s16 *)(p + 0x1C) & 0xF) == 0) {
            func_0015EF10(v, (u8)(p[0x1E6] ^ 1));
            func_001E3710(p, 0x4B);
        }
    }
}
