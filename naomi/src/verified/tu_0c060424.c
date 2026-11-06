#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern void func_0c043324(struct Actor*),func_0c0438ea(struct Actor*),func_0c0437b8(struct Actor*),func_0c02a0c4(struct Actor*,int,int);
void func_0c060424(struct Actor*a){switch(a->b7){case 0:func_0c02a026(a);if(a->b141&1){a->b141&=0xfe;a->b7++;if(!a->b1fc)a->f96=-25.7142849f;else a->f96=-32.1428566f;}break;case 1:{float stopped;func_0c02a026(a);stopped=0.0f;if(!a->b19e){if(a->f41c>a->f56){a->b7++;a->f56=a->f41c;a->b1f9=0;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c043324(a);func_0c02a0c4(a,1,3);}}else{a->f92=5.83333302f;if(a->b1d2)a->f92=-a->f92;a->f104=stopped;a->f96=15.0f;a->f108=-1.07142854f;a->b1d3=1;func_0c0438ea(a);}}break;case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}}
