typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00185980(u8 *);
extern void func_00185870(u8 *, u8 *);
extern void func_00182C30(u8 *, s32);
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_001E7F60(u8 *);
extern void func_00179160(void *, void *);
extern void func_003671D0(u8 *, u8 *);
extern u8 *D_004C2974;
void func_00366CA0(u8 *p) {
    u8 *s;
    s32 r;
    func_00175700(p);
    s = D_004C2974;
    if (s[0xE] != 0) {
        p[5] = 8;
        *(f32 *)(p + 0x118) = 1.0f;
        return;
    }
    if ((s8)s[0xF] != 0) {
        p[0x1B0] = 0;
        p[0x1B1] = 0;
        *(u8 *)(*(u8 **)(p + 0x14) + 0x1B0) = 0;
        *(u8 *)(*(u8 **)(p + 0x14) + 0x1B1) = 0;
    }
    {
        s16 timer = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = timer;
        if (timer == 0) {
            p[5] = 8;
            *(f32 *)(p + 0x118) = 1.0f;
            return;
        }
    }
    if ((s8)p[0x1B2] != 0) {
        s = *(u8 **)(p + 0x1C4);
        r = func_00185980(p);
        if (r == 0) { p[5] = 8; return; }
        p[5] = 6;
        *(u8 *)(*(u8 **)(p + 0x18) + 0x20B) = 0xC3;
        func_00185870(p, s);
        p[0x24] = 0;
        s[0x20A] = 6;
        *(s16 *)(p + 0x1E) = 0x80;
        func_00182C30(s, 0x1E);
        func_001757E0(p, 0xF, 7);
        *(f32 *)(s + 0x5C) = 0.0f;
        *(f32 *)(s + 0x60) = 0.0f;
        *(f32 *)(s + 0x68) = 0.0f;
        *(f32 *)(s + 0x6C) = 0.0f;
        if (s[0x20D] == 2) *(f32 *)(s + 0x38) = *(f32 *)(s + 0x430);
        func_00179160(p, s);
        func_003671D0(p, s);    } else {
        func_001E7F60(p);
    }
}
