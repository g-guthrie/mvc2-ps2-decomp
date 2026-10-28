/* Phase dispatch on p[7] through jtbl_0044CCF0 (6 void(u8 *, u8 *) entries,
 * see src/data/jtbl_0044CCF0.c). */
typedef unsigned char u8;
typedef void (*Callback)(u8 *,u8 *);
extern Callback const jtbl_0044CCF0[6];
void func_001C5980(u8 *p, u8 *owner) {
 u8 *work=owner+0x2b8;
 if(owner[5]!=0 || owner[0x1e4]!=29) {work[11]=0;work[10]=1;}
 jtbl_0044CCF0[p[7]](p,owner);
}
