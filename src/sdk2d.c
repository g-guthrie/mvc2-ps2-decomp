typedef unsigned int u32;
extern void func_00405DC8(void *);
extern char D_004BCDF0[];
extern char D_004BCE10[];
typedef struct Hooks { char pad[0x38]; int (*fn)(void *); } Hooks;
typedef struct Handle { Hooks *h; void *arg; } Handle;

int func_00406EE0(Handle *h) {
    int r = 0;
    if (h == 0) {
        func_00405DC8(D_004BCDF0);
        return 0;
    }
    if (h->h->fn) {
        r = h->h->fn(h->arg);
    } else {
        func_00405DC8(D_004BCE10);
    }
    return r;
}

extern void func_0040D5A0(void *);
extern char D_004BE2F8[];
extern char D_004BE390[];
typedef struct Buf { char pad[0x14]; int pos; int limit; } Buf;


extern void func_0010CEB8(void *, int, int);
extern void func_0010CFD0(void);
extern void func_00104200(int, void *);
extern char D_004AB260[];
extern char *D_004386A0;


extern void *func_00406128(void);
typedef struct Dev { char pad[0x60]; int (*fn)(int, int, int, int); } Dev;
int func_00407AB8(void) {
    Dev *d = func_00406128();
    if (d) {
        if (d->fn) return d->fn(0, 100, 0, 0);
        return 0;
    }
    return (int)d;
}

extern void func_003F9630(void);
extern void func_003F9660(void);
extern void func_0011D8F8(void *, int, int);
void func_003F60B0(void *p) {
    if (p) {
        func_003F9630();
        func_0011D8F8(p, 0, 0x30);
        func_003F9660();
    }
}

typedef struct Slot { char pad[0x2C]; short used; } Slot;
extern char D_006207A0[];
extern int func_003EA130(Slot *);


typedef union { float f; u32 u; } FU;

