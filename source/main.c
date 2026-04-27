
// WARN: this code is untested, and will probably not build correctly


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>



#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240


//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

gfxInitDefault();
consoleInit(GFX_BOTTOM, NULL);
C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
C2D_Prepare();
C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
u32 UI  = C2D_Color32(0x00, 0x00, 0x00, 0x5F);
u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);
u32 white  = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
u32 offwhite  = C2D_Color32(0xF7, 0xF7, 0xD8, 0xFF);
u32 beatred  = C2D_Color32(0xEB, 0x5A, 0x7F, 0xFF);
u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
u32 YAShadow   = C2D_Color32(0x33, 0x36, 0x3F, 0x5F);
float targetScale=.8;
int animation=-1;
float scale=0;
int index = 0;
int pos=0;
int state=0;
struct song {
	char title[20];
	char author[20];
	char artist[20];
};
struct song songs[50];
    char indexs[15];
#include "./general-utills/utillities.c"
#include "./games/unbeat.c"
#include "./general-utills/previews.c"
#include "./general-utills/parser.c"
fsInit();

songs[0] = parseSong("sdmc:/UNBEATABLE/songs.txt");
printSong(songs[0]);
printSong(songs[0]);
printSong(songs[0]);
// C2D_Text Text[2];
// C2D_Font font;
// C2D_TextBuf g_staticBuf;
 
	// Main loop
	
	// consoleInit(GFX_BOTTOM, NULL);
	// while (aptMainLoop())
	// {
	// 	u32 kDown = hidKeysDown();
	// 	if (kDown & KEY_START) break;
	// 	if (kDown & KEY_A) YAFG();
	// 	printf("\x1b[1;1HPress A to Start YAFG");
		
	// }
	void thistick(){

		u32 kDown = hidKeysDown();
		// if (kDown & KEY_START) break;
	}
	
	// consoleInit(GFX_BOTTOM, NULL);
	int time=0;

    void drawBottom(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, white);
        // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
		YACTRText("UNBEATABLE!",80, 145,1,UI);
		YACTRText("Press A!",100, 175,1,UI);
        C3D_FrameEnd(0);
	}
    void drawTop(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        C2D_TargetClear(top, offwhite);
		YACTRText(songs[0].title,100, 50,1,beatred);
        C3D_FrameEnd(0);
	}
	void draw(){
		// drawBottom();
		drawTop();
	}
	void tick(){

    	// hidScanInput();			
		touchPosition touch;
		hidTouchRead(&touch);

		u32 kDown = hidKeysDown();
		if (kDown & KEY_A/*||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)*/) {state=1;}
		// if (kDown & KEY_DLEFT  ||(touch.px<20&&touch.px>3))  {index--;}
		// if (kDown & KEY_DRIGHT ||(touch.px>300)) {index++;}
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
	}
	
while (aptMainLoop())
{
    	hidScanInput();			
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
			animation=0;
			state=1;
		}
		if(state==2) break;
		if(state==0){
			draw();
	        tick();
		}else if (state==1){
			rgTick();
		}
	// printf("\x1b[1;1HPress A to Start YAFG  ");
	// printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
}

	// // Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	fsExit();
	return 0;
}
