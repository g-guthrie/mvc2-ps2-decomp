/* (Mvc2Address)0x... entries are literal words (no code reads them as addresses), not code labels. */
typedef const unsigned char *Mvc2Address;
extern const unsigned char func_001D7DA0[];
extern const unsigned char func_001D7E50[];
extern void func_001D8000(unsigned char *,void *);
extern void func_001D8100(unsigned char *,void *);
extern const unsigned char func_001D8550[];
extern const unsigned char func_001D8570[];
extern void func_001D7E70(unsigned char *,void *);
typedef struct {
    Mvc2Address earlier[5];
    void (*release[3])(unsigned char *,void *);
} PartnerReleasePhaseTables;
const PartnerReleasePhaseTables jtbl_0044E68C = {{
    (Mvc2Address)0x00200008u,
    func_001D7DA0,
    func_001D7E50,
    func_001D8550,
    func_001D8570,
}, {
    func_001D7E70,
    func_001D8000,
    func_001D8100,
}};
