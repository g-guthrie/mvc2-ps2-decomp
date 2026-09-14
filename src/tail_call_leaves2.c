typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_0019A000(u8 *);
extern void func_001AFCA0(u8 *);
extern void func_001754A0(s8 *, int, int);
extern void func_003DAA40(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001A8A10(u8 *);

void func_00199FF0(u8 *p) { p[4] = 3; p[316] = 0; func_0019A000(p); }

void func_001AFC90(u8 *p) { p[4] = 3; p[316] = 0; func_001AFCA0(p); }

void func_0019A710(s8 *p) { p[49] = -1; func_001754A0(p, 27, 3); }

void func_0019A860(s8 *p) { p[49] = -16; func_001754A0(p, 27, 6); }

void func_0019A920(s8 *p) { p[49] = -16; func_001754A0(p, 27, 8); }

void func_0019DAE0(u8 *p) { p[0] = 0; p[4] = 3; p[316] = 0; func_003DAA40(p); }

void func_0019E2C0(u8 *p) { p[316] = 0; p[5] = 0; func_001757E0(p, 23, 30); }

void func_001A89F0(u8 *p) {
    p[5]++;
    *(s32 *)(p + 72) = 0xF000;
    func_001A8A10(p);
}
