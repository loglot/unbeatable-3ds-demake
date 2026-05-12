
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
#include "../lodepng.h"


u8* buffer;
u32 size;

#define ICON_WIDTH 1024
#define ICON_HEIGHT 1024
#define TEX_SIZE 1024

#define SCREEN_WIDTH   400
#define SCREEN_WIDTH_B 320
#define SCREEN_HEIGHT  240