typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s32 f1C; } GC;
extern GC *D_004C2840;
extern u8 D_004D18A0[];

s32 func_00174470(u8 *p);
void func_003CD600(u8 *p, void *owner);
int func_00175700(u8 *p);
void func_003CD610(u8 *p, s32 a);
struct O;
typedef struct { f32 x, y, z; } EffectPosition;
void func_0015B200(struct O *p, EffectPosition *position, u8 count, u16 flags);
int func_001757E0(u8 *p, s32 a, s32 b);
void func_001E7F60(u8 *p);

void func_003CD310(u8 *p, void *owner)
{
    u8 *q = (u8 *)owner;
    s16 h;
    u32 t;

    h = *(s16 *)(p + 0x1E);
    if (h == 0) {
        if (func_00174470(p) == 0) goto call600;
    } else {
        *(s16 *)((s32)p + 0x1E) = h - 1;
    }
    if (*(s8 *)(p + 0x1B2) == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if ((D_004C2840->f1C & 4) != 0) {
            func_003CD610(p, 0x32);
            t = p[0x22];
            p[0x22] = t + 1;
        }
        if (D_004D18A0[0] != 4) return;
        if (*(s8 *)(q + 0x539) == 0 && (*(u16 *)(q + 0x35E) & 2) == 0 && *(s16 *)(p + 0x1C) > 0) {
            *(s16 *)(p + 0x1C) = 0;
        }
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            p[0x13C] = (D_004C2840->f1C & 4) >> 2;
            *(f32 *)(p + 0x5C) /= 2.0f;
            if (*(s16 *)(p + 0x1C) < -0x28) {
                p[4] = 3;
                p[0x13C] = 0;
                *(f32 *)(p + 0x38) += 17.142856597900391f;
                func_0015B200((struct O *)p, (EffectPosition *)(p + 0x34), 1, 8);
                func_001757E0(p, 0x17, (u8)(p[0x168] + 1));
            }
        }
        if ((*(u16 *)(q + 0x35E) & 0x2000) != 0) {
            *(f32 *)(p + 0x38) += 1.6071428060531616f;
        }
        if ((*(u16 *)(q + 0x35E) & 0x1000) != 0) {
            *(f32 *)(p + 0x38) -= 1.6071428060531616f;
        }
        if (*(s8 *)(p + 0x1B3) != 0 || *(f32 *)(p + 0x38) < *(f32 *)(q + 0x430) - 17.142856597900391f) {
            t = p[4];
            p[4] = t + 1;
            *(u32 *)(p + 0x60) = 0x40892492;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
        func_001E7F60(p);
    } else {
call600:
        func_003CD600(p, q);
        return;
    }
}
