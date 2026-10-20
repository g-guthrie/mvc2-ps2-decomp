typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
extern f32 D_004F1FEC __attribute__((section(".bss")));
extern f32 D_004F1FF8 __attribute__((section(".bss")));
extern f32 func_00117078(f32);
extern void func_00126970(f32 *, f32 *);
extern void func_00126280(s32, s32);
extern void func_00126340(s32, s32);

void func_001254F0(void)
{
    f32 pExtra = func_00117078(*(f32 *)(D_004C25D4 + 0x34) - D_004F1FEC) - 200.0f;
    f32 qExtra = func_00117078(*(f32 *)(D_004C25D0 + 0x34) - D_004F1FEC) - 200.0f;
    pExtra = pExtra >= 0.0f ? pExtra : 0.0f;
    qExtra = qExtra >= 0.0f ? qExtra : 0.0f;

    if (func_00117078(*(f32 *)(D_004C25D4 + 0x34) - *(f32 *)(D_004C25D0 + 0x34)) > 400.0f) {
        D_004F1FEC = (*(f32 *)(D_004C25D4 + 0x34) + *(f32 *)(D_004C25D0 + 0x34)) / 2.0f;
        goto done;
    }
    if (pExtra < qExtra) goto qAdjust;
    if (pExtra <= 0.0f) goto done;
    if (D_004F1FEC < *(f32 *)(D_004C25D4 + 0x34)) D_004F1FEC += pExtra;
    else D_004F1FEC -= pExtra;
    goto done;
qAdjust:
    if (qExtra <= 0.0f) goto done;
    if (D_004F1FEC < *(f32 *)(D_004C25D0 + 0x34)) D_004F1FEC += qExtra;
    else D_004F1FEC -= qExtra;
done:
    func_00126970(&D_004F1FEC, &D_004F1FF8);
    D_004F1FF8 = D_004F1FEC;
    func_00126280(0, 8);
    func_00126340(0, 8);
}
