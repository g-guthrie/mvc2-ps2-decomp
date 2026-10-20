#include "sony29_kernel_semaphore_calls.h"
#include "sony29_fileio_descriptor_types.h"
typedef unsigned int u32;
typedef unsigned char u8;

typedef SonyEeSemaParams SemaParams;
typedef SonyFileDescriptor Descriptor;
typedef SonyFileDescriptorRequest DescriptorRequest;

extern u8 D_004C5500[];
extern u8 D_004C6C00[];
extern int D_004C6140;
extern int D_004382FC;
extern Descriptor *func_00107670(u32 descriptor);
extern int func_00107AB8(int operation);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *params);
extern int func_00103DF0(int semaphore);
extern int func_00103E20(int semaphore);
extern int func_00106E68(void *client, int number, int mode,
                         void *send_buffer, int send_size,
                         void *receive_buffer, int receive_size,
                         void (*end_function)(void *), void *end_parameter);

int func_00108118(int descriptor)
{
    Descriptor *entry = func_00107670((u32)descriptor);
    DescriptorRequest *request = (DescriptorRequest *)D_004C5500;
    SemaParams sema;
    int result;
    int semaphore;
    int accepted;
    int threshold;

    func_00107AB8(1);
    if (!D_004382FC) {
        func_00107AE8();
        return -1;
    }
    if (entry == 0 || !entry->active) {
        func_00107AE8();
        return -9;
    }

    request->handle = entry->handle;
    request->value = (int)(entry - D_004C6A00);
    sema.max_count = 1;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->semaphore = semaphore;
    request->completion = &result;
    request->completion_size = 4;

    if (func_00106E68(D_004C6C00, 1, 0, D_004C5500, 20,
                      &D_004C6140, 4, 0, 0) < 0) {
        func_00103DF0(semaphore);
        func_00107AE8();
        return -11;
    }

    entry->active = 0;
    accepted = *(int *)((u32)&D_004C6140 | 0x20000000u);
    func_00107AE8();
    if (!accepted) {
        func_00103DF0(semaphore);
        return -11;
    }

    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    threshold = -1;
    return threshold < result ? 0 : result;
}
