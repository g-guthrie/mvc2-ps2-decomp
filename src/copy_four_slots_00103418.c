/* Copy four native 16-byte slots from independently supplied sources. */
typedef unsigned char u8;
extern void func_00102F20(void *destination, const void *source);
void func_00103418(void *destination, const void *initial, const void *first, const void *second, const void *third) {
    func_00102F20(destination, initial);
    func_00102F20((u8 *)destination + 0x10, first);
    func_00102F20((u8 *)destination + 0x20, second);
    func_00102F20((u8 *)destination + 0x30, third);
}
