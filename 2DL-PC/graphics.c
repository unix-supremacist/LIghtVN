#include <raylib.h>
#include <types.h>

typedef struct texture{
	Texture2D texture;
} texture;

typedef struct color{
	Color color;
} color;

Vector2 ws;
color white;

void renderTexture(texture texture, float x, float y, float w, float h, color color){
   Vector2 origin = { texture.texture.width/(2/w), texture.texture.height/(2/h) };
   Rectangle sourceRec = { 0, 0, texture.texture.width, texture.texture.height };
   Rectangle destRec = { ws.x*x, ws.y*y, texture.texture.width*w, texture.texture.height*h };
   DrawTexturePro(texture.texture, sourceRec, destRec, origin, 0.0f, color.color);
}

void renderInit(){
    white.color = WHITE;
   ws.x=1600;
   ws.y=900;
   SetConfigFlags(FLAG_MSAA_4X_HINT);
   InitWindow(ws.x, ws.y, "LightVN");
   SetTargetFPS(60);
}

texture loadTexture(char* path){
    texture texture;
    texture.texture = LoadTexture(path);
    return texture;
}

bool shouldGameClose(){
    return WindowShouldClose();
}

void startDrawing(){
    BeginDrawing();
}

void clear(){
    ClearBackground(RAYWHITE);
}

void drawtext(char* text, s32 x, s32 y, s32 fs){
    DrawText(text, x, y, fs, LIGHTGRAY);
}

void stopDrawing(){
    EndDrawing();
}

void unloadTexture(texture texture){
    UnloadTexture(texture.texture);
}

s32 uninit(){
    CloseWindow();
}