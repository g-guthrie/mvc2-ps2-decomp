/* Slice of the newlib ctype table (_ctype_, 0x004AC700; entry i+1 is for
   char i). _ctype_[48..71]: chars 47..70. */
typedef unsigned char u8;
#define _U 0x01
#define _L 0x02
#define _N 0x04
#define _S 0x08
#define _P 0x10
#define _C 0x20
#define _X 0x40
#define _B 0x80
u8 data_u32_004AC730[24] = {
    _P, _N, _N, _N,
    _N, _N, _N, _N,
    _N, _N, _N, _P,
    _P, _P, _P, _P,
    _P, _P, _U|_X, _U|_X,
    _U|_X, _U|_X, _U|_X, _U|_X,
};
#undef _U
#undef _L
#undef _N
#undef _S
#undef _P
#undef _C
#undef _X
#undef _B
