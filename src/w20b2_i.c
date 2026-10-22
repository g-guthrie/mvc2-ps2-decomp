typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/w20b2_i.c sn */
typedef struct { u8 pad[0x10]; s32 (*fn)(s8 *, s32, s32); } R_i;
typedef struct { R_i *r; s32 res; } S_i;
extern char D_004BC9A0[], D_004BC9C0[], D_004BCA08[], D_004BCA28[], D_004BCA40[];
extern void func_00406688(u8 *, s8 *, void *);
extern S_i *func_00406610(void);
extern R_i *func_00406440(u8 *, s8 *, void *);
extern void func_00406678(S_i *);
extern void func_00405DC8(char *);

S_i *func_004064E8(void *a, s32 b, s32 c) {
    u8 buf1[0x130];
    s8 buf2[0x130];
    S_i *s;
    R_i *r;
    if (a == 0) {
        func_00405DC8(D_004BC9A0);
        return 0;
    }
    func_00406688(buf1, buf2, a);
    if (buf2[0] == 0) {
        func_00405DC8(D_004BC9A0);
        return 0;
    }
    s = func_00406610();
    if (s == 0) {
        func_00405DC8(D_004BC9C0);
        return 0;
    }
    r = func_00406440(buf1, buf2, a);
    s->r = r;
    if (r == 0) {
        func_00406678(s);
        func_00405DC8(D_004BCA08);
        return 0;
    }
    if (r->fn != 0) {
        s->res = r->fn(buf2, b, c);
    } else {
        func_00406678(s);
        func_00405DC8(D_004BCA28);
        return 0;
    }
    if (s->res == 0) {
        func_00406678(s);
        func_00405DC8(D_004BCA40);
        return 0;
    }
    return s;
}

typedef struct { s32 w0; s32 w4; s32 w8; s32 wc; } D_i;
extern D_i D_004895C0;
extern void func_0011D740(char *, char *, s32);
