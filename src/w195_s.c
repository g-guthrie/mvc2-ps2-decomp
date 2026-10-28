typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PS {
    u8 pad0[0x21];
    u8 b21;
    u8 pad1[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad4[0x1B2 - 0x70];
    s8 b1B2;
    s8 b1B3;
} PS;

extern void func_0019DF50(u8 *, s32, s32);
extern void func_001E7F60(u8 *);
extern s32 func_0035A7B0(u8 *, u8 *);
extern void func_0035AE70(u8 *, s32);
extern void func_0035ACA0(u8 *, s32);
extern s32 func_0035AD40(u8 *, u8 *);
extern s32 func_00175700(u8 *);

void func_00359840(PS *p, u8 *q) {
    if (p->b1B2 < 0) {
        func_0019DF50((u8 *)p, 0xA, p->b21);
        func_001E7F60((u8 *)p);
        func_0035A7B0((u8 *)p, q);
        p->b21 = 7;
        func_0035AE70((u8 *)p, (s32)q);
        func_0035ACA0((u8 *)p, (s32)q);
        return;
    }
    if (p->b1B3 != 0) {
        func_0019DF50((u8 *)p, 0xA, p->b21);
    } else {
        func_00175700((u8 *)p);
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        if (func_0035AD40((u8 *)p, q) == 0) {
            func_001E7F60((u8 *)p);
            func_0035A7B0((u8 *)p, q);
            return;
        }
    }
    func_001E7F60((u8 *)p);
    func_0035A7B0((u8 *)p, q);
    p->b21 = 7;
    func_0035AE70((u8 *)p, (s32)q);
    func_0035ACA0((u8 *)p, (s32)q);
}
