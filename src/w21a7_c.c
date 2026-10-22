typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
typedef struct { u8 pad[0xD]; u8 f0D; u8 pad2[2]; } E16;
extern G *D_004C2794;
extern E16 D_00464880[];

void func_00386260(u8 *p)
{
    extern int func_00174470(const void *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    s32 c;
    s32 k;
    s32 f;
    u8 *o;
    u32 t;

    if (func_00174470(p) == 0) {
        p[4] = 3;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        c = *(s32 *)(p + 0xD0) - 1;
        *(s32 *)(p + 0xD0) = c;
        if (c != 0) {
            k = ((E16 *)((s32)D_00464880 + (p[0x20] << 4)))->f0D;
            f = *(s16 *)(p + 0x1C);
            *(s16 *)(p + 0x1C) = f + 1;
            if ((f & 3) != 0) k = (k + 1) & 0xFF;
            p[0x1B5] = k;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x17, 3);
            return;
        }
    } else {
        if (*(s8 *)(p + 0x1B3) == 0) goto tail;
        o = *(u8 **)(p + 0x1D0);
        if (o != 0 && (o[2] & 0x20) != 0) goto l38c;
        c = *(s32 *)(p + 0xD0) - 1;
        *(s32 *)(p + 0xD0) = c;
        if (c != 0) goto anim;
        t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 3);
        return;
l38c:
        c = *(s32 *)(p + 0xD0) - 3;
        *(s32 *)(p + 0xD0) = c;
        if (c > 0) goto anim;
        t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 3);
        return;
anim:
        k = ((E16 *)((s32)D_00464880 + (p[0x20] << 4)))->f0D;
        f = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = f + 1;
        if ((f & 3) != 0) k = (k + 1) & 0xFF;
        p[0x1B5] = k;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
tail:
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
}
