/* Entry 36 of jtbl_00476010, reached from func_003C7480 as (p, owner) via
 * jtbl_00476010[36 + p[5]](p, q); bounds 0x003C74B0..0x003C7570 (own prologue,
 * jr ra, next function at 0x003C7570). */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
#define F(p,o) (*(float *)((p)+(o)))
/* Advance both velocity components; landing clears their raw 32-bit slots.
 * The negated ordered comparison also preserves the native unordered case. */
void func_003C74B0(u8 *p, void *owner_context) {
    u8 *owner = owner_context;
    float *vx, *vy, *ax, *ay;
    vx=(float *)(p+0x5C); ax=(float *)(p+0x68); vy=(float *)(p+0x60); ay=(float *)(p+0x6C);
    F(p,0x34) += F(p,0x5C);
    F(p,0x5C) += F(p,0x68);
    F(p,0x38) += F(p,0x60);
    F(p,0x60) += F(p,0x6C);
    if (!(F(owner,0x430) <= F(p,0x38))) {
        p[5]++;
        F(p,0x38) = F(owner,0x38);
        *vx=0.0f; *vy=0.0f; *ax=0.0f; *ay=0.0f;
        func_001757E0(p,20,14);
        func_001E3210(owner,26);
    }
}
