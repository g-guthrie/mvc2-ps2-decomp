typedef unsigned char u8;typedef short s16;
typedef struct {u8 a[5];u8 state;u8 b[0x16];s16 timer;u8 c[0x11e];u8 visible;} Actor;
void lbl_0035CFA0(u8 *p, u8 *owner_unused){
 Actor *a=(Actor *)p;
 s16 n=a->timer;
 a->timer=n-1;
 if(n==0){a->state++;a->visible=1;a->timer=60;}
}
