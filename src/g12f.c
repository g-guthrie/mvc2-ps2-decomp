typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct N { u8 pad[0xC]; struct N *next; } N;
extern N *D_004C28F0;
extern N *D_004C28E8;
extern void func_001E7F60();
void func_003268B0(void) {
    N *n = D_004C28F0;
    if (n) {
        do {
            func_001E7F60(n);
            n = n->next;
        } while (n);
    }
    n = D_004C28E8;
    if (n) {
        do {
            func_001E7F60(n);
            n = n->next;
        } while (n);
    }
}


extern u8 *D_004C2840;
extern s32 func_00118FA8(f32);
extern void func_00154650();
void func_00183D90(u8 *p) {
    if ((*(u32 *)(D_004C2840 + 0x1C) & 1) == 0) {
        if (func_00118FA8(*(f32 *)(p + 0x5C))) {
            if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
                func_00154650(p);
            }
        }
    }
}

extern u8 D_004C262C;
extern u8 D_004C2630;
void func_00136D50(void) {
    s32 i = 0;
    D_004C262C = 0;
    D_004C2630 = 0;
    do { func_00136DA0(i); i++; } while (i < 0x3B);
}
