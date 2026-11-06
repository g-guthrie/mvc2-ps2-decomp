/* Hitachi SHC 5.0R31 translation unit: two functions sharing one literal pool.
 * SHC emits the pool once, after both functions, so the object is the unit. */

struct actor_0c1c8ee4 {
    unsigned char pad[300];
    unsigned char v;
};

extern void func_0c037688(struct actor_0c1c8ee4 *p);

#pragma section n1a7ee4
void func_0c1c8ee4(struct actor_0c1c8ee4 *p) { p->v = 0; }

void func_0c1c8eec(struct actor_0c1c8ee4 *p) { p->v = 0; func_0c037688(p); }
