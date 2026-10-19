typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 id; u8 pad[0x3C]; } Ent;
typedef struct { u8 pad[0x38]; Ent tab[16]; } Tb;
extern const char D_004BE2F8[];
extern const char D_004BE368[];
char *func_0040D268(Tb *p, s32 v) {
    extern void func_0040D5A0(const char *, ...);
    s32 i;
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
    } else {
        for (i = 0; i < 16; i++) {
            if (p->tab[i].id == v) break;
        }
        if (i == 16)
            func_0040D5A0(D_004BE368);
        else
            return (char *)p + 0x3C + i * 64;
    }
    return 0;
}
