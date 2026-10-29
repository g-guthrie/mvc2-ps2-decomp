/* func_0010C4C0 (libkernl TLB init): Sony EE GCC 2.9, ./trysony29.sh src/r11_01_e.c 0 O2 (exact).
   Retail keeps the entry counter in $t9 across printf/PutTLBEntry calls and never saves it,
   which only a fixed-register variable produces; the last loop needs its own counter j. */
typedef unsigned int u32;
typedef struct { u32 PageMask, EntryHi, EntryLo0, EntryLo1; } TLBEntry;
typedef struct { int nk, nd, ne, total; TLBEntry *k, *d, *e; } TLBInfo;
extern TLBInfo D_00438958;
extern char D_004AB1E0[], D_004AB218[], D_004AB230[], D_004AB248[];
extern void func_00105E48(const char *, ...);
extern void func_0010D090(int);
extern int func_0010C3E0(int, u32, u32, u32, u32);

int func_0010C4C0(void)
{
    register int i asm("$25");
    TLBEntry *e;
    int n;
    int j;
    func_00105E48(D_004AB1E0, D_00438958.nk - 1, D_00438958.nk, D_00438958.nk + D_00438958.nd - 1,
                  D_00438958.nk + D_00438958.nd, D_00438958.nk + D_00438958.nd + D_00438958.ne - 1);
    __asm__ volatile("mtc0 $0, $6\n\tsync.p");
    n = D_00438958.nk;
    i = 0;
    if (n > 0x30) {
        func_00105E48(D_004AB218);
        func_0010D090(1);
    }
    for (e = D_00438958.k; i < n; i++, e++)
        func_0010C3E0(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    n = i + D_00438958.nd;
    if (n > 0x30) {
        func_00105E48(D_004AB230);
        func_0010D090(1);
    }
    for (e = D_00438958.d; i < n; i++, e++)
        func_0010C3E0(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    D_00438958.total = i;
    __asm__ volatile("mtc0 %0, $6\n\tsync.p" : : "r"(i));
    if (D_00438958.ne > 0) {
        n = i + D_00438958.ne;
        if (n > 0x30) {
            func_00105E48(D_004AB248);
            func_0010D090(1);
        }
        for (e = D_00438958.e; i < n; i++, e++)
            func_0010C3E0(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    }
    for (j = i; j < 0x30; j++)
        func_0010C3E0(j, 0, 0xE0000000 + (j << 13), 0, 0);
    return i;
}
