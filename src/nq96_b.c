typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;
typedef signed int s32;
typedef struct { u16 flags; u8 pad[18]; } Ent;
typedef struct { u8 pad[0x5C]; f32 x5C, x60, x64, x68, x6C; } Mv;
extern Ent D_004F4480[];
void func_00312290(u8 *p) {
    extern int func_00174170(void);
    extern void func_001757E0(u8 *, int, int);
    u8 r;
    u8 c;
    Mv *m = (Mv *)p;
    r = func_00174170() & 3;
    if (*(s8 *)(p + 0x539) == 0) {
        u16 f = D_004F4480[p[2]].flags;
        if (f & 0x200) r = 0;
        else if (f & 0x100) r = 1;
        else if (f & 0x80) r = 2;
    }
    c = (*(u8 **)(p + 0x220))[1];
    if (c == 0x18 || c == 0x19 || c == 0x1A) r = func_00174170() & 1;
    switch (r) {
    case 0:
        func_001757E0(p, 0x13, 0);
        p[0x21] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        break;
    case 1:
        func_001757E0(p, 0x13, 3);
        p[0x21] = 1;
        break;
    default:
        func_001757E0(p, 0, 2);
        p[0x21] = 2;
        m->x5C = 0.0f;
        m->x60 = 0.0f;
        m->x68 = 0.0f;
        m->x6C = 0.0f;
        m->x5C = -5.0f;
        if (*(s16 *)(p + 0x140)) m->x5C = -m->x5C;
        break;
    }
    p[6]++;
    p[7] = 0;
}
