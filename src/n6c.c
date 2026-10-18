typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))


extern void func_003DAA40(u8 *);
extern u8 D_00445410[];
extern f32 D_004453B0[];
extern s32 D_004C2838;
void func_0015DFC0(u8 *a0) {
    s16 *h = (s16 *)a0;
    s16 v = h[0xE];
    if (v < 9) {
        h[0xE] = v + 1;
    } else {
        s16 w = h[0xF];
        if (w > 10) {
            func_003DAA40(a0);
        } else {
            s32 off = w << 2;
            h[0x66] = *(s16 *)(D_00445410 + off);
            S32(a0, 0x84) = D_004C2838;
            F32(a0, 0x74) = D_004453B0[h[0xF]];
            h[0xF] = h[0xF] + 1;
        }
    }
}

extern void func_003DA6F0(s32);
extern s32 func_0012E560(void);
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern u8 *D_004C2840;
void func_0016EB90(void) {
    u8 *a1;
    s32 b;
    func_003DA6F0(0x12);
    S16(D_004C2840, 8)--;
    a1 = D_004C2840;
    b = S8(a1, 0x88);
    if (((b & 1) != 0 && (D_004F4480[0] & 0x360) != 0) || ((b & 2) != 0 && (D_004F4494[0] & 0x360) != 0) || S16(a1, 8) == 0) {
        S16(a1, 8) = 1;
        if (func_0012E560() != 0) {
            S8(D_004C2840, 0x92)++;
        }
    }
}
