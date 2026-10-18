extern void func_00104630(void *, void *);
extern void func_00104770(void *, void *);

void func_00104758(unsigned int first, unsigned int second)
{
    func_00104630((void *)(first & 0xFFFFFFC0), (void *)(second & 0xFFFFFFC0));
}

void func_00104898(unsigned int first, unsigned int second)
{
    func_00104770((void *)(first & 0xFFFFFFC0), (void *)(second & 0xFFFFFFC0));
}
