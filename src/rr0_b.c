typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct N0 { u8 pad[0xC]; struct N0 *next; u8 pad2[0x1B8 - 0x10]; s8 b1B8; } N0;
extern N0 *D_004C28F0;
extern N0 *D_004C28E8;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
extern u8 D_004D18A4[];
extern u8 D_004D18A5[];

void func_00326700(void) {
    N0 *n;
    extern void func_00327750();
    extern void func_00327BC0();
    extern void func_00326930();
    extern void func_001793B0();
    extern void func_001817E0();
    extern void func_00326B70();
    extern void func_00326A30();
    extern void func_00327C70();
    extern void func_00181150();
    extern void func_00190070();
    extern void func_001905F0();
    extern void func_001710C0();
    extern void func_00327C20();
    extern void func_00190130();
    func_00327750();
    func_00327BC0();
    func_00326930();
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        D_004D18A4[0] = 0x3F;
        n = D_004C28F0;
        if (n != 0) {
            do {
                D_004D18A5[0] = 0;
                D_004D18A4[0] &= ~(1 << n->b1B8);
                func_001793B0(n);
                if (D_004D18A5[0] != 0) func_001793B0(n);
                n = n->next;
            } while (n != 0);
            n = D_004C28F0;
            do {
                if (D_004D18A4[0] & (1 << (u8)n->b1B8)) func_001793B0(n);
                n = n->next;
            } while (n != 0);
        }
        n = D_004C28E8;
        if (n != 0) {
            do {
                D_004D18A5[0] = 0;
                func_001793B0(n);
                if (D_004D18A5[0] != 0) func_001793B0(n);
                n = n->next;
            } while (n != 0);
        }
        func_001817E0(D_004C28F0, D_004C28E8);
        func_00326B70();
        func_00326A30();
        func_00327C70();
        func_00181150();
    }
    func_00190070();
    func_001905F0();
    func_001710C0();
    func_00327C20();
    func_00190130();
}
