typedef unsigned char u8;

/* The native SDK caller clears a 20-byte stack record. */
void func_00102548(void *buffer, int count)
{
    u8 *p = buffer;
    while (count--)
        *p++ = 0;
}
