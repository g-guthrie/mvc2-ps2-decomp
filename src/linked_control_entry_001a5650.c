/* Initialize the linked-object control effect and its owner state. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
extern void func_00185960(u8 *,u8 *);
extern void func_001E3710(u8 *,u8);
extern u8 D_0044B310[];
void func_001A5650(u8 *p,u8 *q)
{
    u8 *linked;
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
    func_00185960(q,p);
    linked=*(u8**)(p+0x14);
    ++p[4];p[0x24]=11;*(short*)(p+0x1C)=40;
    *(V3*)(p+0x34)=*(V3*)(linked+0x34);
    func_001E3710(p,13);
    linked[0x20A]=6;linked[0x1FF]=1;
    *(f32*)(linked+0x5C)=0.0f;*(f32*)(linked+0x60)=0.0f;
    *(f32*)(linked+0x68)=0.0f;*(f32*)(linked+0x6C)=0.0f;
    *(s8*)(p+0x24)=*(s8*)(linked+0x24);*(s8*)(p+0x31)=-8;
    p[0x23]=D_0044B310[linked[1]];
    func_001757E0(p,23,(u8)(p[0x23]+29));
}
