#ifndef MVC2_LAUNCH_RECORD_H
#define MVC2_LAUNCH_RECORD_H
/* Native 16-byte records used by the launch solver and landing update. */
typedef struct {
    signed short x, y, targetX, targetY;
    float velocityY;
    signed short phase;
    signed char layer;
    unsigned char frame;
} LaunchRecord;
typedef char LaunchRecordSize[sizeof(LaunchRecord) == 16 ? 1 : -1];
extern const LaunchRecord D_0044B570[];
#endif
