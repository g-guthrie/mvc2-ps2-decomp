/* Copy the SDK heap error into the caller's error field after a failed growth request. */
extern int D_00634300;
extern void *func_001044E0(int);
void *func_0011F858(int *error, int increment)
{
    void *result;
    D_00634300 = 0;
    result = func_001044E0(increment);
    if (result == (void *)-1 && D_00634300 != 0)
        *error = D_00634300;
    return result;
}
