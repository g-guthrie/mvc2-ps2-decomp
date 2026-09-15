typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern int func_00189150(u8 *);
extern void func_00186A60(u8 *, int);

int func_00286A20(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)I(p, 1056)) return 0;
    p[509] = 8;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 29);
    return 1;
}
int func_0028E2E0(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)I(p, 1056)) return 0;
    p[509] = 8;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 29);
    return 1;
}
