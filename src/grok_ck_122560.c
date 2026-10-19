typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct {
    u8 *_p;
    s32 _r;
    s32 _w;
    u16 _flags;
    s16 _file;
    u8 *_base;
    s32 _size;
    s32 _lbfsize;
    u8 pad1c[0x30 - 0x1C];
    u8 *_ub;
    u8 pad34[0x54 - 0x34];
    u8 *_data;
} F;

typedef struct { u8 pad[0x38]; s32 init; } R;

extern R *D_0043B6F8;
extern void func_0011B7A8(R *);
extern void func_0011BAE0(u8 *, u8 *);
extern void func_0011CA18(F *);

s32 func_00122560(F *fp)
{
    if (fp->_data == 0)
        fp->_data = (u8 *)D_0043B6F8;
    if (*(s32 *)(fp->_data + 0x38) == 0)
        func_0011B7A8((R *)fp->_data);
    if ((fp->_flags & 8) == 0) {
        if ((fp->_flags & 0x10) == 0)
            return -1;
        if (fp->_flags & 4) {
            if (fp->_ub && fp->_ub != (u8 *)fp + 0x40) {
                func_0011BAE0(fp->_data, fp->_ub);
            }
            fp->_ub = 0;
            fp->_flags &= ~0x24;
            fp->_r = 0;
            fp->_p = fp->_base;
        }
        fp->_flags |= 8;
    }
    if (fp->_base == 0)
        func_0011CA18(fp);
    if (fp->_flags & 1) {
        fp->_w = 0;
        fp->_lbfsize = -fp->_size;
    } else if ((fp->_flags & 2) == 0) {
        fp->_w = fp->_size;
    } else {
        fp->_w = 0;
    }
    return 0;
}
