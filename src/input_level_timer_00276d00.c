/* Unary frame helper called by func_00275AD0 and func_00276880.
 * The byte timer table remains an external code view without data credit. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
extern u8 D_004B73D0[];
extern u8 D_004D18D8 __attribute__((section(".data")));
extern s32 func_00174170(void);
#define W(p,n) (*(s32 *)((p)+(n)))
void func_00276D00(u8 *p)
{
    if(p[0x425]) return;
    if(*(s8 *)(p+0x539)) {
        if(W(p,0x2BC)==0) {
            if(W(p,0x2B8)) --W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
        --W(p,0x2BC);
        if((func_00174170()&7)==0) {
            if(W(p,0x2B8)<3) ++W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
    } else if(D_004D18D8) {
        if(W(p,0x2BC)==0) {
            if(W(p,0x2B8)) --W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
        --W(p,0x2BC);
        if(func_00174170()&1) {
            if(W(p,0x2B8)<3) ++W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
    } else {
        if(W(p,0x2BC)==0) {
            if(W(p,0x2B8)) --W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
        --W(p,0x2BC);
        if(*(u16 *)(p+0x35C)&0x300) {
            if(W(p,0x2B8)<3) ++W(p,0x2B8);
            W(p,0x2BC)=D_004B73D0[W(p,0x2B8)];
        }
    }
}
