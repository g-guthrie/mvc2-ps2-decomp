/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_00472D80). */
#include "mvc2_state_callbacks.h"

extern void func_003A54E0(u8 *);
extern void func_003A5700(u8 *);
extern void func_003A5900(u8 *);
extern void func_003A5920(u8 *,u8 *);
extern void func_003A5B00(u8 *);
extern void func_003A5C80(u8 *);
extern void func_003A5D60(u8 *);
extern void func_003A5D80(u8 *);

typedef struct {
    Mvc2StateCallback earlier[3];
    void (*shared_release)(u8 *,u8 *);
    Mvc2StateCallback later[4];
} RelatedInheritedActionTables;
const RelatedInheritedActionTables jtbl_00472D80 = {{
    func_003A54E0,
    func_003A5700,
    func_003A5900,
}, func_003A5920, {
    func_003A5B00,
    func_003A5C80,
    func_003A5D60,
    func_003A5D80,
}};
