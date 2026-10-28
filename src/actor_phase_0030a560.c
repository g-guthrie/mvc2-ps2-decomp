/* Same phase-reset body as func_0030A2D0 (src/actor_scale_animation_updates.c),
 * then tail-calls func_0030A590 (src/actor_event_animation_phase_0030a590.c). */
typedef unsigned char u8;
typedef float f32;
extern u8 *D_004C28DC __attribute__((section(".sdata")));
extern void func_0030A590(u8 *);
void func_0030A560(u8 *p) {
 p[6]++; D_004C28DC[8]=0;
 *(f32 *)(p+0x5c)=0.0f; *(f32 *)(p+0x60)=0.0f;
 *(f32 *)(p+0x68)=0.0f; *(f32 *)(p+0x6c)=0.0f;
 func_0030A590(p);
}
