typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_l;
typedef struct { V3_l a; f32 w; } S4_l;
typedef struct { u8 pad0; u8 f1; u8 pad[0x2B7]; u8 f2b9; u8 pad2[0x5B8 - 0x2BA]; } E_l;
extern s32 D_004F1CDC;
extern E_l D_004F20B0[];
extern V3_l D_00460CF0[];
extern f32 D_00460D20[];

void func_00343D30(u8 *p)
{
    extern void func_00154390(S4_l *, s32);
    extern void func_003DAA40(u8 *);
    s32 i, off;
    E_l *e;
    S4_l s;
    u32 t;
    switch (p[4]) {
    case 0:
        if (D_004F1CDC == 1) {
            p[4] = p[4] + 1;
            break;
        }
        i = 0;
        off = 0;
        do {
            e = (E_l *)((u8 *)D_004F20B0 + off);
            if (e->f1 == 0x18 && ((1 << p[0x20]) & e->f2b9) != 0) {
                p[4] = 2;
                break;
            }
            i++;
            off += 0x5B8;
        } while (i < 2);
        break;
    case 1:
        t = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = t;
        if ((s16)t >= 0x28) {
            t = p[4];
            p[4] = t + 1;
        }
        break;
    case 2:
        s.a = D_00460CF0[p[0x20]];
        s.a.y = D_00460D20[p[0x20]];
        func_00154390(&s, 0);
        func_003DAA40(p);
        break;
    }
}
