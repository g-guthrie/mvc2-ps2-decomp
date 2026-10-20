/* NONMATCHING: excluded from production and all progress credit.
 * EE GCC 2.96 O2/G0 emits the correct 244-byte span, but one conditional
 * branch is branch-likely while retail uses the ordinary branch.
 * See RUNTIME_HANDLE_UPDATE_004044E0.md. */
typedef signed short s16;
typedef signed int s32;
typedef struct {
    s32 active, slot, reserved08, state, result, mode;
    s32 arg18, arg1C, arg20, arg24;
    s32 work28, work2C;
    s16 rate30, rate32, output34, timing36, timing38, reserved3A;
} RuntimeHandle;
extern s32 func_003FA728(s32, s32, s32, s32 *, s32, s32, s16 *, s32, s32);
extern s32 func_003FB040(s32, s32, s32, s32 *, s32, s32 *, s32, s32, s16 *, s32, s32);
extern s32 func_004044D0(void);
void func_004044E0(RuntimeHandle *handle)
{
    if (handle->state == 1)
        handle->state = 2;
    if (handle->state == 2) {
        if (handle->mode == 1) {
            handle->result = func_003FA728(handle->arg18, handle->arg1C,
                handle->arg20, &handle->work28, handle->rate30,
                handle->rate32, &handle->output34, handle->timing36,
                handle->timing38);
        } else {
            handle->result = func_003FB040(handle->arg18, handle->arg1C,
                handle->arg20, &handle->work28, handle->arg24,
                &handle->work2C, handle->rate30, handle->rate32,
                &handle->output34, handle->timing36, handle->timing38);
            if (handle->result % 2 == 1)
                func_004044D0();
        }
        handle->state = 3;
    }
}
