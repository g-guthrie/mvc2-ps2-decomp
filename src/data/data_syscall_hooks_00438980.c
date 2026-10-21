typedef unsigned int u32;
extern u32 *func_0010CB10(u32 *begin, u32 *end, u32 value);
extern int func_0010CAD8(u32 *destination, const u32 *source, u32 bytes);
struct SyscallPatch { int number; void *handler; };
struct SyscallPatch data_syscall_hooks_00438980[2] = {
    { 0x83, (void *)func_0010CB10 },
    { 0x5A, (void *)func_0010CAD8 },
};
