/* Complete native helper bodies preserve the original call-register usage.
 * Each helper is independently verified at its own address, with no new credit. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);

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



extern void func_00185490(u8*),func_00183D10(u8*);
void func_002CFA90(u8 *p) {
    ++p[6];
    if(p[0x269]==6) {p[0x404]=255;p[0x405]=16;}
    *(s16*)(p+0x1c)=0;
    func_00185490(p);
    func_00183D10(p);
    *(f32*)(p+0x5c)=0;*(f32*)(p+0x60)=0;
    *(f32*)(p+0x68)=0;*(f32*)(p+0x6c)=0;
    *(f32*)(p+0x5c)=p[0x1e6]?7.5f:-7.5f;
    *(f32*)(p+0x38)=*(f32*)(p+0x430);
    p[0x20d]=0;
    p[0x1b5]=88;
    p[0x1b2]=*(u16*)(p+0x1c0)=0;
    *(s32*)(p+0x1d8)=0;
    {u32 offset=p[2]*2;offset+=(u32)D_004C2794;
     ++*(s16*)(offset+0x7c);}
    func_001757E0(p,22,5);
    func_002CFA20(p);
}
