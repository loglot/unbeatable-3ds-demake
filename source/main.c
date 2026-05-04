
// WARN: this code is untested, and will probably not build correctly


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>
#include <c3d/texture.h>
#include <stdlib.h>
#include <c2d/base.h>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
#include "lodepng.h"



#define ICON_WIDTH 256
#define ICON_HEIGHT 256
#define TEX_SIZE 256

#define SCREEN_WIDTH   400
#define SCREEN_WIDTH_B 320
#define SCREEN_HEIGHT  240


//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

 bool loadPngImage(C2D_Image* image, const char* path) {
    //char path[128] = "sdmc:/22.png";
    //snprintf(path, sizeof(path), "/3ds/switch/icons/%016llX.png", titleId);

    unsigned char* pngData = NULL;
    unsigned width = 0, height = 0;
    unsigned error = lodepng_decode32_file(&pngData, &width, &height, path);
    
    if (error || pngData == NULL) {
        return false;
    }

    if (width != ICON_WIDTH || height != ICON_HEIGHT) {
        free(pngData);
        return false;
    }

    C3D_Tex* tex = (C3D_Tex*)linearAlloc(sizeof(C3D_Tex));
    Tex3DS_SubTexture* subtex = (Tex3DS_SubTexture*)linearAlloc(sizeof(Tex3DS_SubTexture));
    if (!tex || !subtex) {
        if (tex) linearFree(tex);
        if (subtex) linearFree(subtex);
        free(pngData);
        return false;
    }

  
    C3D_TexInit(tex, TEX_SIZE, TEX_SIZE, GPU_RGBA8);
    C3D_TexSetFilter(tex, GPU_LINEAR, GPU_LINEAR);
    tex->border = 0xFFFFFFFF;

    for (u32 y = 0; y < height; y++) {
        for (u32 x = 0; x < width; x++) {
            u32 dstPos = ((((y >> 3) * (TEX_SIZE >> 3) + (x >> 3)) << 6) +
                          ((x & 1) | ((y & 1) << 1) | ((x & 2) << 1) |
                           ((y & 2) << 2) | ((x & 4) << 2) | ((y & 4) << 3))) * 4;
            u32 srcPos = (y * width + x) * 4;
            u8* dst = (u8*)tex->data + dstPos;
      
            dst[0] = pngData[srcPos + 3]; // Alpha
            dst[1] = pngData[srcPos + 2]; // Blue
            dst[2] = pngData[srcPos + 1]; // Green
            dst[3] = pngData[srcPos + 0]; // Red
        }
    }

 
    *subtex = (Tex3DS_SubTexture){
        .width  = ICON_WIDTH,
        .height = ICON_HEIGHT,
        .left   = 0.0f,
        .top    = 1.0f,
        .right  = ICON_WIDTH / (float)TEX_SIZE,
        .bottom = 1.0f - (ICON_HEIGHT / (float)TEX_SIZE)
    };

    *image = (C2D_Image){ tex, subtex };
    free(pngData);
    return true;
}
gfxInitDefault();
// consoleInit(GFX_BOTTOM, NULL);
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
u32 supportcolor  = C2D_Color32(0x00, 0x00, 0x00, 0xFF);
u32 offgrey  = C2D_Color32(0xE0, 0xDE, 0xC9, 0xFF);
u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
u32 YAShadow   = C2D_Color32(0x33, 0x36, 0x3F, 0x5F);
int imgwid, imghei, imgch;
float targetScale=.8;
int animation=-1;
float scale=0;
int index = 0;
int pos=0;
int state=0;
float menuy=0;
struct song {
	char title[20];
	char author[20];
	char artist[20];
	char audio[20];
	char difficulty[20];
	char tags[50];
	char flavor[50];
	char level[4];
};
struct song songs[50];
    char indexs[15];
#include "./general-utills/utillities.c"
#include "./games/unbeat.c"
#include "./general-utills/previews.c"
#include "./general-utills/parser.c"
fsInit();

// songs[0] = parseSong("sdmc:/UNBEATABLE/1.txt");
songs[1] = parseSong("sdmc:/UNBEATABLE/1.txt");
songs[2] = parseSong("sdmc:/UNBEATABLE/2.txt");
songs[3] = parseSong("sdmc:/UNBEATABLE/3.txt");
songs[4] = parseSong("sdmc:/UNBEATABLE/4.txt");
songs[5] = parseSong("sdmc:/UNBEATABLE/5.txt");
songs[6] = parseSong("sdmc:/UNBEATABLE/6.txt");
songs[7] = parseSong("sdmc:/UNBEATABLE/7.txt");
songs[0] = parseSong("sdmc:/UNBEATABLE/8.txt");
int scount = 8;
// unsigned char *cover=stbi_load("sdmc:/UNBEATABLE/cover.png",&imgwid,&imghei,&imgch,4) ;

// C3D_Tex* tex = malloc(sizeof(C3D_Tex));
// C3D_TexInit(tex, imgwid, imghei, GPU_RGBA8);
// tex->border = 0;
// tex->active = true;

// // CITRO 2D SUCKS SO MUCH JUST LET ME DRAW THE IMAGE YOU STUPID LIBRARY

// C3D_TexUpload(tex, cover);
// stbi_image_free(cover);

