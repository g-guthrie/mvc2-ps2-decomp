#ifndef MVC2_SONY29_KERNEL_SEMAPHORE_CALLS_H
#define MVC2_SONY29_KERNEL_SEMAPHORE_CALLS_H

typedef struct SonyEeSemaParams {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    unsigned int attr;
    unsigned int option;
} SonyEeSemaParams;

/* Original PS2SDK kernel ABI: result is returned in V0. */
int func_00103DE0(SonyEeSemaParams *params);
int func_00103DF0(int semaphore_id);
int func_00103E00(int semaphore_id);
int func_00103E10(int semaphore_id);
int func_00103E20(int semaphore_id);

#endif
