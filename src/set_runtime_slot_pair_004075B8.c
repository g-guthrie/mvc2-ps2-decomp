typedef signed int s32;

extern s32 D_004872E4;
extern s32 D_004872E8;

void func_004075B8(s32 first, s32 second)
{
    if (first == 0) {
        D_004872E4 = 0;
        D_004872E8 = 0;
    } else {
        D_004872E4 = first;
        D_004872E8 = second;
    }
}
