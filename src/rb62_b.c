typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* MW 3.0.3: ./try.sh src/rb62_b.c "-O3,p -sdatathreshold 8" */
typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 w14;
    u8 _p0[0x170 - 0x18];
} Slot;

typedef struct {
    u32 w0;
    u8 _p0[8];
    u32 wC;
    u8 _p1[8];
    u32 w18;
    u32 w1C;
} Src;

extern Slot D_005BF2F0[];
extern u8 D_004BABA0[];
extern s32 D_004C2AD4;
extern void func_003ED0D0();
extern void func_003F55B0();
extern s32 func_003DCFE0();
extern s32 func_003DD030();
extern void func_003DCDC0();
extern s32 func_003EE8C0();
extern void func_003F0860();
extern void func_003EF9A0();
extern void func_003F01B0();

s32 func_003EE6F0(Src *a, u32 flags) {
    u32 i;
    s32 off;
    Slot *s;
    u8 *d;
    i = 0;
    off = 0;
    do {
        if (*(s32 *)((u8 *)D_005BF2F0 + off + 4) == 0) break;
        i++;
        off += 0x170;
    } while (i < 0x400);
    if (i == 0x400) {
        func_003ED0D0(D_004BABA0);
        return 0;
    }
    s = &D_005BF2F0[i];
    func_003F55B0(s, 0, 0x170);
    s->w4 = a->w0;
    s->w8 = a->wC;
    s->w0 = flags;
    if ((flags & 4) == 0) {
        s->w10 = 0x30;
        s->w10 += (a->w1C + 0xF) & ~0xF;
        s->w10 += (a->w18 + 0xF) & ~0xF;
        s->w14 = func_003DCFE0(s->w10, 3);
        d = (u8 *)func_003DD030(s->w14);
        func_003DCDC0(d, a, 0x24);
        d += 0x30;
        func_003DCDC0(d, *(s32 *)((u8 *)a + 8), a->w1C);
        d += (a->w1C + 0xF) & ~0xF;
        func_003DCDC0(d, *(s32 *)((u8 *)a + 0x10), a->w18);
    }
    s->wC = D_004C2AD4;
    if (func_003EE8C0(s, a) == 0) {
        func_003F0860(i + 1);
        return 0;
    }
    func_003EF9A0(*(s32 *)((u8 *)s + 0x28), *(s32 *)(*(u8 **)((u8 *)s + 0x40) + 0x14), func_003DD030(*(s32 *)((u8 *)s + 0x20)), (u8 *)s + 0x50);
    func_003F01B0(s, 0);
    return i + 1;
}
