/* Provisional: owner lifetime, state bounds, and callback table types require proof. */
typedef unsigned char u8;
typedef struct {u8 a[2];u8 side;u8 b;u8 state;u8 c[0x143];u8 *owner;} Actor;
typedef void (*Callback)(u8 *,u8 *);
extern u8 *D_004D18B8[][3];
extern Callback const jtbl_0043E8F0[];
void func_00133860(u8 *p){
 Actor *a=(Actor *)p;
 a->owner=D_004D18B8[a->side][0];
 jtbl_0043E8F0[a->state](p,a->owner);
}
