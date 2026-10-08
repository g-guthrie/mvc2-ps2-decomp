typedef unsigned int u32;
u32 func_00102520(u32 address) {
    if ((address >> 28) == 7) {
        address &= 0x0fffffffU;
        address |= 0x80000000U;
    }
    return address;
}
