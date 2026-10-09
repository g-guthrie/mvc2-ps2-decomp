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
} SdkFile;
extern int func_00119E80(void *, int);
int func_0011FB18(void *cookie)
{
 SdkFile *file = cookie;
 return func_00119E80(file->context, file->descriptor);
}
