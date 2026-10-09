typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct ArchiveContext
{
    void *buffer;
    u32 length;
};

extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern void *func_00120440(void *destination, const void *source, u32 size);
extern s32 func_00410540(s32 value, void *destination);

s32 func_00410688(struct ArchiveContext *context, const void *source)
{
    func_0011D8F8(context->buffer, 0, context->length);
    func_00120440(context->buffer, source, 7);
    return func_00410540(context->length - 16, (u8 *)context->buffer + 8);
}
