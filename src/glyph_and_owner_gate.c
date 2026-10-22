typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { signed char resource_bank,glyph_mode,transform,glyph;float advance; } GlyphCommand;
extern const GlyphCommand * const D_0043F140[7];
extern void func_001363D0(u8 *);
void func_00136390(u8 *p)
{
    p[4]++;
    *(float*)(p+0x34)=0.0f;
    *(float*)(p+0x3C)=-40.0f;
    *(const GlyphCommand**)(p+0xD8)=D_0043F140[p[0x20]];
    *(u32*)(p+0xDC)=0;
    func_001363D0(p);
}
void func_0013AFB0(u8 *p)
{
    u8 *owner=*(u8**)(p+0x18);
    if(*(float*)(owner+0x3C)<170.0f || owner[4]>=2) {
        p[0x13C]=0;
        p[4]++;
    }
}
