typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern s32 func_00184540();
extern s32 func_001843A0();
extern s32 func_001E7FD0();
extern s32 func_001E8070();
extern s32 func_002FA2C0();
/* Provisional: callback return and downstream helper interfaces require correction. */
s32 func_002FA200(u8 *p) {
    s32 o;
    s8 r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] == 2) {
            return func_00184540(p);
        } else {
            return func_001843A0(p);
        }
    }
    if (*(s8 *)(p + 0x151) != 0) {
        if ((o = func_001E7FD0(p)) != 0) {
            return func_002FA2C0(p, o);
        }
        if ((o = func_001E8070(p)) != 0) {
            return func_002FA2C0(p, o);
        }
    }
}
