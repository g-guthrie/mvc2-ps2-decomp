/* Bit split: returns whether bit selects the high word and stores the mask
 * for the bit within its word. The `? 1 : 0` spelling keeps the constant 1
 * in r3 as retail does. */
#pragma section N02f662
int func_0c02f662(unsigned int *out, signed char bit)
{
    int high = bit >= 32 ? 1 : 0;
    *out = 1 << (bit - ((signed char)high << 5));
    return high;
}
