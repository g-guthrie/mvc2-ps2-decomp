/* Preserve the native seek result while updating the signed 32-bit cached position. */
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
} SeekFile;
extern long long func_0011C9B8(void *, int, long long, int);

long long func_0011FAB0(SeekFile *file, long long offset, int origin)
{
    long long result = func_0011C9B8(file->context, file->descriptor, offset, origin);
    if (result == -1)
        file->flags &= 0xEFFF;
    else {
        file->position = (int)result;
        file->flags |= 0x1000;
    }
    return result;
}
