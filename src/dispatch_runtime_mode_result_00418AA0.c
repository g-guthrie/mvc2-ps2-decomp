typedef signed int s32;

extern void *D_004C2B50;
extern s32 func_00401920(void *context);
extern s32 func_0010F148(s32 mode);

s32 func_00418AA0(void)
{
    s32 mode;

    if (D_004C2B50 == 0)
        return 1;

    mode = func_00401920(D_004C2B50);
    switch (mode)
    {
    case 0: goto call;
    case 1: goto no_action;
    case 2: goto no_action;
    case 3: goto call;
    case 4: goto no_action;
    case 5: goto call;
    default: goto no_action;
    }

call:
    return !func_0010F148(1);
no_action:
    return 0;
}
