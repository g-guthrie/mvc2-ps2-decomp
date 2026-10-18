typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_00126400();
extern void func_002F1DF0();
extern void func_00197610();
extern void func_001754A0();
extern void func_001BB8D0();
extern void (*D_0044C040[])();
extern void *func_003DA750();
extern void func_00381050();
extern void func_00185490();
extern void func_00184540();
extern void func_001DB2E0();
extern void func_00358DD0();
extern u8 D_0044DA60[];
extern u8 *D_004C283C;
extern void func_00170E60();
extern void func_0032F5C0();
extern f32 D_004F1FD8;
extern f32 D_004F1FDC;
extern void func_0030C470();
extern void func_003BA230();
extern void func_00309310();
extern void func_0016CBD0();
extern u32 D_004C2820;
extern s32 func_00189B90();
extern void func_00186A60();
extern u8 D_0044F620[];
extern s32 func_003D92F0();
extern void func_001843A0();
extern void func_001C8CE0();
extern void func_001757E0();
extern s16 *D_004C2794;
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C4B0();

void func_00190580(u8 *p) {
    if (p[5] == 3) {
        f32 f = 1.6666666f;
        if (!((1 << (s8)(*(s8 *)(p + 0x1B4) & 0x1F)) & 0xCCCCCCCC)) f = -f;
        if (*(s16 *)(p + 0x140)) f = -f;
        *(f32 *)(p + 0x34) += f;
    }
}

void func_00358D50(u8 *p) {
    u8 *s = p + 0x2B8;
    u8 *v = func_003DA750(0, 2, 0);
    if (v) {
        *(void **)(v + 0x10) = func_00358DD0;
        *(u8 **)(v + 0x18) = p;
        v[1] = p[1];
        v[0x20] = 0;
        v[0x21] = 0;
        *(s16 *)(v + 0x26) = 0xB00;
        s[0xE] = 0;
        s[0xF] = 0;
        *(u8 **)s = v;
    }
}
