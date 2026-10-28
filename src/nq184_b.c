typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x36]; s8 b36[1]; } G4b;
typedef struct { u8 pad[0x1C]; s16 h1c; } O4b;
extern G4b *D_004C2794;
extern u8 D_004D18A0[];
extern u8 *D_004D18B8[][3];
extern s8 D_004D18D4[];
extern s8 D_004D18DE[];

void residual_0017BDA0(u8 *o) {
    extern void func_00175700(u8 *);
    extern void func_00186CE0(u8 *, s32);
    extern void func_00191210(u8 *);
    extern void func_00328420(u8 *);
    u8 *a;
    u8 *b;
    if (o[6] == 0) {
        func_00175700(o);
        if (*(s16 *)(o + 0x434) != 0) {
            if ((*(s8 *)(o + 0x1F7) == 0 || *(s16 *)(o + 0x1FA) == 0)
                && !(*(u32 *)(o + 0x428) & 0x7000000)) {
                o[0x209] = 0;
                *(s8 *)(o + 0x1E7) = -1;
                o[0x1F7] = 0;
                func_00186CE0(o, 0x11);
                return;
            }
        } else {
            if (D_004D18A0[0] < 5) {
                a = D_004D18B8[o[2]][(o[0x425] + 2) % 3];
                b = D_004D18B8[o[2]][(o[0x425] + 4) % 3];
                func_00191210(o);
                if (*(s16 *)(a + 0x434) != 0 || *(s16 *)(b + 0x434) != 0) {
                    o[0x201] = 2;
                    *(s16 *)(o + 0x1C) = 0x3C;
                    if (o[0x425] != 0) ((O4b *)o)->h1c = 0;
                    o[6]++;
                    goto end;
                }
            }
            if (D_004D18DE[0] >= 0 && D_004D18DE[0] == o[2] && *(s16 *)(o + 0x1FA) == 0
                && !(*(u32 *)(o + 0x428) & 0x7000000)) {
                func_00191210(o);
                o[0x201] = 2;
                *(s16 *)(o + 0x1C) = 4;
                if (o[0x425] != 0) ((O4b *)o)->h1c = 0;
                o[6]++;
            }
        }
    } else {
        func_00191210(o);
        if (D_004C2794->b36[o[2]] < 3) {
            o[0x201] = 2;
            if (*(s8 *)(o + 0x205) == 0) {
                if (o[0x425] != 0 || (D_004D18D4[o[2]] == 1 && --*(s16 *)(o + 0x1C) <= 0)) {
                    func_00328420(o);
                    o[0x268] = 2;
                }
            }
        }
    }
end:;
}
