/* (Mvc2Address)0x... entries are literal words (no code reads them as addresses), not code labels. */
typedef const unsigned char *Mvc2Address;
extern const unsigned char func_00400020[];
Mvc2Address const jtbl_00475ABC[2] = {
    func_00400020,
    (Mvc2Address)0x0040FFA0u,
};
