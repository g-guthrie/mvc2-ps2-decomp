/* func_00319980: MW 3.0.3 (also exact on 3.0) -O3 -sdatathreshold 8.
 * #pragma opt_common_subs off keeps `a` a real local (CSE otherwise renames it to a
 * temp that is coloured before q); q declared first so q gets a2 and a gets a3. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G319;
extern G319 *D_004C2794;

#pragma push
#pragma opt_common_subs off
void func_00319980(u8 *p)
{
    u8 *q;
    s32 a;
    u8 *t;
    s8 c;
    u8 *r;
    if ((a = (s8)p[0x1B2]) == 0)
        return;
    q = p + 0x2B8;
    r = q + 2;
    if ((s8)q[2] != 0)
        return;
    t = *(u8 **)(p + 0x1C4);
    if (t[3] == 0 && t[0x216] == 0 && ((s8)a & 0x11) == 0) {
        c = q[3] + 1;
        q[3] = c;
        if (c < 5) {
            p[0x1B5] = 0x3D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            *r = 0;
        } else {
            *(s8 *)r = -1;
        }
        p[0x2BC] = 1;
        *(s8 *)(p + 0x2BD) = -1;
        return;
    }
    *(s8 *)r = *(s8 *)(p + 0x2BC) = -1;
}
#pragma pop
