typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; u8 b[8]; } SB;
extern u8 jtbl_0044DF60[];

void func_001D13B0(u8 *d, SB *s) {
    extern void func_001754A0(u8 *, s32, s32);
    extern s32 func_00175670();
    u8 *p;
    s8 *q;
    s32 u;
    s32 v;
    if (*(s8 *)((u8 *)s + 0x13C) == 0) return;
    *(f32 *)(d + 0x34) = *(f32 *)((u8 *)s + 0x34);
    *(f32 *)(d + 0x38) = *(f32 *)((u8 *)s + 0x38);
    *(s16 *)(d + 0x140) = *(s16 *)((u8 *)s + 0x140);
    d[0x24] = *(s8 *)((u8 *)s + 0x24) + *(s8 *)(d + 0x31);
    if (*(s8 *)(d + 0x24) > 7) d[0x24] = 7;
    if (*(s8 *)(d + 0x24) < 0) d[0x24] = 0;
    p = s->b;
    q = (s8 *)(p + 1);
    u = p[1];
    if (*(s8 *)(d + 0x13C) != 0) {
        if (*(u32 *)(d + 0xD0) == *(u16 *)((u8 *)s + 0x168)) {
            if ((u8)u < 0x10) goto L4BC;
            goto L46C;
        }
    }
    if ((u8)u < 0x10) {
        goto L500;
    }
L46C:
    u = (u8)u;
    d[0x13C] = 1;
    if (*(u8 *)((u8 *)s + 0x2B8) != u || *(u32 *)(d + 0xD0) != *(u16 *)((u8 *)s + 0x168)) {
        *(u32 *)(d + 0xD0) = *(u16 *)((u8 *)s + 0x168);
        func_001754A0(d, 0x1B, jtbl_0044DF60[u]);
        return;
    }
L4BC:
    if (*(s8 *)((u8 *)s + 0x1B4) == 0 || (*(s8 *)((u8 *)s + 0x150) & 0x80) != 0) {
        if ((s8)func_00175670(d) >= 0) return;
        if (*q == 0x27) return;
L500:
        v = -1;
L504:
        *(u32 *)(d + 0xD0) = v;
        d[0x13C] = 0;
        *(u32 *)((u8 *)s + 0x2B8) = v;
    }
}
