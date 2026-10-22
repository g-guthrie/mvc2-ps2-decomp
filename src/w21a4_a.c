typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef struct { s32 a, b; } P;
typedef struct { s32 a, b, c; } T;
extern s32 D_004C261C;
extern s32 D_004CAB40[];
extern P D_004CAB44[4];
extern s32 D_004CAB70[5];
extern P D_004CAB20[3];
extern P D_004CA6F0[128];
extern P D_004CA670[16];
extern T D_004CA610[8];

void func_0012E320(void) {
    u32 i;
    P *p1;
    P *p4;
    P *p3;
    s32 *p2;
    P *p5;
    T *t;
    D_004C261C = 0;
    D_004CAB40[0] = 0;
    p1 = D_004CAB44;
    for (i = 0; i < 4; i++) { p1->a = 0; p1->b = 0; p1++; }
    p2 = D_004CAB70;
    for (i = 0; i < 5; i++) { *p2 = 0; p2++; }
    p3 = D_004CAB20;
    for (i = 0; i < 3; i++) { p3->a = 0; p3->b = 0; p3++; }
    p4 = D_004CA6F0;
    for (i = 0; i < 128; i++) { p4->a = 0; p4->b = 0; p4++; }
    p5 = D_004CA670;
    for (i = 0; i < 16; i++) { p5->a = 0; p5->b = 0; p5++; }
    t = D_004CA610;
    for (i = 0; i < 8; i++) { t->a = 0; t->b = 0; t->c = 0; t++; }
}

