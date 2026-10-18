typedef unsigned long long register_word;
extern void func_00105858(void *, register_word *);

void func_00105E48(void *context, ...)
{
    register_word *arguments = (register_word *)__builtin_next_arg(context) - 7;
    func_00105858(context, arguments);
}
