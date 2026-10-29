/* Sony EE GCC 2.9 libgraph/libdma-style SDK code. Built with cc1 2.9-ee-991111 -O2 -G0 and
 * GNU as 2.10-ee-001003-1, which fills the remaining .set reorder jal/jr delay slots itself
 * (volatile MMIO loads/stores) and encodes move as daddu: ./trysony29x.sh src/rc_a_a.c EE29CC1 EEAS210 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

extern u128 D_004381A0[2];

void func_00100478(void)
{
    u32 dummy;

    *(volatile u32 *)0x10003C10 = 1;
    *(volatile u32 *)0x10003C20 = 2;
    dummy = 0;
    __asm__ __volatile__("sync");
    __asm__ __volatile__(
        "cfc2.ni %0,$vi28\n\t"
        "ori %0,%0,0x200\n\t"
        "ctc2.ni %0,$vi28\n\t"
        "sync.p"
        : "=r"(dummy) : "0"(dummy));
    *(volatile u128 *)0x10005000 = D_004381A0[0];
    *(volatile u128 *)0x10005000 = D_004381A0[1];
    *(volatile u32 *)0x10003000 = 1;
}

extern void func_00105E80(char *, ...);
extern char D_004AA9F8[], D_004AAAD8[], D_004AAB08[], D_004AAB38[], D_004AAB60[];
extern char D_004AAA28[], D_004AAA38[], D_004AAA48[], D_004AAA58[], D_004AAA68[];
extern char D_004AAA78[], D_004AAA88[], D_004AAA98[], D_004AAAA8[], D_004AAAC0[];

#define R(a) (*(volatile u32 *)(a))
#define N(a) (*(volatile u32 *)(a))

/* sceGsSyncPath: the timeout message is kept in $a0 across the shared error dump. */

s32 func_00100F00(s32 mode)
{
    u32 n = 0;
    u32 v;
    s32 r;
    register char *msg asm("$4");

    if (mode == 0) {
        while (R(0x10009000) & 0x100) {
            if (n++ > 0x1000000) goto e1;
        }
        while (R(0x1000A000) & 0x100) {
            if (n++ > 0x1000000) goto e2;
        }
        while (R(0x10003C00) & 0x1F000003) {
            if (n++ > 0x1000000) goto e3;
        }
        __asm__ volatile("cfc2.ni %0, $29" : "=r"(v));
        if (v & 0x100) {
            while (1) {
                if (n++ > 0x1000000) goto e4;
                __asm__ volatile("cfc2.ni %0, $29" : "=r"(v));
                if (!(v & 0x100)) break;
            }
        }
        while (R(0x10003020) & 0xC00) {
            if (n++ > 0x1000000) goto e5;
        }
        return 0;
    e1:
        msg = D_004AA9F8; goto fail;
    e2:
        msg = D_004AAAD8; goto fail;
    e3:
        msg = D_004AAB08; goto fail;
    e4:
        msg = D_004AAB38; goto fail;
    e5:
        msg = D_004AAB60;
    fail:
        func_00105E80(msg);
        func_00105E80(D_004AAA28, N(0x10009000));
        func_00105E80(D_004AAA38, N(0x10009030));
        func_00105E80(D_004AAA48, N(0x10009010));
        func_00105E80(D_004AAA58, N(0x10009020));
        func_00105E80(D_004AAA68, N(0x1000A000));
        func_00105E80(D_004AAA78, N(0x1000A030));
        func_00105E80(D_004AAA88, N(0x1000A010));
        func_00105E80(D_004AAA98, N(0x1000A020));
        func_00105E80(D_004AAAA8, N(0x10003C00));
        func_00105E80(D_004AAAC0, N(0x10003020));
        return -1;
    }
    r = 0; if (N(0x10009000) & 0x100) r = 1;
    if (N(0x1000A000) & 0x100) r |= 2;
    if (N(0x10003C00) & 0x1F000003) r |= 4;
    __asm__ volatile("cfc2.ni %0, $29" : "=r"(v));
    if (v & 0x100) r |= 8;
    if (N(0x10003020) & 0xC00) r |= 0x10;
    return r;
}

int func_00105540(int c)
{
    u32 v;
    do {
        v = *(volatile u32 *)0x1000F130 & 0x8000;
        __asm__("nop");
    } while (v);
    *(volatile u8 *)0x1000F180 = c;
    return c;
}
