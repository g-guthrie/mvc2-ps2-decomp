typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s8 gNameEntryComparisons_004B55E0[20][3];
extern int func_00173590(u8 *);
extern int func_00173600(u8 *, s8);
void func_00173650(u8 *p)
{
    s32 off;
    s8 i;
    s8 j;
    s8 m;
    for (i = 0, off = 0; i < 20; i++) {
        m = 0;
        if (i >= 16) {
            for (j = 0; j < 3; j++) {
                if (*(s8 *)(p + 0x544 + j) != ((s8 *)gNameEntryComparisons_004B55E0)[off + j]) break;
                m++;
            }
            if (m == 3) {
                func_00173600(p, i);
                return;
            }
        } else {
            for (j = 0; j < 3; j++) {
                if (*(s8 *)(p + 0x544 + j) != ((s8 *)gNameEntryComparisons_004B55E0)[off + j]) break;
                m++;
            }
            if (m == 3) {
                func_00173590(p);
                return;
            }
        }
        off += 3;
    }
}
