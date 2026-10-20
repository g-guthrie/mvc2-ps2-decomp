typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern u32 * const D_00478940[4];

void func_003EB4A0(u8 *source, u8 *dest, int pitch)
{
    int row, pixel, block;
    u32 * const *table = D_00478940;

    for (block = 0; block < 4; block++) {
        u32 *mapping = *table++;
        for (row = 0; row < 2; row++) {
            int stride = (pitch << 8) - 32;
            for (pixel = 0; pixel < 32; pixel++) {
                int index = *mapping++;
                u8 low, high;

                if ((index & 1) == 0)
                    low = source[index / 2] & 0xF;
                else
                    low = (source[index / 2] & 0xF0) >> 4;

                index = *mapping++;
                if ((index & 1) == 0)
                    high = (source[index / 2] & 0xF) << 4;
                else
                    high = source[index / 2] & 0xF0;

                *dest++ = (s8)low | (s8)high;
            }
            dest += stride;
        }
        source += 0x100;
    }
}
