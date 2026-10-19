/* Metrowerks 3.0: ./try.sh src/grok_t6_205d60.c "-O3 -Op" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);

void func_00205D60(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        func_0018C4B0(p, 0x10);
        if (p[0x20D] != 2) {
            p[0x20D] = 0;
            func_00183D10(p);
            if (p[0x269] == 3) {
                p[0x1B5] = 0x3C;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                ((s16 *)(D_004C2794 + 124))[p[2]]++;
            } else {
                p[0x1B5] = (s8)p[0x1B7] + 0x34;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                ((s16 *)(D_004C2794 + 124))[p[2]]++;
            }
            func_001757E0(p, 0x15, (p[0x1B7] + 4) & 0xFF);
            return;
        }
        p[0x20D] = 2;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x6C) = -45.0f / 56.0f;
        p[0x1B5] = (s8)p[0x1B7] + 0x36;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 0x15, (p[0x1B7] + 6) & 0xFF);
        return;
    }
    if (p[0x20D] != 2) {
        if (((s8)func_00175700(p)) < 0)
            func_001843A0(p);
    } else {
        if (((s8)func_00175700(p)) < 0)
            func_00184540(p);
    }
}
