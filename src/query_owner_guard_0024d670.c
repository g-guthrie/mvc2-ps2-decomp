typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern u8 D_004F20B0[];
int func_0024D670(u8 *p)
{
    s8 flags=*(s8 *)(p+0x1B2);
    u8 *q;
    if (!(flags&0x80)) return 0;
    q=*(u8 **)(p+0x1C4);
    if (q[3]) return 0;
    if (flags&0x11) return 0;
    if (p!=*(u8 **)(q+0x1C8)) return 0;
    if (q[0x425]) return 0;
    if (q[0x20D]==3) return 0;
    if (*(s16 *)(q+0x434)==0) return 0;
    if (q[5]!=3) return 0;
    q=D_004F20B0+p[0x1B8]*0x5B8;
    return (q[5]==1)^1;
}
