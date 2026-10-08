typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef float f32;
typedef struct { u8 pad[0x13C]; u8 initialized; } Object;
typedef struct { f32 x,y,z; } Vec;
extern Vec D_00444A88;
extern volatile u32 D_004C2838 __attribute__((section(".sdata")));
void func_00155A50(Object *p) {
    p->initialized = 1;
    *(u32 *)((u8 *)p + 0xD0) = 0x411;
    *(u16 *)((u8 *)p + 0xCC) = 0x86;
    *(u32 *)((u8 *)p + 0x84) = D_004C2838;
    *(f32 *)((u8 *)p + 0x80) = 1.0f;
    *(f32 *)((u8 *)p + 0x7C) = 1.0f;
    *(f32 *)((u8 *)p + 0x78) = 1.0f;
    *(Vec *)((u8 *)p + 0x50) = D_00444A88;
    *(u16 *)((u8 *)p + 0x1C) = 0;
}
