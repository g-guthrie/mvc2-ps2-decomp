#include "sony_deci2_call.h"


int func_00104E88(int value)
{
    return func_00104210(2, &value);
}

int func_00104EB0(int first, signed char second)
{
    struct { int first; int second; } parameters;
    parameters.first = first;
    parameters.second = second;
    return func_00104210(3, &parameters);
}

void func_00104EE0(int value)
{
    func_00104210(4, &value);
}
