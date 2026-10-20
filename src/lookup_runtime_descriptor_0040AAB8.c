/* EE GCC 2.96: -O2 -G0. */
typedef signed int s32;

typedef struct RuntimeDirectoryEntry {
    s32 descriptor;
    s32 length;
} RuntimeDirectoryEntry;

typedef struct RuntimeDirectory {
    unsigned char *entries;
    s32 count;
    s32 span_count;
    s32 name_length;
} RuntimeDirectory;

extern RuntimeDirectory D_00489000;
extern s32 D_00489018;
extern char gDvdRomDeviceName_004BDCC0[];
extern char gDvciImageOpenedFormat_004BDCC8[];
extern s32 func_0011FD40(const char *table, const char *name);
extern void func_0011EB60(const char *message, ...);
extern void func_0040A9C8(RuntimeDirectoryEntry *out, const char *name,
                           unsigned char *bytes, s32 count);

s32 func_0040AAB8(const char *name, RuntimeDirectoryEntry *out)
{
    if (func_0011FD40(gDvdRomDeviceName_004BDCC0, name) == 0) {
        out->descriptor = -1;
        out->length = -1;
        if (D_00489018 != 2)
            func_0011EB60(gDvciImageOpenedFormat_004BDCC8, 0x2E);
        return 1;
    }

    out->descriptor = 0;
    out->length = 0;
    if (D_00489000.entries != 0)
        func_0040A9C8(out, name, D_00489000.entries, D_00489000.count);
    return 0;
}
