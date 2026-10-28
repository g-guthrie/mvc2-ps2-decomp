typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u16 *D_004C29D0;
extern u8 *D_004C29D4;

void residual_00392C40(u8 *p)
{
    extern void func_00175700(u8 *);
    extern int func_00185980(u8 *);
    extern int func_00393390(u8 *);
    extern void func_00185870(u8 *, u8 *);
    extern void func_001757E0(u8 *, int, int);
    extern void func_00179160(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    u8 *q;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x22] == 0 && *D_004C29D0 != *(u16 *)(o + 0x168)) {
        p[0x22] = 1;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) == 0 || p[0x22] != 0 || func_00393390(p) != 0) {
            p[5]++;
            D_004C29D4[8] = 2;
            return;
        }
        p[5] = 4;
        q = *(u8 **)(p + 0x1C4);
        o[0x1B1] = 0;
        o[0x201] = 2;
        o[0x209] = 2;
        D_004C29D4[8] = 1;
        o[0x20B] = 0xC4;
        func_00185870(p, q);
        func_001757E0(p, 0xF, 7);
        if (*(u32 *)(q + 0x42C) & 0x4000000) {
            *(f32 *)(q + 0x38) = 85.71427917480469f + *(f32 *)(o + 0x430);
        } else if (*(u32 *)(q + 0x428) & 0x20000000) {
            *(f32 *)(q + 0x38) = 51.42856979370117f + *(f32 *)(o + 0x430);
        }
        func_00179160(p, q);
    } else {
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            p[5] += 2;
            func_001757E0(p, 0x17, 8);
        } else if (p[0x22] == 0) {
            func_001E7F60(p);
        }
    }
}
