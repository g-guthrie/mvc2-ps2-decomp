typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 *_p;
    s32 _r;
    s32 _w;
    u16 _flags;
    s16 _file;
    u8 *_base;
    s32 _size;
    u8 pad18[0x28 - 0x18];
    s32 (*_seek)();
    u8 pad2c[0x3C - 0x2C];
    u8 pad3c[0x4C - 0x3C];
    s32 _blksize;
    u8 pad50[4];
    u8 *_reent;
} F;

void func_0011CA18(F *fp)
{
    extern s32 func_0011C3F8();
    extern u8 *func_0011CE68();
    extern s32 func_0011FAB0();
    extern s32 func_00104590();
    extern void func_0011B768();
    u32 st[28];
    s32 size;
    s32 couldbetty;
    u8 *p;
    if (fp->_flags & 2) {
        fp->_base = fp->_p = (u8 *)fp + 0x43;
        fp->_size = 1;
        return;
    }
    if (fp->_file < 0 || func_0011C3F8(fp->_reent, fp->_file, st) < 0) {
        couldbetty = 0;
        size = 0x400;
        fp->_flags |= 0x800;
    } else {
        couldbetty = (st[1] & 0xF000) == 0x2000;
        size = 0x400;
        if ((st[1] & 0xF000) == 0x8000 && fp->_seek == func_0011FAB0) {
            fp->_flags |= 0x400;
            fp->_blksize = size;
        } else {
            fp->_flags |= 0x800;
        }
    }
    p = func_0011CE68(fp->_reent, size);
    if (p == 0) {
        fp->_flags |= 2;
        fp->_base = fp->_p = (u8 *)fp + 0x43;
        fp->_size = 1;
    } else {
        *(void (**)())(fp->_reent + 0x3C) = func_0011B768;
        fp->_flags |= 0x80;
        fp->_base = fp->_p = p;
        fp->_size = size;
        if (couldbetty && func_00104590(fp->_file)) {
            fp->_flags |= 1;
        }
    }
}
