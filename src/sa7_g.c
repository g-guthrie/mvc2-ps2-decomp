typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0; s32 pad[3]; } E70;
extern E70 D_0062FB4C[];

s32 func_004070B0(s32 a)
{
    extern s32 func_0011FFA0(void);
    extern s32 func_00120288(s32, void *, s32);
    extern s32 func_00407AB8(s32);
    s32 args[8];
    s32 i = 0;
    s32 r = 0;
    s32 t = func_0011FFA0();
    s32 *p;
    do {
        if (func_00120288(a, &D_0062FB4C[i], t) == 0) {
            p = (s32 *)*(s32 *)((u8 *)D_0062FB4C + i * 16 - 4);
            if (func_00407AB8(a)) {
                if (p != 0) {
                    p = (s32 *)p[0x60 / 4];
                    if (p != 0) {
                        args[1] = a;
                        r = ((s32 (*)(s32 *, s32, s32, s32))p)(args, 4, 0, 0);
                        break;
                    }
                }
            } else if (p != 0) {
                p = (s32 *)p[0x44 / 4];
                if (p != 0) {
                    r = ((s32 (*)())p)();
                    break;
                }
            }
        }
        i++;
    } while (i < 32);
    return r;
}
