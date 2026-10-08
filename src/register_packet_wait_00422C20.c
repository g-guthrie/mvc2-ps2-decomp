typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00103CD0(void);
extern s32 func_00103B60(u16 time, void (*callback)(s32, u16, void *), void *common);
extern s32 func_00103D00(void);
extern void func_00422BF0(s32 alarmId, u16 time, void *common);

s32 func_00422C20(s32 mode)
{
    s32 threadId;
    s32 result;

    threadId = func_00103CD0();
    result = func_00103B60((u16)mode, func_00422BF0, (void *)(u32)threadId);
    if (result < 0)
        return -2;
    return func_00103D00();
}
