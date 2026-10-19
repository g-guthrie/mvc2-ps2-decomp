typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern void func_00175700(u8 *);

void func_002577D0(u8 *p)
{
    f32 *r5c;
    f32 *r60;
    f32 *r68;
    f32 *r6c;

    r5c = (f32 *)(p + 0x5C);
    r68 = (f32 *)(p + 0x68);
    r60 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x34);
    *r5c = *(f32 *)(p + 0x68) + *r5c;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60) + *(f32 *)(p + 0x38);
    *r60 = *(f32 *)(p + 0x6C) + *r60;
    r6c = (f32 *)(p + 0x6C);
    if ((s8)p[0x1B2] != 0) {
        p[7]++;
        *(u32 *)r5c = 0x40855555;
        if (p[0x1E6] != 0)
            *r5c = -*r5c;
        *(u32 *)r68 = 0;
        *(u32 *)r60 = 0x41700000;
        *(u32 *)r6c = 0xBF892492;
        p[0x1E7] = 1;
        func_001757E0(p, 0x14, 0x14);
        return;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[7] = 3;
        p[0x20D] = 0;
        *(u32 *)r5c = 0;
        *(u32 *)r60 = 0;
        *(u32 *)r68 = 0;
        *(u32 *)r6c = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_001757E0(p, 0x14, 0x15);
    } else {
        func_00175700(p);
    }
}
