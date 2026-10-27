typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_00632140[];
extern s32 D_00632240[];
extern void func_00409708(s32, void *, s32, void *, s32);

s32 func_00410AD0(s32 a, s32 b) {
    D_00632140[0] = a;
    D_00632140[1] = b;
    func_00409708(0x29, D_00632140, 2, D_00632240, 1);
    return D_00632240[0];
}

typedef struct Obj Obj;
struct VT { u8 pad[0x24]; s32 (*f24)(Obj *, s32); };
struct Obj { struct VT *vt; };
typedef struct { u8 pad[0x18]; Obj *tab[1]; } Holder;
extern u8 D_004BC338[];
extern void func_003FB128(void *);

s32 func_00402298(Holder *h, s32 idx) {
    Obj *o;
    if (h == 0 || idx < 0) {
        func_003FB128(D_004BC338);
        return -1;
    }
    if ((o = h->tab[idx]) != 0) {
        return o->vt->f24(o, 1) / 2;
    }
    return 0;
}
