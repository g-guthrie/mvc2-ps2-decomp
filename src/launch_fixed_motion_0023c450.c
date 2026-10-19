/* Fixed-point launch stages: native tables use 8- and 16-byte strides.
 * These are code views of the tables; no data completion is claimed here. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001E3210(u8 *,int);
extern void func_001A31D0(u8 *,u8,u8);
extern s32 D_004526A0[],D_004526A4[],D_004526A8[],D_004526AC[];
#define F(o,n) (*(f32 *)((o)+(n)))
void func_0023C450(u8 *p)
{
    func_00175700(p);
    if(*(s8 *)(p+0x151)) {
        s32 vx,ax,vy,ay;
        p[7]++;
        p[0x20D]=2;
        *(s16 *)(p+0x1C)=30;
        vx=D_004526A0[p[0x21]*4];
        ax=D_004526A4[p[0x21]*4];
        vy=D_004526A8[p[0x21]*4];
        ay=D_004526AC[p[0x21]*4];
        F(p,0x5C)=p[0x1E6] ? 1.6666666269302368f*(f32)vx/65536.0f : -(1.6666666269302368f*(f32)vx/65536.0f);
        F(p,0x68)=p[0x1E6] ? 1.6666666269302368f*(f32)ax/65536.0f : -(1.6666666269302368f*(f32)ax/65536.0f);
        F(p,0x60)=2.142857074737549f*(f32)vy/65536.0f;
        F(p,0x6C)=2.142857074737549f*(f32)ay/65536.0f;
        func_001E3210(p,20);
        func_001E3210(p,32);
        func_001A31D0(p,5,(u8)(p[0x21]+1));
    }
}

extern s8 D_004C0280[] __attribute__((section(".sdata")));
extern s32 D_004526F0[], D_004526F4[];
extern void func_00186A20(u8 *);

/* Native callback slot 00452704; actor A0. */
void func_0023C9A0(u8 *p)
{
    func_00175700(p);
    if(*(s8 *)(p+0x151)) {
        s32 speed;
        p[7]++;
        func_00186A20(p);
        speed=D_004526F0[p[0x1B7]*2];
        F(p,0x5C)=p[0x1E6] ? -(1.6666666269302368f*(f32)speed/65536.0f) : 1.6666666269302368f*(f32)speed/65536.0f;
        F(p,0x68)=p[0x1E6] ? -0.2083333283662796f : 0.2083333283662796f;
        F(p,0x60)=2.142857074737549f*(f32)D_004526F4[p[0x1B7]*2]/65536.0f;
        *(unsigned int *)(p+0x6C)=0xBEF00000;
        *(s16 *)(p+0x1C)=D_004C0280[p[0x1B7]];
        *(s16 *)(p+0x1E)=4;
        func_001E3210(p,20);
        func_001E3210(p,32);
        func_001A31D0(p,5,1);
    }
}
