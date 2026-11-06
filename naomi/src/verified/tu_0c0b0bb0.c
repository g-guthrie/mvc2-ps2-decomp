#include "objects.h"
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0b0c0a(struct Actor *);
void func_0c0b0c4c(struct Actor *);
void func_0c0b0c6e(struct Actor *);
void func_0c0b0bb0(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c0b0bd2(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c0b0bf4(struct Actor *a)
{
    func_0c0421f4(a);
    func_0c0420f8(a);
    func_0c0b0c0a(a);
}
void func_0c0b0c0a(struct Actor *a)
{
    func_0c042018(a);
    func_0c0421b8(a);
    if ((unsigned char)a->b1fe == 1) func_0c0b0c6e(a);
    else func_0c0b0c4c(a);
    if (func_0c044e52(a)) func_0c044f1c(a);
}
void func_0c0b0c4c(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0438de(a); }
void func_0c0b0c6e(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0438de(a); }
