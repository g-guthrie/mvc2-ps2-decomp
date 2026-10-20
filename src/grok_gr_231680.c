/* Metrowerks 3.0: ./try.sh src/grok_gr_231680.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001864a0(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00185870(u8 *, u8 *);
extern void func_00190D50(u8 *, u8 *);

void func_00231680(u8 *p)
{
    u8 *q;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) < 0)
        return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p)) {
        func_001266A0(p, 0, 0);
        func_001843A0(p);
        return;
    }
    q = *(u8 **)(p + 0x1DC);
    if (q[0x20D] != 2)
        return;
    {
        f32 d = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
        if (d < 0.0f)
            d = -d;
        if (d <= 106.66666412353515625f) {
            f32 e = 68.5714263916015625f + (*(f32 *)(q + 0x38) - *(f32 *)(p + 0x38));
            if (e < 0.0f) {
                func_001757E0(p, 0xF, 4);
                p[0x20B] = 0xC4;
                func_00185870(p, q);
                func_00190D50(q, p);
                func_001266A0(p, 5, 5);
                q[0x24A] = 0;
                p[7]++;
            }
        }
    }
}
