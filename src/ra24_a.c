typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32;
typedef struct { u8 pad[0x19]; u8 b19; u8 pad2[2]; } E; typedef struct { u8 pad[0x184]; E *t; } C;
typedef struct { u8 pad0[0x484]; u8 *o484; s16 o488; u8 b48A; u8 b48B; u8 pad1[0x4B4-0x48C]; u8 b4B4; u8 pad2[0x4CC-0x4B5]; C *c; } P;
void func_00169F40(u8 *a) {
    extern s32 func_00174170();
    extern void func_00169C90();
    P *p = (P*)a;
    u8 *base, *rec, *s1, *s3;
    u32 idx, r;
    E *e = p->c->t; e += p->b4B4; rec = (base = *(u8 **)(a + 0x1A4)) + e->b19 * 12;
    s1 = (u8*)(*(s32 *)(rec + 8) + (s32)base);
    s3 = (u8*)((u32)*(u32 *)(rec + 4) + (u32)base);
    r = func_00174170();
    idx = s3[r & 0x1F];
    p->o484 = base + *(s32 *)(s1 + idx * 4);
    p->o488 = 0;
    p->b48A = idx;
    p->b48B = 0;
    func_00169C90(a);
}
