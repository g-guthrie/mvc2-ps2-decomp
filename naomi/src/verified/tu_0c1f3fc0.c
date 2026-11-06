struct ColorQuad {unsigned char x0,x1,x2,packed;};
struct ColorBlock {unsigned char pad48[48];struct ColorQuad quad[4];};
#pragma section N1f3fc0
void func_0c1f3fc0(struct ColorBlock *block,int value)
{
 unsigned char *p=&block->quad[0].x0;
 register unsigned int count=4;
 do{*p=value;p+=4;}while(--count);
}
