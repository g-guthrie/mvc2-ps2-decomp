union StreamWord { unsigned int bits; float value; };
struct StreamTriple { union StreamWord word[3]; };
struct StreamHeader { union StreamWord header[6]; union StreamWord data[1]; };
extern union StreamWord *dat_0c2fb5b4,*dat_0c2fb5b8;
extern union StreamWord *dat_0c2fb5bc,*dat_0c2fb5c0;
extern int dat_0c2fb5c4,dat_0c2fb5c8,dat_0c2fb5cc;
int func_0c1d8ff8(struct StreamHeader *source,struct StreamHeader *destination)
{
    dat_0c2fb5b4=&source->data[0];
    dat_0c2fb5bc=&destination->data[0];
    dat_0c2fb5b8=dat_0c2fb5b4;
    dat_0c2fb5c0=dat_0c2fb5bc;
    dat_0c2fb5c4=0;
    return 0;
}
int func_0c1d901e(void)
{
    unsigned int flags;
    dat_0c2fb5b4=dat_0c2fb5b8;
    dat_0c2fb5bc=dat_0c2fb5c0;
    for (;;) {
        if (!dat_0c2fb5c4) {
            if (dat_0c2fb5b4->bits==0) return -1;
            if ((int)dat_0c2fb5b4->bits<0) {
                dat_0c2fb5b4+=20;
                dat_0c2fb5bc+=20;
            }
            flags=(dat_0c2fb5b4++)->bits;
            if (flags & 16) dat_0c2fb5cc=dat_0c2fb5b4->bits;
            else dat_0c2fb5cc=dat_0c2fb5b4->bits*3;
            dat_0c2fb5b4++;
            dat_0c2fb5bc+=2;
            dat_0c2fb5c4=1;
            dat_0c2fb5c8=0;
        }
        if (dat_0c2fb5b4->bits & 1) break;
        dat_0c2fb5b4+=2;
        dat_0c2fb5bc+=2;
        dat_0c2fb5b8=dat_0c2fb5b4;
        dat_0c2fb5c0=dat_0c2fb5bc;
        if (++dat_0c2fb5c8>=dat_0c2fb5cc) dat_0c2fb5c4=0;
    }
    dat_0c2fb5b8=dat_0c2fb5b4;
    dat_0c2fb5c0=dat_0c2fb5bc;
    dat_0c2fb5b8+=8;
    dat_0c2fb5c0+=8;
    if (++dat_0c2fb5c8>=dat_0c2fb5cc) dat_0c2fb5c4=0;
    return 0;
}
int func_0c1d9100(struct StreamTriple *out)
{
    *out=*(struct StreamTriple *)dat_0c2fb5b4;
    return 0;
}
int func_0c1d9114(struct StreamTriple *out)
{
    *out=*(struct StreamTriple *)(dat_0c2fb5b4+3);
    return 0;
}
int func_0c1d912a(float *id,float *value)
{
    *id=*(float *)((char *)dat_0c2fb5b4+24);
    *value=*(float *)((char *)dat_0c2fb5b4+28);
    return 0;
}
int func_0c1d9140(unsigned int *out)
{
    *out=*(unsigned int *)((char *)dat_0c2fb5b4+16);
    return 0;
}
int func_0c1d914c(const struct StreamTriple *in)
{
    *(struct StreamTriple *)dat_0c2fb5bc=*in;
    dat_0c2fb5bc->bits |= 1;
    return 0;
}
int func_0c1d9168(const struct StreamTriple *in)
{
    *(struct StreamTriple *)(dat_0c2fb5bc+3)=*in;
    return 0;
}
int func_0c1d917e(const float *id,const float *value)
{
    *(float *)((char *)dat_0c2fb5bc+24)=*id;
    *(float *)((char *)dat_0c2fb5bc+28)=*value;
    ((unsigned int *)dat_0c2fb5bc)[7] |= 1;
    return 0;
}
int func_0c1d919c(const unsigned int *in)
{
    ((unsigned int *)dat_0c2fb5bc)[4]=*in;
    return 0;
}
void func_0c1d91a8(union StreamWord *header)
{
    union StreamWord *cursor,*current;
    if ((int)header->bits>=0 && header[6].bits!=0) {
        cursor=header+6;
        do {
            current=cursor;
            current[2].bits = current[2].bits & 0xfffe7fff;
            cursor=(union StreamWord *)((char *)current+80);
            cursor=(union StreamWord *)((char *)cursor+current[19].bits);
        } while(cursor->bits!=0);
    }
}
void func_0c1d91d6(union StreamWord *source,int *count)
{
    *count=0;
    func_0c1d8ff8((struct StreamHeader *)source,(struct StreamHeader *)source);
    while(func_0c1d901e()==0) (*count)++;
}
void func_0c1d9204(union StreamWord *header,unsigned int key,unsigned int mode)
{
    union StreamWord *cursor;
    unsigned int packed;
    if ((int)header->bits>=0 && header[6].bits!=0) {
        packed=(key<<29)|(mode<<26);
        cursor=header+6;
        do {
            if (((cursor->bits>>24)&7)==2) cursor[2].bits=(cursor[2].bits&0x03ffffff)|packed;
            cursor=(union StreamWord *)((char *)cursor+80+cursor[19].bits);
        } while(cursor->bits!=0);
    }
}
