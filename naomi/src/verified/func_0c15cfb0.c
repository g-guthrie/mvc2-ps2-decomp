struct Obj_0c15cfb0 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[0x12c - 5];
    unsigned char b12c;
};

extern char func_0c02a026(struct Obj_0c15cfb0 *);
extern void func_0c037688(struct Obj_0c15cfb0 *);

void func_0c15cfd2(struct Obj_0c15cfb0 *a);
void func_0c15cfe0(struct Obj_0c15cfb0 *a);

void func_0c15cfb0(struct Obj_0c15cfb0 *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = a->b4 + 1;
        a->b12c = 0;
    }
}

void func_0c15cfd2(struct Obj_0c15cfb0 *a)
{
    a->b4 = a->b4 + 1;
    a->b12c = 0;
}

void func_0c15cfe0(struct Obj_0c15cfb0 *a)
{
    func_0c037688(a);
}
