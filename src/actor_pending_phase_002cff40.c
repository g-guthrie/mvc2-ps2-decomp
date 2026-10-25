#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*),func_001757E0(u8*,int,int);

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
static void func_002CFA20(u8 *p) {
    s32 command = p[0x15B];
    if (command) {
        u32 offset;
        p[0x1B5] = command;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        p[0x15B] = 0;
    }
}

void func_002CFF40(u8 *p)
{
 p[0x40C]=2;p[0x33C]=5;
 if((s8)func_00175700(p)<0){
  ++p[6];p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;*(float*)(p+0x60)=-17.14285659790039f;func_001757E0(p,21,5);
 }
 func_002CFA20(p);
}
