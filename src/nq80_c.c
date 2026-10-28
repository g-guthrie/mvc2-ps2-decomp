typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    union {
        struct { unsigned long long psize:8; unsigned long long dsize:24; } b;
        struct { u32 w0; u32 dest; } w;
    } h;
    s32 cid;
    u32 opt;
    s32 len;
    s32 arg;
    char name[0x50];
} Pkt70C0;

typedef struct {
    void *src;
    s32 dest;
    s32 size;
    s32 attr;
} Dma70C0;

extern Pkt70C0 D_004C70C0;
extern void func_001040B0(void);
extern s32 func_001041F0(u32);
extern void func_00106578(void *, s32);
extern void func_001041E0(u32, u32);
extern s32 func_001041A0(Dma70C0 *, s32);

/* Sony EE GCC 2.9: ./trysony29.sh src/nq80_c.c 0 O2 */
s32 func_0010BEF8(char *name, s32 arg)
{
    Dma70C0 d;
    s32 dst;
    s32 i;

    func_001040B0();
    dst = func_001041F0(0x80000000);
    D_004C70C0.arg = arg;
    for (i = 0; name[i] != 0; i++)
        D_004C70C0.name[i] = name[i];
    D_004C70C0.h.w.dest = 0;
    D_004C70C0.len = i;
    D_004C70C0.cid = 0x80000003;
    D_004C70C0.h.b.dsize = 0;
    D_004C70C0.h.b.psize = 0x68;
    d.src = &D_004C70C0;
    d.dest = dst;
    d.size = 0x68;
    d.attr = 0x44;
    func_00106578(&D_004C70C0, 0x68);
    func_001041E0(4, 0x40000);
    if (func_001041A0(&d, 1) != 0) {
        func_001041E0(4, 0x10000);
        func_001041E0(4, 0x20000);
        func_001041E0(0x80000002, 0);
        func_001041E0(0x80000000, 0);
        return 1;
    }
    return 0;
}
