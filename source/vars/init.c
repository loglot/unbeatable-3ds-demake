
	srvInit();
	aptInit();
	hidInit();
gfxInitDefault();
consoleInit(GFX_BOTTOM, NULL);
C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
C2D_Prepare();
fsInit();
romfsInit();
    ndspInit();
	cwavUseEnvironment(CWAV_ENV_DSP);
	// gfxSet3D(true);