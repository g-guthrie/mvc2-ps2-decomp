typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[2]; u8 b2; s8 b3; u8 b4; } G378;
extern G378 *D_004C298C;
extern u8 D_004640D0[];
void func_00378B80(u8 *p)
{
    extern s32 func_001748C0(u8 *, u8 *);
    s8 t;
    u8 k;
    s8 step;
    s32 r;
    s32 a;
    if (D_004C298C->b2 != 0) {
        t = D_004C298C->b3 - 1;
        D_004C298C->b3 = t;
        if (t == 0) {
            D_004C298C->b3 = D_004640D0[p[0x21]];
            D_004C298C->b2--;
            r = (u8)func_001748C0(p + 0x34, &D_004C298C->b4);
            k = r / 8;
            a = p[0x22];
            if (k == a) {
                D_004C298C->b2 = 0;
            } else {
                step = (((k - a) & 0x1F) >= 0xF) ? 0xFF : 1;
                p[0x22] = (a + step) & 0x1F;
                if (*(s16 *)(p + 0x140) != 0) {
                    *(u32 *)(p + 0x48) = ((p[0x22] << 11) + 0x4000) & 0xFFFF;
                } else {
                    *(u32 *)(p + 0x48) = (0x4000 - (p[0x22] << 11)) & 0xFFFF;
                }
            }
        }
    }
}
