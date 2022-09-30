#include <string.h>
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
#include <types.h>

typedef struct texture{
	vita2d_texture *texture;
} texture;

typedef struct color{
	unsigned int color;
} color;

color white;
SceCtrlData pad;
vita2d_pgf *pgf;
vita2d_pvf *pvf;

void renderTexture(texture texture, float x, float y, float w, float h, color color){
   //Vector2 origin = { texture.texture.width/(2/w), texture.texture.height/(2/h) };
   //Rectangle sourceRec = { 0, 0, texture.texture.width, texture.texture.height };
   //Rectangle destRec = { ws.x*x, ws.y*y, texture.texture.width*w, texture.texture.height*h };
   //DrawTexturePro(texture.texture, sourceRec, destRec, origin, 0.0f, color.color);

   vita2d_draw_texture_scale(texture.texture, x*940, y*544, w, h);
}

void renderInit(){
    white.color = 0xFFFFFFFF;
   vita2d_init();
   pgf = vita2d_load_default_pgf();
    pvf = vita2d_load_default_pvf();
   memset(&pad, 0, sizeof(pad));
}

texture loadTexture(char* path){
    texture texture;
    texture.texture = vita2d_load_PNG_file(path);
    return texture;
}

u8 shouldGameClose(){
    return FALSE;
}

void startDrawing(){
    sceCtrlPeekBufferPositive(0, &pad, 1);
    //if (pad.buttons & SCE_CTRL_START) break;
    vita2d_start_drawing();
}

void clear(){
    vita2d_set_clear_color(RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
    vita2d_clear_screen();
}

void drawtext(char* text, s32 x, s32 y, s32 fs){
    vita2d_pgf_draw_text(pgf, x, y, RGBA8(0,255,0,255), fs/20, text);
}

void stopDrawing(){
    vita2d_end_drawing();
    vita2d_swap_buffers();
}

void unloadTexture(texture texture){
    vita2d_fini();//hack this needs a new function implemented
    vita2d_free_texture(texture.texture);
}

s32 uninit(){
    vita2d_free_pgf(pgf);
	vita2d_free_pvf(pvf);
    sceKernelExitProcess(0);
    return 0;
}