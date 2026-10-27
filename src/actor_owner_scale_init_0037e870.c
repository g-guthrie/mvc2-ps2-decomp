typedef unsigned char u8; typedef signed short s16; typedef float f32;
extern void func_0037E8A0(u8 *, void *);
void func_0037E870(u8 *p, void *owner) {
    p[6]++;
    *(s16 *)(p+0x1c)=10;
    *(f32 *)(p+0x118)=1.0f;
    *(f32 *)(p+0x54)=1.0f;
    *(f32 *)(p+0x50)=1.0f;
    func_0037E8A0(p, owner);
}
