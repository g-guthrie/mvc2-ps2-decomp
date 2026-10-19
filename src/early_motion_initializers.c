typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175C00(u8 *,int);
extern void func_001FED30(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_002001C0(u8 *p)
{
    u32 counterOffset;
    p[6]++;
    func_00175C00(p,0);
    p[0x1B5]=0x48;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_001FED30(p);
    func_00183D10(p);
    p[0x2CD]=0;
    if (p[0x269]==6) {
        p[0x404]=255;
        p[0x405]=16;
    }
    func_001757E0(p,22,41);
}
void func_00202130(u8 *p)
{
    u32 counterOffset;
    func_00175C00(p,0);
    p[6]++;
    p[0x20D]=2;
    F(p,0x5C)=30.0f;
    if (!p[0x1E6]) F(p,0x5C)=-F(p,0x5C);
    F(p,0x68)=0;
    F(p,0x60)=4.285714149475098f;
    F(p,0x6C)=-0.8035714030265808f;
    p[0x1B5]=57;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_001757E0(p,20,0);
}
extern void (*jtbl_00450150[])(u8 *);
extern void (*jtbl_00450200[])(u8 *);
void func_00200190(u8 *p) { p[0x2C4]=12; jtbl_00450150[p[6]](p); }
void func_00202110(u8 *p) { jtbl_00450200[p[6]](p); }
