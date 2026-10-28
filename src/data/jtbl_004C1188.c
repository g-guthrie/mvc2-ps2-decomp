/* Entry 0 forwards (p, context); entry 1 takes only p. */
typedef void (*Mvc2Callback)();
extern void func_002EB850(unsigned char *, unsigned char *);
extern void func_002EBAE0(unsigned char *);
const Mvc2Callback jtbl_004C1188[2] = {
    func_002EB850,
    func_002EBAE0,
};
