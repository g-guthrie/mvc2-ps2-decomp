typedef unsigned char u8;

extern u8 D_00583B92[];

void func_00138650(u8 *p) {
    if (D_00583B92[p[0x20]] == 0x77)
        p[5] = 6;
    else
        p[5]++;
}
