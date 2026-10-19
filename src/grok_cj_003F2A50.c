typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    char pad[0x20];
    s16 f20;
} Out;

extern s32 *func_003F1F00(void *);
extern void func_003ED0D0(char *);
extern char D_004BAC60[];
extern s32 *func_003F1F10(void);
extern u8 *func_003F19B0(void *, s32);
extern s32 func_003F1E10(void *, s32);
extern s32 func_003F2B70(Out *, u8 *);

s32 func_003F2A50(Out *out, void *file, u32 index)
{
    s32 *h;
    s32 *info;
    u8 *rec;
    s32 kind;

    h = func_003F1F00(file);
    if ((h[0] & 1) == 0) {
        func_003ED0D0(D_004BAC60);
        return 0;
    }
    info = func_003F1F10();
    if (info == 0)
        return 0;
    if (index >= (u32)info[1])
        return 0;
    rec = func_003F19B0(file, index);
    if (rec == 0)
        return 0;
    kind = rec[0];
    if (kind == 2) {
        out->f20 = (s16)func_003F1E10(file, index);
        return func_003F2B70(out, rec);
    }
    if (kind == 5 || kind == 4 || kind == 3 || kind == 1)
        return 0;
    return 0;
}
