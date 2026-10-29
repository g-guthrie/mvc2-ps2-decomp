/* Render hooks: the frontend (port/host/fe) binds the port's GL renderer. */
#ifndef PORT_HOST_RENDER_H
#define PORT_HOST_RENDER_H
#include <stdint.h>
typedef struct HostRenderOps {
    int (*sprite_tex)(const void *v);   /* func_003DF490 */
    int (*tri_tex)(const void *v);      /* func_003DF0C0 */
    int (*tri)(const void *v);          /* func_003DEE00 */
    int (*quad_tex)(const void *v);     /* func_00420BF0 */
    int (*fill)(int mode, uint32_t argb); /* func_003ED1C0 */
    int (*state)(int id, uintptr_t v);  /* func_003DF850 (after the game's own) */
} HostRenderOps;
extern const HostRenderOps *host_render_ops;
#endif
