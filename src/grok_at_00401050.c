typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *func_0040EF88(u8 *base, s32 index);
extern u8 *func_0040EF70(u8 *base, s32 index);
extern s32 func_00410AD0(u8 *object, s32 flag);
extern s32 func_0011EB60(char *fmt, ...);
extern char D_004BBF48[];
extern char D_004BBF68[];
extern char D_004BBF88[];

typedef struct {
    s32 (*fn)(u8 *, s32);
} VT36;

void func_00401050(u8 *p)
{
    u8 *base = *(u8 **)(p + 12);
    u8 *a = func_0040EF88(base, 0);
    u8 *b = func_0040EF70(base, 0);
    s32 (*fn)(u8 *, s32) = *(s32(**)(u8 *, s32))(*(u8 **)b + 36);
    s32 x = fn(b, 1);
    s32 y = fn(b, 0);
    s32 u = func_00410AD0(a, 1);
    s32 v = func_00410AD0(a, 0);
    func_0011EB60(D_004BBF48, x, y, x + y);
    func_0011EB60(D_004BBF68, u, v, u + v);
    func_0011EB60(D_004BBF88, (s8)p[1], x + v + u + y);
}
