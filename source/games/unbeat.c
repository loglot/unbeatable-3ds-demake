
// #include <citro2d.h>

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <stdbool.h>
#include <time.h>
srand(time(NULL));
int beatposy=140;
int beatvely=0;

void rgDrawBottom(){
    
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(bottom);
    C2D_TargetClear(bottom, white);
    // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
    YACTRText("BEATABLE!",80, 145,1,UI);
    YACTRText("don't Press A!",100, 175,1,UI);
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
    C2D_DrawCircleSolid(200, beatposy, 0, 20, white);
	u32 kDown = hidKeysDown();
	if (kDown & KEY_A/*||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)*/) 
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
	if (kDown & KEY_LEFT/*||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)*/) 
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