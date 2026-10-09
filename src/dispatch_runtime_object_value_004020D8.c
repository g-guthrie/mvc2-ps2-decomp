typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern const char D_004BC218[];
extern void func_003FB128(const char *message);
extern void func_003FF258(s32 *state, s32 value);

void func_004020D8(void *object, s32 value)
{
    if (object == 0) {
        func_003FB128(D_004BC218);
        return;
    }
    *(s16 *)((u8 *)object + 64) = value;
    func_003FF258(*(s32 **)((u8 *)object + 12), value);
}
