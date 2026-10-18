typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct N {
    u8 pad0[0xC];
    struct N *next;
    u8 pad1[0xE];
    s16 count;
    u8 pad2[0x13C - 0x20];
    u8 f13C;
} N;

typedef struct G { u8 pad[0x1C]; s8 flag; } G;
extern G *D_004C2840;

void func_001A61B0(N *p) {
    s32 i;
    s32 n = p->count;
    for (i = 0; i < n; i++) {
        p->f13C = D_004C2840->flag & 1;
        p = p->next;
    }
}
