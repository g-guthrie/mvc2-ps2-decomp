/* Native seek result is preserved at register width; the FILE cache stores its low signed word. */
extern int D_00634300;
extern long long func_001044D8(int, long long, int);
long long func_0011C9B8(void *context, int descriptor, long long offset, int origin)
{
    int *error = context;
    long long result;
    D_00634300 = 0;
    result = func_001044D8(descriptor, offset, origin);
    if (result == -1 && D_00634300 != 0)
        *error = D_00634300;
    return result;
}

