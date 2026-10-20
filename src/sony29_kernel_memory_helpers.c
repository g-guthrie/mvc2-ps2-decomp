/* Native kernel byte copy, handler lookup and kernel-word search. */
typedef unsigned char u8;
typedef unsigned int u32;
int func_0010CE78(void *destination, const void *source, int size)
{
    u8 *out = destination;
    const u8 *in = source;
    u32 i;
    for (i = 0; i < (u32)size; i++) *out++ = *in++;
    return 0;
}

extern void *D_00438978;
extern int func_0010CAC8(void *, const void *, int);
void *func_0010CB60(int index)
{
    void *entry;
    u32 address = (u32)D_00438978 + (u32)index * 4u;
    func_0010CAC8(&entry, (const void *)address, 4);
    return entry;
}

/* The native caller supplies readable kernel RAM, including the end word. */
u32 *func_0010CB10(u32 *begin, u32 *end, u32 value)
{
    while (*begin != value && begin < end) begin++;
    if (begin >= end) begin = 0;
    return begin;
}
