/* Actor callback: kind 11 / 9-10 scale tweaks, then tail-dispatch on state
 * through the 4-entry handler table at 0x00463C80 (all void(u8 *)). */
typedef unsigned char u8;
typedef struct { u8 a[4]; u8 state; u8 b[0x1b]; u8 kind; u8 c[0x2f]; float x,y; } Actor;
typedef void (*Callback)(u8 *);
extern Callback const jtbl_00463C80[4];
void func_0036C120(u8 *p) {
 Actor *a = (Actor *)p;
 if (a->kind == 11) a->y = a->x = 1.03125f;
 if (a->kind == 9 || a->kind == 10) { a->x = 1.09f; a->y = 0.9985f; }
 jtbl_00463C80[a->state](p);
}
