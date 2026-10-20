/*
 * Native-first reconstruction of the internal ADXT stream-start helper at
 * 0x00401640. Prior ADXT research consulted crowded-street/3s-decomp at
 * be9b9bc69dc19822a8eca9ce3e72ba560d5a3835 for interface/semantic context;
 * the C expression here was written from the retail MIPS instructions. This
 * is not a clean-room claim; see docs/ADXT_START_SJ_RECOVERY_20261020.md.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct SJObject SJObject;
typedef struct {
    u8 pad[0x14];
    void (*reset)(SJObject *);
} SJObjectVtable;
struct SJObject {
    SJObjectVtable *vtable;
};

typedef struct ADXT {
    s8 used;
    s8 stat;
    s8 pmode;
    s8 maxnch;
    void *sjd;
    void *stm;
    void *rna;
    void *sjf;
    void *sji;
    SJObject *sjo[2];
    u8 pad20[0x2C];
    s32 lpcnt;
    u8 pad50[0x20];
    s8 pstwait;
    s8 pstready;
    u8 pad72[0x1A];
    s32 lesct;
    s32 trpnsmpl;
    u8 pad94[8];
    u32 tvofst;
    u32 svcnt;
    u32 decofst;
} ADXT;

extern s32 D_004C22C4;
extern void func_003FF5D0(void *decoder, void *sj);
extern void func_003FF628(void *decoder);

void func_00401640(ADXT *adxt, void *sj)
{
    s32 i;
    for (i = 0; i < adxt->maxnch; i++) {
        adxt->sjo[i]->vtable->reset(adxt->sjo[i]);
    }
    func_003FF5D0(adxt->sjd, sj);
    adxt->sji = sj;
    func_003FF628(adxt->sjd);
    adxt->stat = 1;
    adxt->pstready = 0;
    adxt->lesct = 0x7FFFFFFF;
    adxt->trpnsmpl = -1;
    adxt->svcnt = D_004C22C4;
    adxt->tvofst = 0;
    adxt->decofst = 0;
    adxt->lpcnt = 0;
}
