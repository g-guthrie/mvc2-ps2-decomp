typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x10]; void *fn; } RT1A;

extern s32 D_004C2B70;
extern RT1A *D_006338B4[];
extern void D_0041D5F0();

void func_0041D560(u8 *p)
{
    extern s32 func_0012ABC0(s32, s32);
    extern void func_0041D390(u8 *);
    u32 r;
    if (p[0x23] != 0) {
        r = func_0012ABC0(3, 0) & 0xFFFF;
        if ((r & 0xC00) != 0) {
            if ((r & 0x800) != 0) {
                D_004C2B70 = 8;
            } else {
                D_004C2B70 = -1;
            }
            D_006338B4[0]->fn = (void *)D_0041D5F0;
            *(void **)(p + 0x10) = (void *)func_0041D390;
            func_0041D390(p);
        }
    }
}
