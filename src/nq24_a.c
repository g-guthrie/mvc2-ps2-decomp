typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_nq24a;
extern H_nq24a *D_004C2794;
void func_002971B0(u8 *p, u8 *q)
{
    s8 v;
    s32 w;
    u8 c;
    s32 t;
if (!(q[0] > 0) || !(q[1] > 0) || (v = p[0x150]) == 0) return;
c = v;
    p[0x150] = 0;
    w = *(s8 *)(p + 0x1B2);
    if (w != 0) {
        if ((s8)w & 1) {
            t = q[1] - 1;
            q[1] = t;
            if (!((u8)t > 0)) return;
        } else {
            t = q[0] - 1;
            q[0] = t;
            if (!((u8)t > 0)) return;
        }
    }
    p[0x1B5] = c;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}void func_002CDA90(u8 *p, u8 *q)
{
    s8 v;
    s32 w;
    u8 c;
    s32 t;
if (!(q[0] > 0) || !(q[1] > 0) || (v = p[0x150]) == 0) return;
c = v;
    p[0x150] = 0;
    w = *(s8 *)(p + 0x1B2);
    if (w != 0) {
        if ((s8)w & 1) {
            t = q[1] - 1;
            q[1] = t;
            if (!((u8)t > 0)) return;
        } else {
            t = q[0] - 1;
            q[0] = t;
            if (!((u8)t > 0)) return;
        }
    }
    p[0x1B5] = c;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}