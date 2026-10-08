typedef signed int s32;

extern void func_0040DB10(s32 x, s32 y);
extern s32 func_003FCEE0(void *object, s32 code, s32 enabled);

void func_003FEF90(s32 x, s32 y) {
    func_0040DB10(x, y);
}

s32 func_003FCF70(void *object, s32 code, s32 enabled) {
    return func_003FCEE0(object, code, enabled);
}
