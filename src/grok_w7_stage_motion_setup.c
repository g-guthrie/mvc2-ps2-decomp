typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;
typedef union FloatPairBits {
    f32 values[2];
    u32 bits[2];
} FloatPairBits;

extern void func_001266A0(u8 *, int, int);
extern void func_0018C6E0(void *);
extern void func_00176160(u8 *, int, int, int);
extern void func_0015D010(u8 *, f32 *);
extern int func_001757E0(u8 *, int, int);

void func_0030F2E0(u8 *p)
{
    struct {
        FloatPairBits position;
        u32 padding[2];
    } local;
    int mode;

    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);

    if ((p[0x20B] & 0x3F) == 0) {
        if ((p[0x22] & 1) != 0) {
            p[0x1E6] ^= 1;
            *(s16 *)(p + 0x140) ^= 1;
        }
        func_00176160(p, 1, 11, 1);
        mode = 0;
        local.position.bits[0] = 0xC2D55555;
        local.position.bits[1] = 0x432B6DB6;
    } else {
        if ((p[0x22] & 1) != 0) {
            p[0x1E6] ^= 1;
            *(s16 *)(p + 0x140) ^= 1;
        }
        func_00176160(p, 1, 9, 1);
        mode = 1;
        local.position.bits[0] = 0xC3200000;
        local.position.bits[1] = 0x433C9249;
    }

    func_0015D010(p, local.position.values);
    func_001757E0(p, 15, (u8)mode);
}
