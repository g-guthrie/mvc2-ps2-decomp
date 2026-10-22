typedef int s32;
typedef unsigned int u32;
extern unsigned char D_00634380[];
extern void func_00105628(void);

/* Init-once state: word 0 is set to 1 by func_001043A8/func_00104428 after func_00105480
 * succeeds; word 1 points at the end of the data image; word 5 is a handler pointer. */
typedef struct {
    s32 init_flag;
    unsigned char *tail_ptr;
    u32 reserved_08[3];
    void (*handler_14)(void);
    u32 reserved_18[4];
} data_raw_00438250_t;
typedef char data_raw_00438250_size_check[(sizeof(data_raw_00438250_t) == 40) ? 1 : -1];

data_raw_00438250_t data_raw_00438250 = {
    0,
    D_00634380,
    { 0, 0, 0 },
    func_00105628,
    { 0, 0, 0, 0 },
};
