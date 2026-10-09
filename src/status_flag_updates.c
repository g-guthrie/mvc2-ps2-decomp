/* Merge object flags into global state and toggle the signed countdown phase. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern s8 *D_004C2840;
void func_00174030(u8 *p)
{
 int one=1;
 D_004C2840[0x18] |= *(s8 *)(p+0x4dc);
 D_004C2840[0x89] |= *(s8 *)(p+0x4dc);
 D_004C2840[0x90] |= *(s8 *)(p+0x4dc);
 D_004C2840[0x91]=one;
 D_004C2840[0x92]=0;
 D_004C2840[0xb3]=one;
 p[0x4d0]=one;
 p[0x4d1]=0;
}
void func_00173470(u8 *p)
{
 --*(s16 *)(p+0x4da);
 if (*(s16 *)(p+0x4da)>0) return;
 *(s8 *)(p+0x4d3) ^= 1;
 if (*(s8 *)(p+0x4d2)==5) *(s16 *)(p+0x4da)=1;
 else if (*(s8 *)(p+0x4d3)!=0) *(s16 *)(p+0x4da)=40;
 else *(s16 *)(p+0x4da)=20;
}
