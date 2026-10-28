/* Sony EE GCC 2.9-991111, -O2 -G0 (./trysony29.sh src/s7g_a.c 0 O2).
 * Sony libkernel: SIF command initialisation (func_00105F58) and the
 * file-service RPC requests read/write/probe/lseek (func_00108298,
 * func_001084D0, func_00108730, func_0010A430).  The no-wait slot table
 * D_00438278 is shared with the RPC completion callback and is read through
 * a volatile lvalue; the request mode is re-read from the descriptor for the
 * final no-wait test.  libcdvd: func_0010F6A8 (N-command with one argument). */
#include "sony29_kernel_semaphore_calls.h"
#include "sony29_fileio_descriptor_types.h"
typedef unsigned int u32;
typedef unsigned char u8;

/* SIF command layer initialisation. */
typedef signed int s32;

typedef struct { void (*handler)(void *, void *); void *harg; } CmdHandler;
typedef struct {
    void *pktbuf;
    void *unused;
    void *iopbuf;
    CmdHandler *sys_cmd_handlers;
    u32 nr_sys_handlers;
    CmdHandler *usr_cmd_handlers;
    u32 nr_usr_handlers;
    int *sregs;
} SifCmdData;
typedef struct { int size; int dest; int fid; int opt; void *addr; } SysCmdPkt;

extern s32 D_00438268;
extern u8 D_004C3A00[];
extern u8 D_004C3A80[];
extern SysCmdPkt D_004C3AC0;
extern int D_004C3AD4;
extern SifCmdData D_004C3AD8;
extern CmdHandler D_004C3B00[32];
extern int D_004C3C00[32];

extern void func_00105EE0(void *, void *);
extern void func_00105F00(void *, void *);
extern int func_00106450(int);
extern void func_0010CA20(void);
extern void func_0010CA68();
extern void func_00104060(s32);
extern void func_001041C0(void);
extern s32 func_00103AF0(s32, int (*)(int), s32);
extern void func_001049F8(s32);
extern s32 func_001041F0(u32);
extern int func_001041E0(u32, s32);
extern void func_001063D0(u32, void *, s32, s32, s32, s32);

void func_00105F58(void)
{
    int i;

    func_0010CA20();
    if (D_00438268) {
        func_0010CA68();
        return;
    }
    D_00438268 = 1;
    D_004C3AD8.pktbuf = (void *)((u32)D_004C3A00 | 0x20000000);
    D_004C3AD8.unused = (void *)((u32)D_004C3A80 | 0x20000000);
    D_004C3AD8.nr_sys_handlers = 32;
    D_004C3AD8.iopbuf = 0;
    D_004C3AD8.sys_cmd_handlers = D_004C3B00;
    D_004C3AD8.usr_cmd_handlers = 0;
    D_004C3AD8.nr_usr_handlers = 0;
    D_004C3AD8.sregs = D_004C3C00;
    for (i = 0; i < 32; i++) {
        D_004C3B00[i].handler = 0;
        D_004C3B00[i].harg = 0;
    }
    for (i = 0; i < 32; i++)
        D_004C3C00[i] = 0;
    D_004C3B00[0].handler = func_00105F00;
    D_004C3B00[0].harg = &D_004C3AD8;
    D_004C3B00[1].handler = func_00105EE0;
    D_004C3B00[1].harg = &D_004C3AD8;
    func_0010CA68();
    func_00104060(0);
    if (*(volatile u32 *)0x1000E010 & 0x20)
        *(volatile u32 *)0x1000E010 = 0x20;
    if (!(*(volatile u32 *)0x1000C000 & 0x100))
        func_001041C0();
    D_004C3AD4 = func_00103AF0(5, func_00106450, 0);
    func_001049F8(5);
    D_004C3AD8.iopbuf = (void *)func_001041F0(0x80000000);
    if (D_004C3AD8.iopbuf) {
        D_004C3AC0.addr = D_004C3A00;
        func_001063D0(0x80000000, &D_004C3AC0, 0x14, 0, 0, 0);
        return;
    }
    while (!(func_001041F0(4) & 0x20000))
        ;
    D_004C3AD8.iopbuf = (void *)func_001041F0(2);
    func_001041E0(0x80000000, (s32)D_004C3AD8.iopbuf);
    func_001041E0(0x80000001, (s32)&D_004C3AD8);
    D_004C3AC0.addr = D_004C3A00;
    D_004C3AC0.opt = 0;
    func_001063D0(0x80000002, &D_004C3AC0, 0x14, 0, 0, 0);
}

typedef SonyEeSemaParams SemaParams;
typedef SonyFileDescriptor Descriptor;
typedef struct {
    int semaphore;
    int *completion;
    int completion_size, handle;
    void *buffer;
    int size, index;
} ReadRequest;

