typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef float f32;
typedef struct { u8 pad0[0x21]; u8 index; u8 pad1[0x40 - 0x22]; u32 phase; } Object;
typedef struct { f32 x,y,z; } Vec;
typedef signed short s16;
typedef struct { s16 value; s16 pad; } Pair;
extern Vec D_00444A88;
extern Vec D_00444B40[];
extern Pair D_00444B68[];
extern Pair D_00444B6A[];
extern volatile u32 D_004C2838 __attribute__((section(".sdata")));
void func_00155960(Object *p) {
    *(u32 *)((u8 *)p + 0xD0) = 0x413;
    *(u16 *)((u8 *)p + 0xCC) = 0xB7;
    *(u32 *)((u8 *)p + 0x84) = D_004C2838;
    *(f32 *)((u8 *)p + 0x74) = 1.0f;
    *(f32 *)((u8 *)p + 0x80) = 1.0f;
    *(f32 *)((u8 *)p + 0x7C) = 1.0f;
    *(f32 *)((u8 *)p + 0x78) = 1.0f;
    *(Vec *)((u8 *)p + 0x50) = D_00444A88;
    p->phase = 0x1555;
    if (p->index == 2 || p->index == 5)
        p->phase += 0x4000;
    *(Vec *)((u8 *)p + 0x5C) = D_00444B40[p->index];
    *(u16 *)((u8 *)p + 0x1C) = D_00444B68[p->index].value;
    *(u16 *)((u8 *)p + 0x1E) = D_00444B6A[p->index].value;
}
