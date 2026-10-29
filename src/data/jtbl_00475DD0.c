/* (Mvc2Address)0x... entries are literal words (no code reads them as addresses), not code labels. */
/* State tables of the owner-forwarding chain 003C3AE0 -> 003C3B00:
 * 003C3B00 dispatches the second table and 003C4140 the third,
 * each with (object, owner) where owner was loaded from object+0x18.
 * The four leading words address 0x001000F0 and have no dispatcher. */
typedef const unsigned char *Mvc2Address;
typedef void (*Mvc2OwnerByteCallback)(unsigned char *, unsigned char *);
extern void func_003C3B80(unsigned char *, unsigned char *);
extern void func_003C3DE0(unsigned char *, unsigned char *);
extern void func_003C4140(unsigned char *, unsigned char *);
extern void func_003C42C0(unsigned char *, unsigned char *);
extern void func_003C41C0(unsigned char *, unsigned char *);
extern void func_003C41F0(unsigned char *, unsigned char *);
extern void func_003C4260(unsigned char *, unsigned char *);

typedef struct {
    Mvc2Address unused[4];
    Mvc2OwnerByteCallback states[4];
    Mvc2OwnerByteCallback sub_states[3];
} OwnerStateTables;
const OwnerStateTables jtbl_00475DD0 = {{
    (Mvc2Address)0x001000F0u,
    (Mvc2Address)0x001000F0u,
    (Mvc2Address)0x001000F0u,
    (Mvc2Address)0x001000F0u,
}, {
    func_003C3B80,
    func_003C3DE0,
    func_003C4140,
    func_003C42C0,
}, {
    func_003C41C0,
    func_003C41F0,
    func_003C4260,
}};
