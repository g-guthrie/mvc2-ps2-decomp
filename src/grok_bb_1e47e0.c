typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 b0;
    u8 pad[3];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} E_001E47E0;

extern E_001E47E0 D_004CBE80[];
extern void func_00422FB0(s32);

void func_001E47E0(u8 a, u8 b)
{
    s32 i = 0;
    s32 off = 0;
    E_001E47E0 *e;
    s32 *px;
    s32 *py;
    do {
        e = (E_001E47E0 *)((u8 *)D_004CBE80 + off);
        px = &e->f4;
        py = &e->f8;
        if ((a & 0xFF) == *px && (b & 0xFF) == *py) {
            func_00422FB0(((*px & 0x7F) << 16) | ((*py & 0x7F) << 8) | (i & 0x7F));
            e->b0 = 0;
            *px = 0;
            *py = 0;
            e->fC = 0;
            e->f10 = 0;
        }
        i = i + 1;
        off = off + 0x14;
    } while (i < 0x25);
}
