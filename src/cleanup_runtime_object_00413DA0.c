typedef unsigned int u32;

struct RuntimeObject
{
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 handle;
    u32 unk10;
};

extern void func_004120A0(u32 handle);

void func_00413DA0(struct RuntimeObject *object)
{
    if (object->handle != 0)
    {
        func_004120A0(object->handle);
        object->handle = 0;
    }
}
