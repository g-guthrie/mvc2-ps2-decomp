extern void func_00104210(int, void *);

void func_00104E88(int value)
{
    func_00104210(2, &value);
}

void func_00104EB0(int first, signed char second)
{
    struct { int first; int second; } parameters;
    parameters.first = first;
    parameters.second = second;
    func_00104210(3, &parameters);
}

void func_00104EE0(int value)
{
    func_00104210(4, &value);
}
