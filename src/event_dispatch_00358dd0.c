/* Provisional: callback table ABI and phase bounds require proof. */
typedef unsigned char u8;
typedef signed char s8;
typedef void (*EventPhase)(u8 *, u8 *);
extern EventPhase const jtbl_004630D0[7];
void func_00358DD0(u8 *p)
{
 u8 *work = p+0x88;
 u8 *owner = *(u8 **)(p+0x18);
 if (owner[0x169] == 19 && owner[0x168] == 6) p[0x24] = 1;
 else p[0x24] = *(s8 *)(owner+0x24);
 jtbl_004630D0[p[4]](p, work);
}
