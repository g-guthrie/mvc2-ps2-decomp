typedef signed char s8;

extern void func_004007F0(void *entry);

void func_00400AD0(const s8 *entry)
{
    if (entry[1] == 2)
        func_004007F0((void *)entry);
}
