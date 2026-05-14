
// WARN: this code is untested, and will probably not build correctly


#include "./vars/head.c"

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

#include "./vars/include.c"

C2D_Image image ;//= //{ {tex, NULL}, {0, 0, imgwid, imghei} };
loadPngImage(&image, "sdmc:/UNBEATABLE/3/cover.png");

printSong(songs[0]);
	void thistick(){

		u32 kDown = hidKeysDown();
		// if (kDown & KEY_START) break;
	}
	// consoleInit(GFX_BOTTOM, NULL);
	int time=0;// Example freeing sequence
void FreeCitro2DImage(C2D_Image* image) {
    if (image->tex) {
        C3D_TexDelete(image->tex); // Deletes the GPU texture
        // free(image->tex);          // Free the C3D_Tex struct if you used malloc
    }
}

	void changeImg(char *loc){
		char place [50];
		strcpy(place, "sdmc:/UNBEATABLE/");
		strcat(place, loc);
		printf(place);
		printf("\n\n");
		printf(loc);
		printf("\n\n");
		FreeCitro2DImage(&image);
		
		loadPngImage(&image, place);
	}
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
	void renderList(float x,float y){

		for(int z=0; z<3;z++){
			for(int i=0; i<scount;i++){
				if(y+50*i-menuy+(50*(z-1)*scount)>-20&&100+50*i-menuy+(50*(z-1)*scount)<420){

					drawSong(x,y+50*i-menuy+(50*(z-1)*scount), songs[i],false);		

				}
			}
		}
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
		renderList(10-(250*animation),(100-50*5));		
		drawInfoSelect();
		betterText("UNBEATABLE!",C2D_AlignRight,SCREEN_WIDTH_B-10, 205+100-(100*animation),.7,1,1,offwhite);
		betterText("UNBEATABLE!",C2D_AlignRight,SCREEN_WIDTH_B-10, 205+(100*animation),.7,1,1,offwhite);
		betterText("START! [A]",C2D_AlignRight,SCREEN_WIDTH_B-10, 175+(100*animation),.7,1,1,offwhite);
		betterText("INFO [B]",C2D_AlignRight,SCREEN_WIDTH_B-10, 10-(35*animation),.7,.5,.5,offwhite);
		betterText("SONG SELECT [B]",C2D_AlignRight,SCREEN_WIDTH_B-10, 10-35-(35*(-animation)),.7,.5,.5,offwhite);
		// YACTRText("UNBEATABLE!",80, 145,1,offwhite);
		// YACTRText("Press A!",100, 175,1,offwhite);
		C2D_DrawRectangle(
			0, 240-(250*anims[0]), 1, 
			5000,  (250*anims[0]),supportcolor, supportcolor,supportcolor,supportcolor);
        C3D_FrameEnd(0);
	}
	void drawCurSong(struct song s){
		C2D_DrawRectangle(
			200+(250*animation), 50, .2, 
			150,  150,supportcolor, supportcolor,supportcolor,supportcolor);
		C2D_DrawRectangle(
			350+(250*animation), 50, .4, 
			150,  150,offwhite, offwhite,offwhite,offwhite);
		C2D_DrawRectangle(
			200+(250*animation), 200, .4, 
			150,  150,offwhite, offwhite,offwhite,offwhite);
		C2D_DrawImageAt(image, 200+(250*animation), 50, 0.3f, NULL,150.0/imgwidt,150.0/imgheit);
		if(imgwidt>1024){
			betterText("[!WARN!] IMAGE TOO BIG",0,200, 50,.7,.4,.5,offwhite);
			// betterText("[!WARN!] IMAGE TOO BIG",color, float x, float y, float d, float size,float sizet,u32 color)
		}

		YACTRTextRightCusDep("Charted By:", SCREEN_WIDTH-5, SCREEN_HEIGHT-35+(45*animation),.5,offwhite,1);
		YACTRTextRightCusDep(s.author, SCREEN_WIDTH-5, SCREEN_HEIGHT-20+(45*animation),.5,offwhite,1);
		// YACTRTextRightCusDep(s.tags, SCREEN_WIDTH-10, 70,.5,beatred,1);
		YACTRTextRightCusDep(s.flavor, SCREEN_WIDTH-10, 25-(45*animation),.5,offgrey,.1);
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
		drawInfo(indexes[0],indexes[1]);
		YACTRTextRightSqu("SONG", SCREEN_WIDTH-5, -30-(40*animation),3,2,offgrey);
		YACTRTextRightSqu("SELECT", SCREEN_WIDTH-100, SCREEN_HEIGHT-35+(40*animation),3,2,offgrey);
		YACTRTextRightSqu("3DS", SCREEN_WIDTH-5, -30-40-(-40*animation-1),3,2,offgrey);
		YACTRTextRightSqu("INFO", SCREEN_WIDTH-200, SCREEN_HEIGHT-35+40+(-40*animation-1),3,2,offgrey);
		// if(state==0){
			drawSong(50-(250*animation),100+50*index-menuy, songs[index],true);		

		// }
		renderList(50-(200*animation),100);		
		menuy=(menuy+index*50)/2.0;
		C2D_DrawRectangle(
			0, 0, 1, 
			5000,  (250*anims[0]),supportcolor, supportcolor,supportcolor,supportcolor);
        C3D_FrameEnd(0);
	}
	void draw(){
		drawBottom();
		drawTop();
	}
	void itick(){
		if(states[1]==2){
			animation=(animation*3+1)/4.0;
		}else{
			animation=(animation*3)/4.0;
		}
	}
	void tick(){

    	// hidScanInput();			
		touchPosition touch;
		hidTouchRead(&touch);

		
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A/*||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)*/) {states[0]=1;states[1]=1;}
		

		if (kDown & KEY_DUP  )  {
			index--;
			chind=1;

		}
		if (kDown & KEY_DDOWN ) {
			index++;
			chind=1;
		}
		
		if (index<0){
			index=scount-1;
			menuy=(menuy+(scount)*50);
		}
		if (index>scount-1){
			index=0;
			menuy=(menuy-scount*50);
		}
		if(chind==1){
			chind=0;
			strcpy(inds, "");
    		sprintf(inds, "%d", index+1);
			strcat(inds, "/cover.png");
			changeImg(inds);
		}
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
	}
	
