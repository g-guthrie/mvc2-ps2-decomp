typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0040EC90(void);
extern void func_0040EA48(void);
extern void func_0040ED00(void);
extern s32 func_00411720(s32, s32, long long, long long);
extern void func_0011D8F8(void *, s32, s32);
extern void func_003F79A8();

void func_003FF1F8(void) { func_0040EC90(); }
void func_003FF178(void) { func_0040EA48(); }
void func_003FF210(void) { func_0040ED00(); }
void func_003FEF48(long long a, long long b) { func_00411720(6, 0, a, b); __asm__ volatile(""); }
extern char D_00484100[];
void func_003FF388(void) { func_0011D8F8(D_00484100, 0, 0x9C0); }
void func_003F85D0(u16 *d, u16 *s, s32 n) { while (n > 0) { *d = *s; s++; n--; d++; } }

extern char D_00484AC0[];
s32 func_004000F8(void) { func_0011D8F8(D_00484AC0, 0, 0xA00); return 1; }

extern char D_004BE2F8[];
extern void func_0040D5A0(void *);
void func_0040D518(u8 *p, s32 v) { if (p == 0) func_0040D5A0(D_004BE2F8); else p[3] = v; }

extern char D_004BC4F0[];
extern void func_003FB128(void *);
void func_00402650(u8 *p, s32 v) { if (p == 0) func_003FB128(D_004BC4F0); else p[0x70] = v; }

extern s32 D_00438978;
extern void func_0010CAC8(void *, s32, s32);

extern u8 *func_003F1F90(void *, s32);

extern void func_0040D040(void);
void func_0040CD38(u8 *p) {
    if (p) { func_0040D040(); p[0] = 0; func_0011D8F8(p, 0, 0x438); __asm__ volatile(""); }
}

s32 func_004098F8(void) {
    extern signed char D_00488390[];
    s32 i; signed char *p = D_00488390;
    for (i = 0; i < 40; i++, p += 0x48) if (p[0] == 1 && p[2] == 2) return 1;
    return 0;
}

extern s32 D_00632140[], D_00632240;
extern void func_00409708(s32, void *, s32, void *, s32);
s32 func_00410848(s32 a, s32 b) {
    D_00632140[0] = a; D_00632140[1] = b;
    func_00409708(0x21, D_00632140, 2, &D_00632240, 1);
    return D_00632240;
}

extern char D_004BC1E8[];
s32 func_00402098(u8 *p, s32 i) {
    if (p == 0) { func_003FB128(D_004BC1E8); return 0; }
    return ((short *)(p + 0x42))[i];
}
