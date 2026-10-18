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


extern void func_00160570(void);
extern void func_00160680(void);
extern void func_001E42D0(s32);
extern u8 D_004D18E8[];
extern u8 D_004D18E5[];
extern u8 *D_004C2840;
void func_001604D0(void) {
    s32 i = 0;
    do {
        func_00160570();
        func_00160680();
        i++;
    } while (i <= 0);
    if (D_004D18E8[0] == 8 && S8(D_004C2840, 0x8F) == 0) {
        if (D_004D18E5[0] == 2) {
            func_001E42D0(1);
        }
    } else {
        func_001E42D0(1);
    }
}
