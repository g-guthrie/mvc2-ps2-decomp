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
    s32 _unk18;
    s32 _unk1C;
    u8 pad20[4];
    s32 _unk24;
    u8 pad28[0x54 - 0x28];
    void *_data;
} F;

extern s32 func_001209B8(F *);
extern s32 func_0011B480(F *);

s32 func_00120900(F *fp)
{
    F tmp;
    u8 buf[0x400];
    s32 r;
    tmp._base = buf;
    tmp._flags = fp->_flags & 0xFFFD;
    tmp._file = fp->_file;
    tmp._data = fp->_data;
    tmp._unk1C = fp->_unk1C;
    tmp._unk24 = fp->_unk24;
    tmp._size = 0x400;
    tmp._p = buf;
    tmp._w = 0x400;
    tmp._unk18 = 0;
    r = func_001209B8(&tmp);
    if (r >= 0) {
        if (func_0011B480(&tmp))
            r = -1;
    }
    if (tmp._flags & 0x40)
        fp->_flags |= 0x40;
    return r;
}
