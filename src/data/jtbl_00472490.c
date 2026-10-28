/* State callbacks for 00396E30, two four-entry halves indexed by p[4].
 * The first half receives (actor, owner from actor+0x18, work at actor+0x88);
 * the second receives (actor, work, owner work at owner+0x88). */
typedef void (*Mvc2WorkCallback)(unsigned char *, unsigned char *, unsigned char *);
extern void func_00397030(unsigned char *, unsigned char *, unsigned char *);
extern void func_00397140(unsigned char *, unsigned char *, unsigned char *);
extern void func_003972B0(unsigned char *, unsigned char *, unsigned char *);
extern void func_003972C0(unsigned char *, unsigned char *, unsigned char *);
extern void func_003972D0(unsigned char *, unsigned char *, unsigned char *);
extern void func_003973F0(unsigned char *, unsigned char *, unsigned char *);
extern void func_00397560(unsigned char *, unsigned char *, unsigned char *);
extern void func_00397570(unsigned char *, unsigned char *, unsigned char *);
typedef struct {
    Mvc2WorkCallback owner_half[4];
    Mvc2WorkCallback work_half[4];
} WorkStateTables;
const WorkStateTables jtbl_00472490 = {{
    func_00397030,
    func_00397140,
    func_003972B0,
    func_003972C0,
}, {
    func_003972D0,
    func_003973F0,
    func_00397560,
    func_00397570,
}};
