typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

extern s32 func_003EDA60(s32 i);
extern s32 func_003EE690(s16 a, s16 b);
extern void func_003EE530(s16 *p, s16 v);
extern u8 D_0062C090[];
extern u8 D_0062C530[];
extern u8 D_00478DE0[];
extern u8 D_0062C500[];
extern u8 D_004C2AF8[] __attribute__((section(".sdata")));
extern u8 D_004C2AF0[] __attribute__((section(".sdata")));

void func_003ED920(void)
{
    s32 i;
    u8 *slot;
    s32 off34;
    s32 offc;
    s32 off8;
    u32 w;
    s32 a;
    s32 b;
    u8 *pair;

    off8 = 0;
    offc = 0;
    off34 = 0;
    i = 0;
    do {
        if (func_003EDA60(i) != 0) {
            slot = D_0062C530 + off34;
            slot[6] = (D_0062C090 + offc)[5];
            w = *(u32 *)(slot + 8);
            w = (w & 0xFFF0) | D_00478DE0[w & 0xF];
            *(u32 *)(slot + 8) = w;
            a = func_003EE690(*(s16 *)(slot + 0x1C), *(s16 *)(slot + 0x1E)) & 0xFF;
            b = func_003EE690(*(s16 *)(slot + 0x28), *(s16 *)(slot + 0x2A)) & 0xFF;
            *(u32 *)(slot + 8) = *(u32 *)(slot + 8) | (a << 16);
            *(u32 *)(slot + 8) = *(u32 *)(slot + 8) | (b << 20);
            pair = D_0062C500 + off8;
            func_003EE530((s16 *)(slot + 0x1C), *(s16 *)(pair + 2));
            func_003EE530((s16 *)(slot + 0x28), *(s16 *)(pair + 4));
        }
        D_004C2AF0[i] = D_004C2AF8[i];
        off34 += 0x34;
        offc += 0xC;
        off8 += 8;
        i++;
    } while (i < 5);
}
