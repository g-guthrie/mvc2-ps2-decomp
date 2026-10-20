/* Clear the runtime word and update flags after the existing resource reset. */
typedef unsigned char u8;
typedef signed int s32;
extern void func_00102428(void *);
void func_00102A08(u8 *p) {
    s32 flags;
    func_00102428(p);
    *(s32 *)(p + 0x20) = 0;
    flags = *(s32 *)p;
    flags &= -13;
    flags |= 4;
    flags &= -2;
    flags |= 0x100;
    *(s32 *)p = flags;
}
