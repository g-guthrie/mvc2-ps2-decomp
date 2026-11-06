/* Complete SDK byte-order converter; trailing padding is excluded. */
#pragma section n2047fc
void func_0c2047fc(unsigned char *destination, const unsigned short *source)
{
int shift = 8;
unsigned char *cursor = destination;
unsigned char *end = destination + 2;
do{*cursor = *source >> shift; cursor++; shift-=8;}while(cursor<end);
}
