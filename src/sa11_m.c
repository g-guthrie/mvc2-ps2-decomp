typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_00473FD0[])(u8 *, u8 *);
extern void (*D_00473FE0[])(u8 *, u8 *);
extern void (*D_004C1FF0[2])(u8 *, u8 *);

void func_003B5300(u8 *p, u8 *q) {
    u8 *r;
    u32 t;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    r = q + 0x2B8;
    if (p[0x22] == 0) {
        if (p[0x20] == 0) {
            if (q[5] != 0 || q[0x1E4] != 0x15) {
                t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
                r[4] = 1;
            } else {
                D_00473FD0[p[5]](p, q);
                return;
            }
        } else {
            if (q[5] != 0 || q[0x1E4] != 0x15) {
                t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
            } else {
                p[0x13C] = 0;
                D_004C1FF0[p[5]](p, q);
            }
        }
    } else {
        if (p[0x20] == 0) {
            if (q[5] != 1 || q[0x1E4] != 0x1E) {
                t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
                r[4] = 1;
            } else {
                D_00473FE0[p[5]](p, q);
            }
        } else {
            if (q[5] != 1 || q[0x1E4] != 0x1E) {
                t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
            } else {
                p[0x13C] = 0;
                D_004C1FF0[p[5]](p, q);
            }
        }
    }
}
