
// #include <citro2d.h>

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <stdbool.h>
#include <time.h>
srand(time(NULL));
int beatposy=140;
int beatvely=0;

C2D_Image RG_SIL_SINGLE ;//= //{ {tex, NULL}, {0, 0, imgwid, imghei} };
loadPngImage(&RG_SIL_SINGLE, "romfs:/img/silence.png");
void rgDrawBottom(){
    
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(bottom);
    C2D_TargetClear(bottom, YAOL);
    // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
    // YACTRText("rhythm game test zone",80, 145,1,UI);
		C2D_DrawRectangle(
			0, 0, .6, 
			500,  105, beatred, beatred,beatred,beatred );
		C2D_DrawRectangle(
			0, 125, .6, 
			500,  130, quaverblue,quaverblue,quaverblue,quaverblue);
    C2D_DrawCircleSolid(160, 120, 1, 75, YAOL);
    C2D_DrawCircleSolid(160, 120, 1, 55, white);
    C3D_FrameEnd(0);
}
void rgDrawTop(){
    
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(top);
    C2D_TargetClear(top, YAOL);
    // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
    C2D_DrawCircleSolid(150, 70, 0, 15, white);
    C2D_DrawCircleSolid(150, 140, 0, 15, white);
    C2D_DrawCircleSolid(250, 70, 0, 15, white);
    C2D_DrawCircleSolid(250, 140, 0, 15, white);
		C2D_DrawImageAt(RG_SIL_SINGLE, 300, 50, 0.5f, NULL,1,1);
		C2D_DrawImageAt(RG_SIL_SINGLE, 300, 120, 0.5f, NULL,1,1);
		C2D_DrawImageAt(RG_SIL_SINGLE, 50, 50, 0.5f, NULL,-1,1);
		C2D_DrawImageAt(RG_SIL_SINGLE, 50, 120, 0.5f, NULL,-1,1);
    C2D_DrawCircleSolid(200, beatposy, 0, 20, white);
	u32 kDown = hidKeysDown();
	if (kDown & (KEY_A | KEY_B | KEY_X | KEY_Y)) 
    {
        beatposy=80;
        beatvely=-5;
    }
    else{ 
        if (beatposy<140){
            beatposy+=beatvely;
            beatvely++;
        } if(beatposy>140){
            beatposy=140;
        }
    }
	if (kDown & (KEY_LEFT | KEY_RIGHT | KEY_DOWN | KEY_UP)) 
    {
        beatposy=140;
        // beatvely=-5;
    }
    C3D_FrameEnd(0);
}



void rgTick() {
    rgDrawBottom();
    rgDrawTop();
}