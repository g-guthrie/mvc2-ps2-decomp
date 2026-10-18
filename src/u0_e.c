typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
typedef struct { u8 pad0[4]; u8 f4; u8 pad5[0xD]; s32 f12; s32 f18; } X;
typedef struct { u8 pad0[0x10]; void *f10; s32 f14; s32 f18; u8 pad1C[4]; u8 f20; u8 pad21[0xAF]; s32 fD0; s32 fD4; } R;
typedef struct { u8 pad0[4]; u8 f4; u8 pad5[0x13]; s32 f18; u8 pad1C[0xBC]; s32 fD8; u8 padDC[0x60]; u8 f13C; } A;
typedef struct { u8 pad[0x168]; u16 k; } B;
extern R *func_003DA750(A *, s32, s32);
extern void func_0041ACC0(void);
extern void func_0041B190(A *, B *), func_0041B0E0(A *);
void func_0041AEA0(A *a, B *b) {
    R *r;
    if (b->k != 0x1603 && b->k != 0x161B) {
        a->f4++;
        a->f13C = 0;
        return;
    }
    if ((r = func_003DA750(a, 1, 2)) != 0) {
        r->f10 = func_0041ACC0;
        r->f18 = a->f18;
        r->f20 = 1;
        r->fD0 = 0;
        r->f14 = (s32)a;
        r->fD4 = 0;
        if (--a->fD8 == 0) {
            a->fD8 = 5;
            r->fD4 = 0xFF;
        }
    }
    func_0041B190(a, b);
    func_0041B0E0(a);
}
