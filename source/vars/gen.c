
C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
u32 UI  = C2D_Color32(0x00, 0x00, 0x00, 0x5F);
u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);
u32 white  = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
u32 offwhite  = C2D_Color32(0xF7, 0xF7, 0xD8, 0xFF);
u32 beatred  = C2D_Color32(0xEB, 0x5A, 0x7F, 0xFF);
u32 quaverblue  = C2D_Color32(0x5A, 0x9E, 0xEB, 0xFF);
u32 supportcolor  = C2D_Color32(0x00, 0x00, 0x00, 0xFF);
u32 offgrey  = C2D_Color32(0xE0, 0xDE, 0xC9, 0xFF);
u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
u32 YAShadow   = C2D_Color32(0x33, 0x36, 0x3F, 0x5F);
int imgwid, imghei, imgch;
float targetScale=.8;
float animation=0;
float anims[]={3,0,0};
float states[]={0,0};
float scale=0;
int index = 0;
int indexes[] = {0,0};
int pos=0;
int state=0;
int chind=1;

int imgwidt=0;
int imgheit=0;

float menuy=0;
struct song {
	char title[20];
	char author[20];
	char artist[20];
	char audio[20];
	char difficulty[20];
	char tags[50];
	char path[50];
	char flavor[50];
	char level[4];
};
struct beatmap {
	struct beat* beats;
};
struct beat {
	float time;
	float type;
};
struct song songs[50];
    char indexs[15];

char inds [50];
