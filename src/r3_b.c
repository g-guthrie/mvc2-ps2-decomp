typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[8]; s32 f1c; u8 pad3[8]; s32 f28; } F;
extern u8 D_004BE080[];
extern void func_0040AF58(F *, void *);
s32 func_0040B958(F *f, s32 off, s32 whence) {
    s32 end, pos;
    if (f == 0) {
        func_0040AF58(f, D_004BE080);
        return 0;
    }
    if (whence == 0) {
        f->f1c = off;
        end = f->f10;
    } else if (whence == 2) {
        end = f->f10;
        f->f1c = end + off;
    } else if (whence == 1) {
        end = f->f10;
        f->f1c = f->f1c + off;
    } else {
        end = f->f10;
    }
    pos = f->f1c;
    f->f28 = 0;
    if (pos >= end) pos = end;
    if (pos < 0) pos = 0;
    f->f1c = pos;
    return pos;
}

typedef struct {
    u8 pad0[8];
    s32 end;
    s32 position;
    u8 pad1[4];
    s32 status;
} SeekState;

extern u8 D_004BDBA8[];
extern void func_004098A8(s32 auxiliary, const char *message);
s32 func_00409EB8(SeekState *f, s32 off, s32 whence) {
    s32 end, pos;
    if (f == 0) {
        func_004098A8((s32)f, (const char *)D_004BDBA8);
        return 0;
    }
    if (whence == 0) {
        f->position = off;
        end = f->end;
    } else if (whence == 2) {
        end = f->end;
        f->position = end + off;
    } else if (whence == 1) {
        end = f->end;
        f->position = f->position + off;
    } else {
        end = f->end;
    }
    pos = f->position;
    f->status = 0;
    if (pos >= end) pos = end;
    if (pos < 0) pos = 0;
    f->position = pos;
    return pos;
}

typedef struct { s32 a; s32 b; } G;
extern G D_004895C0;
extern void func_0040C6D0(s32 *, s32, s32, s32);


typedef struct { u8 pad0; s8 f1; s8 f2; u8 pad3[0x25]; s32 f28; s32 f2c; s32 f30; s32 f34; } O;
extern u8 D_004BE2F8[];
extern void func_0040D5A0(void *);
extern void func_00400740(s8 *);
extern void func_004005F8(s32);
extern void func_0040CF98(O *);
void func_0040D040(O *o) {
    if (o == 0) {
        func_0040D5A0(D_004BE2F8);
        return;
    }
    if (o->f1 != 0) {
        o->f1 = 0;
        if (o->f28 != 0) {
            if (o->f2 == 1) {
                func_00400740((s8 *)o->f28);
                o->f2 = 0;
            }
            func_004005F8(o->f28);
            o->f28 = 0;
        }
        o->f2c = 0;
        func_0040CF98(o);
        o->f34 = 0;
    }
}

typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; u8 pad[0x3C]; s32 data; } FL;
extern s32 D_0043B6F8;
extern s32 func_001209B8(FL *, const char *, void *);
s32 func_0011F938(char *buf, const char *fmt, ...) {
    __builtin_va_list ap;
    FL f;
    s32 written;
    __builtin_stdarg_start(ap, fmt);
    f.flags = 0x208;
    f.p = (u8 *)buf;
    f.base = (u8 *)buf;
    f.w = 0x7FFFFFFF;
    f.size = 0x7FFFFFFF;
    f.data = D_0043B6F8;
    written = func_001209B8(&f, fmt, ap);
    *f.p = 0;
    return written;
}
