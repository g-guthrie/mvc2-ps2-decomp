/* Reset on completed animation or consume an event through its effect handler. */
typedef unsigned char u8;
extern signed char func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003A6DC0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_002EA320(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003A6DC0(p,0x1,0x2);
    }
}
extern void func_003A6DC0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_002EA380(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003A6DC0(p,0x1,0x4);
    }
}
extern void func_003A6DC0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_002EA510(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003A6DC0(p,0x1,0x5);
    }
}
extern void func_003A6DC0(u8 *,int,int);
extern void func_00184540(u8 *);
void func_002EA6D0(u8 *p) {
    if (func_00175700(p) < 0) func_00184540(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003A6DC0(p,0x1,0x3);
    }
}
extern void func_003B38F0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_003019A0(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003B38F0(p,0x1,0x2);
    }
}
extern void func_003B38F0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_00301B90(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003B38F0(p,0x1,0x5);
    }
}
extern void func_003B38F0(u8 *,int,int);
extern void func_00184540(u8 *);
void func_00301D50(u8 *p) {
    if (func_00175700(p) < 0) func_00184540(p);
    else if (*(signed char *)(p+0x151)) {
        p[0x151] = 0; func_003B38F0(p,0x1,0x3);
    }
}
