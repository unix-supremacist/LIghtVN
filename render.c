#include <graphics.c>

void render(){
    renderInit();
    texture texture = loadTexture("tatr02_l_1611.png");
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