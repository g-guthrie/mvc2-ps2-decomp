/* Slice of the newlib ctype table (_ctype_, 0x004AC700; entry i+1 is for
   char i). _ctype_[16..31]: chars 15..30. */
typedef unsigned char u8;
#define _U 0x01
#define _L 0x02
#define _N 0x04
#define _S 0x08
#define _P 0x10
#define _C 0x20
#define _X 0x40
#define _B 0x80
u8 data_u32_004AC710[16] = {
    _C, _C, _C, _C,
    _C, _C, _C, _C,
    _C, _C, _C, _C,
    _C, _C, _C, _C,
};
#undef _U
#undef _L
#undef _N
#undef _S
#undef _P
#undef _C
#undef _X
#undef _B
