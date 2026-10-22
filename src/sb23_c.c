typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {u8 prefix[0x1B5];u8 action;} ActorActionView;
extern u8 *D_004C2794;

extern u32 D_004BFC60;
extern u32 D_004BFC64;
extern u32 D_004BFC68;
extern u32 D_004BFC78;
extern u32 D_004BFC7C;
extern u32 D_004BFC80;
void func_001F8140(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004BFC60;
        else *(u32 **)(p + 0x408) = &D_004BFC78;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004BFC64;
        else *(u32 **)(p + 0x408) = &D_004BFC7C;
        p[0x1BB] = 1;
        break;
    case 2:
        if(*(u16 *)(p+0x20E)&0x2000) {p[0x168]=5;p[0x1B5]=14;}
        else {p[0x168]=2;p[0x1B5]=14;}
        func_001E3710(p,0x16);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004BFC68;
        else *(u32 **)(p + 0x408) = &D_004BFC80;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    {u32 t=p[0x1B5];((ActorActionView *)p)->action=t;}
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    func_001757E0(p, 0xB, p[0x168]);
    if (*(s8 *)(p + 0x1EA) & 0xF) p[0x1EA] = *(s8 *)(p + 0x1EA) - 1;
}
