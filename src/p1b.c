/* EE GCC 2.96 -O2 -G8 (tryee8.sh src/p1b.c sn). The state word is volatile so
   each store stays ahead of its call, leaving a nop in every jal slot. */
typedef signed int s32;

extern volatile s32 D_004C22AC;
extern void func_00400AF8(void);
extern void func_00406A88(void);
extern void func_004084E8(void);
extern void func_003FD2A0(void);

void func_003FD928(void) {
    if (D_004C22AC == 0) {
        D_004C22AC = 1;
        func_00400AF8();
        D_004C22AC = 2;
        func_00406A88();
        D_004C22AC = 3;
        func_004084E8();
        D_004C22AC = 4;
        func_00406A88();
        D_004C22AC = 5;
        func_00400AF8();
        D_004C22AC = 6;
        func_003FD2A0();
        D_004C22AC = 0;
    }
}
