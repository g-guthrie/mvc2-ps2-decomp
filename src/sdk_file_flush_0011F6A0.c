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
extern int func_0011B480(SdkFile *);
int func_0011F6A0(SdkFile *file)
{
 if ((file->flags &9)==9) return func_0011B480(file);
 return 0;
}
