typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0xB4]; s8 b4; } G32;
extern G32 *D_004C2840;
extern s8 D_004F7F3E[];
extern s32 D_004F8010[];
typedef struct { u16 h; u8 pad[18]; } E20;
extern E20 D_004F4484[];

typedef struct { s8 f0; s8 f1; s8 pad0[2]; s8 a[2]; s8 b[2]; s8 pad1[0x10]; s8 c; } P32;

void func_003D32A0(P32 *p, s32 i) {
    s32 f;
    if (D_004C2840->b4 != 0) return;
    if (!(p->f1 & (1 << i))) return;
    if (D_004F7F3E[0] != 0) return;
    if (*(s8 *)&D_004F8010[i] == 1) {
        f = p->f0;
        if (f & 4) {
            if (p->a[i] != 0) return;
            if (f & (i + 1)) {
                p->b[i] = 2;
            } else {
                p->b[i] = 0;
            }
        } else {
            if (!(D_004F4484[i].h & 0x8000)) return;
            if (f & (i + 1)) {
                if (p->c != 0) return;
                p->b[i] = 0;
            } else {
                if (p->b[1 - i] == 2) return;
                p->b[i] = 2;
            }
        }
    } else {
        if (p->a[i] != 0) p->b[i] = 1;
    }
}
