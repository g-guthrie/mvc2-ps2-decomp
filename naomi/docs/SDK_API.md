# SDK functions the game calls

Every Sega SDK function (above 0x0c1e9000) that game code calls or takes the address of, from a scan of reviewed retail code. `docs/sdk_api.json` holds one row per function: address, name, evidence, owning unit and reference count. A port replaces this layer; this is the interface it must provide.

| Evidence | Functions |
| --- | ---: |
| Linked from Sega's prebuilt libraries (exact; real name) | 104 |
| Instruction similarity >= 0.8 to a named library function | 33 |
| Similarity 0.6-0.8, or position between named neighbours of one module | 18 |
| Module known, function one of a short list | 16 |
| Unknown | 31 |
| **Total** | **202** |

Similarity and position names are identifications, not byte matches: retail links an older build of the AM2 NAOMI libraries (`libnaomik2`, `libam`, `nlstrip`, `nlmath`, ...) than the August 2000 SDK in `toolchain/naomi-sdk/`. Most-referenced (literal loads plus calls): `nlSin` (212), `nlRand` (152), `nlCos` (138).

## Not yet identified

| Address | References | Closest / candidates |
| --- | ---: | --- |
| 0xc1e9200 | 2 | closest nlaInitSystemNoBoot (0.414) |
| 0xc1e9260 | 45 | closest buSetPrintFunc (0.667) |
| 0xc1e9e80 | 8 | one of module nlsystem: nlSetShadingMode, nlSetUseSpecular, nlSetUseAlpha, nlSetFilterMode, nlSetBackColor, nlCreateVertexBuffer_clx16, nlInitLibrary0, nlInitLibrary, nlInitLibraryDC, nlSetVsyncCount, nlSetFogColor, nlSetFogVertexColor, nlSetFogTable, nlSetCullingMode, nlSetCullingVal |
| 0xc1ea060 | 2 | one of module nlsystem: nlSetShadingMode, nlSetUseSpecular, nlSetUseAlpha, nlSetFilterMode, nlSetBackColor, nlCreateVertexBuffer_clx16, nlInitLibrary0, nlInitLibrary, nlInitLibraryDC, nlSetVsyncCount, nlSetFogColor, nlSetFogVertexColor, nlSetFogTable, nlSetCullingMode, nlSetCullingVal |
| 0xc1ea460 | 2 | one of module nlsystem: nlVtxBufScanInit, nlVtxBufScan, nlSetUserTileClip, nlSetUserTileClipMode, nlFlushTileClip, nlChangeDisplayFilterMode, nlGetCurrentScanLine, nlSetEORFunction, nlSetEOVFunction, nlSetVSyncFunction, nlSetHSyncFunction, nlSetHsyncLine, nlSetTextureOverFunction, nlSetStripOverFunction, nl_system_config_init, nlSysSetTextureSize, nlSysUseLatency2V, nlSysUseLatency3V, nlSysSetDirectListTypeLatency2V, nlSysUseStripBuffer, nlSysCancelStripBuffer, nlSysNoWaitRenderingOver, nlSysWaitRenderingOver, nlSysCreatePunchBuffer, nlSysSetVertexBufferBaseAddress, nlCreateVertexBuffer_clx22, nlCreateVertexBuffer, nlSysTextureWaitDMA, nlSysTextureNoWaitDMA |
| 0xc1ea470 | 2 | one of module nlsystem: nlVtxBufScanInit, nlVtxBufScan, nlSetUserTileClip, nlSetUserTileClipMode, nlFlushTileClip, nlChangeDisplayFilterMode, nlGetCurrentScanLine, nlSetEORFunction, nlSetEOVFunction, nlSetVSyncFunction, nlSetHSyncFunction, nlSetHsyncLine, nlSetTextureOverFunction, nlSetStripOverFunction, nl_system_config_init, nlSysSetTextureSize, nlSysUseLatency2V, nlSysUseLatency3V, nlSysSetDirectListTypeLatency2V, nlSysUseStripBuffer, nlSysCancelStripBuffer, nlSysNoWaitRenderingOver, nlSysWaitRenderingOver, nlSysCreatePunchBuffer, nlSysSetVertexBufferBaseAddress, nlCreateVertexBuffer_clx22, nlCreateVertexBuffer, nlSysTextureWaitDMA, nlSysTextureNoWaitDMA |
| 0xc1ea530 | 2 | one of module nlsystem: nlVtxBufScanInit, nlVtxBufScan, nlSetUserTileClip, nlSetUserTileClipMode, nlFlushTileClip, nlChangeDisplayFilterMode, nlGetCurrentScanLine, nlSetEORFunction, nlSetEOVFunction, nlSetVSyncFunction, nlSetHSyncFunction, nlSetHsyncLine, nlSetTextureOverFunction, nlSetStripOverFunction, nl_system_config_init, nlSysSetTextureSize, nlSysUseLatency2V, nlSysUseLatency3V, nlSysSetDirectListTypeLatency2V, nlSysUseStripBuffer, nlSysCancelStripBuffer, nlSysNoWaitRenderingOver, nlSysWaitRenderingOver, nlSysCreatePunchBuffer, nlSysSetVertexBufferBaseAddress, nlCreateVertexBuffer_clx22, nlCreateVertexBuffer, nlSysTextureWaitDMA, nlSysTextureNoWaitDMA |
| 0xc1ea5e0 | 2 | one of module nlsystem: nlVtxBufScanInit, nlVtxBufScan, nlSetUserTileClip, nlSetUserTileClipMode, nlFlushTileClip, nlChangeDisplayFilterMode, nlGetCurrentScanLine, nlSetEORFunction, nlSetEOVFunction, nlSetVSyncFunction, nlSetHSyncFunction, nlSetHsyncLine, nlSetTextureOverFunction, nlSetStripOverFunction, nl_system_config_init, nlSysSetTextureSize, nlSysUseLatency2V, nlSysUseLatency3V, nlSysSetDirectListTypeLatency2V, nlSysUseStripBuffer, nlSysCancelStripBuffer, nlSysNoWaitRenderingOver, nlSysWaitRenderingOver, nlSysCreatePunchBuffer, nlSysSetVertexBufferBaseAddress, nlCreateVertexBuffer_clx22, nlCreateVertexBuffer, nlSysTextureWaitDMA, nlSysTextureNoWaitDMA |
| 0xc1eaa20 | 2 | one of module nlsystem: nlVtxBufScanInit, nlVtxBufScan, nlSetUserTileClip, nlSetUserTileClipMode, nlFlushTileClip, nlChangeDisplayFilterMode, nlGetCurrentScanLine, nlSetEORFunction, nlSetEOVFunction, nlSetVSyncFunction, nlSetHSyncFunction, nlSetHsyncLine, nlSetTextureOverFunction, nlSetStripOverFunction, nl_system_config_init, nlSysSetTextureSize, nlSysUseLatency2V, nlSysUseLatency3V, nlSysSetDirectListTypeLatency2V, nlSysUseStripBuffer, nlSysCancelStripBuffer, nlSysNoWaitRenderingOver, nlSysWaitRenderingOver, nlSysCreatePunchBuffer, nlSysSetVertexBufferBaseAddress, nlCreateVertexBuffer_clx22, nlCreateVertexBuffer, nlSysTextureWaitDMA, nlSysTextureNoWaitDMA |
| 0xc1eb070 | 2 | closest buRemount (1.0) |
| 0xc1eb090 | 2 | closest ovMdlEntryTbl (0.2) |
| 0xc1ebc70 | 20 | closest fhFmReadExec (0.273) |
| 0xc1ec0e0 | 9 | one of module nlmath: nlCosec, nlCosf, nlCosh, nlCot, nlExp, nlFloor, nlFraction, nlInvertAbsSqrt, nlInvertSqrt, nlLdexpf, nlLog, nlLog10, nlLog2, nlPow |
| 0xc1ec580 | 4 | closest nlCosh (0.305) |
| 0xc1ef190 | 8 | one of module nlproj: nlPerspective, nlPerspectiveX, nlPerspective_L, nlPerspectiveX_L |
| 0xc1ef410 | 6 | one of module nlproj: nlPerspective, nlPerspectiveX, nlPerspective_L, nlPerspectiveX_L |
| 0xc1f0084 | 2 | closest wsBufGetWrPos (0.353) |
| 0xc1f0170 | 6 | closest buSetPrintFunc (0.667) |
| 0xc1f0410 | 4 | closest vmsfs_c_fiber1 (1.0) |
| 0xc1f0500 | 5 | closest buDisableServer (0.509) |
| 0xc1f2b20 | 2 | closest cmd_seeksec (0.258) |
| 0xc1f2cb0 | 9 | closest gdFsSearchName (0.308) |
| 0xc1f2df0 | 2 | closest nlDispStripTrnslX (0.387) |
| 0xc1f2f50 | 2 | closest wsSetSubcommand (0.459) |
| 0xc1f30c0 | 6 | closest buFbrExit (0.3) |
| 0xc1f31c0 | 2 | closest ufGetFreeBlock (0.333) |
| 0xc1f3240 | 11 | closest mpdrv_swapmode (0.374) |
| 0xc1f3340 | 12 | closest pdTmrSetTimeCallback (0.282) |
| 0xc1f35d0 | 3 | closest gdFsExecServerG (0.293) |
| 0xc1f3870 | 2 | closest vmsio_exit (0.8) |
| 0xc1f4570 | 2 | closest syTmrInt1Set (1.0) |
| 0xc1f45f0 | 2 | closest buSetPrintFunc (0.667) |
| 0xc1f7430 | 2 | closest syBtFntGetAddr (0.375) |
| 0xc1f8390 | 2 | one of module nlam: nlaCheckWaitROMDMA, nlaGetROMCRC, nlaLoadBootService, nlaLoadBootServiceDebug, nlaInitCreditData, nlaCredirServiceModeChange, nlaCreditProcess, nlaGetTestModeCount, nlaSetTestModeCount, nlaJumpGameMode, nlaJumpTestMode, nlaJumpGameTestMode, nlaGetBootFuncitonAddress, nlaJumpMultiGame, nlaLoadProgramMultiSlave, nlaGetSerialID, nlaGetMemoryDeviceInfo, nlaVersionInfo, nlaCreditConfForce, nlaSetSystemFlagForce, nlaGetSystemFlag, nlaCheckReleaseBootROM, nlaGetTotalTime, nlaInitSystemBoot, nlaInitSystemSimpleBoot |
| 0xc1f8a00 | 2 | one of module nlam: nlaGetCreditConf, nlaGetCreditData |
| 0xc1f8bb0 | 3 | one of module nlam: nlaGetCreditSound, nlaChangeCreditSequence, nlaCheckCreditEnough, nlaUpdateEEPROM, nlaUpdateEEPROMBootDefault, nlaGetBootID, nlaGetBackupData, nlaBackupSystemDataClear, nlaBackupClear, nlaInitUserBackup, nlaInitUserEEPROM |
| 0xc1f8bd0 | 2 | one of module nlam: nlaGetCreditSound, nlaChangeCreditSequence, nlaCheckCreditEnough, nlaUpdateEEPROM, nlaUpdateEEPROMBootDefault, nlaGetBootID, nlaGetBackupData, nlaBackupSystemDataClear, nlaBackupClear, nlaInitUserBackup, nlaInitUserEEPROM |
| 0xc1f8e10 | 4 | one of module nlam: nlaGetCreditSound, nlaChangeCreditSequence, nlaCheckCreditEnough, nlaUpdateEEPROM, nlaUpdateEEPROMBootDefault, nlaGetBootID, nlaGetBackupData, nlaBackupSystemDataClear, nlaBackupClear, nlaInitUserBackup, nlaInitUserEEPROM |
| 0xc1f8ec0 | 2 | one of module nlam: nlaGetCreditSound, nlaChangeCreditSequence, nlaCheckCreditEnough, nlaUpdateEEPROM, nlaUpdateEEPROMBootDefault, nlaGetBootID, nlaGetBackupData, nlaBackupSystemDataClear, nlaBackupClear, nlaInitUserBackup, nlaInitUserEEPROM |
| 0xc1f8f60 | 6 | closest nlBlurInit (0.237) |
| 0xc1f9170 | 2 | closest vmsio_init (0.75) |
| 0xc1f92e0 | 2 | closest nlaJAMMACreditInit (0.581) |
| 0xc1fb930 | 2 | closest syFbrSetIntStack (0.5) |
| 0xc1fb940 | 4 | closest vmsfs_fread (0.197) |
| 0xc206566 | 2 | closest syTmrGetCount (1.0) |
| 0xc206570 | 2 | closest syTmrDiffCount (1.0) |
| 0xc206818 | 1 | closest syTmrGetCount (1.0) |
