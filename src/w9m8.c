typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x14]; s16 h; u8 pad2[4]; } Ent;
extern Ent D_006267A0[];
extern s32 D_004C2AB0[2];
Ent *func_003EB960(void)
{
    s32 i = 0;
    s32 off = 0;
    do {
        if (*(s16 *)((u8 *)D_006267A0 + off + 0x14) == 0) {
            D_004C2AB0[0]++;
            return (Ent *)((u8 *)D_006267A0 + ((i * 3) << 3));
        }
        i++;
        off += 0x18;
    } while (i < 0x380);
    return 0;
}
