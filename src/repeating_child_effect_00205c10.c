typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
extern u8 *func_0034B5A0(u8 *,int);
extern u8 *func_00198690(u8 *,int,int);
extern s8 func_00175700(u8 *);
extern void func_00184540(u8 *);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_00205C10(u8 *p)
{
    if (p[6]==0) {
        u32 counterOffset;
        p[6]++;
        func_00185490(p);
        func_0018C4B0(p,2);
        p[0x20D]=2;
        F(p,0x5C)=0;
        F(p,0x60)=0;
        F(p,0x68)=0;
        F(p,0x6C)=0;
        F(p,0x6C)=-0.8035714030265808f;
        p[0x1B5]=*(s8 *)(p+0x1B7)+50;
        p[0x1B2]=*(u16 *)(p+0x1C0)=0;
        *(u32 *)(p+0x1D8)=0;
        counterOffset=p[2]*2;
        counterOffset+=(u32)D_004C2794;
        counterOffset+=0x7C;
        ++*(s16 *)counterOffset;
        func_001757E0(p,21,(u8)(p[0x1B7]+2));
        return;
    }
    if (*(s8 *)(p+0x151)!=0) {
        u8 *owner;
        if ((owner=func_0034B5A0(p,0)) != 0) {
            int i;
            p[0x151]=0;
            for (i=0;i<4;++i) {
                u8 *child=func_00198690(owner,0,0);
                if (child) *(s16 *)(child+0x1C)=i*7;
            }
        }
    }
    if (func_00175700(p)<0) func_00184540(p);
}
