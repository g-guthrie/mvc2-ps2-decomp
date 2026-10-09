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
typedef struct Glue { struct Glue *next; int count; SdkFile *files; } Glue;
typedef struct Reent {
 u8 unknown0[56]; int initialized; void (*cleanup)(void *);
 u8 unknown64[408]; Glue glue; SdkFile standard[3];
} Reent;
extern void func_0011B768(void *);
extern void func_0011B598(SdkFile *, int, int, void *);
void func_0011B7A8(void *context)
{
 Reent *reent = context;
 reent->cleanup = func_0011B768;
 reent->initialized = 1;
 func_0011B598(&reent->standard[0], 4, 0, context);
 func_0011B598(&reent->standard[1], 9, 1, context);
 func_0011B598(&reent->standard[2], 10, 2, context);
 reent->glue.next = 0;
 reent->glue.count = 3;
 reent->glue.files = &reent->standard[0];
}
