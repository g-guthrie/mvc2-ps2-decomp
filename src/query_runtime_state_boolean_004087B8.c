typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 padding0[2];
    s8 mode;
    u8 padding3[45];
    s32 handle;
} RuntimeMetricState;

extern RuntimeMetricState D_004872F0;
extern s32 func_001089F0(s32 handle, s32 option, s32 *result);

s32 func_004087B8(void)
{
    s32 result;

    if (D_004872F0.mode == 2) {
        if (func_001089F0(D_004872F0.handle, 1, &result) >= 0) {
            if (result != 0)
                return 1;
        }
    }

    return 0;
}
