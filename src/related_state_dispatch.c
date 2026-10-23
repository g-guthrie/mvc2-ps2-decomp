typedef unsigned char u8;
typedef signed char s8;
typedef struct { float x, y, z; } Vec3;
typedef void (*OwnerCallback)(u8 *, u8 *);
typedef void (*RelatedCallback)(u8 *, u8 *, u8 *);
extern OwnerCallback jtbl_0044CB60[10];
extern RelatedCallback const jtbl_004BF750[2] __attribute__((section(".sdata")));
void func_001C3430(u8 *p, u8 *owner)
{
    u8 *state=owner+0x2B8;
    if(owner[5] || owner[0x1E4]!=0x1D) { state[0xB]=0; state[0xA]=1; }
    jtbl_0044CB60[p[7]](p,owner);
}
void func_001A57C0(u8 *p, u8 *owner)
{
    u8 *other=*(u8 **)(owner+0x1DC);
    other[0x1FF]=1;
    *(Vec3 *)(p+0x34)=*(Vec3 *)(other+0x34);
    *(s8 *)(p+0x24)=*(s8 *)(other+0x24);
    *(s8 *)(p+0x31)=-8;
    jtbl_004BF750[p[5]](p,owner,other);
}
