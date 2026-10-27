typedef unsigned char u8;

struct Object;
extern void func_003DAA40(struct Object *);

void func_003B6620(u8 *p, void *owner) {
    u8 *q = owner;
    q[0x2bd]--;
    func_003DAA40((struct Object *)p);
}
