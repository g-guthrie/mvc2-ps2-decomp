typedef signed int s32;
typedef signed short s16;

extern void func_003F9698(s32 primary, s32 secondary, s16 *first,
                          s16 *second);

void func_00404360(void *record, s32 primary, s32 secondary)
{
    unsigned char *bytes = record;
    func_003F9698(secondary, primary, (s16 *)(bytes + 48),
                  (s16 *)(bytes + 50));
}
