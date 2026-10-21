#include "../cri_sj_ring_buffer_types.h"

extern void func_0040FEA8(SJ_OBJ *object);
extern UUID *func_0040FEE0(SJ_OBJ *object);
extern void func_0040FEF8(SJ_OBJ *object);
extern void func_00410000(SJ_OBJ *object, signed int id, signed int nbyte, SJCK *chunk);
extern void func_00410290(SJ_OBJ *object, signed int id, SJCK *chunk);
extern void func_00410138(SJ_OBJ *object, signed int id, SJCK *chunk);
extern signed int func_0040FF88(SJ_OBJ *object, signed int id);
extern signed int func_004103D8(SJ_OBJ *object, signed int id, signed int nbyte, signed int *available);
extern void func_0040FEE8(SJ_OBJ *object, void (*callback)(void *, signed int), void *context);

CriSjInterface D_00494DA8 = {
    0, 0, 0,
    func_0040FEA8,
    func_0040FEE0,
    func_0040FEF8,
    func_00410000,
    func_00410290,
    func_00410138,
    func_0040FF88,
    func_004103D8,
    func_0040FEE8,
};
typedef char D_00494DA8_size_check[sizeof(CriSjInterface) == 0x30 ? 1 : -1];
