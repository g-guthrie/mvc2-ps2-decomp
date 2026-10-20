typedef void (*RuntimeAnimationCallback)();

/* Native code at 0041C484, 0041C584/58C/590, and 0041CA2C writes, reloads,
 * and indirect-calls this one-slot code pointer. Its initial ROM value is
 * null. The next independently cataloged data object begins at 0043CD10. */
RuntimeAnimationCallback data_callback_slot_0043CD0C[1] = { 0 };
