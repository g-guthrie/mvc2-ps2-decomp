/* newlib_heap_core.c's authoritative SVID2 struct mallinfo occupies 0x28 bytes through the independent 0043BB60 object. arena is read/written by func_0011CC10, func_0011BDD8, and func_0011CE68. */
struct mallinfo {
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};
struct mallinfo gCurrentMallinfo_0043BB38[1] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
