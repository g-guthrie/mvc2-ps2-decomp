typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern int func_003F81B0(void *);
extern void func_003F81A8(int);
extern void func_0010B970(int, int, int, int, int);
extern void func_001061D8(void);
extern int D_00438270;
extern int func_00104C90(int);
extern void func_0011EB60(void *);
extern char D_004BE900[];
extern int *func_0011B370(void);
extern char D_004BC490[];
extern void func_003FB128(void *);
extern void func_0040E980(void *, int);
extern int func_0040E9F8(void *, int);

int func_00104598(int a, char *b) {
    *(u64 *)(b + 0x48) = 0;
    *(int *)(b + 4) = 0x2000;
    return 0;
}
int func_003FFFF0(int *p) { return func_003F81B0((void *)p[1]); }
void func_003FFFD8(int *p) { func_003F81A8(p[1]); }


int func_0040EEB0(void) { func_0011EB60(D_004BE900); return 0; }

void func_004025F0(char *p, int v) {
    if (p == 0) func_003FB128(D_004BC490);
    else p[0x6C] = v;
}
int func_0040E950(void *p) { func_0040E980(p, 0); return func_0040E9F8(p, 0); }

