struct Obj_0c16df74 {
    unsigned char pad[5];
    signed char state;
};

extern void func_0c037688(void);

void func_0c16df74(struct Obj_0c16df74 *p)
{
    if (p->state == 0)
        p->state++;
    else
        func_0c037688();
}
