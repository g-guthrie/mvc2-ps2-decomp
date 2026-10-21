typedef struct Stream Stream;
typedef struct StreamVTable { void (*reserved[5])(void); void (*reset)(Stream *); } StreamVTable;
struct Stream { StreamVTable *vtable; };
typedef struct Audio { signed char fields0[2]; signed char mode; signed char fields3[5]; unsigned char *decoder; unsigned int fieldC; unsigned int field10; Stream *stream; unsigned char gap18[124]; void *work; } Audio;
extern const char D_004BC020[];
extern void func_003FB128(const char *);
extern void func_00400740(signed char *);
extern void func_004005F8(unsigned char *);
extern void func_0040D040(void *);
extern void func_004017E0(void *);
void func_00401868(void *owner)
{
    Audio *audio = owner;
    if (!audio) { func_003FB128(D_004BC020); return; }
    if (audio->decoder) {
        func_00400740((signed char *)audio->decoder);
        func_004005F8(audio->decoder);
        if (audio->stream) audio->stream->vtable->reset(audio->stream);
        audio->decoder = 0;
    }
    if (audio->mode == 4) {
        func_0040D040(audio->work);
        if (audio->stream) audio->stream->vtable->reset(audio->stream);
    }
    func_004017E0(audio);
}
