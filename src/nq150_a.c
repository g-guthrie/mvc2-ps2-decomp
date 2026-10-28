typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[2]; s16 f80[1]; } G806;
extern G806 *D_004C2794;
typedef struct { u8 *t[3]; } T806;
extern T806 D_004D18B8[];

void func_001806B0(u8 *p, s32 b)
{
    u8 *q;
    s32 found;
    s32 k;
    *(s8 *)(p + 0x13D) = -1;
    if (p[0] != 0 && (*(u32 *)(p + 0x428) & 0x3000000) != 0) {
        found = 0;
        if (b == 0) {
            if (p[1] == 0x18) {
                k = 0x19;
                q = D_004D18B8[p[2]].t[(p[0x425] + 4) % 3];
                found = 1;
                if (q[1] != k) {
                    q = D_004D18B8[p[2]].t[(p[0x425] + 2) % 3];
                    if (q[1] != k)
                        q[0x540] = k;
                }
            }
        } else {
            if (p[1] == 0x19) {
                k = 0x1A;
                q = D_004D18B8[p[2]].t[(p[0x425] + 4) % 3];
                found = 1;
                if (q[1] != k) {
                    q = D_004D18B8[p[2]].t[(p[0x425] + 2) % 3];
                    if (q[1] != k)
                        q[0x540] = k;
                }
            }
        }
        if (found) {
            u8 x, y;
            p[0x13C] = 0;
            p[0] = 0;
            *(s16 *)(p + 0x434) = 0;
            *(s16 *)(p + 0x438) = 0;
            q[0] = 1;
            q[0x13C] = 0;
            *(s16 *)(q + 0x434) = 0x90;
            *(s16 *)(q + 0x438) = 0x90;
            *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34);
            x = p[0x425];
            y = q[0x425];
            p[0x425] = y;
            q[0x425] = x;
            q[7] = 0;
            q[6] = 0;
            q[5] = 0;
            q[4] = 0;
        }
    }
    D_004C2794->f7c[p[2]] = 0;
    D_004C2794->f80[p[2]] = 0;
    p[0x1F5] = 0x50;
    p[0x1F7] = 0;
    p[0x226] = 0;
}
