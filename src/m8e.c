typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 v[1]; } G0;
extern G0 *D_004C2794;
extern s32 func_00175700(void *p);
extern void func_001843A0(void *p);

void func_00270ED0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        s8 x = *(s8 *)(p + 0x151);
        if (x != 0) {
            p[0x1B5] = x + 0x30;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->v[p[2]]++;
            p[0x151] = 0;
        }
    }
}
