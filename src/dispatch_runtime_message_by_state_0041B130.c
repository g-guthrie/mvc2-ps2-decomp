typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct RuntimeMessageState { u8 unk00[0x1C]; s32 selector; };
struct RuntimeMessageObject { u8 unk00[0xD0]; s32 active; };
extern struct RuntimeMessageState *D_004C2840;
extern u8 D_004C2528[2];
extern u8 D_004C252C[2];
extern void func_00175910(struct RuntimeMessageObject *object, s32 first,
                          s32 second, u32 message);
void func_0041B130(struct RuntimeMessageObject *object)
{
    u32 selector = D_004C2840->selector & 1;
    if (object->active != 0)
        func_00175910(object, 22, 29, D_004C252C[selector]);
    else
        func_00175910(object, 22, 29, D_004C2528[selector]);
}
