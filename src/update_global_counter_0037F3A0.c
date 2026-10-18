typedef unsigned char u8;
extern u8 *D_004C299C;
void func_0037F3A0(void)
{
    if (D_004C299C[2] < 10) {
        unsigned int value = D_004C299C[3] - 1;
        D_004C299C[3] = value;
        if ((u8)value <= 0) {
            D_004C299C[3] = 1;
            D_004C299C[2]++;
        }
    }
}
