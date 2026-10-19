typedef signed int s32;
typedef signed short s16;

typedef struct {
    s16 used;
    s16 pad;
    s32 pad2;
    s32 w8;
    char pad3[0x2C];
    s32 w38;
    s32 w3c;
    s32 w40;
    s32 w44;
    char pad4[0x30];
    void *w78;
    void *w7c;
    void *w80;
    void *w84;
} Slot;

extern Slot D_004791F8[];
extern void func_0011D8F8(void *, s32, s32);
extern s32 func_00404290(void);
extern void func_003F7D58(Slot *);
extern void func_003F7BE8(void);
extern void func_003F7C18(void);

Slot *func_003F7C38(s32 a, s32 b, s32 c, s32 d)
{
    s32 i;
    Slot *p;

    p = D_004791F8;
    i = 0;
    if (p->used) {
        i++;
        while (i < 16) {
            p++;
            if (p->used)
                i++;
            else
                break;
        }
    }
    if (i == 16)
        return 0;
    p = &D_004791F8[i];
    func_0011D8F8(p, 0, 0xB0);
    p->used = 1;
    p->w8 = func_00404290();
    if (p->w8 == 0) {
        func_003F7D58(p);
        return 0;
    }
    p->w38 = a;
    p->w3c = b;
    p->w40 = c;
    p->w44 = d;
    p->w78 = (void *)func_003F7BE8;
    p->w80 = (void *)func_003F7C18;
    p->w7c = p;
    p->w84 = p;
    return p;
}
