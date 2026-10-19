typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern const u8 D_004B7170[],D_004B7180[],D_004B71C0[],D_004B71D0[];
extern const u8 D_004B7230[],D_004B71F0[];
extern int func_001757E0(u8 *,int,int);
extern void func_00222730(u8 *,int,f32 *,f32 *);
void func_002206A0(u8 *p)
{
    u8 *q=p+0x2B8;
    u8 old;
    f32 x,y;
    u32 offset;
    p[0x1B5]=D_004B7170[*(u16 *)(p+0x2D4)];
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    offset=p[2]*2; offset+=(u32)D_004C2794; offset+=0x7C;
    ++*(s16 *)offset;
    func_001757E0(p,21,D_004B7180[*(u16 *)(p+0x2D4)*4]);
    p[0x22]=D_004B71C0[*(u16 *)(q+0x1C)];
    old=p[0x22];
    p[0x22]=D_004B71D0[*(u16 *)(q+0x1C)];
    func_00222730(p,1000,&x,&y);
    p[0x22]=old;
    if (p[0x1E6]) x=-x;
    *(f32 *)(p+0x5C)=x;
    *(f32 *)(p+0x60)=y;
}

void func_00220E40(u8 *p)
{
    u8 *q=p+0x2B8;
    u8 old;
    f32 x,y;
    u32 offset;
    p[0x1B5]=D_004B7230[*(u16 *)(p+0x2D4)];
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    offset=p[2]*2; offset+=(u32)D_004C2794; offset+=0x7C;
    ++*(s16 *)offset;
    func_001757E0(p,21,D_004B71F0[*(u16 *)(p+0x2D4)*4]);
    p[0x22]=D_004B71C0[*(u16 *)(q+0x1C)];
    old=p[0x22];
    p[0x22]=D_004B71D0[*(u16 *)(q+0x1C)];
    func_00222730(p,1000,&x,&y);
    p[0x22]=old;
    if (p[0x1E6]) x=-x;
    *(f32 *)(p+0x5C)=x;
    *(f32 *)(p+0x60)=y;
}
