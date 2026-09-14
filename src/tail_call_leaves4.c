typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_00175700();
extern void func_001754A0();
extern void func_001CCB60(u8 *);
extern void func_001CE9F0(u8 *);
extern void func_001CB5A0();
extern void func_00176160();

void func_001C7190(s8 *p, s8 *q) { p[36] = q[36]; func_00175700(p); }

void func_001C9640(u8 *p) { p[316] = 0; func_001754A0(p, 27, 0); }

void func_001C9690(s8 *p) { p[49] = -10; func_001754A0(p, 27, 67); }

void func_001C9AF0(s8 *p) { p[49] = 8; func_001754A0(p, 27, 44); }

void func_001CCB50(u8 *p) { p[4] = 3; p[316] = 0; func_001CCB60(p); }

void func_001CE9E0(u8 *p) { p[4] = 3; p[316] = 0; func_001CE9F0(p); }

void func_001CB130(u8 *p) {
    p[5] = 1;
    *(s16 *)(p + 320) ^= 1;
    func_001CB5A0(p, 27, 84);
}

void func_001CF780(u8 **pp) {
    u8 *q = pp[6];
    func_00176160(q, 0, q[37] * 2, 1);
}
