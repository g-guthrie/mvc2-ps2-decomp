typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
/* The native writes x/y and leaves z untouched before the matched Vec3 consumer. */
typedef struct { f32 x, y, z; } V3;

extern u8 D_004F1F46;
extern u8 D_004F1F45;
extern int func_00175700(u8 *);
extern void func_00158C70(u8 *, int);
extern void func_001E3A40(u8 *);
extern void func_00126400(void);
extern int func_001757E0(u8 *, int, int);

void func_002E0A40(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 336) == 0) {
        *(f32 *)(p + 56) += *(f32 *)(p + 96);
        *(f32 *)(p + 96) += *(f32 *)(p + 108);
    }
    if (*(f32 *)(p + 56) >= *(f32 *)(p + 1072))
        ;
    else {
        V3 sp;
        u8 *s0 = *(u8 **)(p + 476);
        sp.x = *(f32 *)(s0 + 52);
        sp.y = *(f32 *)(s0 + 1072);
        func_00158C70((u8 *)&sp, s0[2]);
        func_001E3A40(p);
        D_004F1F46 = 1;
        D_004F1F45 = 2;
        *(u8 **)(s0 + 456) = p;
        s0[522] = 2;
        s0[437] = 0x21;
        *(s16 *)(s0 + 320) = *(s16 *)(p + 320);
        s0[486] = p[486];
        func_00126400();
        p[7]++;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        *(u32 *)(p + 92) = 0x40855555u;
        *(u32 *)(p + 96) = 0x414DB6DBu;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 108) = 0xBF4DB6DBu;
        if (p[486])
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        func_001757E0(p, 15, 4);
    }
}
