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
extern int func_0011C838(void *, int (*)(SdkFile *));
void func_0011B768(void *context) { func_0011C838(context, func_0011B480); }
