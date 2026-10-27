typedef signed int s32;

extern void *func_0011D740(void *, const void *, unsigned int);

void func_00143CA0(void **arr, void *src, s32 count)
{
    s32 n = count - 1;
    s32 i;
    s32 j;

    func_0011D740(arr, src, count * 4);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            unsigned char *a = (unsigned char *)arr[j];
            unsigned char *b = (unsigned char *)arr[j + 1];
            if ((signed char)b[0x24] < (signed char)a[0x24]) {
                void *t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
