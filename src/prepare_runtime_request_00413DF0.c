typedef unsigned char u8;
typedef unsigned int u32;
struct RuntimeRequestOwner
{
    u8 unk00[12];
    u32 value;
};
extern void func_003DE640(void *destination, u32 index);
extern void func_00412260(u32 objectValue, u32 argument1, void *requestData,
                          u32 argument3, u32 argument4, u32 argument5);
void func_00413DF0(struct RuntimeRequestOwner *owner, u32 argument1,
                   u32 argument2, u32 argument3)
{
    u8 requestData[64];
    func_003DE640(requestData, 0);
    func_00412260(owner->value, argument1, requestData,
                  argument3, argument2, 0);
}
