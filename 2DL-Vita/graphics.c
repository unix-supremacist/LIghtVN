#include <string.h>
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
#include <types.h>

#define shouldGameClose() FALSE
#define dltexture vita2d_texture*
#define color u32
#define white 0xFFFFFFFF

SceCtrlData pad;
vita2d_pgf *pgf;
vita2d_pvf *pvf;

void renderTexture(vita2d_texture *texture, float x, float y, float w, float h, u32 color){
   vita2d_draw_texture_scale(texture, x*940, y*544, w, h);
}

void renderInit(){
   vita2d_init();
   pgf = vita2d_load_default_pgf();
    pvf = vita2d_load_default_pvf();
   memset(&pad, 0, sizeof(pad));
}

vita2d_texture* loadTexture(char* path){
    vita2d_texture *texture;
    texture = vita2d_load_PNG_file(path);
    return texture;
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

void unloadTexture(vita2d_texture *texture){
    vita2d_fini();//hack this needs a new function implemented
    vita2d_free_texture(texture);
}

s32 uninit(){
    vita2d_free_pgf(pgf);
	vita2d_free_pvf(pvf);
    sceKernelExitProcess(0);
    return 0;
}