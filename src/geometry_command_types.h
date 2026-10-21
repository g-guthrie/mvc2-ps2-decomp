#ifndef MVC2_GEOMETRY_COMMAND_TYPES_H
#define MVC2_GEOMETRY_COMMAND_TYPES_H

/* Native format: byte count, byte origin adjustment, then count vertex IDs. */
typedef struct GeometryCommand1 { unsigned char count, origin_adjustment; unsigned char vertex[1]; } GeometryCommand1;
typedef struct GeometryCommand3 { unsigned char count, origin_adjustment; unsigned char vertex[3]; } GeometryCommand3;
typedef struct GeometryCommand4 { unsigned char count, origin_adjustment; unsigned char vertex[4]; } GeometryCommand4;
typedef struct GeometryCommand5 { unsigned char count, origin_adjustment; unsigned char vertex[5]; } GeometryCommand5;
typedef struct GeometryCommand6 { unsigned char count, origin_adjustment; unsigned char vertex[6]; } GeometryCommand6;
typedef struct GeometryCommand7 { unsigned char count, origin_adjustment; unsigned char vertex[7]; } GeometryCommand7;
typedef struct GeometryCommand10 { unsigned char count, origin_adjustment; unsigned char vertex[10]; } GeometryCommand10;

extern GeometryCommand1 gGeometryCommand_004B48E8;
extern GeometryCommand5 gGeometryCommand_004B48F0;
extern GeometryCommand5 gGeometryCommand_004B48F8;
extern GeometryCommand7 gGeometryCommand_004B4900;
extern GeometryCommand6 gGeometryCommand_004B4910;
extern GeometryCommand7 gGeometryCommand_004B4918;
extern GeometryCommand1 gGeometryCommand_004B4928;
extern GeometryCommand5 gGeometryCommand_004B4930;
extern GeometryCommand5 gGeometryCommand_004B4938;
extern GeometryCommand7 gGeometryCommand_004B4940;
extern GeometryCommand6 gGeometryCommand_004B4950;
extern GeometryCommand3 gGeometryCommand_004B4958;
extern GeometryCommand4 gGeometryCommand_004B4960;
extern GeometryCommand10 gGeometryCommand_004B4968;
extern GeometryCommand10 gGeometryCommand_004B4978;
extern GeometryCommand10 gGeometryCommand_004B4988;

#endif
