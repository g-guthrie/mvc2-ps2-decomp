typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern volatile s32 D_0048732C;
s32 func_004084D0(void) { return D_0048732C; }

extern char D_004BC588[];
extern void func_003FB128(void *);
s32 func_004027A8(u8 *a0) {
    if (a0 == 0) { func_003FB128(D_004BC588); return 0; }
    return *(s8 *)(a0 + 0x72);
}

extern void func_004098A8(void *, void *);
extern char D_004BDBA8[];
s32 func_0040A258(u8 *a0) {
    if (a0 == 0) { func_004098A8(a0, D_004BDBA8); return 0; }
    if (*(s8 *)(a0 + 2) == 1) return *(s32 *)(a0 + 0x14) << 11;
    return 0;
}

extern void func_003FCCF0(void *);
extern u8 D_00479E00[];
void func_003FCD80(void) {
    s32 i;
    u8 *p = D_00479E00;
    for (i = 15; i >= 0; i--) {
        if (*(s8 *)p == 1) func_003FCCF0(p);
        p += 0x138;
    }
}

typedef struct { s32 x, y; } P2;
extern P2 D_00632360[];
extern char D_004BEB70[];
extern void func_00411380(void *);
extern void func_00411288(void);
extern void func_004112B0(void);
void func_004116B0(s32 a, u32 b) {
    if (b >= 4) func_00411380(D_004BEB70);
    func_00411288();
    D_00632360[a * 4 + b].x = D_00632360[a * 4 + b].y = 0;
    func_004112B0();
}

extern void func_004075B8(void *, s32);
extern void func_00400D20(void);
extern u8 D_004C23B8[];
extern void func_00405FC0(void *, void *, s32);
extern void func_00409870(void);
extern void func_004062F8(void *);
extern void func_0040ADF0(s32, s32, s32, s32);
extern void func_0040AE10(char *);
typedef struct { char *path; s32 f4, f8, fC, f10; } PathConfig;
void func_00400D38(PathConfig *p) {
    func_004075B8(func_00400D20, 0);
    func_00405FC0(D_004C23B8, func_00409870, 0);
    func_004062F8(D_004C23B8);
    if (p) {
        func_0040ADF0(p->f8, p->fC, p->f10, p->f4);
        func_0040AE10(p->path);
    } else {
        func_0040ADF0(0, 0, 0, 0);
        func_0040AE10(0);
    }
}

extern char D_00489020[];
extern char D_004BDC30[];
extern char D_004BDC38[];
extern void func_0011FE88(char *, void *);
extern void func_0011FC10(char *, void *);
extern s32 func_0011FFA0(char *);
extern s32 func_0011FD40(char *, void *);
extern void func_00409AE0(char *);
