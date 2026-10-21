typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef struct { s32 f0, f4, f8, fC; } S;
extern S D_00632610[];
s32 func_004120A0(s32 n) {
    extern void func_003DC9C0(s32);
    extern s32 func_003DD030(s32);
    extern void func_003DD020(s32);
    extern void func_003E94D0(s32), func_003E9420(s32);
    s32 i;
    S *s;
    s32 *b;
    s32 off2;
    s32 k;
    s32 *a;
    s32 off;
    if ((u32)(--n) >= 16) return 0;
    s = &D_00632610[n];
    if (s->f0 == 0) return 1;
    func_003DC9C0(n);
    a = (s32 *)(u32)func_003DD030(s->fC);
    i = 0;
    off = 0;
    do {
        func_003E94D0(*(s32 *)((u8 *)a + off));
        i++;
        off += 4;
    } while (i < 16);
    func_003DD020(s->fC);
    s->fC = 0;
    b = (s32 *)(u32)func_003DD030(s->f8);
    k = 0;
    off2 = 0;
    do {
        func_003E9420(*(s32 *)((u8 *)b + off2));
        k++;
        off2 += 4;
    } while (k < 26);
    func_003DD020(s->f8);
    s->f8 = 0;
    func_003DD020(s->f4);
    s->f4 = 0;
    s->f0 = 0;
    return 1;
}
