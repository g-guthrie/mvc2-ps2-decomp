typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0037AFC0(u8 *p, u8 *a1, u8 *a2) {
    extern s32 func_00175700();
    extern s32 func_0037B300();
    extern void func_0037B400();
    extern void func_0037B420();
    extern void func_001E7F60();
    if (p[1] != *(u8 *)(*(u8 **)(p + 0x18) + 1)) {
        func_0037B400(p, a1, a2);
        return;
    }
    if (*(s32 *)a2 != 0) {
        if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) != p) {
            p[4] = 4;
            *(s32 *)(a2 + 8) = 1;
            return;
        }
        func_00175700(p);
        if (func_0037B300(p, a1, a2) != 0) {
            return;
        }
        p[4] = 4;
        *(s16 *)(p + 0x1E) = 0x14;
        *(u32 *)(p + 0x118) = 0x3F800000;
        p[0x13C] = 1;
        return;
    }
    if (*(s16 *)(p + 0x1E) != 0) {
        func_00175700(p);
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        func_0037B420(p, a2[0]);
        if (*(s8 *)(p + 0x1B2) != 0) {
            *(s16 *)(p + 0x1E) = 0;
        }
        func_001E7F60(p);
        return;
    }
    p[4] = 4;
    *(s16 *)(p + 0x1E) = 0x14;
    *(u32 *)(p + 0x118) = 0x3F800000;
    p[0x13C] = 1;
}
