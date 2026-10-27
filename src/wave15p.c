typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_001754A0();


extern void func_001E7F60(u8 *);

void func_003C5780(u8 *p) {
    float f = -6.666666507720947f;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140)) f = -f;
    *(float *)(p + 0x5C) = f;
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    if (*(s8 *)(p + 0x1B3) == 0) func_001E7F60(p);
}

extern float D_004F7FD0;
extern float D_004F7FD4;
extern s32 D_004F7FD8;
extern float D_0043DD10[];

void func_001474E0(u8 *p) {
    float f;
    *(float *)(p + 0x34) = D_004F7FD0 / 10.0f;
    *(float *)(p + 0x38) = -(D_004F7FD4 / 10.0f);
    f = D_0043DD10[D_004F7FD8];
    *(float *)(p + 0x54) = f;
    *(float *)(p + 0x50) = f;
}

void func_003B7520(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = *(u8 **)(q + 0x220);
    float d;
    if (p[5] == 0) {
        d = *(float *)(r + 0x34) - *(float *)(p + 0x34);
        if (*(s16 *)(q + 0x140) == 0) d = -d;
        if (!(d <= 80.0f)) *(s16 *)(p + 0x1C0) = 0x10;
    }
}

extern void func_00134850();
typedef struct Obj { u8 h[0xC]; struct Obj *next; u8 f[0x12c]; signed char active; } Obj;
extern Obj *D_004D36CC[];

void func_00153670(void) {
    Obj *o = D_004D36CC[0];
    while (o != 0) {
        if (o->active) func_00134850(o);
        o = o->next;
    }
}
