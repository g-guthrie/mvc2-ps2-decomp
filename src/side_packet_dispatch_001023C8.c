typedef unsigned char u8;

extern void func_00100908(const void *packet);
extern int func_00100D80(void *p);

int func_001023C8(void *p, int side)
{
    unsigned int right = (unsigned int)side & 1;
    int result;

    func_00100908((u8 *)p + right * 0x28);
    if (right) {
        result = func_00100D80((u8 *)p + 0x1C0);
        goto done;
    }
    result = func_00100D80((u8 *)p + 0x50);
done:
    return result;
}
