typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct RuntimeObjectInit
{
    u32 value;
    u8 unk04[8];
    s32 initialized;
    s32 context;
};
extern s32 func_00411C10(u32 value, s32 mode);
void func_00413D50(struct RuntimeObjectInit *object, s32 context)
{
    if (object->initialized == 0)
    {
        object->initialized = func_00411C10(object->value, context);
        object->context = context;
    }
}
