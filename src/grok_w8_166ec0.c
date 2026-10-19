typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 *base;
    u16 off;
} Stream;

extern void func_0016B0C0(u8 *, Stream *, int);
extern int func_00174170(void);

void func_00166EC0(u8 *p, Stream *a1)
{
    u8 *q;

    func_0016B0C0(p, a1, 0);
    q = a1->base + a1->off;
    a1->off = a1->off + 4;
    p[1170] = q[func_00174170() & 3];
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
}
