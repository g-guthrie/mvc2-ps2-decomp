/* Copy the native request-state label or write its fallback byte. */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 D_00439940[];
extern u8 D_004AB388;
extern u8 *func_0011FE88(u8 *destination, const u8 *source);
void func_0010DAF8(u32 state, u8 *destination) {
    if (state < 4) {
        func_0011FE88(destination, (const u8 *)D_00439940[state]);
    } else {
        *destination = D_004AB388;
    }
}
