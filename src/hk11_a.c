typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C28BC;
extern s32 D_004C28B8;
extern s32 D_004C28B4;
extern s32 D_004C28B0;
extern s32 D_004C28AC;
extern s32 D_004C2878;
extern s32 D_004C287C;
extern u8 D_004C2880[8];
extern u8 D_004BED60[];

s32 func_00414CB0(void)
{
    u8 t1[0x18];
    u8 t2[8];
    extern void func_0010FC98(void *);
    extern void func_003DCF90(void *);
    extern s32 func_003DCF70(s32);
    extern s32 func_00126AB0(s32, s32);

    func_0010FC98(t2);
    memcpy(t1, D_004BED60, 0x12);
    func_003DCF90(D_004C2880);
    if ((D_004C28BC = func_003DCF70(0x7E0000)) == 0) {
        return 0;
    }
    { s32 t = D_004C28BC; t += 0x3F; D_004C28BC = (t & 0xFFFFFFC0); }
    if ((D_004C28B8 = func_003DCF70(0x200000)) == 0) {
        return 0;
    }
    { s32 t = D_004C28B8; t += 0x3F; D_004C28B8 = (t & 0xFFFFFFC0); }
    if ((D_004C28B4 = func_003DCF70(0x60000)) == 0) {
        return 0;
    }
    { s32 t = D_004C28B4; t += 0x3F; D_004C28B4 = (t & 0xFFFFFFC0); }
    if ((D_004C28B0 = func_003DCF70(0x150000)) == 0) {
        return 0;
    }
    { s32 t = D_004C28B0; t += 0x3F; D_004C28B0 = (t & 0xFFFFFFC0); }
    if ((D_004C28AC = func_003DCF70(0x180000)) == 0) {
        return 0;
    }
    { s32 t = D_004C28AC; t += 0x3F; D_004C28AC = (t & 0xFFFFFFC0); }
    if ((D_004C2878 = func_003DCF70(0x100000)) == 0) {
        return 0;
    }
    { s32 t = D_004C2878; t += 0x3F; D_004C2878 = (t & 0xFFFFFFC0); }
    if ((D_004C287C = func_003DCF70(0xD0000)) == 0) {
        return 0;
    }
    { s32 t = D_004C287C; t += 0x3F; D_004C287C = (t & 0xFFFFFFC0); }
    func_00126AB0(D_004C28BC, 0);
    return 1;
}
