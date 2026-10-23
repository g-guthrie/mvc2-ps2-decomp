/* Copy the supplied owner state and position, then begin slow horizontal drift. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
void func_001A0D60(u8 *p,u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
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
    ++p[4];p[0x24]=7;
    *(V3*)(p+0x34)=*(V3*)(q+0x34);
    *(f32*)(p+0x5C)=0.20833332836627960205078125f;
    *(f32*)(p+0x68)=-0.013020833022892475128173828125f;
    func_001757E0(p,23,22);
}
