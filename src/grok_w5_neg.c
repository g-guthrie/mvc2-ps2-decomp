typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
static void func_001EBBD0(u8 *p) {
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    if (*(float *)(p + 56) <= *(float *)(p + 1072))
        *(float *)(p + 56) = *(float *)(p + 1072);
}
static void func_0024B9B0(u8 *a0)
{
    *(float *)(a0 + 52) += *(float *)(a0 + 92);
    *(float *)(a0 + 92) += *(float *)(a0 + 104);
    *(float *)(a0 + 56) += *(float *)(a0 + 96);
    *(float *)(a0 + 96) += *(float *)(a0 + 108);
    if (*(float *)(a0 + 1072) >= *(float *)(a0 + 56)) {
        *(float *)(a0 + 56) = *(float *)(a0 + 1072);
    }
}
static void func_00255620(u8 *p) {
    if ((*(short *)(p + 696)) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}
extern void func_00289570(u8 *);
extern void func_00290E30(u8 *);
extern void func_00297D50(u8 *);
extern void func_00297F90(u8 *);
static void func_002CE6E0(u8 *p) {
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    if (*(float *)(p + 56) <= *(float *)(p + 1072))
        *(float *)(p + 56) = *(float *)(p + 1072);
}

void func_0024D390(u8 *p)
{
    extern int func_00175700(u8 *);
    func_0024B9B0(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_00259D60(u8 *p)
{
    extern int func_00175700(u8 *);
    func_00255620(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_0025A4B0(u8 *p)
{
    extern int func_00175700(u8 *);
    func_00255620(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_0028D610(u8 *p)
{
    func_00289570(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_00294920(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_00298320(u8 *p)
{
    func_00297F90(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_001EBE10(u8 *p)
{
    extern int func_00175700(u8 *);
    func_001EBBD0(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_0028C320(u8 *p)
{
    func_00289570(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_002911B0(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_00293690(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_00297F20(u8 *p)
{
    func_00297D50(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_002CE8B0(u8 *p)
{
    extern int func_00175700(u8 *);
    func_002CE6E0(p);
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
    }
}

void func_002F0510(u8 *p)
{
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 22, 0);
    }
}

void func_00324DE0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[827] = 0;
        p[828] = 0;
        p[6]++;
        func_001757E0(p, 22, 11);
    }
}

void func_003A20A0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        func_001757E0(p, 21, (p[33] + 8) & 0xff);
    }
}
