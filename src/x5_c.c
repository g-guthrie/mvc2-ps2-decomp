typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00184540(void *);
extern void func_001843A0(u8 *);
extern u8 *func_001E7FD0(u8 *);
extern u8 *func_001E8070(u8 *);
extern void func_002FA2C0(u8 *, u8 *);
void func_002FA200(u8 *p) {
    u8 *o;
    s8 r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] == 2) func_00184540(p);
        else func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        if ((o = func_001E7FD0(p)) != 0) {
            func_002FA2C0(p, o);
            return;
        }
        if ((o = func_001E8070(p)) != 0) {
            func_002FA2C0(p, o);
            return;
        }
    }
}
