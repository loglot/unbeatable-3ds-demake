
// #include <citro2d.h>

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <stdbool.h>
#include <time.h>
srand(time(NULL));

// #include <3ds.h>
void rgDrawBottom(){
    
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(bottom);
    C2D_TargetClear(bottom, white);
    // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
    YACTRText("BEATABLE!",80, 145,1,UI);
    YACTRText("don't Press A!",100, 175,1,UI);
    C3D_FrameEnd(0);
}



int rgTick() {
    rgDrawBottom();

}