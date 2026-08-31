typedef unsigned char u8;

void func_0038DE10(u8 *state) {
    u8 *other;
    u8 *destination;

    state[4] = 2;
    other = *(u8 **)(state + 0x18);
    destination = other + 0x2b8;
    if (state[1] == other[1]) {
        destination[2] = 0;
    }
}

void func_0038E120(u8 *state) {
    u8 *other;
    u8 *destination;
    state[4] = 2;
    other = *(u8 **)(state + 0x18);
    destination = other + 0x2b8;
    if (state[1] == other[1]) destination[2] = 0;
}
void func_0039BFA0(u8 *state) {
    u8 *other; u8 *destination;
    state[4] = 2; other = *(u8 **)(state + 0x18); destination = other + 0x2b8;
    if (state[1] == other[1]) destination[2] = 0;
}
void func_0039C320(u8 *state) {
    u8 *other; u8 *destination;
    state[4] = 2; other = *(u8 **)(state + 0x18); destination = other + 0x2b8;
    if (state[1] == other[1]) destination[2] = 0;
}
