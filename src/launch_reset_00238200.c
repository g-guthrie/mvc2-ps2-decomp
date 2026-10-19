typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_00238200(u8 *p, void *context)
{
    u32 counterOffset;
    if (p[0x269]==6) {
        p[0x404]=255;
        p[0x405]=16;
    }
    p[7]++;
    F(p,0x38)=F(p,0x430);
    p[0x20D]=0;
    *(s16 *)(p+0x1C)=2;
    ((u8 *)context)[0x38]=0;
    func_00185490(p);
    func_00183D10(p);
    F(p,0x5C)=0;
    F(p,0x60)=0;
    F(p,0x68)=0;
    F(p,0x6C)=0;
    p[0x1B5]=99;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset = p[2]*2;
    counterOffset += (u32)D_004C2794;
    counterOffset += 0x7C;
    ++*(s16 *)counterOffset;
    F(p,0x5C)=5.2083330154418945f;
    F(p,0x68)=0;
    F(p,0x60)=21.428569793701172f;
    F(p,0x6C)=-1.0714285373687744f;
    if (p[0x1E6]) F(p,0x5C)=-F(p,0x5C);
    func_001757E0(p,22,32);
}
extern void (*jtbl_004C01E8[])(u8 *,void *) __attribute__((section(".sdata")));
void func_002381E0(u8 *p)
{
    jtbl_004C01E8[p[7]](p,p+0x2B8);
}
