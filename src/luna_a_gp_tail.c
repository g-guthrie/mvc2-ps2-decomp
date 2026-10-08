typedef unsigned int u32;

extern u32 func_0016F5B0(int, int, int, int, int, int);
extern volatile u32 D_004C28AC;
extern volatile u32 D_004C28B8;
extern volatile u32 D_004C280C;

u32 func_00170140(void) {
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    int arg4;

    arg2 = D_004C28AC;
    arg0 = 0xD10;
    arg3 = D_004C28B8;
    arg4 = 6;
    arg1 = D_004C280C;
    return func_0016F5B0(arg0, arg1, arg2, arg3, arg4, 0);
}
