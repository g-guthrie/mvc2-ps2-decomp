/* Fixed 64-byte text records. The EABI va_start expression follows GCC 2.95.2
 * va-mips.h's single-float register-save area; args_info(2) is the named GPR
 * argument count supported by MWCCPS2. No frame-offset assumption is needed.
 */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
extern s32 D_004C2A58;
typedef struct { u8 x, y; unsigned short attribute; char text[60]; } TextRecord;
extern TextRecord D_0058CC40[128];
extern s32 func_00122340(char *, const char *, char *);
void func_003D7350(u8 a, u8 b, u8 c, const char *fmt, ...)
{
    TextRecord *dst;
    char *text;
    s32 n;
    char *ap;
    if (D_004C2A58 == 0x80)
        return;
    ap = ((char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8));
    dst = &D_0058CC40[D_004C2A58];
    dst->x = a;
    dst->y = b;
    dst->attribute = c;
    text = dst->text;
    n = func_00122340(text, fmt, ap);
    text += n;
    *text = 0;
    D_004C2A58 = D_004C2A58 + 1;
}
