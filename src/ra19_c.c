typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96: ./tryee.sh src/ra19_c.c sn */
typedef struct { u8 pad[0x40]; s32 (*fn)(s8 *); } R_c;
extern char D_004BCEC8[], D_004BCF18[], D_004BCF40[];
extern void func_00406688(u8 *, s8 *, void *);
extern R_c *func_00406440(u8 *, s8 *, void *);
extern void func_00405DC8(char *);

s32 func_00407008(void *a) {
    u8 buf1[0x130];
    s8 buf2[0x130];
    R_c *r;
    func_00406688(buf1, buf2, a);
    if (buf2[0] == 0) {
        func_00405DC8(D_004BCEC8);
        return 0;
    }
    r = func_00406440(buf1, buf2, a);
    if (r == 0) func_00405DC8(D_004BCF18);
    if (r->fn != 0) return r->fn(buf2);
    func_00405DC8(D_004BCF40);
    return 0;
}
