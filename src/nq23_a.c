typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_nq23a;
extern G_nq23a *D_004C2794;

void func_001EB060(u8 *p, u8 *q) {
    s8 v;
    u8 c;
    s32 f;
    if (q[0] <= 0 || q[1] <= 0 || (v = *(s8 *)(p + 0x150)) == 0) {
        return;
    }
        c = v;
        p[0x150] = 0;
        f = *(s8 *)(p + 0x1B2);
        if (f != 0) {
            if ((s8)f & 1) {
                u32 t = q[1];
                u8 n = t - 1;
                q[1] = n;
                if (n <= 0) return;
            } else {
                u32 t = q[0];
                u8 n = t - 1;
                q[0] = n;
                if (n <= 0) return;
            }
        }
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
}
