typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
static void func_001EC2D0(u8 *p) {
    u32 offset;
    u8 c = p[0x15B];
    if (c != 0) {
        p[0x15B] = 0;
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
}
void func_001EC660(u8 *p) {
 p[0x40c]=2;p[0x33c]=5;
 if ((s8)func_00175700(p)<0) {p[6]++;func_001757E0(p,22,2);p[0x40d]=0;p[0x40c]=0;p[0x33b]=0;p[0x33c]=0;}
 else {*(f32 *)(p+0x38)+=-0.1339285671710968f;func_001EC2D0(p);}
}
