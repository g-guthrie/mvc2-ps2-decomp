typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5C]; f32 f5c; } O386940;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G386940;
extern G386940 *D_004C2794;
extern u8 D_004D18A0[];
extern f32 D_00464900[];
extern f32 D_00464904[];

void func_00386940(u8 *o, u8 *q)
{
    extern void func_00386570(u8 *, u8 *);
    extern s32 func_003870C0(u8 *, u8 *);
    extern void func_00386EC0(u8 *, u8 *);
    extern void func_001548D0(u8 *, s32 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s;
    O386940 *so;
    s32 v[3];
    u32 t;
    s32 h;

    s = q + 0x2B8;
    so = (O386940 *)o;
    if (q[0x425] != 0 || s[4] != 0 || D_004D18A0[0] >= 5) {
        func_00386570(o, q);
        return;
    }
    if (q[0x169] == 8 || q[0x169] == 10 || *(u16 *)(q + 0x168) == 0x1403 || *(u16 *)(q + 0x168) == 0x150F) {
        if (func_003870C0(o, q) != 0) {
            t = o[5];
            o[5] = t + 1;
            s[5] = 0xFF;
            o[0x21] = 0;
            *(s16 *)(o + 0x1C) = 8;
            *(f32 *)((s32)o + 0x5C) = D_00464900[q[0x20D] * 2];
            *(f32 *)(o + 0x60) = D_00464904[q[0x20D] * 2];
            *(s32 *)(o + 0x68) = 0;
            *(s32 *)(o + 0x6C) = 0;
            h = *(s16 *)(q + 0x140);
            *(s16 *)(o + 0x140) = h;
            if (h != 0) {
                so->f5c = -so->f5c;
            }
            func_00386EC0(o, q);
            v[2] = 0;
            v[1] = 0;
            v[0] = 0;
            func_001548D0(o, v, 0);
            func_001E3710(o, 0);
            o[0x1B0] = 0x44;
            o[0x1B1] = 0x44;
            o[0x1B5] = 0x39;
            o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            D_004C2794->f7c[o[2]]++;
            func_001757E0(o, 0x17, 0x13);
        }
    }
}
