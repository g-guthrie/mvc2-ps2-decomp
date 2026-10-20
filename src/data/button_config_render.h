#ifndef MVC2_BUTTON_CONFIG_RENDER_H
#define MVC2_BUTTON_CONFIG_RENDER_H

/* Bytes 0, 1, and 3 supply renderer arguments; byte 2 is preserved. */
typedef struct ButtonConfigRenderRecord {
    unsigned char rendererArgs[4];
    const void *resource;
} ButtonConfigRenderRecord;

#endif
