/* Owner context is bound by func_003C81C0 and forwarded through both state dispatchers. */
#include "mvc2_state_callbacks.h"
extern void func_003C81F0(u8 *,void *);
extern void func_003C8310(u8 *,void *);
extern void func_003C9200(u8 *,void *);
extern void func_003C9210(u8 *,void *);
const Mvc2OwnerStateCallback jtbl_004761D0[4] = {
    func_003C81F0,
    func_003C8310,
    func_003C9200,
    func_003C9210,
};
