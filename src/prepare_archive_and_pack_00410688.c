typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct ArchiveContext
{
    char *buffer;
    u32 length;
};

extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern char *func_00120440(char *destination, const char *source, u32 size);
extern void func_00410540(s32 value, char *destination);

void func_00410688(struct ArchiveContext *context, const char *source)
{
    func_0011D8F8(context->buffer, 0, context->length);
    func_00120440(context->buffer, source, 7);
    func_00410540(context->length - 16, context->buffer + 8);
}
