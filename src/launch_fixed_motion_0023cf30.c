/* jtbl_00452780 slot 1; direct caller 0023CE30 supplies actor A0.
 * Interleaved fixed-point components use the native state-dependent stride. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001E3210(u8 *,int);
extern void func_001A31D0(u8 *,u8,u8);
extern s32 D_00452720[],D_00452724[],D_00452728[],D_0045272C[];
extern u8 D_004C0298[] __attribute__((section(".sdata")));
extern u8 D_004C029C[] __attribute__((section(".sdata")));
#define F(o,n) (*(f32 *)((o)+(n)))
void func_0023CF30(u8 *p)
{
    func_00175700(p);
    if(*(s8 *)(p+0x151)) {
        s32 vx,ax,vy,ay;
        p[7]++;
        *(s16 *)(p+0x1C)=D_004C0298[p[0x20]];
        vx=D_00452720[p[0x21]*8+p[0x20]*4];
        ax=D_00452724[p[0x21]*8+p[0x20]*4];
        vy=D_00452728[p[0x21]*8+p[0x20]*4];
        ay=D_0045272C[p[0x21]*8+p[0x20]*4];
        F(p,0x5C)=p[0x1E6] ? -(1.6666666269302368f*(f32)vx/65536.0f) : 1.6666666269302368f*(f32)vx/65536.0f;
        F(p,0x68)=p[0x1E6] ? -(1.6666666269302368f*(f32)ax/65536.0f) : 1.6666666269302368f*(f32)ax/65536.0f;
        F(p,0x60)=2.142857074737549f*(f32)vy/65536.0f;
        F(p,0x6C)=2.142857074737549f*(f32)ay/65536.0f;
        func_001E3210(p,20);
        func_001E3210(p,32);
        func_001A31D0(p,5,D_004C029C[p[0x21]]);
    }
}
