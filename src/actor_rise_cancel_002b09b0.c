/* Complete native helper bodies preserve the original call-register usage.
 * Each helper is independently verified at its own address, with no new credit. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8*),func_001757E0(u8*,int,int);
static float func_002ADC20(u8 *p) {
    float old=*(float*)(p+0x5c);
    *(float*)(p+0x34)+=old;
    *(float*)(p+0x5c)+=*(float*)(p+0x68);
    *(float*)(p+0x38)+=*(float*)(p+0x60);
    *(float*)(p+0x60)+=*(float*)(p+0x6c);
    return *(float*)(p+0x5c)*old;
}
void func_002B09B0(u8*p) {
    func_00175700(p);
    {
    int command=p[0x15b];
    if(command) {
        u32 offset;
        p[0x1b5]=command;
        p[0x1b2]=*(u16*)(p+0x1c0)=0;
        *(u32*)(p+0x1d8)=0;
        offset=p[2]*2;offset+=(u32)D_004C2794;
        ++*(s16*)(offset+0x7c);
        p[0x15b]=0;
    }
    }
    if(func_002ADC20(p)<0.0f) {
        *(float*)(p+0x5c)=0;
        *(float*)(p+0x68)=0;
    }
    if(*(float*)(p+0x60)<0.0f) {
        ++p[6];
        *(float*)(p+0x5c)=0;
        *(float*)(p+0x68)=0;
        func_001757E0(p,22,7);
    }
}
