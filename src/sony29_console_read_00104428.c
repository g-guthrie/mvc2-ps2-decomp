/* Native stdin read through the initialized debug console. */
extern int D_00438250;
extern int func_00105480(void);
extern int func_001053B0(void *,int);
int func_00104428(int channel, void *buffer, int length)
{
    if (channel == 0) {
        if (!D_00438250) {
            if (!func_00105480()) return -1;
            D_00438250 = 1;
        }
        return func_001053B0(buffer,length);
    }
    return -1;
}
