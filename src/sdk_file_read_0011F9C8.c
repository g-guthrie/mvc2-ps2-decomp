typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {
    u8 prefix[12];
    u16 flags;
    s16 descriptor;
    u8 state[64];
    int position;
    void *context;
} ReadFile;
extern long long func_0011F640(int *, int, void *, int);
int func_0011F9C8(ReadFile *file, void *buffer, int count)
{
    int result = func_0011F640(file->context, file->descriptor, buffer, count);
    if (result >= 0)
        file->position += result;
    else
        file->flags &= 0xEFFF;
    return result;
}
