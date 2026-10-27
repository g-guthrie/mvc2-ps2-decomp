typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_00496708[7];
extern u8 D_00496728[28];
typedef void (*RuntimeSlotCallback)(void *);
struct RuntimeSlotPair { RuntimeSlotCallback callback; void *context; };
extern struct RuntimeSlotPair D_004C2B10;
extern struct RuntimeSlotPair D_004C2B18;
extern void *func_0011D8F8(void *destination, s32 value, u32 size);

void func_00411B28(void)
{
    u32 *entry;
    s32 count;

    func_0011D8F8(D_00496728, 0, 28);
    func_0011D8F8(&D_004C2B10, 0, sizeof D_004C2B10);
    func_0011D8F8(&D_004C2B18, 0, sizeof D_004C2B18);

    entry = D_00496708;
    count = 3;
    do
    {
        count--;
        *entry = 0;
        entry++;
    } while (count >= 0);
}
