typedef unsigned int u32;

extern int func_003DF850(int, int);
extern int func_00163F70(void *, void *);
extern int func_00176230(void *, u32);

int func_001537B0(int enabled) {
    return func_003DF850(0x62, enabled ? 0 : 0x10000);
}

int func_00169BC0(void *owner, int index) {
    u32 entry = (u32)owner + 0x474;
    entry += index << 3;
    return func_00163F70(owner, (void *)entry);
}

int func_0016F4B0(int index, void *destination, void *table) {
    u32 entry = index << 4;
    entry += (u32)table;
    return func_00176230(destination, *(u32 *)(entry + 8));
}
