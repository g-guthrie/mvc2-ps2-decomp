typedef struct H { char pad[0x98]; short mode; } H;
extern void func_003F8810(H *);
extern void func_003F64F0(H *);
extern void func_003F8BF0(H *);
extern void func_003F6E48(H *);
extern void func_003F78B0(H *);
extern void func_003F95D0(H *);
void func_003F88E0(H *p) {
    if (p->mode == 0) func_003F8810(p);
    else if (p->mode == 10) func_003F64F0(p);
    else if (p->mode == 2) func_003F8BF0(p);
    else if (p->mode == 3) func_003F6E48(p);
    else if (p->mode == 4) func_003F78B0(p);
    else if (p->mode == 1) func_003F95D0(p);
}
