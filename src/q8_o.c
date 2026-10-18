typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0062BFD8;
extern s32 D_0062BBE4[];
extern s32 D_0062BBEC[];
extern s32 D_0062BBF4[];
extern s32 D_0062BBB4[];
extern s32 D_0062BBBC[];
extern s32 D_0062BBC4[];

s32 func_003DC9C0(void) {
    extern void func_003DC950();
    extern void func_003DD0D0();
    s32 i = D_0062BFD8 ^ 1;
    if (D_0062BBE4[i] == 0 && D_0062BBB4[i] == 0) {
        return 0;
    }
    func_003DC950();
    i = i ^ 1;
    if (D_0062BBE4[i] == 0 && D_0062BBB4[i] == 0) {
        return 0;
    }
    D_0062BBE4[i] = 0;
    D_0062BBEC[i] = 0;
    D_0062BBF4[i] = 0;
    D_0062BBB4[i] = 0;
    D_0062BBBC[i] = 0;
    D_0062BBC4[i] = 0;
    func_003DD0D0();
    return 1;
}
