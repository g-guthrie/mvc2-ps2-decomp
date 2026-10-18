/* Initialize one of the related actor launch variants. */
typedef float f32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7C[2]; } G6;
extern G6 *D_004C2794;

extern u8 D_004B7130[];
extern f32 D_004B7140[], D_004B7144[], D_004B7148[], D_004B714C[];
void func_0021F8E0(u8 *o) {
    void func_0018C4B0(); void func_001757E0();
    o[0x1B5] = D_004B7130[0];
    o[0x1B2] = *(u16*)(o + 0x1C0) = 0;
    *(s32*)(o + 0x1D8) = 0;
    D_004C2794->f7C[o[2]] = D_004C2794->f7C[o[2]] + 1;
    func_0018C4B0(o, 5);
    func_001757E0(o, 0x15, 0xB);
    if (o[0x1E6] != 0) {
        *(f32*)(o + 0x5C) = D_004B7140[0];
        *(f32*)(o + 0x68) = D_004B7144[0];
    } else {
        *(f32*)(o + 0x5C) = -D_004B7140[0];
        *(f32*)(o + 0x68) = -D_004B7144[0];
    }
    *(f32*)(o + 0x60) = D_004B7148[0];
    *(f32*)(o + 0x6C) = D_004B714C[0];
}
