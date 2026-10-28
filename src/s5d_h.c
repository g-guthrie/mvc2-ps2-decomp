/* s5d: MW 3.0.3, ./try.sh src/s5d_h.c "-O3 -Op -sdatathreshold 0". Float decrement (f8c--) loads the 1.0 constant before the field. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 pad[0x88]; f32 f88; f32 f8c; } S;
extern void func_00174910(u8 *, s32);
extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);
void func_00358C50(u8 *p) {
    u32 t;

    ((S*)p)->f8c--; if (((S*)p)->f8c < 0.0f) {
        *(f32 *)(p + 0x8C) = 2.0f;
        t = p[0x23]; p[0x23] = t + 1;
        t = p[0x23]; p[0x23] = t & 7;
        p[0x22] = *(s8 *)(p + 0x20) + *(s8 *)(p + 0x23);
    }
    ((S*)p)->f88 -= 1.0f; if (!((S*)p)->f88) {
        t = p[4]; p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    func_00174910(p, *(s16 *)(p + 0x1E));
    func_00175700(p);
    if (p[0x21] == 0) func_001E7F60(p);
}
