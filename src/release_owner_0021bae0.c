typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern int func_00182E20(u8 *);
extern int func_00182D30(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void (*D_00451120[])(u8 *,u8 *);
extern void (*jtbl_00451108[])(u8 *);
void func_0021BAE0(u8 *p)
{
    u8 *state, *target;
    target = *(u8 **)(p+0x1DC);
    state = p+0x2B8;
    if (func_00175700(p)<0 && *(s8 *)(state+12)<=0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p+0x140) = p[0x1E6];
        *(s8 *)(p+0x1B1) = -0x80;
        p[0x201] = 0;
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(state+12)>0) {
        if (func_00182E20(p)) p[0x152]=1;
        --*(s16 *)(target+0x270);
        if (func_00182D30(target)) {
            *(s8 *)(state+12) = -1;
            func_001757E0(p,15,1);
        }
    }
    D_00451120[(*(s8 *)(p+0x151))>>1](p,target);
}
void func_0021BAB0(u8 *p)
{
    p[0x1FE] = 1;
    p[0x201] = 3;
    jtbl_00451108[p[0x20B]](p);
}

extern void (*jtbl_0045DC98[])(u8 *);
void func_00321360(u8 *p)
{
    p[0x1FE] = 1;
    p[0x201] = 3;
    jtbl_0045DC98[p[0x20B]](p);
}
