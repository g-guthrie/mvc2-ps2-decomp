typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 D_004C2894;
extern volatile s32 D_004C2898;
extern volatile s32 D_004C289C;
extern u8 D_004F9170[0x24900];
extern u8 D_004F8470[0xD00];
extern u8 D_0051DA70[0x51400];

extern void *func_0011D8F8(void *destination, s32 value, u32 bytes);
extern void func_003F0860(s32 handle);
extern void func_0041B6C0(void **entry);
extern s32 func_003F0930(void);

void func_004154C0(void)
{
    s32 i;
    u8 *entry;

    entry = D_004F9170;
    i = 0;
    while (i < D_004C2898) {
        u32 handle = *(u32 *)entry;
        if (handle != 0xFFFFFFFFu && handle < 1024) {
            func_003F0860((s32)handle);
            func_0041B6C0((void **)(entry + 144));
        }
        entry += 180;
        i++;
    }

    D_004C289C = 0;
    func_0011D8F8(D_0051DA70, 0, sizeof(D_0051DA70));
    D_004C2898 = 0;
    func_0011D8F8(D_004F9170, -1, sizeof(D_004F9170));
    D_004C2894 = 0;
    func_0011D8F8(D_004F8470, 0, sizeof(D_004F8470));
    func_003F0930();
}
