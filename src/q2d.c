/* MWCCPS2 3.0 (011126): ./try30.sh src/q2d.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 *a, *b, *c; } T12;
typedef struct { u8 pad[0x18]; T12 arr[1]; } G;
extern G *D_004C2794;
extern s16 D_004F25D2[];
void func_00171210(void) {
    G *g = D_004C2794;
    s8 i = *(s8 *)((u8 *)g + 0x3E);
    if (i >= 0) {
        u8 *x = g->arr[i].a;
        if (*(s8 *)(x + 0x539) != 0) {
            s16 s = *(s16 *)(x + 0x434);
            s += *(s16 *)(g->arr[i].b + 0x434);
            s += *(s16 *)(g->arr[i].c + 0x434);
            if (s == 0x1B0) {
                *(s16 *)(i * 0x5B8 + (u32)D_004F25D2) += 0x50;
            }
        }
    }
}
