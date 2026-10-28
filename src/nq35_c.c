typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004AAED8[];
extern u32 *data_u32_004381E0[];
extern void func_00102548(void *, int);
extern int func_00102688(void *);

int func_001025A8(int mode)
{
    u8 buf[0x20];
    int i;
    int old;
    old = *(volatile u32 *)0x1000E000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_004AAED8[i] != 0) {
            volatile u32 *r = data_u32_004381E0[i];
            r[0x20] = 0;
            r[0] = 0;
            r[0xC] = 0;
            r[4] = 0;
            r[0x14] = 0;
            r[0x10] = 0;
        }
    }
    {
        u32 *e = (u32 *)0x1000E010;
        *(volatile u32 *)e = 0xFF1F;
        *e = *(volatile u32 *)e & 0xFF1F0000;
    }
    func_00102548(buf, 0x14);
    func_00102688(buf);
    if (mode == 1)
        *(volatile u32 *)0x1000E000 |= 1;
    return old;
}
