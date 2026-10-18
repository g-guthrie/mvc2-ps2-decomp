typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 id; u8 pad[0x8C]; u8 data[0x24]; } EL_d;
typedef struct ND_d { u8 pad0[0xC]; struct ND_d *next; struct ND_d *child; u8 pad1[0x180 - 0x14]; s32 idx; } ND_d;

static ND_d *func_00170E10(ND_d *a0)
{
    ND_d *a1 = a0;
    while (a0->idx == -1 && a1 != 0) {
        ND_d *v1 = a0->child;
        if (v1 != 0) a0 = v1;
        a1 = a0->next;
        if (a1 != 0) a0 = a1;
    }
    return a0;
}

void func_00170E60(EL_d *A, ND_d *a1, EL_d *B, ND_d *a3, void (*cb)(u8 *, u8 *, s32), s32 arg)
{
    ND_d *s0;
    ND_d *s1;
    s32 i;
    s1 = func_00170E10(a1);
    s0 = func_00170E10(a3);
    for (;;) {
        i = s1->idx;
        if (i != -1) {
            EL_d *a = &A[i];
            EL_d *b = &B[s0->idx];
            if (a->id != -1 && cb != 0) {
                cb(a->data - 0 + 0, b->data, arg);
            }
        }
        if (*(s32 *)((u8 *)s1 + 0x10) != 0) {
            s0 = *(ND_d **)((u8 *)s0 + 0x10);
            s1 = *(ND_d **)((u8 *)s1 + 0x10);
            continue;
        }
        s1 = *(ND_d **)((u8 *)s1 + 0xC);
        if (s1 == 0) break;
        s0 = *(ND_d **)((u8 *)s0 + 0xC);
    }
}
