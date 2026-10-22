typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u32 a, b; } __attribute__((packed)) Pk8;
typedef struct { u8 b0; u8 b1; u16 h2; u32 w4; Pk8 q; } OutE;
typedef struct VT { u8 pad[0x18]; s32 (*f18)(); } VT;
typedef struct Obj { VT *vt; } Obj;
typedef struct { s8 b0; u8 pad1; u16 h2; Obj *obj; u8 pad8[4]; u32 wC; u32 w10; } InE;
extern InE D_00495BB8[];

void func_00410CB8(s32 unused, u8 *out)
{
    extern void func_0040EFE0();
    extern void func_0040EFF8();
    s32 n, k;
    InE *s1;
    OutE *s0, *base;
    Pk8 buf;
    u8 t1;
    u32 t2;
    u16 t3;
    n = 0;
    k = 0;
    base = (OutE *)(out + 0x10);
    func_0040EFE0();
    s1 = D_00495BB8;
    do {
        if (s1->b0 == 1) {
            s0 = (OutE *)((n << 4) + (s32)base);
            for (;;) {
                if (n == 0x80) goto done;
                s1->obj->vt->f18(s1->obj, s1->wC, 0x7FFFFFFF, &buf);
                if (buf.b == 0) {
                    k++;
                    break;
                }
                s0->b0 = 0;
                n++;
                t1 = s1->wC; t2 = s1->w10;
                s0->b1 = t1;
                s0->w4 = t2;
                t3 = s1->h2;
                s0->q = buf;
                s0->h2 = t3;
                s0++;
            }
        } else {
            k++;
        }
        s1++;
    } while (k < 0x20);
done:
    func_0040EFF8();
    *(s32 *)out = n;
}
