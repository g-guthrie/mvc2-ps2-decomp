typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x10]; u8 f10; } G1;
extern G1 *D_004C299C;
void func_0037F120(u8 *p) {
    extern u8 *func_003DA750(); extern void func_0037F230();
    s8 i, j; u8 *o;
    j = 0;
    for (i = 0; i < 10; i++) {
        if ((o = func_003DA750(p, 1, 2)) != 0) {
            *(void**)(o+0x10) = func_0037F230;
            o[0x20] = 1;
            *(u8**)(o+0x18) = p;
            *(s16*)(o+0x26) = 0x1803;
            o[0x8E] = j;
            j = j + 1;
            o[0x98] = D_004C299C->f10;
        }
    }
}

