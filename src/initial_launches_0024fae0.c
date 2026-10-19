typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_0024FAE0(u8 *p, void *context)
{
    u32 counterOffset;
    p[6]++;
    p[0x1B5]=48;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_0018C4B0(p,5);
    func_00185490(p);
    F(p,0x38)=F(p,0x430);
    p[0x20D]=0;
    F(p,0x5C)=0;
    F(p,0x60)=0;
    F(p,0x68)=0;
    F(p,0x6C)=0;
    func_00183D10(p);
    func_001757E0(p,21,0);
}
extern void (*jtbl_00453300[])(u8 *,void *);
void func_0024FAB0(u8 *p) { jtbl_00453300[p[6]](p,p+0x2B8); }
extern void (*jtbl_004C0618[])(u8 *) __attribute__((section(".sdata")));
void func_00261DA0(u8 *p) { p[0x1FE]=1; jtbl_004C0618[p[0x20B]&0x3F](p); }

extern void (*jtbl_004C0700[])(u8 *) __attribute__((section(".sdata")));
extern void (*jtbl_004C0EB0[])(u8 *) __attribute__((section(".sdata")));
extern void (*jtbl_004C1580[])(u8 *) __attribute__((section(".sdata")));
extern void (*jtbl_004C1830[])(u8 *) __attribute__((section(".sdata")));
void func_0026EA70(u8 *p) { p[0x1FE]=1; jtbl_004C0700[p[0x20B]&0x3F](p); }
void func_002CB9E0(u8 *p) { p[0x1FE]=1; jtbl_004C0EB0[p[0x20B]&0x3F](p); }
void func_00308870(u8 *p) { p[0x1FE]=1; jtbl_004C1580[p[0x20B]&0x3F](p); }
void func_00325F90(u8 *p) { p[0x1FE]=1; jtbl_004C1830[p[0x20B]&0x3F](p); }
