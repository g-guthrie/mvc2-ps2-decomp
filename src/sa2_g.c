typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 f0;
    u8 pad1[4];
    u8 f5;
    u8 pad6[0x2E];
    f32 f34, f38;
    u8 pad3C[0x20];
    f32 f5c, f60;
    u8 pad64[4];
    f32 f68, f6c;
    u8 pad70[0x144];
    s8 b1B4;
} PK;
typedef struct {
    u8 pad[0x430];
    f32 f430;
} OK;

void func_00377650(PK *p, OK *o) {
    extern s32 func_00175700();
    extern void func_001757E0(PK *, s32, s32);
    extern void func_00377860(PK *, OK *);
    extern void func_003DAA40(PK *);
    s32 t;
    switch (p->f5) {
    case 0:
        t = p->b1B4;
        if (t != 0) {
            p->b1B4 = t - 1;
            func_00175700();
            return;
        }
    case 5:
        t = p->b1B4;
        if (t != 0) {
            p->b1B4 = t - 1;
            break;
        }
    case 1:
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (p->f38 <= o->f430) {
            p->f5 = 3;
            p->f38 = o->f430;
            func_001757E0(p, 0x17, 0xC);
        }
        break;
    case 2:
    case 3:
        if ((s8)func_00175700() < 0) {
            p->f5 = 4;
            func_00377860(p, o);
        }
        break;
    case 4:
        func_00377860(p, o);
        p->f0 = 0;
        func_003DAA40(p);
        break;
    }
}
