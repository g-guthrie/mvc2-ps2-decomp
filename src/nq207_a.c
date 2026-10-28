typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G91a;
extern G91a *D_004C2794;
typedef struct { u8 pad[0x38]; f32 f38; } P38;

void func_002BAE60(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_002BB130(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185640(u8 *, u8 *);
    extern u8 *func_001E8070(u8 *);
    u8 *o;
    u32 t;
    u16 h;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = p[7];
    if (t == 0) {
        if (*(s8 *)(p + 0x151) == 0) {
            func_002BB130(p);
            return;
        }
        p[7] = t + 1;
        ((P38 *)p)->f38 += 102.85713958740234f;
    }
    if ((*(u8 **)(p + 0x220))[0x20D] == 3) {
        func_002BB130(p);
        return;
    }
    if (*(s8 *)(p + 0x539) != 0) {
        if (p[0x212] != 0) {
            func_002BB130(p);
            return;
        }
    } else {
        h = *(u16 *)(p + 0x362);
        if ((h & 0x60) != 0) {
            f32 v;
            p[6] = 6;
            p[0x1B5] = 0x60;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            v = *(f32 *)(p + 0x38) - 85.71427917480469f;
            *(f32 *)(p + 0x38) = v;
            if (v <= *(f32 *)(p + 0x430)) {
                ((P38 *)p)->f38 = *(f32 *)(p + 0x430);
            }
            func_001757E0(p, 0x15, 0x1D);
            return;
        }
        if ((h & 0x300) == 0) {
            func_002BB130(p);
            return;
        }
    }
    o = func_001E8070(p);
    if (o != 0) {
        if (o[0x20D] == 1) {
            p[0x20B] = 0xC4;
        } else if (o[0x20D] == 2) {
            p[0x20B] = 0xC3;
        } else {
            f32 f = (f32)(u32)o[0x14C];
            f32 a = 2.142857074737549f * f;
            f32 b = a * *(f32 *)(o + 0x54);
            f32 x = b / 2.0f;
            if (*(f32 *)(o + 0x38) + x < *(f32 *)(p + 0x38)) p[0x20B] = 0xC3; else p[0x20B] = 0xC4;
        }
        func_00185640(p, o);
    } else if (*(s8 *)(p + 0x539) != 0) {
        func_002BB130(p);
    } else {
        p[6] = 5;
        *(f32 *)(p + 0x38) -= 102.85713958740234f;
        func_001757E0(p, 0x15, 0xC);
    }
}
