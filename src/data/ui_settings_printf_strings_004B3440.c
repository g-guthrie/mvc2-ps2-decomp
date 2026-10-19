/* Native calls at 001496E0 and 001496F0 select rows 12..19 and 38..41 of D_004B36E0; their pointers are forwarded as format strings to the existing formatter at 00122340. Only bytes through each NUL are credited. */
char gControllerUpLabel_004B34B0[18] = "^P  <           >";
char gControllerDownLabel_004B34D0[18] = "^O  <           >";
char gControllerRightLabel_004B34F0[18] = "^Q  <           >";
char gControllerLeftLabel_004B3510[18] = "^N  <           >";
char gVibrationSettingPrompt_004B3530[17] = "VIBRATE  <     >";
char gCommandSettingPrompt_004B3550[17] = "COMMAND <      >";
char gDefaultSettingsLabel_004B3570[17] = "DEFAULT SETTINGS";
char gExitLabel_004B3588[5] = "EXIT";
char gL1ButtonSettingPrompt_004B3660[17] = "L1 <           >";
char gL2ButtonSettingPrompt_004B3680[17] = "L2 <           >";
char gR1ButtonSettingPrompt_004B36A0[17] = "R1 <           >";
char gR2ButtonSettingPrompt_004B36C0[17] = "R2 <           >";
