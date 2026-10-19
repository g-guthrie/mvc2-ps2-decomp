typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_003FB128(void *);
extern char D_004BAE30[], D_004BAE68[];
s32 func_003FB5F0(u32 a, void *b) {
    if (a >= 0x100) { func_003FB128(D_004BAE30); return -3; }
    if (b == 0) { func_003FB128(D_004BAE68); return -3; }
    return 0;
}

typedef struct Pool { u8 pad[0xC]; u32 cur; u32 limit; u32 align; } Pool;

typedef struct Obj { s32 (**vt)(void *); void *arg; } Obj;
extern void func_00405DC8(void *);
extern char D_004BCB38[], D_004BCB58[], D_004BCB00[], D_004BCB20[];
s32 func_004069C8(Obj *o) {
    s32 r = 0;
    if (o == 0) { func_00405DC8(D_004BCB38); return 0; }
    if (*(s32 (**)(void *))((u8 *)o->vt + 0x24)) r = (*(s32 (**)(void *))((u8 *)o->vt + 0x24))(o->arg);
    else func_00405DC8(D_004BCB58);
    return r;
}
s32 func_00406960(Obj *o, s32 count, s32 buffer) {
    s32 r;
    if (o == 0) { func_00405DC8(D_004BCB00); return 0; }
    if (*(s32 (**)(void *, s32, s32))((u8 *)o->vt + 0x20)) r = (*(s32 (**)(void *, s32, s32))((u8 *)o->vt + 0x20))(o->arg, count, buffer);
    else { r = 0; func_00405DC8(D_004BCB20); }
    return r;
}

typedef struct Req { s32 cmd; s32 arg; s32 result; } Req;
extern s32 D_004C8380[];
extern Req D_004C85C0;
extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, s32, s32);

extern void func_00103038(void *, void *, float);
extern void func_00103188(void *, void *, float);
extern void func_001030E0(void *, void *, float);
