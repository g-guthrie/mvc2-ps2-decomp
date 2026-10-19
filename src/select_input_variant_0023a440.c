typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
extern s8 D_004525A0[], D_004525B0[], D_004525C0[], D_004525C1[];
void func_0023A440(u8 *p)
{
    if (p[0x1FD]!=0 && p[0x1FD]!=5) return;
    if (p[6]!=0) return;
    if (p[7]!=1 && p[7]!=2) return;
    if (*(s8 *)(p+0x539)==0) {
        u16 buttons=*(u16 *)(p+0x362);
        if (buttons&0x60) {
            u16 direction;
            if (buttons&0x40) p[0x20]=0;
            else p[0x20]=1;
            direction=(*(u16 *)(p+0x35E)&0x3C00)>>10;
            if (p[0x1FD]==0) p[0x21]=D_004525A0[(u16)direction];
            else p[0x21]=D_004525B0[(u16)direction];
            p[0x23]=1;
        } else p[0x23]=0;
    } else if (p[0x425]==0) {
        p[0x20]=D_004525C0[p[0x212]*2];
        p[0x21]=D_004525C1[p[0x212]*2];
        p[0x23]=1;
    }
    {
        s32 flags=*(s8 *)(p+0x1B2);
        if (flags && ((s8)flags&1)) p[0x23]=0;
    }
}
