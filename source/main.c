
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
#include "./general-utills/utillities.c"
#include "./games/unbeat.c"
#include "./general-utills/previews.c"
char indexs[15];
char mode[30];
fsInit();
FILE *file = fopen("sdmc:/UNBEATABLE/songs.txt", "r");
char line[128];
		while (fgets(line, sizeof(line), file) != NULL) {
			// printf("File content: %s\n", line);
			if(line[0]=='['){
				// index++;
				// indexs=line[0];
				if(line[1] == 'M'){
					strcpy(mode,"Meta");
				}else{
					strcpy(mode,"UNDEFINED!!!");
				}
			}else{
				if (strcmp(mode,"Meta")==0){
					// index++;
					char* split=strtok(line,":");
					char statew[20];
					strcpy(statew,"null");
					while(split != NULL)
					{
						char* word=split;
						if(strcmp(statew,"null")==0){
							if(strcmp(word,"Title")==0){
								strcpy(statew,"Title");
								// printf(word);
							}
							if(strcmp(word,"Artist")==0){
								strcpy(statew,"Artist");
								// printf(word);
							}
							if(strcmp(word,"Creator")==0){
								strcpy(statew,"Author");
								// printf(word);
							}
						}else{
							if(strcmp(statew,"Title")==0){
								index+=1;
								strcpy(songs[0].title,word);
								printf(word);
							}
							if(strcmp(statew,"Artist")==0){
								index+=1;
								strcpy(songs[0].artist,word);
								printf(word);
							}
							if(strcmp(statew,"Author")==0){
								index+=1;
								strcpy(songs[0].author,word);
								printf(word);
							}
							strcpy(statew,"null");
						}
						
						// printf(word);
						split=strtok(NULL," ");
					}
				}
			}

		}
								//printf(songs);
		sprintf(indexs, "%d", index);
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
        C2D_TargetClear(top, YABlue);
		YACTRText(indexs,100, 50,1,UI);
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
