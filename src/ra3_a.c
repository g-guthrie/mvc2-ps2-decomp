typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[0xC];
    u32 cur;
    u32 end;
    u32 align;
} AL;

void *func_003F09C0(AL *p, u32 n, s32 commit) {
    u32 a, o, e;
    a = p->align; o = p->cur;
    n = (n + a - 1) & ~(a - 1);
    e = o + n;
    if (p->end < e) return 0;
    if (commit != 0) { p->end -= n; return (void *)p->end; }
    p->cur = e;
    return (void *)o;
}