typedef struct {
    int semaphore;
    long long *completion;
    int completion_size, handle;
    long long offset;
    int whence, index;
} SeekRequest;

typedef struct {
    int semaphore;
    int *completion;
    int completion_size, handle;
    void *buffer;
    int size, pad18, index;
} WriteRequest;

typedef struct {
    int semaphore;
    int *completion;
    int completion_size, handle;
    u32 buffer;
    int size, head_size;
    u8 head[16];
    int index;
} ProbeRequest;

typedef union { ReadRequest r; WriteRequest w; ProbeRequest p; SeekRequest s; } FileRequest;
extern FileRequest D_004C5500;
extern u8 D_004C6C00[];
extern int D_004C6140;
extern int D_004382FC;
extern int D_0043830C;
extern int D_00438278[32];
extern int func_00107AB8(int operation);
extern void func_00106578(void *, int);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *params);
extern int func_00103DF0(int semaphore);
extern int func_00103E00(int semaphore);
extern int func_00103E20(int semaphore);
extern int func_00106E68(void *client, int number, int mode,
                         void *send_buffer, int send_size,
                         void *receive_buffer, int receive_size,
                         void (*end_function)(void *), void *end_parameter);

int func_00108298(int descriptor, void *buffer, int size)
{
    ReadRequest *request = &D_004C5500.r;
    Descriptor *entry = func_00107670(descriptor);
    SemaParams sema;
    int flags, semaphore, accepted, result, i, mode;

    func_00107AB8(4);
    if (!D_004382FC) {
        func_00107AE8();
        return -1;
    }
    if (!entry || !(flags = entry->active)) {
        func_00107AE8();
        return -9;
    }
    mode = entry->active;
    request->buffer = buffer;
    request->handle = entry->handle;
    request->size = size;
    request->index = (int)(entry - D_004C6A00);
    sema.max_count = 1;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->completion = &result;
    request->completion_size = 4;
    D_004C5500.r.semaphore = semaphore;
    if (flags & 0x8000) {
        func_00103E20(D_0043830C);
        for (i = 0; i < 32; i++) {
            if (((volatile int *)D_00438278)[i] == -1) {
                D_00438278[i] = request->semaphore;
                request->semaphore = -request->semaphore;
                break;
            }
        }
        func_00103E00(D_0043830C);
    }
    if (func_00106E68(D_004C6C00, 4, 0, &D_004C5500, 28, &D_004C6140, 4, 0, 0) < 0) {
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
    if (mode & 0x8000) {
        func_00103DF0(semaphore);
        return 0;
    }
    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    return result;
}

int func_001084D0(int descriptor, void *buffer, int size)
{
    WriteRequest *request = &D_004C5500.w;
    Descriptor *entry = func_00107670(descriptor);
    SemaParams sema;
    int flags, semaphore, accepted, result, i, mode;

    func_00107AB8(2);
    if (!D_004382FC) {
        func_00107AE8();
        return -1;
    }
    if (!entry || !(flags = entry->active)) {
        func_00107AE8();
        return -9;
    }
    mode = entry->active;
    request->handle = entry->handle;
    request->index = (int)(entry - D_004C6A00);
    request->buffer = buffer;
    request->size = size;
    sema.max_count = 1;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->completion = &result;
    request->completion_size = 4;
    D_004C5500.w.semaphore = semaphore;
    if (flags & 0x8000) {
        func_00103E20(D_0043830C);
        for (i = 0; i < 32; i++) {
            if (((volatile int *)D_00438278)[i] == -1) {
                D_00438278[i] = request->semaphore;
                request->semaphore = -request->semaphore;
                break;
            }
        }
        func_00103E00(D_0043830C);
    }
    if (!(flags & 0x20000000))
        func_00106578(buffer, size);
    func_00106578(request, 32);
    if (func_00106E68(D_004C6C00, 2, 0, &D_004C5500, 32, &D_004C6140, 4, 0, 0) < 0) {
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
    if (mode & 0x8000) {
        func_00103DF0(semaphore);
        return 0;
    }
    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    return result;
}

int func_00108730(int descriptor, u32 buffer, int size)
{
    ProbeRequest *request = &D_004C5500.p;
    Descriptor *entry = func_00107670(descriptor);
    SemaParams sema;
    int flags, semaphore, accepted, result, i, mode, n;

    func_00107AB8(3);
    if (!D_004382FC) {
        func_00107AE8();
        return -1;
    }
    if (!entry || !(flags = entry->active)) {
        func_00107AE8();
        return -9;
    }
    mode = entry->active;
    request->handle = entry->handle;
    request->index = (int)(entry - D_004C6A00);
    request->size = size;
    request->buffer = buffer;
    sema.max_count = 1;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->completion = &result;
    request->completion_size = 4;
    D_004C5500.p.semaphore = semaphore;
    if (flags & 0x8000) {
        func_00103E20(D_0043830C);
        for (i = 0; i < 32; i++) {
            if (((volatile int *)D_00438278)[i] == -1) {
                D_00438278[i] = request->semaphore;
                request->semaphore = -request->semaphore;
                break;
            }
        }
        func_00103E00(D_0043830C);
    }
    if ((buffer & 0xF) == 0)
        n = 0;
    else
        n = ((buffer >> 4) << 4) + 16 - buffer;
    if (size < n)
        n = size;
    if (!(flags & 0x20000000))
        func_00106578((void *)buffer, size);
    buffer |= 0x20000000;
    request->head_size = n;
    {
        int j;
        for (j = 0; j < n; j++)
            request->head[j] = ((u8 *)buffer)[j];
    }
    if (func_00106E68(D_004C6C00, 3, 0, &D_004C5500, 48, &D_004C6140, 4, 0, 0) < 0) {
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
    if (mode & 0x8000) {
        func_00103DF0(semaphore);
        return 0;
    }
    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    return result;
}

long long func_0010A430(int descriptor, long long offset, int whence)
{
    SeekRequest *request = &D_004C5500.s;
    Descriptor *entry = func_00107670(descriptor);
    SemaParams sema;
    int flags, semaphore, accepted, i, mode;
    long long result;

    func_00107AB8(22);
    if (!D_004382FC) {
        func_00107AE8();
        return -1;
    }
    if (!entry || !(flags = entry->active)) {
        func_00107AE8();
        return -9;
    }
    mode = entry->active;
    request->offset = offset;
    request->handle = entry->handle;
    request->whence = whence;
    request->index = (int)(entry - D_004C6A00);
    sema.max_count = 1;
    sema.init_count = 0;
    sema.option = 0;
    semaphore = func_00103DE0(&sema);
    request->completion = &result;
    request->completion_size = 8;
    D_004C5500.s.semaphore = semaphore;
    if (flags & 0x8000) {
        func_00103E20(D_0043830C);
        for (i = 0; i < 32; i++) {
            if (((volatile int *)D_00438278)[i] == -1) {
                D_00438278[i] = request->semaphore;
                request->semaphore = -request->semaphore;
                break;
            }
        }
        func_00103E00(D_0043830C);
    }
    if (func_00106E68(D_004C6C00, 22, 0, &D_004C5500, 32, &D_004C6140, 4, 0, 0) < 0) {
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
    if (mode & 0x8000) {
        func_00103DF0(semaphore);
        return 0;
    }
    func_00103E20(semaphore);
    func_00103DF0(semaphore);
    return result;
}

/* libcdvd: CD/DVD N-command with a one-word argument. */
extern char D_004C8890[];
extern int D_004C88D0;
extern char D_0043AB80[];
extern char D_004AB528[];
extern char D_004AB538[];
extern char D_004AB558[];
extern volatile int D_004399AC;
extern int D_00439990;
extern int D_004399C4;
typedef struct {
    char pad[0x24];
    int f24;
} S7080;
extern void func_0010E9A8(void);
extern int func_00103E30(int);
extern int func_0010F1E8(int);
extern void func_00106628(int);
extern int func_00106C98(void *, unsigned, int);
extern int func_00105E80(const char *, ...);

int func_0010F6A8(int command) {
    int i;
    char *p;
    int r;
    int result;

    if (D_00439990 > 0) func_00105E80(D_004AB528);
    func_0010E9A8();
    if (D_004399AC != func_00103E30(D_004399AC)) return 6;
    if (func_0010F1E8(1) != 0) {
        func_00103E00(D_004399AC);
        return command != 8 ? 6 : -1;
    }
    func_00106628(0);
    if (D_004399C4 < 0) {
        for (;;) {
            p = D_004C8890;
            r = func_00106C98(p, 0x8000059A, 0);
            if (r < 0) {
                if (D_00439990 > 0) func_00105E80(D_004AB538);
                i = 0x100000;
                do {
                    i--;
                    asm volatile ("nop");
                } while (i != -1);
            } else {
                if (((S7080 *)p)->f24 != 0) {
                    D_004399C4 = 0;
                    break;
                }
                i = 0x100000;
                do {
                    i--;
                    asm volatile ("nop");
                } while (i != -1);
            }
        }
    }

    D_004C88D0 = command;
    func_00106578(&D_004C88D0, 4);
    if (func_00106E68(D_004C8890, 0, 0, &D_004C88D0, 4, D_0043AB80, 4, 0, 0) < 0) {
        func_00103E00(D_004399AC);
        return command != 8 ? 6 : -1;
    }
    if (D_00439990 > 0) func_00105E80(D_004AB558);
    result = *(int *)((unsigned int)D_0043AB80 | 0x20000000u);
    func_00103E00(D_004399AC);
    return result;
}
