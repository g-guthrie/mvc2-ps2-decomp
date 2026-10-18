/* Dispatch a stage actor to the setup routine selected by its type byte. */
typedef unsigned char u8;
typedef signed int s32;

extern void func_001DFFC0(u8 *);
extern void func_001D34C0(u8 *, u8);
extern void func_001D1250(u8 *);
extern void func_001D1550(u8 *);
extern void func_001CF800(void *);
extern void func_001C9420(u8 *, s32, s32);
extern void func_001CA290(u8 *);
extern void func_001CAEA0(u8 *);
extern void func_001C85D0(void *);
extern void func_001C16B0(u8 *);
extern void func_001BFAC0(u8 *);
extern void func_001BE420(u8 *);
extern void func_001B7350(u8 *);
extern void func_001A96A0(u8 *, s32);
extern void func_001B3300(u8 *, s32);
extern void func_0019FEE0(void *);
extern void func_00358D50(u8 *);
extern void func_0019D540(u8 *);
extern void func_0019A010(void *, u8);
extern void func_00198620(u8 *, s32, s32);
extern void func_0034BC80(u8 *, s32);
extern void func_00194A20(u8 *);
extern void func_00192B00(void *);

void func_00180F20(u8 *p)
{
    switch (p[1]) {
    case 0x00:
        func_00192B00(p);
        break;
    case 0x03:
        func_00194A20(p);
        break;
    case 0x04:
        func_00198620(p, 3, 0);
        func_00198620(p, 3, 1);
        func_0034BC80(p, 0);
        break;
    case 0x06:
        func_0019A010(p, 0);
        break;
    case 0x0A:
        func_0019D540(p);
        break;
    case 0x0B:
        func_00358D50(p);
        break;
    case 0x0C:
        func_0019FEE0(p);
        break;
    case 0x10:
        func_001A96A0(p, 0);
        break;
    case 0x14:
        func_001B3300(p, 0);
        break;
    case 0x15:
        func_001B7350(p);
        break;
    case 0x18:
        func_001BE420(p);
        break;
    case 0x19:
        func_001BFAC0(p);
        break;
    case 0x1C:
        func_001C16B0(p);
        break;
    case 0x1E:
        func_001C85D0(p);
        break;
    case 0x1F:
        func_001C9420(p, 0, 0);
        func_001CA290(p);
        func_001CAEA0(p);
        break;
    case 0x27:
        func_001CF800(p);
        break;
    case 0x2A:
        func_001D1250(p);
        func_001D1550(p);
        break;
    case 0x2C:
        func_001D34C0(p, 0);
        break;
    case 0x38:
        func_001DFFC0(p);
        break;
    default:
        break;
    }
}
