extern int D_00634300;
extern int func_001043A8(int, const void *, int);
long long func_00122500(int *error, int descriptor, const void *buffer, int count)
{
    long long result;
    D_00634300 = 0;
    result = func_001043A8(descriptor, buffer, count);
    if (result == -1 && D_00634300 != 0)
        *error = D_00634300;
    return result;
}
