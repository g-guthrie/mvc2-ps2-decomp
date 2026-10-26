/* The native dispatcher forwards actor and owner to all seven callbacks. */
typedef void (*InheritedActionCallback)(unsigned char *,unsigned char *);
extern void func_003A50E0(unsigned char *,unsigned char *);
extern void func_003A5220(unsigned char *,unsigned char *);
extern void func_003A58E0(unsigned char *,unsigned char *);
extern void func_003A5920(unsigned char *,unsigned char *);
extern void func_003A53A0(unsigned char *,unsigned char *);
extern void func_003A53E0(unsigned char *,unsigned char *);
extern void func_003A5460(unsigned char *,unsigned char *);
const InheritedActionCallback jtbl_00472D60[7] = {
    func_003A50E0,
    func_003A5220,
    func_003A58E0,
    func_003A5920,
    func_003A53A0,
    func_003A53E0,
    func_003A5460,
};
