#include "sony_deci2_call.h"


int func_00104F78(int first, signed char second)
{
    struct { int first; int second; } parameters;
    parameters.first = first;
    parameters.second = second;
    return func_00104210(-7, &parameters);
}

int func_00104FA8(int value)
{
    return func_00104210(-8, &value);
}

int func_00104FD0(int value)
{
    return func_00104210(-9, &value);
}

int func_00104FF8(char *value)
{
    return func_00104210(16, &value);
}
