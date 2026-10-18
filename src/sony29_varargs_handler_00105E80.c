typedef void (*output_handler)(int);
typedef unsigned long long register_word;

extern output_handler D_00438264;
extern void func_00105578(int);
extern void func_00105858(void *, register_word *);

void func_00105E80(void *context, ...)
{
    output_handler previous = D_00438264;
    D_00438264 = func_00105578;
    /* Rewind past the seven saved 64-bit EABI register slots to the save-area start. */
    func_00105858(context, (register_word *)__builtin_next_arg(context) - 7);
    D_00438264 = previous;
}
