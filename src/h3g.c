typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004CAE80[][20];
void func_0014D670(s32 idx)
{
    s32 i = 0;
    do {
        if (D_004CAE80[idx][i] != 0) {
            D_004CAE80[idx][i][0x13C] = 0;
        }
        i++;
    } while (i < 0x12);
    if (i < 0x14) {
        do {
            if (D_004CAE80[idx][i] != 0) {
                D_004CAE80[idx][i][0x13C] = 1;
            }
            i++;
        } while (i < 0x14);
    }
}
