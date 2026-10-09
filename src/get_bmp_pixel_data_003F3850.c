typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char D_004BAD30[];
extern void func_003F5540(const char *format, ...);

u8 *func_003F3850(const u16 *header)
{
    if (header[0] != 0x4d42) {
        func_003F5540(D_004BAD30);
        return (u8 *)0;
    }
    return (u8 *)header + ((u32)header[5] | ((u32)header[6] << 16));
}
