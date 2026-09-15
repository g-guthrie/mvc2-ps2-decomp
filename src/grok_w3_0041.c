typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct CallbackEntry {
    u8 prefix[16];
    u32 callback;
    u8 callback_padding[4];
    void *arg;
    u8 arg_padding[4];
    u8 mode;
} CallbackEntry;

extern CallbackEntry *func_003DA750(int, int, int);
extern void func_0041A090(void);
extern void func_0041ACC0(void);
extern void func_003DD020(void *);
extern s32 func_003299D0(void);
extern void (*D_0043CD0C)(void);
extern void func_0041C2F0(void);
extern void func_0041C220(void);
extern void func_0012ACC0(s32);
extern void func_00422DB0(void);
extern void func_004238A0(s32, s32);
extern void func_004232C0(s32, s32, s32);
extern void func_00423750(s32);


s32 func_0041B380(u16 *a, u16 *b)
{
    if (*a > *b)
        return 1;
    if (*a < *b)
        return -1;
    return 0;
}

void func_0041A040(s32 a0, u8 mode)
{
    CallbackEntry *entry = func_003DA750(a0, 1, 2);
    if (entry != 0) {
        entry->callback = (u32)func_0041A090;
        entry->arg = (void *)a0;
        entry->mode = mode;
    }
}

void func_0041AC70(void *arg)
{
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0041ACC0;
        entry->arg = arg;
        entry->mode = 0;
    }
}

void func_0041B6C0(void **p)
{
    if (p[2]) {
        func_003DD020(p[2]);
        p[2] = 0;
    }
    if (p[3]) {
        func_003DD020(p[3]);
        p[3] = 0;
    }
}

void func_0041C2C0(void)
{
    if (func_003299D0() == 0)
        D_0043CD0C = func_0041C2F0;
}

void func_0041CA00(void)
{
    if (func_003299D0() == 0) {
        func_0012ACC0(0);
        D_0043CD0C = func_0041C220;
    }
}

s32 func_00419F70(void)
{
    func_00422DB0();
    func_004238A0(16, 0);
    func_004232C0(0, 0, 0);
    func_00423750(0);
    return 1;
}




