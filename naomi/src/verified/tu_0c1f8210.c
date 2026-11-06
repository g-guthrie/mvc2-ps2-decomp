struct PackedSource20 {
 unsigned char pad0[4];unsigned int high,low;unsigned char pad12[4],bytes[4];
};
#pragma section N1f8210
void func_0c1f8210(struct PackedSource20 *source,unsigned char *out)
{
 out[0]=(source->high<<4)+source->low;
 out[1]=source->bytes[0];
 out[2]=source->bytes[1];
 out[3]=source->bytes[2];
 out[4]=source->bytes[3];
}
