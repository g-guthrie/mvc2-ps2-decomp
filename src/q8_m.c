typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x2B8]; u8 b[2]; u8 pad2[2]; f32 f2bc; } Q383;

void func_00383A60(u8 *p) {
    extern void func_0018D930();
    extern void func_001E3520();
    extern void func_001E7F60();
    Q383 *q = *(Q383 **)(p + 0x18);
    f32 a;
    u8 *b;
    if (*(u8 *)q != 0) {
        *(V3 *)(p + 0x34) = *(V3 *)((u8 *)q + 0x34);
        a = 40.0f * *(f32 *)((u8 *)q + 0x50);
        if (*(s16 *)((u8 *)q + 0x140) == 0) a = -a;
        *(f32 *)(p + 0x34) += a;
        *(f32 *)(p + 0x38) += 205.7142791748047f * *(f32 *)((u8 *)q + 0x54);
        if (*(s8 *)((u8 *)q + 0x1B1) != 0) {
            if (*(s8 *)(p + 0x1B3) != 0) {
                func_0018D930(p);
                func_001E3520(p, 0xF);
            }
            b = q->b;
            if (b[0] != 0 || b[1] != 0) {
                if (1.0f == q->f2bc) {
                    func_001E7F60(p);
                }
            }
        }
    }
}
