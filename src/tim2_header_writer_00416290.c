typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {
    volatile u32 offset;
    volatile u32 type;
    volatile u32 size;
    volatile u16 headerSize;
    volatile u16 format;
    volatile u8 zero0;
    volatile u8 one;
    volatile u8 mode0;
    volatile u8 mode1;
    volatile u16 width;
    volatile u16 height;
} Header;
typedef struct {
    volatile u8 *base;
    volatile u8 *cursor;
    volatile Header *header;
    volatile u32 reserved;
    volatile u8 *dataStart;
    volatile u8 *dataEnd;
    u32 writePointer;
} Writer;
void func_00416290(volatile Writer *writer, u8 *buffer, int width, int height, int format)
{
    writer->base = buffer;
    writer->cursor = buffer;
    writer->cursor[0] = 'T';
    writer->cursor[1] = 'I';
    writer->cursor[2] = 'M';
    writer->cursor[3] = '2';
    writer->cursor[4] = 0;
    writer->cursor[5] = 0;
    *(volatile u16 *)(writer->cursor + 6) = 1;
    writer->header = (volatile Header *)(buffer + 16);
    switch (format) {
    case 4:
        writer->header->type = 128;
        writer->header->format = 32;
        writer->header->mode0 = 67;
        writer->header->mode1 = 4;
        break;
    case 8:
        writer->header->type = 1024;
        writer->header->format = 256;
        writer->header->mode0 = 3;
        writer->header->mode1 = 5;
        break;
    case 16:
        writer->header->type = 0;
        writer->header->format = 0;
        writer->header->mode0 = 0;
        writer->header->mode1 = 1;
        break;
    case 24:
        writer->header->type = 0;
        writer->header->format = 0;
        writer->header->mode0 = 0;
        writer->header->mode1 = 2;
        break;
    case 32:
        writer->header->type = 0;
        writer->header->format = 0;
        writer->header->mode0 = 0;
        writer->header->mode1 = 3;
        break;
    default:
        break;
    }
    writer->header->size = ((width + 3) & -4) * height;
    writer->header->headerSize = 48;
    writer->header->zero0 = 0;
    writer->header->one = 1;
    writer->header->width = (u16)width;
    writer->header->height = (u16)height;
    {
        volatile Header *header = writer->header;
        header->offset = 48 + header->size + header->type;
    }
    {
        volatile Header *header = writer->header;
        writer->dataStart = (volatile u8 *)header + header->headerSize;
    }
    {
        volatile Header *header = writer->header;
        volatile u8 *start = writer->dataStart;
        writer->dataEnd = start + header->size;
    }
    {
        volatile Header *header = writer->header;
        writer->writePointer = header->offset + 16;
    }
}
