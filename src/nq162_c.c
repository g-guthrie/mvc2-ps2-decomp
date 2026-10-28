/* Sony EE GCC 2.9: ./trysony29.sh src/nq162_c.c 0 O2 */
#include "sony29_fileio_descriptor_types.h"
typedef struct { void (*function)(void *); void *argument; } CompletionHook;
extern CompletionHook D_004C6C80;
extern unsigned char D_004C6C00[];
extern int D_004C6C40[];
extern int D_004C6C28;
extern int D_004C6140[];
extern int D_004C6180[];
extern int *D_004C54C0[2];
extern int D_004382FC, D_00438300, D_00438308;
extern void func_00106628(int);
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00106240(unsigned int, void (*)(void *, void *), void *);
extern void func_001076E0(void *, void *);
extern void func_00107B90(void *, void *);
extern int func_00106C98(void *, unsigned int, int);
extern int func_00103E20(int), func_00103E00(int);
extern int func_00106E68(void *client, int number, int mode,
                         void *send_buffer, int send_size,
                         void *receive_buffer, int receive_size,
                         void (*end_function)(void *), void *end_parameter);

int func_00107BC0(void)
{
    CompletionHook *hook = &D_004C6C80;
    int interrupts;
    int i;
    int version;
    SonyFileDescriptor *entry;

    func_00106628(0);
    hook->function = 0;
    hook->argument = 0;
    interrupts = func_0010CA20();
    func_00106240(0x80000011, func_001076E0, D_004C6C40);
    func_00106240(0x80000013, func_00107B90, hook);
    if (interrupts)
        func_0010CA68();
    while (1) {
        if (func_00106C98(D_004C6C00, 0x80000001, 0) < 0)
            return -1;
        if (*(int *)(D_004C6C00 + 0x24) != 0)
            break;
        i = 0x100000;
        while (i-- != 0)
            ;
    }
    func_00107588();
    func_00103E20(D_00438308);
    for (entry = D_004C6A00; entry < D_004C6A00 + 32; entry++)
        entry->active = 0;
    func_00103E00(D_00438308);
    D_004C54C0[0] = D_004C6180;
    D_004C54C0[1] = D_004C6180 + 0x110;
    if (func_00106E68(D_004C6C00, 0xFF, 0, D_004C54C0, 8, D_004C6140, 8, 0, 0) < 0)
        return 0xFFFEFFFF;
    __builtin_memcpy(&D_004C6C28, (void *)((unsigned int)D_004C6140 | 0x20000000), 4);
    __builtin_memcpy(&version, (void *)((unsigned int)(D_004C6140 + 1) | 0x20000000), 4);
    D_00438300 = version == 2;
    D_004382FC = 1;
    return 0;
}
