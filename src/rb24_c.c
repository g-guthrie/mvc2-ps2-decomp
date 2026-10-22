#pragma global_optimizer off
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0012DA40(s32 a, s32 b, s32 c) {
    extern void func_0012DBF0();
    extern s32 func_00418AA0();
    extern void func_00418B10();
    extern s32 func_003FCBC0(s32, s32);
    extern s32 func_003FD450(s32);
    extern void func_003FD0F8(s32, s32, s32);
    extern void func_003FCCF0(s32);
    extern s32 func_003FD530(s32);
    s32 s0, s1, s2, s3, s4;
    func_0012DBF0();
    s1 = 0;
    for (;;) {
        while (func_00418AA0() == 0) {
            asm { nop; nop; nop; nop; nop; nop }
            func_00418B10();
        }
        s0 = func_003FCBC0(c, a);
        if (s0 != 0) {
            s2 = func_003FD450(s0);
            func_003FD0F8(s0, s2, b);
            s4 = 0;
            for (;;) {
                if (s4++ >= 900) {
                    func_003FCCF0(s0);
                    func_00418B10();
                    break;
                }
                s3 = func_003FD530(s0);
                asm { nop; nop; nop; nop; nop; nop }
                func_00418B10();
                if (s3 == 2) continue;
                func_003FCCF0(s0);
                if (s3 == 3) goto done;
                break;
            }
        }
        s1++;
    }
done:
    return s2;
}
