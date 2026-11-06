/* mpdrv lock pointer: the word every mpdrv entry loads from its pool, then
   dereferences and claims with TAS.B (released with a byte store of 0). */
extern unsigned char dat_0c220044[];

#pragma section n1ff040
unsigned char *const ptr_0c220040 = dat_0c220044;
