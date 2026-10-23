/* Copy and inherit the cached owner state before entering the selected unary callback. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef void (*OwnerCallback)(u8 *);
extern OwnerCallback jtbl_0044DE20[];

void func_001CEB70(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q=*(u8**)(p+0x18);
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
    ++p[4];
    jtbl_0044DE20[p[0x20]](p);
}

extern void func_001CF6F0(u8 *);
extern unsigned short *D_004C2718 __attribute__((section(".sdata")));
extern int func_001754A0(u8 *,int,int);
void func_001CEC30(u8 *p) {
 func_001CF6F0(p);
 *D_004C2718=*(unsigned short*)(*(u8**)(p+0x18)+0x168);
 func_001754A0(p,27,0);
}
