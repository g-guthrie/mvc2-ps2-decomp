typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045B720[];
s32 func_002EDCF0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_0045B720, p + 0x378) == 0) return 0;
    if (*(s32 *)(p + 0x304) != 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x378);
    { s32 v = 1; if (p[0x20D] != 2) v = 0; p[0x1FD] = v; }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}


void func_002F4940(u8 *p, u8 *q) {
    extern void func_002F4A50();
    extern void func_00175700();
    extern void func_001E3210();
    extern void func_002F4C30();
    u32 v;
    if (*(u16 *)(p + 0x35E) & 0x3C00) {
        v = *(u16 *)(p + 0x362);
        if (v & 0x300) {
            func_002F4A50(p, q, 0);
            return;
        }
        if (v & 0x60) {
            func_002F4A50(p, q, 1);
            goto done;
        }
        goto tail;
    } else {
        v = *(u16 *)(p + 0x362);
        if (v & 0x300) {
            p[6] = 9;
            func_001E3210(p, 0x17);
            func_002F4C30(p, q);
            goto done;
        }
        if (v & 0x60) {
            p[6] = 0xA;
            func_001E3210(p, 0x16);
            func_002F4C30(p, q);
            goto done;
        }
    }
tail:
    func_00175700(p);
done:
    ;
}


extern u8 D_00454120[];
s32 func_00262830(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_00454120, p + 0x3B8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3B8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x1D);
    *(s16 *)(p + 0x2C2) = 0xF0;
    if (*(s8 *)(p + 0x539) != 0) {
        p[0x1FD] = 0xC;
    }
    return 0;
}
