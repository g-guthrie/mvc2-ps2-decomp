typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00272FF0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
    }
}
