/* Metrowerks 3.0: ./try.sh src/grok_t6_205c10.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern u8 *func_0034B5A0(u8 *, int);
extern u8 *func_00198690(u8 *, int, int);
extern s8 func_00175700(u8 *);
extern void func_00184540(u8 *);

void func_00205C10(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        func_0018C4B0(p, 2);
        p[0x20D] = 2;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        p[0x1B5] = (s8)p[0x1B7] + 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 0x15, (p[0x1B7] + 2) & 0xFF);
        return;
    }
    if ((s8)p[0x151] != 0) {
        u8 *s = func_0034B5A0(p, 0);
        if (s != 0) {
            int i;
            s16 n;
            p[0x151] = 0;
            n = 0;
            for (i = 0; i < 4; i++, n += 7) {
                u8 *r = func_00198690(s, 0, 0);
                if (r != 0)
                    *(s16 *)(r + 0x1C) = n;
            }
        }
    }
    if (func_00175700(p) < 0)
        func_00184540(p);
}
