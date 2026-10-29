/* func_0032DF90: MW 3.0.3 -O3,p -sdatathreshold 8. The CPU team pick. bit is reused as the scan word; loop 2 walks an explicit byte offset. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 *D_004C2840;
extern u8 D_00583B90[];
extern u8 D_00583B92[];
extern s8 D_004405A0[];
typedef struct {
    u8 b0; s8 b1; u8 pad2[0x1C]; s16 h1E; u8 pad20[0x4DD - 0x20]; u8 b4DD;
    u8 pad4DE[0x518 - 0x4DE]; u32 w518[2]; u8 pad520[0x538 - 0x520]; s8 b538;
    u8 pad539[0x540 - 0x539]; s8 b540; u8 pad541[0x5B8 - 0x541];
} E;
extern E D_004F20B0[];
typedef struct { u8 pad[0x10]; u32 w[2]; } R8;

void func_0032DF90(s8 side) {
    extern s32 func_00417A40(void);
    u32 stk[2];
    E *t;
    E *o;
    u32 n;
    u32 r;
    s8 i;
    s32 bit;
    s32 m;
    u32 off;
    u8 j;
    u32 k;
    t = D_004F20B0 + side;
    o = D_004F20B0 + (side ^ 1);
    D_00583B92[side] = 0;
    if (D_004C2840[0x85] == 7) {
        t->h1E = 0;
        while (t->h1E < 3) {
            D_004F20B0[side + t->h1E * 2].b540 = t->h1E + 0x18;
            D_004F20B0[side + t->h1E * 2].b1 = t->h1E + 0x18;
            D_004F20B0[side + t->h1E * 2].b4DD = 0;
            D_00583B90[side + 2] |= 0x11 << (s8)t->h1E;
            t->h1E++;
        }
        return;
    }
    stk[1] = 0;
    stk[0] = 0;
    t->h1E = 0;
    while (t->h1E < 3) {
        n = 0;
        m = 1;
        do {
            r = func_00417A40();
            i = func_00417A40() & 1;
            j = r & 0x1F;
            bit = 1 << j;
            if ((bit & o->w518[i]) == 0) {
                u32 s = ((volatile R8 *)(D_00583B90 + o->b538 * 8))->w[i];
                if ((s & bit) != 0 && (bit & stk[i]) == 0) {
                    goto found;
                }
            }
            n++;
        } while (n < 0x10);
        for (i = 0, off = 0; i < 2; i++, off += 4) {
            for (k = 0; k < 32; k++) {
                bit = *(u32 *)((u8 *)o + off + 0x518) ^ *(u32 *)((u8 *)((R8 *)(D_00583B90 + o->b538 * 8))->w + off);
                if (bit & (m = 1 << k)) {
                    j = k;
                    bit = m;
                    if ((m & *(u32 *)((u8 *)stk + off)) == 0) goto found;
                }
            }
        }
        for (i = 0; i < 2; i++) {
            for (k = 0; k < 32; k++) {
                bit = ((R8 *)(D_00583B90 + o->b538 * 8))->w[i];
                if (bit & (m = 1 << k)) {
                    j = k;
                    bit = m;
                    if ((m & stk[i]) == 0) goto found;
                }
            }
        }
found:
        stk[i] |= bit;
        D_00583B90[side + 2] |= 0x11 << (s8)t->h1E;
        D_004F20B0[side + t->h1E * 2].b540 = i * 32 + (s8)j;
        D_004F20B0[side + t->h1E * 2].b1 = D_004F20B0[side + t->h1E * 2].b540;
        D_004F20B0[side + t->h1E * 2].b4DD = D_004405A0[D_004F20B0[side + t->h1E * 2].b540];
        t->h1E++;
    }
}
