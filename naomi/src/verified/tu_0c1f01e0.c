/* SDK initialization wrapper: complete 0c1f01e0..0c1f0234 unit.
 * Six calls including tail call; 52 code bytes and 32 literal bytes.
 * Alignment padding at 0c1f0234..0c1f0240 remains in its data owner. */
extern void func_0c1ed5d0(void *);
extern void func_0c1f01a0(void *);
extern void func_0c1ee000(void *);
extern void func_0c1edcb0(void *);
extern char dat_0c33f988[];
extern char dat_0c33f860[];
extern char dat_0c33f908[];
extern char dat_0c33f948[];
void func_0c1f01e0(void)
{
    char *context = dat_0c33f988;
    func_0c1ed5d0(context);
    func_0c1f01a0(dat_0c33f860);
    func_0c1ee000(context);
    func_0c1ed5d0(dat_0c33f908);
    func_0c1ed5d0(dat_0c33f948);
    func_0c1edcb0(context);
}