while (aptMainLoop())
{
    	hidScanInput();			
		u32 kDown = hidKeysDown();
		if (kDown & KEY_B) {
			if(chind==0&(state==0)){
				if(states[1]==2){
					states[1]=0;
				}else if(states[1]==0){
					states[1]=2;
				}
				chind=-1;
			}
		}else{
			chind=0;
		}
		if(states[1]==2){
			if (kDown & KEY_DLEFT) {
				indexes[0]--;
				indexes[1]=0;
			}
			if (kDown & KEY_DRIGHT) {
				indexes[0]++;
				indexes[1]=0;
			}
			if (kDown & KEY_L) {
				indexes[1]--;
				anims[2]-=400;
			}
			if (kDown & KEY_R) {
				indexes[1]++;
				anims[2]+=400;
			}
		}
		if (kDown & KEY_START){
			animation=0;
			state=1;
		}
		if(state==9) break;
		if(state==0){
			draw();
			if(states[1]==0){
		        tick();

			}
	        itick();
		}else if (state==1){
			rgTick();
		} 
		if (states[1]==1){
			anims[0]=(anims[0]*7+1.05)/8;
			if(anims[0]>1){
				state=states[0];
				states[1]=0;
			}
		}else{

			anims[0]=(anims[0]*7)/8;
		}
	// printf("\x1b[1;1HPress A to Start YAFG  ");
	// printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
}

	#include "./vars/end.c"
	return 0;
}
