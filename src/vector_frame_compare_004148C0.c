typedef float f32;

extern volatile f32 D_004C2B28;

int func_004148C0(const f32 *a, const f32 *b, const f32 *c, f32 marker)
{
    if (a[0] != *(volatile f32 *)0x00632730) goto fail;
    if (a[1] != *(volatile f32 *)0x00632734) goto fail;
    if (a[2] != *(volatile f32 *)0x00632738) goto fail;
    if (b[0] != *(volatile f32 *)0x00632720) goto fail;
    if (b[1] != *(volatile f32 *)0x00632724) goto fail;
    if (b[2] != *(volatile f32 *)0x00632728) goto fail;
    if (c[0] != *(volatile f32 *)0x00632710) goto fail;
    if (c[1] != *(volatile f32 *)0x00632714) goto fail;
    if (c[2] != *(volatile f32 *)0x00632718) goto fail;
    if (marker != D_004C2B28) goto fail;
    return 1;
fail:
    return 0;
}
