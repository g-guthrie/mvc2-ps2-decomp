typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s16 D_004BF530[4];

void func_00193970(u8 *a, u8 *b)
{
    extern void func_001937E0(u8 *, u8 *);
    extern void func_00193870(u8 *, u8 *);
    extern void func_00175670(u8 *);
    s8 *c;
    s16 v;
    c = (s8 *)(a + 0x88);
    if (*(u16 *)(a + 0x98) != *(u16 *)(b + 0x168)) {
        a[5]++;
        c[0x1C] = 0;
        func_001937E0(a, b);
        func_00193870(a, b);
        func_00175670(a);
        return;
    }
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        v = *(s16 *)(a + 0x1E) - 1;
        *(s16 *)(a + 0x1E) = v;
        if (v == 0) {
            *(s16 *)(a + 0x1E) = D_004BF530[c[0x1C]];
            if (c[0x1C] != 0) {
                c[0x1C] = c[0x1C] - 1;
                *(s16 *)(a + 0x1C) = 4;
            } else {
                *(s16 *)(a + 0x1C) = 1;
            }
        } else {
            *(s16 *)(a + 0x1C) = 1;
        }
        func_001937E0(a, b);
    }
    func_00193870(a, b);
    func_00175670(a);
}
