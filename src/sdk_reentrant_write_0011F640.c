extern int D_00634300;
extern int func_00104428(int, const void *, int);
long long func_0011F640(int *error, int descriptor, const void *buffer, int count)
{
    long long result;
    D_00634300 = 0;
    result = func_00104428(descriptor, buffer, count);
    if (result == -1 && D_00634300 != 0)
        *error = D_00634300;
    return result;
}
