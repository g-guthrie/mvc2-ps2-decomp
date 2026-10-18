typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct { char pad[0x2C]; s16 f; char pad2[0x12]; } E64;
extern E64 D_0061C7A0[];
extern char D_004BA9A0[];
extern s32 D_004C2AE8[2];
extern void func_003ED0D0(void *);
s32 func_003E93A0(void) {
    s32 i = 0;
    s32 off = 0;
    do {
        if (*(s16 *)((char *)D_0061C7A0 + off + 0x2C) == 0) break;
        i++;
        off += 0x40;
    } while (i < 0x100);
    if (i == 0x100) {
        func_003ED0D0(D_004BA9A0);
        return 0;
    }
    D_004C2AE8[0]++;
    return (i + 1) << 16;
}
