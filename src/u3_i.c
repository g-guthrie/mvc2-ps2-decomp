typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 func_00120288(u8 *, void *, s32);
extern s32 func_004105D8(u8 *);
extern void func_004106E8(u8 *, void *);

u8 *func_00410720(s32 *r, void *a, void *b, s32 *out) {
    u8 *p;
    u8 *end;
    out[0] = 0;
    out[1] = 0;
    end = (u8 *)r[0] + r[1];
    p = (u8 *)r[0];
    while (p < end) {
        if (func_00120288(p, a, 7) == 0) {
            func_004106E8(p, out);
            break;
        }
        if (b != 0 && func_00120288(p, b, 7) == 0) return 0;
        p += func_004105D8(p + 8) + 0x10;
    }
    return p < end ? p : 0;
}
