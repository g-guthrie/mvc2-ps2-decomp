/* EE GCC 2.96: ./tryee.sh src/s5a_b.c sn
 * func_0011D8F8 is memset; declaring its void * return value is what keeps
 * retail's store order before the call (sched2 dependence counts). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    u32 addr;
    u32 size;
    u32 end;
    u32 x;
    u32 total;
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    u8 pad[0x44 - 0x30];
} E409;

extern E409 D_00487B60[];
extern char D_004BD920[];
extern char D_004BD940[];
extern char D_004BD960[];
extern char D_004BD978[];
extern char D_004BD990[];
extern void func_00409198();
extern void func_004091A8();
extern void func_0011EB60(char *, ...);
extern s32 func_004090D8();
extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern void func_001046D8(u32, u32);
extern void func_00104818(u32, u32);

E409 *func_00409250(u32 idx, u32 addr, u32 x, u32 size) {
    E409 *e;
    s32 r;
    u32 s;
    if (addr & 0x3F) {
        func_0011EB60(D_004BD920);
        return 0;
    }
    if (x & 0x1F) {
        func_0011EB60(D_004BD940);
        return 0;
    }
    if (size & 0x3F) {
        func_0011EB60(D_004BD960, size);
        return 0;
    }
    if (idx >= 8) {
        func_0011EB60(D_004BD978, idx);
        return 0;
    }
    e = &D_00487B60[idx];
    if (e->b0 != 0) return 0;
    r = func_004090D8(idx, addr, x, size);
    e->w4 = r;
    if (r == 0) {
        func_0011EB60(D_004BD990);
        return 0;
    }
    s = size - 0x40;
    e->size = s;
    e->total = size;
    e->x = x;
    e->end = (addr + s) | 0x20000000;
    e->w8 = 0;
    e->addr = addr;
    e->b1 = 0;
    func_0011D8F8((void *)addr, 0, s);
    func_001046D8(e->addr, e->addr + e->size + 0x3F);
    func_00104818(e->addr, e->addr + e->size + 0x3F);
    e->f20 = func_00409198;
    e->f28 = func_004091A8;
    e->f24 = 0;
    e->f2C = 0;
    e->b2 = 1;
    e->b0 = 1;
    return e;
}
