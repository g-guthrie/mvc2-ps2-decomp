typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 slot7c[2]; s16 slot80[2]; } G2794;
extern G2794 *D_004C2794;
extern s8 data_s8_004ACD08[6] __attribute__((section(".data")));
extern const s8 D_004ACD90[]; /* byte table interior at 0x004ACD90 */
extern const f32 data_f32_004ACD30[6];
extern u8 D_004D18E5[];

/* Provisional: palette and character selector bounds and table ownership require proof. */
void func_001804F0(u8 *p)
{
    *(s8 *)(p + 0x13D) = -1;
    *(s16 *)(p + 0x13E) = data_s8_004ACD08[p[0x1B8]];
    p[0x30] = D_004ACD90[*(s8 *)(p + 0x540)];

    if (D_004D18E5[0] == 0) {
        *(f32 *)(p + 0x34) = data_f32_004ACD30[p[2] * 3];
        *(f32 *)(p + 0x38) = data_f32_004ACD30[p[2] * 3 + 1];
        *(f32 *)(p + 0x3C) = data_f32_004ACD30[p[2] * 3 + 2];
        *(f32 *)(p + 0x430) = *(f32 *)(p + 0x38);
    }

    *(u32 *)(p + 0xFC) = 0x3FD55555;
    *(u32 *)(p + 0x100) = 0x40092492;
    *(u32 *)(p + 0x118) = 0x3F800000;
    *(u16 *)(p + 0x434) = 0x90;
    *(u16 *)(p + 0x438) = 0x90;
    p[0x1F0] = 0;

    if (p[0x425] != 0 && (*(u32 *)(p + 0x428) & 0x07000000) != 0) {
        *(u16 *)(p + 0x434) = 0;
        *(u16 *)(p + 0x438) = 0;
    }

    D_004C2794->slot7c[p[2]] = 0;
    D_004C2794->slot80[p[2]] = 0;
    p[0x1F5] = 0x50;
    p[0x1F7] = 0;
    p[0x226] = 0;
}
