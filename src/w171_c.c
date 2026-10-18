typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C27D0;

void func_003412F0(void)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00341800(u8 *, s32, s32, s32);
    extern void func_003419A0(u8 *);
    extern void func_003418A0(void);
    extern void func_00341900(u8 *);
    extern void func_003413B0();
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_003413B0;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1E) = 1;
        i = 7;
        do {
            func_00341800(o, i, 0x800, 6);
            i--;
        } while (i > -1);
        func_003419A0(o);
        if ((D_004C27D0 & 0x1F) == 7) {
            func_003418A0();
            return;
        }
        if ((D_004C27D0 & 0x1F) == 0x10) {
            func_00341900(o);
        }
    }
}

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x1B4 - 6];
    s8 b1b4;
    u8 pad1b5[0x362 - 0x1B5];
    u16 h362;
    u8 pad364[0x370 - 0x364];
    u8 q[8];
    u8 pad378[0x538 - 0x378];
    s8 b538;
} PS2;

extern s8 *D_004C2840;
extern s8 D_004F7F35[];
extern s8 D_004F7F3F[];

s32 func_00188330(PS2 *p)
{
    extern s32 func_00188430();
    s8 t;
    u8 *q = p->q;
    if (p->b5 != 0) {
        return func_00188430(p);
    }
    if (p->b1b4 == 0) {
        q[5] = 0;
    }
    if (D_004C2840[0x4C] == 2 && D_004F7F35[0] == 3 && D_004F7F3F[0] == 2 - (p->b538 & 1)) {
        goto hit;
    }
    if (q[0] == 0) {
        if ((p->h362 & 0x1000) != 0) {
            q[0] = 1;
            q[1] = 15;
        }
        return 0;
    }
    t = *(s8 *)(q + 1) - 1;
    q[1] = t;
    if (t < 0) {
        q[0] = 0;
        return 0;
    }
    if ((p->h362 & 0x2000) == 0) {
        return 0;
    }
hit:
    q[0] = 0;
    q[5] = 2;
    return 1;
}
