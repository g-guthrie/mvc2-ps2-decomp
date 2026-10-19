typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0035F430(void);
extern void func_00175700(u8 *);
extern int func_0035EF90(u8 *, int, u8 *);
extern void func_001E7F60(u8 *);

void func_0035F270(u8 *p, u8 *q, u8 *r)
{
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        func_0035F430();
        func_00175700(p);
        if (p[0x15B]) {
            unsigned int offset;
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(s16 *)(offset + 0x7C);
            p[0x15B] = 0;
            *(s16 *)(p + 0x1C) = 0;
        }
        if (*(s8 *)(p + 0x151)) {
            p[5]++;
            if (!func_0035EF90(p, p[0x20] + 1, q))
                *(s8 *)(r + 4) = -1;
        }
    }
    func_001E7F60(p);
}
