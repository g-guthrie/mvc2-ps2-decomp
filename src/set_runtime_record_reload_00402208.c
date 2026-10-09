typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern const char D_004BC2D8[];
extern void func_003FB128(const char *message);

void func_00402208(u8 *object, s32 reload_count)
{
    if (object == 0) {
        func_003FB128(D_004BC2D8);
        return;
    }

    *(s16 *)(object + 62) = reload_count;
}
