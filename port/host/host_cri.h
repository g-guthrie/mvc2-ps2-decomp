/* Host CRI layer (port/host/cri.c): the disc and the ADXT hook. */
#ifndef PORT_HOST_CRI_H
#define PORT_HOST_CRI_H
#include "fs.h"

/* The frontend's ADX player (port/audio padx_*); NULL = status machine only. */
typedef struct HostAdxtOps {
    int (*start_afs)(int ptid, int fid);
    void (*stop)(void);
    int (*get_stat)(void);
    void (*set_out_vol)(int vol);
    void (*pause)(int sw);
    void (*set_mono)(int mono);
    void (*exec)(void);
} HostAdxtOps;
extern const HostAdxtOps *host_adxt_ops;

int host_disc_open(const char *iso_path);
int host_disc_open_source(FsSource src);
GameDisc *host_disc(void);
#endif
