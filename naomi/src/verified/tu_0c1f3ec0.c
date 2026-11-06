struct PackedWord34 {unsigned char header[34];unsigned short packed;};
#pragma section N1f3ec0
void func_0c1f3ec0(struct PackedWord34 *block,short high,int low)
{
 unsigned short *packed=&block->packed;
 *packed=((unsigned int)(int)high<<11)|(unsigned int)low;
}
