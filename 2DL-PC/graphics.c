#include <raylib.h>
#include <types.h>

#define shouldGameClose() WindowShouldClose()
#define clear() ClearBackground(RAYWHITE)
#define stopDrawing() EndDrawing()
#define dltexture Texture2D
#define color Color
#define white WHITE
#define uninit() CloseWindow()

Vector2 ws;

void startDrawing(){
	ws.x = GetScreenWidth();
	ws.y = GetScreenHeight();
	BeginDrawing();
}

void renderTexture(Texture2D texture, float x, float y, float w, float h, Color color){
	int fake_res=900;
	float new_w = texture.width*(ws.y/fake_res);
	float new_h = texture.height*(ws.y/fake_res);

	Vector2 origin = { new_w/(2/w), new_h/(2/h) };
	Rectangle sourceRec = { 0, 0, texture.width, texture.height };
	Rectangle destRec = { ws.x*x, ws.y*y, new_w*w, new_h*h };
	DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, color);
}

void renderInit(){
   ws.x=1600;
   ws.y=900;
   SetConfigFlags(FLAG_MSAA_4X_HINT| FLAG_WINDOW_RESIZABLE);
   //SetConfigFlags(FLAG_MSAA_4X_HINT| FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
   InitWindow(ws.x, ws.y, "LightVN");
}

Texture2D loadTexture(char* path){
    Texture2D texture;
    texture = LoadTexture(path);
    return texture;
}

void drawtext(char* text, s32 x, s32 y, s32 fs){
    DrawText(text, x, y, fs, LIGHTGRAY);
}

void unloadTexture(Texture2D texture){
    UnloadTexture(texture);
}