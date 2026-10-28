/* EE GCC 2.96: ./tryee.sh src/s5a_a.c sn
 * Runtime file-open helpers, 0x0040AF58..0x0040B8A8, in retail address order.
 * The callees are defined before their callers so cc1 treats them as
 * non-throwing (reorg then fills branch delay slots as retail does). */
#include "runtime_message_callback.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed long long s64;

extern RuntimeMessageCallback D_004891AC;
extern void *D_004891B0;
extern s32 func_0011EB60();

void func_0040AF58(s32 auxiliary, const char *message)
{
    if (D_004891AC != 0)
        D_004891AC(D_004891B0, message, auxiliary);
}

extern s32 func_0040B028(void);
extern char D_004BDD88[];
void func_0040B098(void) { u32 i; for (i = 0; func_0040B028() != 1; i++) { if (i > 0x29810) func_0011EB60(D_004BDD88); } }

extern char D_004BDDD8[];
extern char D_004BDDB0[];
extern s32 func_001089F0();
s32 func_0040B110(s32 h) {
    u32 i = 0;
    s32 buf;
    s32 r;
    while (1) {
        r = func_001089F0(h, 1, &buf);
        if (r < 0) {
            func_0011EB60(D_004BDDB0, h, r);
            return 0;
        }
        if (buf == 0) break;
        if (i > 0x29810) func_0011EB60(D_004BDDD8);
        i++;
    }
    return 1;
}

typedef struct { s32 a, b; } FileInfo;

extern u8 D_004BDE28[], D_004BDE58[], D_004BDE78[], D_004BDEA0[], D_004BDED8[];
extern u8 D_004BDF00[], D_004BDF38[], D_004BDF68[];
extern u8 D_00489490[];
extern s32 D_004895D4;
extern s32 D_004895D0;

extern void func_0040C7C0();
extern void func_0040BF58();
extern void func_00408698();
extern s32 func_00107E90();
extern void func_004086B8();
extern s32 func_00108298();
extern s32 func_00108118();

/* Returns the file size (seek to end), or 0 on error. */
s64 func_0040B458(u8 *name)
{
    FileInfo q;
    s32 fd;
    s32 r;
    u8 *path;

    if (name == 0) {
        func_0040AF58((s32)name, D_004BDE28);
        return 0;
    }
    func_0040C7C0(name, &q);
    if (q.b == 0) {
        path = D_00489490;
        func_0040BF58(name, path);
        func_0040B098();
        func_00408698();
        fd = func_00107E90(path, 1);
        func_004086B8();
        if (fd < 0) {
            if (D_004895D4 != 2)
                func_0011EB60(D_004BDE58, path);
            func_0040AF58(0, D_004BDE78);
            return 0;
        }
        if (fd == 0x10004) {
            if (D_004895D4 != 2)
                func_0011EB60(D_004BDEA0);
            func_0040AF58(0, D_004BDED8);
            return 0;
        }
        if (fd == 0x13) {
            if (D_004895D4 != 2)
                func_0011EB60(D_004BDF00);
            func_0040AF58(0, D_004BDED8);
            return 0;
        }
        func_0040B110(fd);
        func_00408698();
        r = func_00108298(fd, 0, 2);
        if (r < 0) {
            func_0040AF58(0, D_004BDF38);
            func_00108118(fd);
            func_004086B8();
            return 0;
        }
        func_0040B110(fd);
        if (func_00108118(fd) < 0) {
            func_0040AF58(0, D_004BDF68);
            func_004086B8();
            return 0;
        }
        func_004086B8();
    } else
        r = q.b;
    return r;
}

typedef struct {
    u8 b0, b1, b2, b3;
    s32 f4;
    s64 f8;
    s32 f10, f14, f18, f1c, f20, f24;
} FileHandle;
typedef union { s64 w; struct { s32 a, b; } s; } FileInfo64;
extern u8 D_004BDF98[], D_004BDFC0[], D_004BDFE8[], D_004BE018[], D_004BE040[];
extern FileHandle *func_0040B6A8();
extern void func_0040B6E0();

FileHandle *func_0040B700(u8 *name, s32 a1, s32 a2)
{
    FileHandle *s0;
    u8 *path;
    FileInfo64 q;
    s32 v;
    s64 r;

    q.w = 0;
    if (name == 0) {
        func_0040AF58((s32)name, D_004BDF98);
        return 0;
    }
    if (a2 != 0) {
        func_0040AF58(0, D_004BDFC0);
        return 0;
    }
    if ((s0 = func_0040B6A8()) == 0) {
        func_0040AF58(0, D_004BDFE8);
        return 0;
    }
    func_0040C7C0(name, &q);
    if (q.s.b == 0) {
        path = D_00489490;
        func_0040BF58(name, path);
        if (D_004895D4 == 0)
            func_0011EB60(D_004BE018, name);
        r = func_0040B458(name);
        s0->f8 = r;
        if (r == 0) return 0;
        func_0040B098();
        func_00408698();
        s0->f18 = func_00107E90(path, D_004895D0);
        func_004086B8();
        if (s0->f18 < 0) {
            func_0040AF58(0, D_004BE040);
            func_0040B6E0(s0);
            return 0;
        }
        func_0040B110(s0->f18);
        s0->b1 = 0;
    } else {
        s0->b1 = 1;
        s0->f18 = q.s.a;
        s0->f8 = q.s.b;
    }
    v = (s32)(s0->f8 + 0x7FF);
    s0->f1c = 0;
    s0->f20 = 0;
    s0->f24 = 0;
    s0->f14 = 0;
    s0->f10 = v / 2048;
    s0->b2 = 0;
    s0->b0 = 1;
    return s0;
}
