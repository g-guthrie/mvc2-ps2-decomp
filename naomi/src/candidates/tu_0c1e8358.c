extern char dat_0c302e14[2][512];
extern char dat_0c2fc048[];
int func_0c1e8358(unsigned char n)
{
    register unsigned int limit=80;
char *p=dat_0c302e14[n];
unsigned int i=0;
int sum=0;
    do { sum+=*p++; } while(++i<limit);
    return (unsigned char)sum;
}
int func_0c1e8376(void)
{
    char *p=dat_0c2fc048;
    register unsigned int limit=75;
    register unsigned int i=0;
    register int sum=0;
    do { sum+=*p++; } while(++i<limit);
    return (unsigned char)sum;
}
