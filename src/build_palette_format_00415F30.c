typedef struct PaletteSource { short width, height; unsigned int flags; unsigned char *data; int attributes; } PaletteSource;
typedef struct PaletteFormat {
    int flags, count, height, size;
    unsigned char *data;
    int bytes;
    int red_bits, red_shift, red_mask;
    int green_bits, green_shift, green_mask;
    int blue_bits, blue_shift, blue_mask;
    int alpha_bits, alpha_shift, alpha_mask;
} PaletteFormat;
int func_00415F30(PaletteFormat *out, const PaletteSource *source)
{
    out->flags = 0;
    switch (source->flags & 0xf0) {
    case 0x10:
        out->count = 16;
        out->height = 1;
        out->data = source->data + (source->width * source->height) / 2;
        break;
    case 0x20:
        out->count = 256;
        out->height = 1;
        out->data = source->data + source->width * source->height;
        break;
    default: return 0;
    }
    switch (source->flags & 15) {
    case 2:
        out->bytes = 2;
        out->red_bits = 5; out->red_shift = 10; out->red_mask = 31;
        out->green_bits = 5; out->green_shift = 5; out->green_mask = 31;
        out->blue_bits = 5; out->blue_shift = 0; out->blue_mask = 31;
        out->alpha_bits = 1; out->alpha_shift = 15; out->alpha_mask = 1;
        out->red_shift = 0; out->blue_shift = 10;
        break;
    case 3:
        out->bytes = 3;
        out->red_bits = 8; out->red_shift = 16; out->red_mask = 255;
        out->green_bits = 8; out->green_shift = 8; out->green_mask = 255;
        out->blue_bits = 8; out->blue_shift = 0; out->blue_mask = 255;
        out->alpha_bits = 0; out->alpha_shift = 0; out->alpha_mask = 0;
        out->red_shift = 0; out->blue_shift = 16;
        break;
    case 4:
        out->bytes = 4;
        out->red_bits = 8; out->red_shift = 16; out->red_mask = 255;
        out->green_bits = 8; out->green_shift = 8; out->green_mask = 255;
        out->blue_bits = 8; out->blue_shift = 0; out->blue_mask = 255;
        out->alpha_bits = 8; out->alpha_shift = 24; out->alpha_mask = 255;
        out->red_shift = 0; out->blue_shift = 16;
        break;
    default: return 0;
    }
    out->size = out->bytes * out->count;
    return 1;
}
