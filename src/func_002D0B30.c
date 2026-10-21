typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_002D0CD0(u8 *);

void func_002D0B30(u8 *p)
{
    u8 *q;
    f32 v;
    s8 result;
    if (p[6] == 0) {
        *(f32 *)(p+0x34) += *(f32 *)(p+0x5c);
        *(f32 *)(p+0x5c) += *(f32 *)(p+0x68);
        *(f32 *)(p+0x38) += *(f32 *)(p+0x60);
        *(f32 *)(p+0x60) += *(f32 *)(p+0x6c);
        func_00175700(p);
        if (*(f32 *)(p+0x38) <= *(f32 *)(p+0x430)) {
            p[6]++;
            *(f32 *)(p+0x38) = *(f32 *)(p+0x430);
            v = p[0x1e6] ? -10.0f : 10.0f;
            *(f32 *)(p+0x5c) = v;
            *(f32 *)(p+0x6c) = 0.0f;
            func_001757E0(p, 15, 4);
            p[0x20d] = 0;
            func_001E3710(p, 0x30);
            func_002D0CD0(p);
            return;
        }
    } else {
        if (!*(s8 *)(p+0x150)) *(f32 *)(p+0x34) += *(f32 *)(p+0x5c);
        *(f32 *)(p+0x5c) += *(f32 *)(p+0x68);
        result = (s8)func_00175700(p);
        if (result < 0) { func_001843A0(p); return; }
        if (!*(s8 *)(p+0x151)) return;
        p[0x151] = 0;
        q = *(u8 **)(p+0x1dc);
        *(u8 **)(q+0x1c8) = p;
        q[0x20a] = 1;
        q[0x20d] = 2;
        func_001266A0(p, 0, 0);
        q[0x1b5] = 0x20;
        q[0x1e6] = p[0x1e6];
    }
}
