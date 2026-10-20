/* Configure the remapped address, value and native runtime mode flags. */
typedef unsigned int u32;
typedef signed int s32;
struct RuntimeState {
    s32 flags;
    unsigned char pad4[0xC];
    u32 address;
    unsigned char pad14[0xC];
    s32 value;
};
extern u32 func_00102520(u32 address);
extern void func_00102428(void *p);
void func_00102A50(struct RuntimeState *p, u32 address, s32 value) {
    u32 mapped;
    s32 flags;
    mapped = func_00102520(address);
    func_00102428(p);
    if (p->address != 0xFFFFFFFFu) {
        p->address = mapped;
    }
    p->value = value;
    flags = p->flags;
    flags &= -13;
    flags &= -2;
    flags |= 0x100;
    p->flags = flags;
}

void func_00102AD0(struct RuntimeState *p, u32 address, s32 value) {
    u32 mapped;
    s32 flags;
    mapped = func_00102520(address);
    func_00102428(p);
    if (p->address != 0xFFFFFFFFu) {
        p->address = mapped;
    }
    p->value = value;
    flags = p->flags;
    flags &= -13;
    flags |= 0x8;
    flags &= -2;
    flags |= 0x100;
    p->flags = flags;
}
