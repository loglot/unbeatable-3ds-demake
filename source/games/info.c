
char opt[][10]={"ALBUM ART", "MISC"};
int optlen=2;
int timAAA=10;
void AlbumINF(float x, float y, int page){
    // betterText("ALBUM ART",0,20,y-30,0,1.4,2,offgrey);
    if(page==0){
        char AAA[20];
        char AAAA[20];
        char TMPA[40];
        char TMPB[40];
        sprintf(AAA, "%f", x);
        sprintf(AAAA, "%f", y);
        if (timAAA>0){
            timAAA--;
        }else{
            timAAA=40;
            strcpy(TMPA,"WHAT THE HELL IS X? :");
            strcpy(TMPB,"WHAT THE HELL IS Y? :");
            strcat(TMPA,AAA);
            strcat(TMPA,"\n");
            strcat(TMPB,AAAA);
            strcat(TMPB,"\n\n");
            printf(TMPA);
            printf(TMPB);
        }

    //	betterText("1x1 TO 1024x1024"  ,0                ,x+20,y+50,.7,.8,.8,beatred);
    // 	betterText("RENDERED AT 150x150",0,x+20,y+80,.7,.8,.8,beatred);
    // 	betterText("RENDERED AT 150x150",0,x+20,y+80,.7,.8,.8,beatred);
    // 	betterText("THE LARGER THE ART THE ",0,x+20,y+130,.7,.8,.8,beatred);
    // 	betterText("LONGER IT TAKES TO PARSE",0,x+20,y+160,.7,.8,.8,beatred);
    }
    // if(page==1){
    // 	betterText("AAAAAAA",0,x+20,y+50,.7,.8,.8,beatred);
    // 	betterText("AAAAAAA",0,x+20,y+80,.7,.8,.8,beatred);
    // 	betterText("AAAAAAA",0,x+20,y+130,.7,.8,.8,beatred);
    // 	betterText("AAAAAAA",0,x+20,y+160,.7,.8,.8,beatred);
    // }
    // if(page==2){
    // 	betterText("BBBBBBB",0,x+20,y+50,.7,.8,.8,beatred);
    // 	betterText("BBBBBBB",0,x+20,y+80,.7,.8,.8,beatred);
    // 	betterText("BBBBBBB",0,x+20,y+130,.7,.8,.8,beatred);
    // 	betterText("BBBBBBB",0,x+20,y+160,.7,.8,.8,beatred);
    // }

}
void MiscINF(float x, float y, int page){
    	betterText("MISC",0,20,y-30,0,2,2,offgrey);
    if(page==0){
    	betterText("Welcome to the Miscellaneous",0,x+20,y+50,.7,.8,.8,beatred);
    	betterText("Page!",0,x+20,y+80,.7,.8,.8,beatred);
    	betterText("This Was Made so That i Could",0,x+20,y+130,.7,.8,.8,beatred);
    	betterText("Test Out the Information Page.",0,x+20,y+160,.7,.8,.8,beatred);
    }
    if(page==1){
    	betterText("AAAAAAA",0,x+20,y+50,.7,.8,.8,beatred);
    	betterText("AAAAAAA",0,x+20,y+80,.7,.8,.8,beatred);
    	betterText("AAAAAAA",0,x+20,y+130,.7,.8,.8,beatred);
    	betterText("AAAAAAA",0,x+20,y+160,.7,.8,.8,beatred);
    }
    if(page==2){
    	betterText("BBBBBBB",0,x+20,y+50,.7,.8,.8,beatred);
    	betterText("BBBBBBB",0,x+20,y+80,.7,.8,.8,beatred);
    	betterText("BBBBBBB",0,x+20,y+130,.7,.8,.8,beatred);
    	betterText("BBBBBBB",0,x+20,y+160,.7,.8,.8,beatred);
    }

}

void *InfoList[]={AlbumINF, MiscINF};
void RenderInfo(void (*fun)(float, float, int), float x, float y, int page){

        fun(x,y,page);
        // fun(x-400,y,page-1);
        // fun(x+400,y,page+1);
}
void drawInfo(int info,int page){
    anims[2]=(anims[2]*3)/4;
    float x=anims[2];
    float y=300-(300*animation);
    if(info>=0&info<(optlen)){
        RenderInfo(InfoList[info],x,y,page);
    }
}
void drawInfoSelect(){
		float WID;
		float HEI;
    anims[1]=(anims[1]*2-140*indexes[0])/3;
    for(int i = 0; i<optlen; i++){
        float x=SCREEN_WIDTH_B-140+i*140+anims[1];
        float y= 155+100-(100*animation);


        if(indexes[0]==i){
            YACTRText(opt[i],-1000, y+5,.7,beatred);
            C2D_TextGetDimensions(&Text, .8, .8, &WID, &HEI);
            C2D_DrawRectangle(
                x-(WID/2)-5, y-5, .68, 
                WID+10,  HEI+10, supportcolor, supportcolor,supportcolor,supportcolor );

        }
    	betterText(opt[i],C2D_AlignCenter,x,y,.7,.8,.8,offwhite);
    }

}