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

static void func_00296FB0(u8 *p) {
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


extern void func_00183d50(u8*);
void func_00299A20(u8*p) {
    func_00175700(p);
    if(!*(s8*)(p+0x151)) {
        *(float*)(p+0x34)+=*(float*)(p+0x5c);
        *(float*)(p+0x5c)+=*(float*)(p+0x68);
        *(float*)(p+0x38)+=*(float*)(p+0x60);
        *(float*)(p+0x60)+=*(float*)(p+0x6c);
    }
    if(*(float*)(p+0x38)<=*(float*)(p+0x430)) {
        ++p[6];
        *(float*)(p+0x38)=*(float*)(p+0x430);
        p[0x20d]=0;
        func_001757E0(p,21,(u8)(p[0x1b7]+27));
        func_00183d50(p);
    }
    func_00296FB0(p);
}
