typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    u8 *base;
    u16 off;
} Stream;

extern void func_0016B0C0(u8 *, Stream *, int);
extern s16 D_004D1802;

void func_00166FC0(u8 *p, Stream *a1)
{
    u8 *q;
    int i;

    func_0016B0C0(p, a1, 0);
    q = a1->base + a1->off;
    a1->off = a1->off + 7;
    for (i = 0; i < 3; i++, q += 2) {
        if (D_004D1802 < q[1])
            break;
    }
    p[1170] = q[0];
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
}
