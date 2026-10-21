#include "runtime_entry_table.h"
#include "runtime_directory_types.h"
/* EE GCC 2.96: -O2 -G0 -fno-optimize-sibling-calls. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern void *func_0011D740(void *, const void *, u32);
extern void *func_0011D8F8(void *, s32, u32);
extern char *func_0011FE88(char *, const char *);
extern char *func_0011FC10(char *, const char *);
extern s32 func_0011FD40(const char *, const char *);
extern u32 func_0011FFA0(const char *);

extern void *D_004872E8;
extern void func_00405D98(void *, const char *, s32);
void func_00405DC8(const char *message)
{
    func_00405D98(&D_004872E8, message, 0);
}

extern char D_0062FD48[];
void func_004067B8(char *destination)
{
    s32 length = func_0011FFA0(D_0062FD48);
    if (D_0062FD48[0] == 0)
        destination[0] = 0;
    else
        func_0011D740(destination, D_0062FD48, length + 1);
}

extern char D_00489020[], D_004BDC30[], D_004BDC38[];
extern void func_00409AE0(char *);
void func_0040A440(char *name, char *path)
{
    func_0011FE88(path, D_00489020);
    if (*name != '/' && *name != '\\')
        func_0011FC10(path, D_004BDC30);
    func_0011FC10(path, name);
    if (func_0011FD40(path + func_0011FFA0(path) - 2, D_004BDC38))
        func_0011FC10(path, D_004BDC38);
    func_00409AE0(path);
}

extern void func_0040C808(s32, s32, s32, s32);
void func_00400F98(s32 *parameters)
{
    if (parameters != 0)
        func_0040C808(parameters[0], parameters[2], parameters[3], parameters[1]);
    else
        func_0040C808(0, 0, 0, 0);
}

extern void func_0040C6D0(s32 *output, char *name, unsigned char *bytes, s32 count);
void func_0040C7C0(void *opaque_name, s32 *output)
{
    char *name = (char *)opaque_name;
    output[0] = 0;
    output[1] = 0;
    if (D_004895C0.entries != 0)
        func_0040C6D0(output, name, D_004895C0.entries, D_004895C0.count);
}

extern void func_0040D040(void *);
void func_0040CD38(u8 *object)
{
    if (object != 0) {
        func_0040D040(object);
        object[0] = 0;
        func_0011D8F8(object, 0, 0x438);
    }
}

typedef struct { u8 pad[2]; s8 mode; } RuntimeObject;
extern struct { u8 pad; u8 phase; } D_004872F0;
extern s32 D_0048734C;
extern void func_00411288(void), func_004112B0(void);
extern void func_00407EF8(RuntimeObject *), func_00407F18(RuntimeObject *);
void func_00407FC8(RuntimeObject *object)
{
    s8 mode;
    func_00411288();
    mode = object->mode;
    if (mode == 2) {
        if ((s8)D_004872F0.phase == 1)
            func_00407EF8(object);
        if ((s8)D_004872F0.phase == mode)
            func_00407F18(object);
        if (object->mode != 9) {
            object->mode = 3;
            D_0048734C++;
        }
    }
    func_004112B0();
}

typedef struct { s8 first, second; } PathPrefix;
extern PathPrefix D_004895D8, D_004BE128;
void func_0040CAA0(s8 *path)
{
    if (path == 0) {
        D_004895D8.first = 0;
    } else {
        if (*path != '/' && *path != '\\')
            D_004895D8 = D_004BE128;
        else
            D_004895D8.first = 0;
        func_0011FE88((char *)&D_004895D8, (const char *)path);
    }
}

extern unsigned char D_004896E0[];
extern char gHostPathPrefix_004BE278[6];
void func_0040CB30(const char *source)
{
    if (source == 0)
        __builtin_memcpy(D_004896E0, gHostPathPrefix_004BE278, sizeof gHostPathPrefix_004BE278);
    else
        func_0011FE88((char *)D_004896E0, source);
}

void func_0040D738(RuntimeEntrySlot *p)
{
    extern s32 func_004003C8(s32, s32, s32, s32, s32);
    extern void func_0040D5A0(const char *, ...);
    extern s32 func_00400BE0(void *);
    extern s32 func_00400BB8(u8 *, s32, s32);
    extern s32 func_00400658(s32 *, s32);
    extern s32 func_004006E8(u8 *);
    extern char D_004BE3E0[];
    extern char D_004BE400[];
    RuntimeEntryRecord *e;
    s32 v, r;
    e = &p->records[p->record_index];
    if (p->remaining > 0) {
        if (p->handle == 0) {
            r = func_004003C8((s32)e->name, e->argument_2c, e->argument_30,
                              e->argument_34, p->argument_08);
            p->handle = r;
            if (r == 0) func_0040D5A0(D_004BE3E0, e->name);
            v = func_00400BE0((void *)p->handle);
            p->state_02 = 0;
            p->scaled_size = (v + 2047) / 2048;
            e->value_3c = 0;
        }
        if (p->state_02 == 0) {
            func_00400BB8((u8 *)p->handle, p->argument_14, p->argument_18);
            func_00400658((s32 *)p->handle, 0);
            func_004006E8((u8 *)p->handle);
            p->state_02 = 1;
        }
        e->word_38 = 1;
    } else {
        if (p->handle != 0) {
            func_0040D5A0(D_004BE400, p->remaining, p->handle);
        }
    }
}
