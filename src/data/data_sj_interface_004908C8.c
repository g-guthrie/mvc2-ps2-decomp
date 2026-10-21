#include "../cri_sj_ring_buffer_types.h"

extern void func_0040F180(SJ_OBJ *object);
extern UUID *func_0040F1B8(SJ_OBJ *object);
extern void func_0040F1D0(SJ_OBJ *object);
extern void func_0040F228(SJ_OBJ *object, signed int id, signed int nbyte, SJCK *chunk);
extern void func_0040F380(SJ_OBJ *object, signed int id, SJCK *chunk);
extern void func_0040F2E8(SJ_OBJ *object, signed int id, SJCK *chunk);
extern signed int func_0040F1E0(SJ_OBJ *object, signed int id);
extern signed int func_0040F478(SJ_OBJ *object, signed int id, signed int nbyte, signed int *available);
extern void func_0040F1C0(SJ_OBJ *object, void (*callback)(void *, signed int), void *context);

/* Complete 12-slot SJ_IF at the address installed in SJ_OBJ.vtbl. */
CriSjInterface D_004908C8 = {
    0, 0, 0,
    func_0040F180,
    func_0040F1B8,
    func_0040F1D0,
    func_0040F228,
    func_0040F380,
    func_0040F2E8,
    func_0040F1E0,
    func_0040F478,
    func_0040F1C0,
};
typedef char D_004908C8_size_check[sizeof(CriSjInterface) == 0x30 ? 1 : -1];
