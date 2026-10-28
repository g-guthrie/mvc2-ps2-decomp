/* EE GCC 2.96: -O2 -G0 -fno-optimize-sibling-calls.
 *
 * CRI cvFs entry points that split a path into device and file names, look the
 * device up, and call one slot of its interface table, reporting errors
 * through func_00405DC8 ("cvFsXxx #n:..." messages).
 *
 * func_00405DC8 is defined first on purpose. GCC 2.96 (built without
 * -fexceptions) marks every function it has finished compiling as unable to
 * throw, and calls to such a function carry a REG_EH_REGION 0 note. Reorg's
 * liveness scan (resource.c: find_dead_or_set_registers) stops at any call
 * that might throw, so with an extern error reporter the argument register in
 * the "#1" check's delay slot looks live on the error path and the branch is
 * annulled (bnezl). Retail's plain bnez needs the reporter defined earlier in
 * the same unit, as it was in the original cvfs source.
 *
 * The device call keeps its result in a local and the "#4" error is an else
 * arm. That shape gives eleven basic blocks before the first scheduling pass,
 * one more than GCC 2.96 allows in an interblock region, so the arguments
 * are not hoisted speculatively across the error checks (the early-return
 * form has ten blocks and needs -fno-sched-spec, which func_00406CE0 cannot
 * use).
 */
typedef signed int s32;

typedef struct CvFsDevice {
    void *slot_00[2];
    s32 (*get_file_size)(char *);               /* 0x08 */
    void *slot_0c[12];
    s32 (*change_dir)(char *);                  /* 0x3C */
    void *slot_40[4];
    s32 (*make_dir)(char *);                    /* 0x50 */
    s32 (*remove_dir)(char *);                  /* 0x54 */
    s32 (*delete_file)(char *);                 /* 0x58 */
    s32 (*get_file_size_ex)(char *, s32);       /* 0x5C */
} CvFsDevice;

extern void *D_004872E8;
extern void func_00405D98(void *, const char *, s32);
extern void func_00406688(char *device_name, char *file_name, char *path);
extern CvFsDevice *func_00406440(char *device_name, char *file_name, char *path);

void func_00405DC8(const char *message)
{
    func_00405D98(&D_004872E8, message, 0);
}

extern char D_004BCBF0[], D_004BCC40[], D_004BCC68[];
s32 func_00406B50(char *path)
{
    char device_name[0x130];
    char file_name[0x130];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BCBF0);
        return 0;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BCBF0);
        return 0;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BCC40);
    if (device->get_file_size != 0) {
        result = device->get_file_size(file_name);
    } else {
        func_00405DC8(D_004BCC68);
        return 0;
    }
    return result;
}

extern char D_004BCC88[], D_004BCCE0[], D_004BCD08[];
s32 func_00406C10(char *path, s32 arg)
{
    char device_name[0x130];
    char file_name[0x130];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BCC88);
        return 0;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BCC88);
        return 0;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BCCE0);
    if (device->get_file_size_ex != 0) {
        result = device->get_file_size_ex(file_name, arg);
    } else {
        func_00405DC8(D_004BCD08);
        return 0;
    }
    return result;
}

extern char D_004BCD28[], D_004BCD50[];
extern char D_0062FB4C[];
extern void func_004067B8(char *);
extern s32 func_0011FFA0(char *);
extern s32 func_00120288(char *, char *, s32);
extern void *memcpy(void *, const void *, unsigned int);
s32 func_00406CE0(char *name)
{
    char buf[0x130];
    s32 len;
    s32 i;
    s32 r = 0;
    unsigned char *h;

    if (name == 0 || name[0] == 0) {
        func_004067B8(buf);
        if (buf[0] == 0) {
            func_00405DC8(D_004BCD28);
            return 0;
        }
    } else {
        memcpy(buf, name, func_0011FFA0(name) + 1);
    }
    len = func_0011FFA0(buf);
    if (len <= 0) {
        func_00405DC8(D_004BCD28);
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (func_00120288(buf, D_0062FB4C + i * 16, len) == 0) {
            h = *(unsigned char **)(D_0062FB4C + i * 16 - 4);
            if (h != 0) {
                h = *(unsigned char **)(h + 0xC);
                if (h != 0) {
                    r = ((s32 (*)(void))h)();
                }
            } else {
                func_00405DC8(D_004BCD50);
                return 0;
            }
        }
    }
    return r;
}

extern char D_004BCE30[], D_004BCE80[], D_004BCEA8[];
s32 func_00406F48(char *path)
{
    char device_name[0x130];
    char file_name[0x130];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BCE30);
        return -1;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BCE30);
        return -1;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BCE80);
    if (device->change_dir != 0) {
        result = device->change_dir(file_name);
    } else {
        func_00405DC8(D_004BCEA8);
        return -1;
    }
    return result;
}

extern char D_004BCFB0[], D_004BD000[], D_004BD020[];
s32 func_004072F0(char *path)
{
    char device_name[0x30];
    char file_name[0x30];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BCFB0);
        return -1;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BCFB0);
        return -1;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BD000);
    if (device->make_dir != 0) {
        result = device->make_dir(file_name);
    } else {
        func_00405DC8(D_004BD020);
        return -1;
    }
    return result;
}

extern char D_004BD040[], D_004BD090[], D_004BD0B8[];
s32 func_004073B0(char *path)
{
    char device_name[0x130];
    char file_name[0x130];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BD040);
        return -1;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BD040);
        return -1;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BD090);
    if (device->remove_dir != 0) {
        result = device->remove_dir(file_name);
    } else {
        func_00405DC8(D_004BD0B8);
        return -1;
    }
    return result;
}

extern char D_004BD0D8[], D_004BD128[], D_004BD150[];
s32 func_00407470(char *path)
{
    char device_name[0x130];
    char file_name[0x130];
    CvFsDevice *device;
    s32 result;

    if (path == 0) {
        func_00405DC8(D_004BD0D8);
        return -1;
    }
    func_00406688(device_name, file_name, path);
    if (file_name[0] == 0) {
        func_00405DC8(D_004BD0D8);
        return -1;
    }
    device = func_00406440(device_name, file_name, path);
    if (device == 0)
        func_00405DC8(D_004BD128);
    if (device->delete_file != 0) {
        result = device->delete_file(file_name);
    } else {
        func_00405DC8(D_004BD150);
        return -1;
    }
    return result;
}
