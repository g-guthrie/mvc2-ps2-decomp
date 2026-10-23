/* Inherit the owner state and dispatch with the live owner argument; wait for its status transition. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef void (*OwnerCallback)(u8 *,u8 *);
extern OwnerCallback jtbl_0044AD70[];
extern u8 D_004D18A0;
void func_0019F820(u8 *p,u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    ++p[4];
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_0044AD70[p[0x20]](p,q);
}
void func_0019F8E0(u8 *p,u8 *owner) {
 if(D_004D18A0<3) {if(owner[7]<=2)return;}
 ++p[5];*(short*)(p+0x1C)=32;
}
