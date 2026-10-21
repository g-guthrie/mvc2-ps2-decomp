typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Prefix used by the existing resource cursor getter. */
typedef struct A41B { s32 w0;u32 w4;s32 w8,wC;u16 h10,h12; } A41B;
typedef void (*SampleFn)(A41B *,u16,f32 *);
/* The iterator's native model-node data region is 0x24 bytes. */
typedef struct { A41B cursor;u32 reserved14;SampleFn read,write;u32 byte_count; } Sampler;
typedef char Sampler_size36[(sizeof(Sampler)==36)?1:-1];
extern void func_0041BAD0(A41B *);
extern u8 *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
extern s8 D_004F258D[];
extern u32 data_u32_0043DD50[3][4];
/* This signature matches the actual callback in func_00170E60.
 * Its constructor supplies context as the address of a saved player-selector word. */
void func_00131E20(u8 *first,u8 *second,s32 context) {
    Sampler *sampler;
    u32 i,*metric;
    f32 sample[12];
    func_0041BAD0((A41B *)first);
    metric=(u32 *)((u8 *)data_u32_0043DD50+((s32)D_004F258D[0x5b8u* *(const u32 *)(u32)context]<<4));
    sampler=(Sampler *)first;
    for(i=0;i<4;i++) {
        func_0041BBB0(&sampler->cursor);
        sampler->read(&sampler->cursor,sampler->cursor.h10,sample);
        sample[4]=(f32)((*metric>>16)&0xff);
        sample[5]=(f32)((*metric>>8)&0xff);
        sample[6]=(f32)*(u8 *)metric;
        sample[7]=128.0f;
        sampler->write(&sampler->cursor,sampler->cursor.h10,sample);
        metric++;
    }
    sampler->cursor.h12=0;sampler->cursor.h10=0;
    func_0041BB30(&sampler->cursor);
}
