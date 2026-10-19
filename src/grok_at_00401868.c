typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_003FB128(char *s);
extern void func_00400740(u8 *object);
extern void func_004005F8(u8 *object);
extern void func_0040D040(s32 handle);
extern void func_004017E0(u8 *p);
extern char D_004BC020[];

void func_00401868(u8 *p)
{
    u8 *obj;
    u8 *h;
    if (p == 0) {
        func_003FB128(D_004BC020);
        return;
    }
    h = *(u8 **)(p + 8);
    if (h != 0) {
        func_00400740(h);
        func_004005F8(*(u8 **)(p + 8));
        obj = *(u8 **)(p + 20);
        if (obj != 0)
            (*(void (**)(u8 *))(*(s32 *)obj + 20))(obj);
    }
    *(u8 **)(p + 8) = 0;
    if ((s8)p[2] == 4) {
        func_0040D040(*(s32 *)(p + 0x94));
        obj = *(u8 **)(p + 20);
        if (obj != 0)
            (*(void (**)(u8 *))(*(s32 *)obj + 20))(obj);
    }
    func_004017E0(p);
}
