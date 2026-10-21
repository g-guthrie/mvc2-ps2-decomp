/* Unregistered candidate: cleanup helper uses its actual two inputs. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_0037AFC0(u8 *a, u8 *b, u8 *c)
{
    extern void func_0037B400(u8 *, u8 *);
    extern int func_00175700(u8 *);
    extern s32 func_0037B300(u8 *, u8 *, u8 *);
    extern void func_0037B420(u32, u8);
    extern void func_001E7F60(u8 *);
    if (a[1] != (*(u8 **)(a + 0x18))[1]) {
        func_0037B400(a, b);
        return;
    }
    if (*(s32 *)c != 0) {
        if (*(u8 **)(*(u8 **)(a + 0x1E0) + 0x1E0) != a) {
            a[4] = 4;
            *(s32 *)(c + 8) = 1;
            return;
        }
        func_00175700(a);
        if (func_0037B300(a, b, c) == 0) {
            a[4] = 4;
            *(s16 *)(a + 0x1E) = 0x14;
            *(f32 *)(a + 0x118) = 1.0f;
            a[0x13C] = 1;
        }
    } else {
        if (*(s16 *)(a + 0x1E) != 0) {
            func_00175700(a);
            *(s16 *)(a + 0x1E) = *(s16 *)(a + 0x1E) - 1;
            func_0037B420((u32)a, c[0]);
            if (*(s8 *)(a + 0x1B2) != 0) *(s16 *)(a + 0x1E) = 0;
            func_001E7F60(a);
        } else {
            a[4] = 4;
            *(s16 *)(a + 0x1E) = 0x14;
            *(f32 *)(a + 0x118) = 1.0f;
            a[0x13C] = 1;
        }
    }
}
