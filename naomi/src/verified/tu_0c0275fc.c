struct RelocationEntry_0275fc {
    int words0[2];
    int address;
    int word12;
};
extern int func_0c022ccc(int, struct RelocationEntry_0275fc *, int);

int func_0c0275fc(int id, struct RelocationEntry_0275fc *base)
{
    int result;
    int i;
    struct RelocationEntry_0275fc *entries = base;
    register int origin = (int)base;
    result = func_0c022ccc(id, base, 1);
    for (i = 0; entries[i].address > 0; i++)
        entries[i].address += origin;
    return result;
}

int func_0c02763a(int id, struct RelocationEntry_0275fc *base)
{
    int result;
    result = func_0c022ccc(id, base, 1);
    return result;
}
