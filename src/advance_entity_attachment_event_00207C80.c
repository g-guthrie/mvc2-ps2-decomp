typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
extern s32 func_00175700(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_0018FDB0(u8 *);
extern void func_00198620(u8 *, s32, s32);
extern s32 func_001757E0(u8 *, s32, s32);
void func_00207C80(u8 *p) {
    u8 *child = *(u8 **)(p + 0x1DC);
    s32 event;
    s16 timer;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_001E3710(p, 23);
    }
    event = *(s8 *)(p + 0x151);
    if (event != 0) {
        if (p[0x20D] != 2)
            child[0x1B5] = 56;
        else
            child[0x1B5] = 57;
        func_0018FDB0(p);
        p[0x151] = 0;
        timer = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = timer;
        if (timer == 0) {
            p[6]++;
            func_00198620(p, 4, 0);
            if ((s8)event < 0)
                *(s16 *)(p + 0x140) ^= 1;
            if (p[0x20D] != 2)
                p[0x168] = 12;
            else
                p[0x168] = 17;
            func_001757E0(p, 21, p[0x168]);
        }
    }
}
