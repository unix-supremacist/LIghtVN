#include <graphics.c>
#include <types.h>

void render(){
    renderInit();
    dltexture texture = loadTexture("tatr02_l_1611.png");
    while (!shouldGameClose()){
        startDrawing();
        clear();
        renderTexture(texture, 0.3, 0.5, 0.3, 0.3, white);
        drawtext("Testing", 190, 200, 20);
        stopDrawing();
    }
    unloadTexture(texture);
    uninit();
}