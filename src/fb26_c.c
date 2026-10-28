typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0xD0]; s8 b[8]; } OBc;

/* Provisional: func_003A2AE0 requires the actor argument. */
void func_003A28F0(u8 *p, u8 *q)
{
    extern void func_003A2AE0();
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700(u8 *);
    extern void func_003DAA40(u8 *);
    extern void func_001E7F60(u8 *);
    extern s32 func_00174240(u8 *);
    u8 *o = *(u8 **)(p + 0x14);
    s8 r;
    u32 t;
    if (p[4] == 0) {
        func_003A2AE0();
        p[0x13C] = 1;
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -4;
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
        if (p[0x21] == 12) {
            *(f32 *)(p + 0x38) = 8.0f + (334.28570556640625f + *(f32 *)(o + 0xD0));
            p[0x22] = 5;
        } else {
            *(f32 *)(p + 0x38) = *(f32 *)(o + 0xD0) + 55.71428298950195f * (f32)(12 - p[0x21]);
            p[0x22] = 0x13;
            if (p[0x21] == 0) p[0x22] = 7;
        }
        func_001757E0(p, 0x16, p[0x22]);
    }
    r = func_00175700(p);
    if (p[5] == 0) {
        if (o[5] != 1) {
            t = p[0x22];
            p[0x22] = t + 1;
            func_001757E0(p, 0x16, p[0x22]);
            t = p[5];
            p[5] = t + 1;
        }
        r = 0;
    }
    if (r < 0) {
        func_003DAA40(p);
        return;
    }
    if (p[0x21] != 12) {
        s8 *b = ((OBc *)o)->b;
        s8 f = b[5];
        s8 *c = b + 5;
        if (f == 0) {
            if (*(s8 *)(p + 0x1B2) != 0) {
                *c = 1;
            }
            if (*(s8 *)(o + 0xD4) == p[0x21]) func_001E7F60(p);
        }
        if (func_00174240(p) != 0) p[0x13C] = 1;
        else p[0x13C] = 0;
    }
    {s32 t2 = p[0x21];
    if (t2 > 0 && t2 < 12) p[0x13C] = 0;}
}
