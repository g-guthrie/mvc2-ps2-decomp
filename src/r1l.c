typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;typedef signed int s32;
extern s32 func_00175700(u8 *p);
static void func_002B5100(u8 *p) {
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (!(*(float *)(p + 0x60) * *(float *)(p + 0x6C) <= 0.0f)) *(float *)(p + 0x6C) = -1.607142806053161621f;
}
void func_002B5150(u8 *p) { func_002B5100(p); *(float *)(p + 0x34) += *(float *)(p + 0x5C); *(float *)(p + 0x5C) += *(float *)(p + 0x68); if (*(float *)(p + 0x5C) * *(float *)(p + 0x68) > 0.0f) p[6]++; func_00175700(p); }
