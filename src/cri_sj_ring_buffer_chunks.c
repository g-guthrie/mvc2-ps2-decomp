#include "cri_sj_ring_buffer_types.h"
#define SJ_MIN(a,b) ((a)<(b)?(a):(b))
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
void func_0040F7A0(SJ_OBJ *object,int line,int requested,SJCK *chunk)
{
    SJRBFRecord *p=(SJRBFRecord *)object;

    func_0040EFE0();
    if(line==0) {
        chunk->len=SJ_MIN(SJ_MIN(p->unk10,p->bsize-p->unk14+p->xsize),requested);
        chunk->data=p->buf+p->unk14;
        p->unk14=(p->unk14+chunk->len)%p->bsize;
        p->unk10-=chunk->len;
        p->unk28=(int)((unsigned int)p->unk28+(unsigned int)chunk->len);
    } else if(line==1) {
        chunk->len=SJ_MIN(SJ_MIN(p->unk0C,p->bsize-p->unk18+p->xsize),requested);
        chunk->data=p->buf+p->unk18;
        p->unk18=(p->unk18+chunk->len)%p->bsize;
        p->unk0C-=chunk->len;
        p->unk30=(int)((unsigned int)p->unk30+(unsigned int)chunk->len);
    } else {
        chunk->len=0;chunk->data=0;
        if(p->err_func)p->err_func(p->err_obj,-3);
    }
    func_0040EFF8();
}

void func_0040FA70(SJ_OBJ *object,int line,SJCK *chunk)
{
    SJRBFRecord *p=(SJRBFRecord *)object;
    int offset;
    if(chunk->len<=0 || chunk->data==0)return;
    func_0040EFE0();
    if(line==0) {
        offset=(p->unk14+p->bsize-chunk->len)%p->bsize;
        if(offset==((int)((unsigned int)chunk->data-(unsigned int)p->buf))%p->bsize){
            p->unk14=offset;
            p->unk10+=chunk->len;
        } else if(p->err_func)p->err_func(p->err_obj,-3);
        p->unk28=(int)((unsigned int)p->unk28-(unsigned int)chunk->len);
    } else if(line==1) {
        offset=(p->unk18+p->bsize-chunk->len)%p->bsize;
        if(offset==((int)((unsigned int)chunk->data-(unsigned int)p->buf))%p->bsize){
            p->unk18=offset;
            p->unk0C+=chunk->len;
        } else if(p->err_func)p->err_func(p->err_obj,-3);
        p->unk30=(int)((unsigned int)p->unk30-(unsigned int)chunk->len);
    } else {
        chunk->len=0;chunk->data=0;
        if(p->err_func)p->err_func(p->err_obj,-3);
    }
    func_0040EFF8();
}
