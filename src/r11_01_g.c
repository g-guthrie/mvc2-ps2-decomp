/* func_00105858 (kernel printf core): Sony EE GCC 2.9 -O2 -G0 -ffunction-sections (exact).
   Build: cpp, EE29CC1, then rewrite the switch-table %hi/%lo($LNNN) to jtbl_004AB000 in the .s
   (tools/fix_switch_table.py only handles the lw $LNN form), then SN as -G0. */
typedef void (*putc_fn)(int);

extern putc_fn D_00438264;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_001056F0(double);

void func_00105858(char *fmt, long *ap)
{
    int locked;
    char buf[32];
    char *p;
    char *q;
    char *pad;
    int mod;
    int w;
    int c2;
    int c;
    unsigned long v;
    long sv;
    char *str;
    char *s;
    float f;

    locked = func_0010CA20();
    p = fmt;
    while (*p) {
        pad = 0;
        mod = 0;
        if (*p == '%') {
        pct:
            q = p + 1;
        again:
            p = q;
            c = (char)(*p - '0');
            if ((unsigned)c > 'x' - '0') goto range;
            switch (c) {
            case '0' - '0':
                w = q[1] - '0';
                c2 = q[2];
                if ((unsigned char)w < 10) {
                    if ((unsigned)(c2 - '0') < 10) {
                        { int t = w * 10 - '0'; w = t + c2; }
                        p = q + 2;
                        if (w >= 32) w = 31;
                    } else {
                        p = q + 1;
                    }
                    { char *t = buf + 31; pad = t - w; }
                    if (w <= 0) goto pct;
                    q = p + 1;
                fill:
                    buf[31 - w] = '0';
                    w--;
                    if (w > 0) goto fill;
                    goto again;
                }
                q++;
                goto again;
            case 'l' - '0':
                mod = 'l';
                q++;
                goto again;
            case 'h' - '0':
                mod = 'h';
                q++;
                goto again;
            case 'o' - '0':
                if (mod == 'l') { ap++; v = ap[-1]; }
                else if (mod == 'h') { ap++; v = *(unsigned short *)(ap - 1); }
                else { ap++; v = *(unsigned int *)(ap - 1); }
                p = buf + 31;
                *p = 0;
                if (v == 0) {
                    *--p = '0';
                    q++;
                } else {
                    q++;
                    do {
                        *--p = (v & 7) + '0';
                        v >>= 3;
                    } while (v);
                }
                if (pad && pad < p) p = pad;
                while (*p) D_00438264(*p++);
                break;
            case 'x' - '0':
                if (mod == 'l') { ap++; v = ap[-1]; }
                else if (mod == 'h') { ap++; v = *(unsigned short *)(ap - 1); }
                else { ap++; v = *(unsigned int *)(ap - 1); }
                p = buf + 31;
                *p = 0;
                if (v == 0) {
                    *--p = '0';
                    q++;
                } else {
                    q++;
                    do {
                        unsigned long d = v & 0xF;
                        if (d < 10) *--p = d + '0'; else *--p = d + 'a' - 10;
                        v >>= 4;
                    } while (v);
                }
                if (pad && pad < p) p = pad;
                while (*p) D_00438264(*p++);
                break;
            case 'd' - '0':
                if (mod == 'l') { ap++; sv = ap[-1]; }
                else if (mod == 'h') { ap++; sv = *(short *)(ap - 1); }
                else { ap++; sv = *(int *)(ap - 1); }
                p = buf + 31;
                *p = 0;
                if (sv == 0) {
                    *--p = '0';
                } else {
                    if (sv < 0) {
                        sv = -sv;
                        D_00438264('-');
                    }
                    if (sv != 0) {
                        q++;
                        do {
                            *--p = sv % 10 + '0';
                            sv /= 10;
                        } while (sv);
                        goto dpad;
                    }
                }
                q++;
            dpad:
                if (pad && pad < p) p = pad;
                while (*p) D_00438264(*p++);
                break;
            case 'u' - '0':
                if (mod == 'l') { ap++; v = ap[-1]; }
                else if (mod == 'h') { ap++; v = *(unsigned short *)(ap - 1); }
                else { ap++; v = *(unsigned int *)(ap - 1); }
                p = buf + 31;
                *p = 0;
                if (v == 0) {
                    *--p = '0';
                    q++;
                } else {
                    q++;
                    do {
                        *--p = v % 10 + '0';
                        v /= 10;
                    } while (v);
                }
                if (pad && pad < p) p = pad;
                while (*p) D_00438264(*p++);
                break;
            case 'e' - '0':
            case 'f' - '0':
                ap++; f = *(float *)(ap - 1);
                if (f == 0.0f) {
                    D_00438264('0');
                    q++;
                } else {
                    q++;
                    func_001056F0(f);
                }
                break;
            case 's' - '0':
                ap++; str = *(char **)(ap - 1);
                if (*str == 0) {
                    D_00438264('(');
                    q++;
                    D_00438264('n');
                    D_00438264('u');
                    D_00438264('l');
                    D_00438264('l');
                    D_00438264(')');
                } else {
                    s = str;
                    q++;
                    do D_00438264(*s++); while (*s);
                }
                break;
            case 'c' - '0':
                ap++; sv = *(char *)(ap - 1);
                D_00438264(sv);
                q++;
                break;
            default:
                goto deflt;
            }
            goto next;
        } else {
            D_00438264(*p);
            q = p + 1;
            goto next;
        }
    range:
        q = p + 1;
        goto next;
    deflt:
        q++;
    next:
        p = q;
    }
    if (locked) func_0010CA68();
}
