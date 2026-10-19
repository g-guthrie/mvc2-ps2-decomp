typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
#define GP(name) extern u8 name[] __attribute__((section(".sdata")))
GP(D_004C04B8); GP(D_004C04BC); GP(D_004C04C0); GP(D_004C0500);
GP(D_004C0508); GP(D_004C050C); GP(D_004C0510); GP(D_004C0514);
GP(D_004C0518); GP(D_004C0520); GP(D_004C0524); GP(D_004C0528);
GP(D_004C052C); GP(D_004C0530); GP(D_004C0534); GP(D_004C053C);
/* Partial actor view; the action byte is at the verified offset 0x1B5.
 * This is a code view, not a recovered data object or a full actor layout. */
typedef struct { u8 beforeAction[0x1B5]; u8 action; } ActorActionView;
typedef char ActorActionOffsetCheck[
    ((u32)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];
static inline void select_event(u8 *p, u8 action, int event)
{
    u32 counterOffset;
    ((ActorActionView *)p)->action=action;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_001757E0(p,event,p[0x168]);
}
#define SELECT_EVENT(event) select_event(p,p[0x1B5],event)
void func_00255950(u8 *p)
{
    u8 *q=p+0x2B8;
    *(u16 *)(p+0x2BC)=0;
    if (p[0x1FC]>=3) *(u16 *)(q+4)=1;
    switch(p[0x1FC]) {
    case 0:
        *(u16 *)(q+2)=1;
        if (*(u16 *)(p+0x20E)&0x400) {
            *(u16 *)(q+4)=1;
            p[0x168]=5; p[0x1B5]=0x44; *(u8 **)(p+0x408)=D_004C0508;
            SELECT_EVENT(20); p[0x1BB]=0; return;
        }
        p[0x168]=0; p[0x1B5]=0; *(u8 **)(p+0x408)=D_004C04B8; p[0x1BB]=0;
        break;
    case 1:
        *(u16 *)(q+2)=1;
        p[0x168]=1; p[0x1B5]=1; *(u8 **)(p+0x408)=D_004C04BC; p[0x1BB]=1;
        break;
    case 2:
        p[0x168]=2; p[0x1B5]=2; *(u8 **)(p+0x408)=D_004C04C0;
        if (*(u16 *)(q+2)==0 && (*(u16 *)(p+0x20E)&0x400)) {
            *(u16 *)(q+4)=1;
            p[0x168]=13; p[0x1B5]=0x4C; *(u8 **)(p+0x408)=D_004C0528;
            SELECT_EVENT(20); p[0x1BB]=0; return;
        }
        p[0x1BB]=2;
        if (*(u16 *)(p+0x20E)&0x800) {
            p[0x168]=3; p[0x1B5]=0x13; *(u8 **)(p+0x408)=D_004C0500;
        }
        p[0x1BB]=2;
        break;
    case 3:
        p[0x168]=6; p[0x1B5]=69; *(u8 **)(p+0x408)=D_004C050C;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 4:
        p[0x168]=7; p[0x1B5]=70; *(u8 **)(p+0x408)=D_004C0510;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 5:
        p[0x168]=8; p[0x1B5]=71; *(u8 **)(p+0x408)=D_004C0514;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 6:
        p[0x168]=9; p[0x1B5]=72; *(u8 **)(p+0x408)=D_004C0518;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 7:
        p[0x168]=11; p[0x1B5]=74; *(u8 **)(p+0x408)=D_004C0520;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 8:
        p[0x168]=12; p[0x1B5]=75; *(u8 **)(p+0x408)=D_004C0524;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 9:
        p[0x168]=14; p[0x1B5]=77; *(u8 **)(p+0x408)=D_004C052C;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 10:
        p[0x168]=15; p[0x1B5]=78; *(u8 **)(p+0x408)=D_004C0530;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 11:
        p[0x168]=16; p[0x1B5]=79; *(u8 **)(p+0x408)=D_004C0534;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 12:
        p[0x168]=18; p[0x1B5]=81; *(u8 **)(p+0x408)=D_004C053C;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    default:
        *(u16 *)(q+4)=0;
        p[0x168]=5; p[0x1B5]=0x44; *(u8 **)(p+0x408)=D_004C0508;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    }
    SELECT_EVENT(7);
}
