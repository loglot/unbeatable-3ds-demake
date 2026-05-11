const u32 next_pow2(u32 n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}
const u32 clamp(u32 n, u32 lower, u32 upper) {
  if (n < lower)
    return lower;
  if (n > upper)
    return upper;
  return n;
}
 bool loadPngImage(C2D_Image* image, const char* path) {
    //char path[128] = "sdmc:/22.png";
    //snprintf(path, sizeof(path), "/3ds/switch/icons/%016llX.png", titleId);

    unsigned char* pngData = NULL;
    unsigned width = 0, height = 0;
    unsigned error = lodepng_decode32_file(&pngData, &width, &height, path);
    
    if (error || pngData == NULL) {
        return false;
        return false;
    }

    if (width != ICON_WIDTH || height != ICON_HEIGHT) {
        // free(pngData);
        // // return false;
        // ICON_WIDTH=width;
        // ICON_HEIGHT=height;
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
        .width  = clamp(next_pow2(width), 64, 1024),
        .height = clamp(next_pow2(height), 64, 1024),
        .left   = 0.0f,
        .top    = 1.0f,
        .right  = clamp(next_pow2(width), 64, 1024) / (float)TEX_SIZE,
        .bottom = 1.0f - (clamp(next_pow2(height), 64, 1024) / (float)TEX_SIZE)
    };

    *image = (C2D_Image){ tex, subtex };
    free(pngData);
    return true;
}