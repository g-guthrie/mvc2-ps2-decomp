typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } V4_a;

extern s8 D_004F7F30[];
extern s8 D_004F7F32[];
extern s8 D_004F7F39[];
extern s8 D_004F7F3A[];
extern s8 D_004F7F3B[];
extern s8 D_004F7F3C[];
extern s8 D_004F7F3D[];
extern s8 D_004F7F49[];
extern V4_a D_00476B60;
extern V4_a D_00476B70;
extern V4_a D_00476B80;
extern s32 D_004C283C;

void func_003D09E0(u8 *p)
{
    extern void func_003DAA40();
    if (D_004F7F30[0] != 2) {
        func_003DAA40();
        return;
    }
    *(V4_a *)(p + 0x74) = D_00476B80;
    if (D_004F7F32[0] == p[0x20]) {
        *(V4_a *)(p + 0x74) = D_00476B60;
    }
    switch (p[0x20]) {
    case 0:
        *(s16 *)(p + 0xCC) = 0x22;
        *(s32 *)(p + 0x84) = D_004C283C;
        if (D_004F7F3D[0] != 0) {
            *(s16 *)(p + 0xCC) = 0x21;
            *(s32 *)(p + 0x84) = D_004C283C;
        }
        break;
    case 1:
        *(s16 *)(p + 0xCC) = 0x3B;
        *(s32 *)(p + 0x84) = D_004C283C;
        if (D_004F7F49[0] != 0) {
            *(s16 *)(p + 0xCC) = 0x3C;
            *(s32 *)(p + 0x84) = D_004C283C;
        }
        break;
    case 2:
        *(s16 *)(p + 0xCC) = 0x20;
        *(s32 *)(p + 0x84) = D_004C283C;
        if (D_004F7F39[0] != 0) {
            *(s16 *)(p + 0xCC) = 0x1F;
            *(s32 *)(p + 0x84) = D_004C283C;
        }
        break;
    case 3:
        *(V4_a *)(p + 0x74) = D_00476B70;
        if (D_004F7F32[0] == p[0x20]) {
            *(V4_a *)(p + 0x74) = D_00476B60;
        }
        switch (D_004F7F3A[0]) {
        case 0: *(s16 *)(p + 0xCC) = 0x33; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 1: *(s16 *)(p + 0xCC) = 0x34; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 2: *(s16 *)(p + 0xCC) = 0x35; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 3: *(s16 *)(p + 0xCC) = 0x36; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 4: *(s16 *)(p + 0xCC) = 0x37; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 5: *(s16 *)(p + 0xCC) = 0x38; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 6: *(s16 *)(p + 0xCC) = 0x39; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 7: *(s16 *)(p + 0xCC) = 0x3A; *(s32 *)(p + 0x84) = D_004C283C; break;
        }
        break;
    case 4:
        *(V4_a *)(p + 0x74) = D_00476B70;
        if (D_004F7F32[0] == p[0x20]) {
            *(V4_a *)(p + 0x74) = D_00476B60;
        }
        switch (D_004F7F3B[0]) {
        case 0: *(s16 *)(p + 0xCC) = 0x1A; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 1: *(s16 *)(p + 0xCC) = 0x1B; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 2: *(s16 *)(p + 0xCC) = 0x1C; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 3: *(s16 *)(p + 0xCC) = 0x1E; *(s32 *)(p + 0x84) = D_004C283C; break;
        }
        break;
    case 5:
        switch (D_004F7F3C[0]) {
        case 0: *(s16 *)(p + 0xCC) = 0x43; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 1: *(s16 *)(p + 0xCC) = 0x44; *(s32 *)(p + 0x84) = D_004C283C; break;
        case 2: *(s16 *)(p + 0xCC) = 0x40; *(s32 *)(p + 0x84) = D_004C283C; break;
        }
        break;
    case 7:
        *(V4_a *)(p + 0x74) = D_00476B70;
        if (D_004F7F32[0] == p[0x20]) {
            *(V4_a *)(p + 0x74) = D_00476B60;
        }
        break;
    }
}
