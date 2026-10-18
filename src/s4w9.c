typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;



extern u8 D_004BB4D8[];
extern s32 func_003FB128(u8 *);
s32 func_003FD500(s32 *p){ if (p == 0) { func_003FB128(D_004BB4D8); return -3; } return p[8]; }


extern u8 D_004BDBA8[];
extern s32 func_004098A8(s32 *, u8 *);
s32 func_00409F50(s32 *p){ if (p == 0) { func_004098A8(p, D_004BDBA8); return 0; } return p[3]; }

extern u8 D_00487FA0[];
extern s32 D_0062FEC0;
extern u8 D_0062FFC0[];
extern s32 func_00106E68(u8 *, s32, s32, s32 *, s32, u8 *, s32, s32, s32);
void func_00409148(s32 a){ D_0062FEC0 = a; func_00106E68(D_00487FA0, 3, 0, &D_0062FEC0, 4, D_0062FFC0, 0, 0, 0); }

extern void func_00103CF0(s32, s32 *);
extern void func_00104C90(s32);
void func_003FE0D0(s32 a){
    if (a != 0) {
        s32 v[12];
        func_00103CF0(a, v);
        if (v[0] == 4 || v[0] == 12) func_00104C90(a);
    }
}

typedef unsigned short u16;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
extern void func_003F85D0(u16 *, u16 *, s32);
void func_003F8600(u16 *base, s32 b, s32 c, s32 d){
    func_003F85D0(base, base + b, d);
    func_003F85D0(base + c, base + (c + b), d);
}


typedef struct { u8 a; u8 st; u8 pad[6]; s32 f8; u8 pad2[0x54]; s16 h60; u8 pad3[0x32]; s32 f94; } O404;
extern s32 func_00400650(s32);
extern s32 func_0040D178(s32);
void func_00404070(O404 *p){
    if (p->f8 != 0) {
        if (func_00400650(p->f8) == 4) { p->h60 = -1; p->st = 6; }
    }
    if (p->f94 != 0) {
        if (func_0040D178(p->f94) == 3) { p->h60 = -1; p->st = 6; }
    }
}


typedef struct { u8 a; u8 b; s8 sel; u8 pad; s32 f4; s32 f8; } S4040;
extern s32 func_00401920(S4040 *);
extern void func_003FF620(s32);
void func_004040F0(S4040 *p){
    if (func_00401920(p)) {
        switch (p->sel) {
        case 0:
        case 1:
            if (func_00400650(p->f8) == 2) { func_003FF620(p->f4); __asm__ volatile(""); }
            break;
        case 2:
            func_003FF620(p->f4); __asm__ volatile("");
            break;
        case 3:
        case 4:
            break;
        }
    }
}


