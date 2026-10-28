typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef struct { s8 b0; s8 b1; s8 b2; s8 b3; s32 w4; } SNH8;
extern SNH8 D_004872F0[];
extern volatile s32 D_00487350;
extern void func_00411288(void);
extern void func_00407BC0(void);
extern void func_004112B0(void);
SNH8 *func_00407BF8(void) {
    SNH8 *r = 0;
    SNH8 *p;
    func_00411288();
    p = D_004872F0;
    if (p->b0 == 0) {
        func_00407BC0();
        p->b0 = 1;
        p->b3 = -1;
        p->b2 = 0;
        D_00487350++;
        p->w4 = 0;
        r = p;
    }
    func_004112B0();
    return r;
}
