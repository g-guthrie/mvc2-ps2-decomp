#include "cri_sj_ring_buffer_types.h"
#define SJ_MIN(a,b) ((a)<(b)?(a):(b))
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
extern void *memcpy(void *, const void *, unsigned int);

void func_0040F910(SJ_OBJ *object,int line,SJCK *chunk)
{
    SJRBFRecord *p=(SJRBFRecord *)object;
    int off;
    int n;

    if(chunk->len<=0 || chunk->data==0)return;
    func_0040EFE0();
    if(line==1) {
        p->unk0C+=chunk->len;
        off=(int)((unsigned int)chunk->data-(unsigned int)p->buf);
        if(off<p->xsize)
            memcpy(p->buf+(p->bsize+off),chunk->data,SJ_MIN(chunk->len,p->xsize-off));
        off=(int)((unsigned int)chunk->data-(unsigned int)p->buf)+chunk->len;
        if(p->bsize<off){
            n=SJ_MIN(chunk->len,off-p->bsize);
            memcpy(p->buf,p->buf+(off-n),n);
        }
        p->unk34=(int)((unsigned int)p->unk34+(unsigned int)chunk->len);
    } else if(line==0) {
        p->unk10+=chunk->len;
        p->unk2C=(int)((unsigned int)p->unk2C+(unsigned int)chunk->len);
    } else {
        chunk->len=0;chunk->data=0;
        if(p->err_func)p->err_func(p->err_obj,-3);
    }
    func_0040EFF8();
}
