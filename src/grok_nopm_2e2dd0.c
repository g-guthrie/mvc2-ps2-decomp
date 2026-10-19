/* Metrowerks 3.0: ./try.sh src/grok_nopm_2e2dd0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_002E2F10(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002E2E90(u8 *);

void residual_002E2DD0(u8 *p)
{
    if (p[533]) {
        func_002E2F10(p);
        return;
    }
    p[6]++;
    if (p[525] != 2) {
        func_00183D10(p);
    }
    p[533] = 255;
    p[525] = 2;
    p[528] = 0;
    *(u32 *)(p + 96) = 0x414DB6DB;
    *(u32 *)(p + 108) = 0xBE892492;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(s16 *)(p + 702) = 600;
    *(s16 *)(p + 28) = 16;
    func_001757E0(p, 26, 0);
    func_002E2E90(p);
}
