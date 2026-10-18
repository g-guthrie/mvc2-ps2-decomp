extern void func_00104210(int, void *);

void func_00104F78(int first, signed char second)
{
    struct { int first; int second; } parameters;
    parameters.first = first;
    parameters.second = second;
    func_00104210(-7, &parameters);
}

void func_00104FA8(int value)
{
    func_00104210(-8, &value);
}

void func_00104FD0(int value)
{
    func_00104210(-9, &value);
}

void func_00104FF8(int value)
{
    func_00104210(16, &value);
}