C2D_Image image ;//= //{ {tex, NULL}, {0, 0, imgwid, imghei} };
loadPngImage(&image, "sdmc:/UNBEATABLE/cover.png");

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
	void drawSong(int x,int y, struct song s,bool sel){
		char temp[50];
		char lim[11];
		int aaa=0;
		strcpy(temp, "//");
		if(strlen(s.title)>10){
			//char target[11]; // 10 chars + 1 for null terminator '\0'
			snprintf(lim, sizeof(lim), "%.10s", s.title);
			// while (aaa<10){
			// 	lim[aaa]=s.title[aaa];
			// 	aaa++;
			// }
			// strcpy(lim,s.title);
			strcat(temp,lim);
			strcat(temp,"...");
		}else{
			strcat(temp,s.title);

		}
		float WID;
		float HEI;

		YACTRText(temp,x+10, y+5,.7,beatred);
		if(sel){

			C2D_TextGetDimensions(&Text, .7, .7, &WID, &HEI);
			C2D_DrawRectangle(
				x+5, y, .51, 
				WID+10,  HEI+10, supportcolor, supportcolor,supportcolor,supportcolor );
			betterText(temp,0,x+10, y+5,1,.7,.7,offwhite);
		}
		// YACTRText(temp,x+10, y+5,.7,offwhite);



		YACTRTextRight(s.level,x-5, y,1,beatred);
		YACTRTextRight(s.level,x-5, y+1,1,beatred);
		YACTRTextRight(s.level,x-5, y-1,1,beatred);
		YACTRTextRight(s.level,x-6, y,1,beatred);
		YACTRTextRight(s.level,x-4, y,1,beatred);
		YACTRTextRightSqu("LV",x-4, y-5,.5,.3,beatred);
		YACTRTextRightSqu("LV",x-5, y-5,.5,.3,beatred);
		YACTRTextRightSqu("LV",x-4, y-6,.5,.3,beatred);
		YACTRTextRightSqu(s.difficulty,x-4, y+25,.3,.3,beatred);

		// strcpy(temp, "By: ");
		// strcat(temp,s.artist);
		// YACTRText(temp,x+15, y+30,.5,beatred);

	}

    void drawBottom(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, offwhite);
        // C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
		C2D_DrawTriangle(
			190, 0, beatred, 
			190,  190, beatred,
			0, 190, beatred, .6);
		C2D_DrawRectangle(
			190, 0, .6, 
			300,  300, beatred, beatred,beatred,beatred );
		C2D_DrawRectangle(
			0, 190, .6, 
			300,  300, beatred, beatred,beatred,beatred );
		for(int i=0; i<scount;i++){
			drawSong(10,100+50*i-menuy-50*5, songs[i],false);		

		}
		betterText("UNBEATABLE!",C2D_AlignRight,SCREEN_WIDTH_B-10, 205,.7,1,1,offwhite);
		betterText("Press A!",C2D_AlignRight,SCREEN_WIDTH_B-10, 175,.7,1,1,offwhite);
		// YACTRText("UNBEATABLE!",80, 145,1,offwhite);
		// YACTRText("Press A!",100, 175,1,offwhite);
        C3D_FrameEnd(0);
	}
	void drawCurSong(struct song s){
		C2D_DrawRectangle(
			200, 50, .2, 
			150,  150,supportcolor, supportcolor,supportcolor,supportcolor);
		C2D_DrawImageAt(image, 200, 50, 0.5f, NULL,150/256.0,150/256.0);

		YACTRTextRightCusDep("Charted By:", SCREEN_WIDTH-5, SCREEN_HEIGHT-35,.5,offwhite,1);
		YACTRTextRightCusDep(s.author, SCREEN_WIDTH-5, SCREEN_HEIGHT-20,.5,offwhite,1);
		YACTRTextRightCusDep(s.tags, SCREEN_WIDTH-10, 70,.5,beatred,1);
		YACTRTextRightCusDep(s.flavor, SCREEN_WIDTH-10, 25,.5,offgrey,1);
		// YACTRText(s.audio, 5, SCREEN_HEIGHT-20,.5,beatred);
	}
    void drawTop(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);	
        C2D_SceneBegin(top);
        C2D_TargetClear(top, offwhite);
		C2D_DrawTriangle(
			SCREEN_WIDTH-150, SCREEN_HEIGHT, beatred, 
			SCREEN_WIDTH,  SCREEN_HEIGHT, beatred,
			SCREEN_WIDTH, SCREEN_HEIGHT-150, beatred, .6);	
		drawCurSong(songs[index]);	
		YACTRTextRightSqu("SONG", SCREEN_WIDTH-5, -30,3,2,offgrey);
		YACTRTextRightSqu("SELECT", SCREEN_WIDTH-100, SCREEN_HEIGHT-35,3,2,offgrey);
		drawSong(50,100+50*index-menuy, songs[index],true);		
		for(int i=0; i<scount;i++){
			drawSong(50,100+50*i-menuy, songs[i],false);		

		}
		menuy=(menuy+index*50)/2;
        C3D_FrameEnd(0);
	}
	void draw(){
		drawBottom();
		drawTop();
	}
	void tick(){

    	// hidScanInput();			
		touchPosition touch;
		hidTouchRead(&touch);

		u32 kDown = hidKeysDown();
		if (kDown & KEY_A/*||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)*/) {state=1;}
		if (kDown & KEY_DUP  )  {index--;}
		if (kDown & KEY_DDOWN ) {index++;}
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
