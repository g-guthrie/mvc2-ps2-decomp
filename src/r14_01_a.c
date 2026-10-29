/* Sony EE GCC 2.9-991111 cc1 + GNU as 2.10-ee-001003-1: ./trysony29x.sh src/r14_01_a.c EE29CC1 EEAS210 0 O2
   Volatile accesses keep reorg out of the jal slots (.set reorder); GNU as 2.10 then swaps the
   instruction before each jal into its slot, which is retail's pattern. */
typedef signed int s32;
typedef struct { s32 count, max_count, init_count, wait_threads, attr, option; } Sema;
extern s32 func_00103DE0(Sema *);
extern s32 D_004399A8, D_004399AC, D_004399A0, D_004399B0;
void func_0010E9A8(void)
{
    Sema s;
    if (*(volatile s32 *)&D_004399A8 != -1 && *(volatile s32 *)&D_004399AC != -1) return;
    s.init_count = 1;
    s.option = 0;
    s.max_count = 1;
    *(volatile s32 *)&D_004399A8 = func_00103DE0(&s);
    D_004399AC = func_00103DE0(&s);
    s.init_count = 0;
    *(volatile s32 *)&D_004399A0 = func_00103DE0(&s);
    *(volatile s32 *)&D_004399B0 = 0;
}

typedef struct {
    int a;
    int b;
    int c;
    unsigned char d[4];
    void *e;
    void *f;
} R149c;
extern R149c D_00439A80;
extern volatile int D_004399B4;
extern int D_004399D4;
extern int D_00439990;
extern unsigned char D_0043AA80[];
extern int D_0043AB40;
extern unsigned char D_0043AB50[];
extern char D_004AB570[];
extern char D_004AB588[];
extern int func_0010F0B0(void);
extern int func_0010EF40(int);
extern void func_00106578(void *, int);
extern void func_00105E80(char *);
extern void func_00103E00(int);
extern void func_0010E908(void *);
extern int func_00106E68(void *, int, int, void *, int, void *, int, void (*)(void *), void *);

int func_0010F968(int a, int b, void *c, unsigned char *d)
{
    R149c *s = &D_00439A80;
    int n;

    if (!(D_004399B4 & 1)) {
        if (func_0010F0B0() == 6) return 0;
    }
    if (!func_0010EF40(4)) return 0;
    s->a = a;
    s->b = b;
    s->c = (int)c;
    s->d[0] = d[0];
    s->d[1] = d[1];
    s->d[2] = d[2];
    s->e = D_0043AA80;
    s->f = &D_0043AB40;
    switch (d[2]) { case 0: n = b << 11; break; case 1: n = b * 0x918; break; case 2: n = b * 0x924; break; default: n = b << 11; break; }
    D_0043AB40 = 0;
    if (!(D_004399B4 & 2)) func_00106578(c, n);
    func_00106578(D_0043AA80, 0x90);
    func_00106578(s, 0x18);
    func_00106578(&D_0043AB40, 4);
    if (D_00439990 > 0) func_00105E80(D_004AB570);
    *(volatile int *)&D_004399D4 = 1;
    *(volatile int *)&D_004399B0 = 1;
    if (func_00106E68(D_0043AB50, 1, 1, s, 0x18, 0, 0, func_0010E908, D_0043AA80) < 0) {
        *(volatile int *)&D_004399D4 = 0;
        *(volatile int *)&D_004399B0 = 0;
        func_00103E00(*(volatile int *)&D_004399A8);
        return 0;
    }
    if (D_00439990 > 0) func_00105E80(D_004AB588);
    return 1;
}
