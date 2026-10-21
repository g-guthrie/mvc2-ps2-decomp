#ifndef MVC2_SCALE_PAIR_BLOCK_H
#define MVC2_SCALE_PAIR_BLOCK_H
typedef float f32;
typedef struct { f32 component_0; f32 component_1; } ScalePair;
typedef struct { ScalePair pair[8]; } ScalePairBlock;
#endif
