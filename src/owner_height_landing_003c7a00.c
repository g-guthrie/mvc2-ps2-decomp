typedef unsigned char u8;
typedef unsigned int u32;
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
#define F(p,o) (*(float *)((p)+(o)))
/* Advance both velocity components; landing clears their raw 32-bit slots.
 * The negated ordered comparison also preserves the native unordered case. */
void func_003C7A00(u8 *p, void *owner_context) {
    u8 *owner = owner_context;
    u32 *vx, *vy, *ax, *ay;
    vx=(u32 *)(p+0x5C); ax=(u32 *)(p+0x68); vy=(u32 *)(p+0x60); ay=(u32 *)(p+0x6C);
    F(p,0x34) += F(p,0x5C);
    F(p,0x5C) += F(p,0x68);
    F(p,0x38) += F(p,0x60);
    F(p,0x60) += F(p,0x6C);
    if (!(F(owner,0x430) <= F(p,0x38))) {
        p[5]++;
        F(p,0x38) = F(owner,0x38);
        *vx=0; *vy=0; *ax=0; *ay=0;
        func_001757E0(p,20,17);
        func_001E3210(owner,25);
    }
}
