
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>

C2D_Text Text;
C2D_Font font;
C2D_TextBuf g_staticBuf;
float scaleX = 1;
float scaleY = 1;

void textSetup(u32 fon, char input[30]){
		g_staticBuf  = C2D_TextBufNew(4096);
		font = C2D_FontLoadSystem(fon);
		C2D_TextFontParse(&Text, font, g_staticBuf, input);
		C2D_TextOptimize(&Text);

}
void textEnd(){

        C2D_TextBufDelete(g_staticBuf);
        C2D_FontFree(font);
}
void YACTRText(char input[30], float x, float y, float size,u32 color){

		textSetup(CFG_REGION_USA, input);
		C2D_DrawText(&Text, C2D_WithColor, x, y, 0.5f, size, size,color);
		textEnd();
}
void YACTRTextRight(char input[30], float x, float y, float size,u32 color){

		textSetup(CFG_REGION_USA, input);
		C2D_DrawText(&Text, C2D_WithColor|C2D_AlignRight, x, y, .5, size, size,color);
		textEnd();
}
void YACTRTextRightCusDep(char input[30], float x, float y, float size,u32 color, float depth){

		textSetup(CFG_REGION_USA, input);
		C2D_DrawText(&Text, C2D_WithColor|C2D_AlignRight, x, y, depth, size, size,color);
		textEnd();
}
void YACTRTextRightSqu(char input[30], float x, float y, float size,float sizet,u32 color){

		textSetup(CFG_REGION_USA, input);
		C2D_DrawText(&Text, C2D_WithColor|C2D_AlignRight, x, y, 0.5f, size, sizet,color);
		textEnd();
}
void betterText(char input[30],u32 flags, float x, float y, float d, float size,float sizet,u32 color){

		textSetup(CFG_REGION_USA, input);
		C2D_DrawText(&Text, C2D_WithColor|flags, x, y, d, size, sizet,color);
		textEnd();
}
void DrawRect(int x, int y, int width, int height, u32 color, int depth){
	C2D_DrawRectSolid(x*scaleX, y*scaleY, depth, width*scaleX, height*scaleY, color);
}
void DrawCirc(int x, int y, int r, u32 color, int depth){
	C2D_DrawEllipseSolid((x-r)*scaleX, (y-r)*scaleY, 0, (r*2)*scaleX, (r*2)*scaleY, color);
}