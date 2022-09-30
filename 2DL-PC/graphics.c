#include <raylib.h>
#include <types.h>

#define shouldGameClose() WindowShouldClose()
#define startDrawing() BeginDrawing()
#define clear() ClearBackground(RAYWHITE)
#define stopDrawing() EndDrawing()
#define dltexture Texture2D
#define color Color
#define white WHITE
#define uninit() CloseWindow()

Vector2 ws;

void renderTexture(Texture2D texture, float x, float y, float w, float h, Color color){
   Vector2 origin = { texture.width/(2/w), texture.height/(2/h) };
   Rectangle sourceRec = { 0, 0, texture.width, texture.height };
   Rectangle destRec = { ws.x*x, ws.y*y, texture.width*w, texture.height*h };
   DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, color);
}

void renderInit(){
   ws.x=1600;
   ws.y=900;
   SetConfigFlags(FLAG_MSAA_4X_HINT);
   InitWindow(ws.x, ws.y, "LightVN");
   SetTargetFPS(60);
}

Texture2D loadTexture(char* path){
    Texture2D texture;
    texture = LoadTexture(path);
    return Texture2D;
}

void drawtext(char* text, s32 x, s32 y, s32 fs){
    DrawText(text, x, y, fs, LIGHTGRAY);
}

void unloadTexture(Texture2D texture){
    UnloadTexture(texture);
}