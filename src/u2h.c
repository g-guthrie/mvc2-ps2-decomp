typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 flags;
    u32 count;
    u16 *src;
    s32 kind;
} Cmd;

void func_0041B7E0(u16 *dst, Cmd *c) {
    u16 *src;
    u32 count;
    u32 i, j;
    u32 n, flags;
    s32 kind;
    count = c->count;
    src = c->src;
    for (i = 0; i < count; i++) {
        flags = c->flags;
        n = *src++;
        if (flags & 0x400000) {
            src++;
        }
        if (flags & 0x100000) {
            src += 2;
        }
        kind = c->kind;
        flags &= 0x1000;
        n &= 0x3FFF;
        for (j = 0; j < n; j++) {
            switch (kind) {
            case 0x25:
            case 0x35:
            case 0x235:
                if (flags) {
                    *dst = *src;
                    src++;
                    dst += 2;
                }
                break;
            }
        }
    }
}
