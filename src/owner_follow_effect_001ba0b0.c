/* Initialize the owner-following effect and choose its drawing flags before the next phase. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001BA1B0(u8 *);
void func_001BA0B0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;p[5]=0;p[0x13C]=0;
    q=*(u8**)(p+0x18);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    s = (s32 *)(q + 0xEC);
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
    *(V3*)(p+0x34)=*(V3*)(q+0x34);
    *(s8*)(p+0x24)=*(s8*)(q+0x24);
    *(s8*)(p+0x31)=-1;p[0x22]=0;
    if(p[0x20]==0)p[0xD2]=23;else p[0xD2]=26;
    func_001BA1B0(p);
}
