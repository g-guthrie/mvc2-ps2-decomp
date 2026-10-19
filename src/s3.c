typedef signed int s32;

extern void func_00408628(void);
extern void func_00411288(void);
void func_00408698(void) { func_00408628(); func_00411288(); }

extern char D_004872E8[];
extern void func_00405D98(void *, void *, int);



typedef struct S3F6 { char pad[0xA8]; s32 a; s32 b; } S3F6;
void func_003F64D0(S3F6 *p, s32 v) { p->a = v; p->b = v / 0x60; }

extern volatile s32 D_00487330[];
void func_004086D0(s32 v) { func_00408628(); D_00487330[0] = v; }

typedef struct P3FF { s32 pad0; void *obj; char pad1[0x24]; s32 f2C; s32 f30; s32 f34; } P3FF;
extern s32 func_003F81B0(void *), func_003F8430(void *), func_003F8438(void *);
void func_003FFCF8(P3FF *p) {
    void *o = p->obj;
    s32 a = func_003F81B0(o);
    s32 b = func_003F8430(o);
    s32 c = func_003F8438(o);
    s32 n = a - p->f34;
    if (c < n) n = c;
    p->f2C += n; p->f30 += b; p->f34 += n;
}

typedef struct P11C { char pad[0x30]; s32 f30; s32 f34; } P11C;
extern s32 func_0011FD40(const char *, const char *);
extern char D_004AC8B0[], D_004AC8A0[];
char *func_0011C8D0(P11C *p, s32 y, const char *z) {
    if (z) {
        if (func_0011FD40(z, D_004AC8B0) && func_0011FD40(z, D_004AC8A0)) return 0;
        p->f30 = y;
        p->f34 = (s32)z;
    }
    return D_004AC8B0;
}

typedef struct Q407 { char pad[1]; unsigned char f1; } Q407;
typedef struct R407 { char pad[2]; signed char b2; } R407;
extern void func_00411288(void), func_004112B0(void);
extern void func_00407EF8(void *), func_00407F18(void *);
extern Q407 D_004872F0;
extern volatile s32 D_0048734C;


typedef struct A119 { s32 a, b, c, d; } A119;
extern void func_00118E90(A119 *);
void func_00119028(s32 a, s32 b, s32 c, s32 d) { A119 s; s.a = a; s.b = b; s.c = c; s.d = d; func_00118E90(&s); }

typedef struct B119 { s32 a, b, c; long d; } B119;
extern void func_00119118(B119 *);
void func_00119C60(s32 a, s32 b, s32 c, long d) { B119 s; s.a = a; s.b = b; s.c = c; s.d = d; func_00119118(&s); }
