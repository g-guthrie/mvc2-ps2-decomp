/* The frame driver advances D_004D18DB modulo 16 before actor updates. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0035F430(u8*,u8*),func_001E7F60(u8*);
extern int func_00175700(u8*);
extern u8 *func_0035EF90(u8*,int,void*);
void func_0035F270(u8 *p,u8 *owner,s8 *state) {
    if(!(D_004D18DC & (1u << D_004D18DB))) {
        int command;
        func_0035F430(p,owner);
        func_00175700(p);
        command=p[0x15b];
        if(command) {
            u32 offset;
            p[0x1b5]=command;
            p[0x1b2]=*(u16*)(p+0x1c0)=0;
            *(u32*)(p+0x1d8)=0;
            offset=p[2]*2;offset+=(u32)D_004C2794;
            ++*(s16*)(offset+0x7c);
            p[0x15b]=0;
            *(s16*)(p+0x1c)=0;
        }
        if(*(s8*)(p+0x151)) {
            ++p[5];
            if(!func_0035EF90(p,p[0x20]+1,owner))state[4]=-1;
        }
    }
    func_001E7F60(p);
}
