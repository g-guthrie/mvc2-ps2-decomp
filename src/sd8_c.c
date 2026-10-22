#include "sony29_kernel_semaphore_calls.h"
#include "sony29_fileio_descriptor_types.h"
typedef unsigned int u32;
typedef unsigned char u8;

typedef SonyEeSemaParams SemaParams;
typedef SonyFileDescriptor Descriptor;
typedef struct {
    int semaphore;
    int *completion;
    int completion_size, handle, value, size, index;
} IoRequest;

extern IoRequest D_004C5500;
extern u8 D_004C6C00[];
extern int D_004C6140;
extern int D_004382FC;
extern int D_0043830C;
extern int D_00438278[32];
extern Descriptor *func_00107670(u32 descriptor);
extern int func_00107AB8(int operation);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *params);
extern int func_00103DF0(int semaphore);
extern int func_00103E00(int semaphore);
extern int func_00103E20(int semaphore);
extern int func_00107DC8(void);
extern int func_00106E68(void *client, int number, int mode,
                         void *send_buffer, int send_size,
                         void *receive_buffer, int receive_size,
                         void (*end_function)(void *), void *end_parameter);

typedef struct {
    int semaphore;
    int *completion;
    int completion_size, flags, mode;
    char path[1024];
    int index;
} OpenRequest;
extern int D_00438308;
extern int func_00107BC0(void);
extern Descriptor *func_001075E8(void);

int func_00107E90(const char *path, int flags, ...)
{
    OpenRequest *request = (OpenRequest *)&D_004C5500;
    SemaParams sema;
    Descriptor *entry;
    int length, semaphore, accepted, result, index;
    int mode;

    func_00107AB8(0);
    if (!D_004382FC) func_00107BC0();
    if (func_00107DC8()) {
        func_00107AE8();
        return 0xFFFEFFFC;
    }
    entry = func_001075E8();
    if (!entry) {
        func_00107AE8();
        return -19;
    }
    mode = *(int *)((char *)__builtin_next_arg(flags) - 48);
    for (length = 0; length < 1024 && (request->path[length] = path[length]); length++);
    if (length == 1024) request->path[1023] = 0;
    index = (int)(entry - D_004C6A00);
    request->flags = flags & 0x6FFFFFFF;
    request->mode = mode;
    sema.max_count = 1;
    request->index = index;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->completion = &result;
    request->semaphore = semaphore;
    request->completion_size = 4;
    if (func_00106E68(D_004C6C00, 0, 0, &D_004C5500, 1048, &D_004C6140, 4, 0, 0) < 0) {
        func_00103DF0(semaphore);
        func_00107AE8();
        return -11;
    }
    accepted = *(int *)((u32)&D_004C6140 | 0x20000000u);
    func_00107AE8();
    if (!accepted) {
        func_00103DF0(semaphore);
        return -11;
    }
    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    if (result < 0) {
        func_00103E20(D_00438308);
        entry->active = 0;
        func_00103E00(D_00438308);
        return result;
    }
    accepted = index;
    func_00103E20(D_00438308);
    entry->handle = result;
    entry->active |= flags;
    func_00103E00(D_00438308);
    return accepted;
}
