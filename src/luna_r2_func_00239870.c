typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
/* Exact IEEE-754 words observed for these float motion fields. */
extern int func_00175700(u8 *);
extern void func_00126400(void);
void func_00239870(u8 *p) {
    if (p[7] == 0) {
        func_00175700(p);
        if ((s8)p[0x151] == 0)
            goto done;
        p[7]++;
        p[0x151] = 0;
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0xC0555555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x413C9249;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        p[0x1EA] = 0x11;
        p[0x1E8] = 1;
        if (p[0x1E6] != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        goto done;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (p[0x15B] == 0)
        goto done;
    {
        u32 childMode = 2;
        u32 childState = 0x21;
        u8 count = p[6];
        u8 *child;
        count++;
        p[6] = count;
        p[7] = 0;
        child = *(u8 **)(p + 0x1DC);
        *(u8 **)(child + 0x1C8) = p;
        child[0x20A] = 1;
        child[0x1E6] = p[0x1E6];
        child[0x20D] = childMode;
        child[0x1B5] = childState;
        *(s16 *)(child + 0x140) ^= 1;
        child[0x1E6] ^= 1;
        func_00126400();
    }
done:
    return;
}
