/* MW 3.0.3 (./try.sh) -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00583B9D;
extern u8 D_00583B90[];
extern u8 D_0045E200[];
typedef struct { u32 a[3]; } R3;
extern R3 D_0045E220[];
extern u8 D_004F20B1[];
extern u8 D_004F25F0[];
extern u8 D_004F258D[];

void func_0032D970(u8 *p) {
    s32 c = *(s8 *)(p + 0x538);
    s32 h = *(volatile s16 *)(p + 0x1E);
    u8 *m;
    u8 i;
    u8 idx;
    s32 o;
    u8 *t;
    u8 v;
    idx = c + h * 2;
    if (D_00583B9D != 0) {
        s32 k = idx * 0x5B8;
        v = D_0045E220[c].a[0];
        D_004F20B1[k] = v;
        D_004F25F0[k] = v;
        D_004F258D[k] = 0;
        return;
    }
    m = D_00583B90 + c * 8;
    i = 0;
    o = 0;
    t = D_0045E200 + c * 12;
    while (i < 3) {
        if (*(u32 *)(m + 0x20) & *(u32 *)((u32)o + (u32)t)) {
            s32 k = idx * 0x5B8;
            v = D_0045E220[c].a[i];
            D_004F20B1[k] = v;
            D_004F25F0[k] = v;
            D_004F258D[k] = 0;
            return;
        }
        o += 4;
        i++;
    }
}
