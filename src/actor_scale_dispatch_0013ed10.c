typedef unsigned char u8;
typedef signed char s8;
typedef struct { u8 a[0x20]; u8 state; u8 b[0x57]; float x,y,z; } Actor;
typedef void (*StateCallback)(u8 *);
extern s8 *D_004C2840 __attribute__((section(".sdata")));
extern StateCallback const jtbl_00440678[3];
void func_0013ED10(u8 *p) {
    Actor *a = (Actor *)p;
    if (D_004C2840[2] >= 3 && !(a->x < 0.5f)) {
        a->x -= 0.01f;
        a->y = a->x;
        a->z = a->x;
    }
    jtbl_00440678[a->state](p);
}
