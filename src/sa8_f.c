typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3B8C10;
typedef struct { u8 pad[0x1C]; u32 f1c; } H3B8C10;
extern G3B8C10 *D_004C2794;
extern H3B8C10 *D_004C2840;
extern void (*D_00474340[])(u8 *, u8 *);

void func_003B8C10(u8 *p)
{
    extern void func_003B9100(u8 *, u8 *);
    extern s32 func_00174170();
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *x;
    u8 *y;
    u8 *q;
    u32 t;
    x = *(u8 **)(p + 0x14);
    y = *(u8 **)(x + 0x220);
    q = x + 0x2B8;
    if ((*(u8 **)(p + 0x18))[4] != 1) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 3;
        func_003B9100(p, q);
        return;
    }
    if (*q != 0) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 3;
        func_003B9100(p, q);
        return;
    }
    D_00474340[p[0x21]](p, q);
    if ((D_004C2840->f1c & 0x1F) == 0) {
        if ((func_00174170() & 3) != 0) {
            p[0x1B5] = 0x39;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1B5] = 0x38;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    func_00175700(p);
    if (*(s8 *)(y + 0x1B4) == 0)
        func_001E7F60(p);
}
