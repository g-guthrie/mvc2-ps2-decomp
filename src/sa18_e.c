typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u16 h0, h2, h4, h6; u8 pad[0xB8]; u8 b0[0x44]; u8 b1[0x40]; u8 b2[0x40]; u8 b3[0x40]; } T38;

extern s32 D_00464CA0[];
extern u8 D_004B85A0[], D_004B85C0[], D_004B85D0[], D_00584AE0[];
extern u8 D_00464E00[], D_00464E44[], D_00464D00[], D_00464D40[], D_00464D80[], D_00464DC0[];
extern T38 D_00464E90;

void func_0038CE40(s32 n) {
    extern void func_0011F938();
    extern void *memcpy(void *, void *, u32);
    if (n != 4) {
        func_0011F938(D_00584AE0, D_004B85C0, D_004B85A0, D_00464CA0[n], D_004B85A0, D_00464CA0[n]);
        memcpy(((u8 *)&D_00464E90 + 0xC0), D_00464E00, 0x44);
        memcpy(((u8 *)&D_00464E90 + 0x104), D_00464D00, 0x40);
        memcpy(((u8 *)&D_00464E90 + 0x144), D_00464D00, 0x40);
        memcpy(((u8 *)&D_00464E90 + 0x184), D_00464D00, 0x40);
        *(u16 *)((u8 *)&D_00464E90 + 6) = 0x20;
    } else {
        func_0011F938(D_00584AE0, D_004B85D0);
        memcpy(((u8 *)&D_00464E90 + 0xC0), D_00464E44, 0x44);
        memcpy(((u8 *)&D_00464E90 + 0x104), D_00464D40, 0x40);
        memcpy(((u8 *)&D_00464E90 + 0x144), D_00464D80, 0x40);
        memcpy(((u8 *)&D_00464E90 + 0x184), D_00464DC0, 0x40);
        *(u16 *)((u8 *)&D_00464E90 + 6) = 0x20;
    }
}
