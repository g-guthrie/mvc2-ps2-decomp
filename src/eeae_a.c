/* EE GCC 2.96 -O2 -G0 -fasynchronous-exceptions (reorg then keeps retail's bgtzl). */
typedef unsigned char u8;
typedef signed int s32;

extern char D_004BCD28[];
extern char D_004BCD50[];
extern char D_0062FB4C[];

extern void func_004067B8(char *);
extern void func_00405DC8(char *);
extern s32 func_0011FFA0(char *);
extern s32 func_00120288(char *, char *, s32);
extern void *memcpy(void *, const void *, unsigned int);

s32 func_00406CE0(char *name)
{
    char buf[0x130];
    s32 len;
    s32 i;
    s32 r = 0;
    u8 *h;

    if (name == 0 || name[0] == 0) {
        func_004067B8(buf);
        if (buf[0] == 0) {
            func_00405DC8(D_004BCD28);
            return 0;
        }
    } else {
        memcpy(buf, name, func_0011FFA0(name) + 1);
    }
    len = func_0011FFA0(buf);
    if (len <= 0) {
        func_00405DC8(D_004BCD28);
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (func_00120288(buf, D_0062FB4C + i * 16, len) == 0) {
            h = *(u8 **)(D_0062FB4C + i * 16 - 4);
            if (h != 0) {
                h = *(u8 **)(h + 0xC);
                if (h != 0) {
                    r = ((s32 (*)(void))h)();
                }
            } else {
                func_00405DC8(D_004BCD50);
                return 0;
            }
        }
    }
    return r;
}
