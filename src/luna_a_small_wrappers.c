typedef unsigned int u32;

extern int func_003DF850(int, int);
extern int func_00163F70(void *, void *);
extern void func_00176230(short *, short *);

int func_001537B0(int enabled) {
    return func_003DF850(0x62, enabled ? 0 : 0x10000);
}

int func_00169BC0(void *owner, int index) {
    u32 entry = (u32)owner + 0x474;
    entry += index << 3;
    return func_00163F70(owner, (void *)entry);
}

void func_0016F4B0(int index, void *source, void *table) {
    u32 entry = index << 4;
    entry += (u32)table;
    func_00176230((short *)source, *(short **)(entry + 8));
}
