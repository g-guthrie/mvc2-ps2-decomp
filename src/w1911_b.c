typedef unsigned char u8;
typedef signed int s32;
extern s32 D_004BED80[];
typedef struct { u8 pad[0x13]; u8 k; } K;
typedef struct { s32 pad[2]; K *k; } P;
s32 func_004166B0(P *p) {
    if (p->k->k > 5) return 0;
    return D_004BED80[p->k->k];
}
