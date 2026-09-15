typedef signed int s32;
typedef unsigned char u8;

extern s32 D_004C3AD8;

s32 func_00106210(s32 a, s32 b) {
    s32 old = *(s32 *)((u8 *)&D_004C3AD8 + 0x14);
    *(s32 *)((u8 *)&D_004C3AD8 + 0x18) = b;
    *(s32 *)((u8 *)&D_004C3AD8 + 0x14) = a;
    return old;
}

s32 func_00106228(s32 a, s32 b) {
    s32 old = *(s32 *)((u8 *)&D_004C3AD8 + 0xC);
    *(s32 *)((u8 *)&D_004C3AD8 + 0x10) = b;
    *(s32 *)((u8 *)&D_004C3AD8 + 0xC) = a;
    return old;
}
