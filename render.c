#include "types.h"
#include <raylib.h>

Vector2 ws;

void renderTexture(Texture2D texture, float x, float y, float w, float h, Color color){
	int fake_res=900;
	float new_w = texture.width*(ws.y/fake_res);
	float new_h = texture.height*(ws.y/fake_res);

	Vector2 origin = { new_w/(2/w), new_h/(2/h) };
	Rectangle sourceRec = { 0, 0, texture.width, texture.height };
	Rectangle destRec = { ws.x*x, ws.y*y, new_w*w, new_h*h };
	DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, color);
}

void render(){
	float i=0.0f;
	float delta;
	ws.x=1600;
	ws.y=900;
	SetConfigFlags(FLAG_MSAA_4X_HINT| FLAG_WINDOW_RESIZABLE);
	//SetConfigFlags(FLAG_MSAA_4X_HINT| FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(ws.x, ws.y, "LightVN");
	Texture2D texture = LoadTexture("alexa.png");
	while (!WindowShouldClose()){
		delta = GetFrameTime()*60;
		/* this makes speeds act as if you didnt have a delta
		and were just running at 60fps, while also actually having a delta.
		this may not be ideal down the road as this is no longer a second
		delta, look at it later */
		i+=0.01f*delta; if (i > 1.0f) i=0.0f;
		DrawText(TextFormat("DELTA: %f", delta), 280, 130, 40, LIGHTGRAY);
		ws.x = GetScreenWidth();
		ws.y = GetScreenHeight();
		BeginDrawing();
		ClearBackground(RAYWHITE);
		renderTexture(texture, i, 0.5, 1, 1, WHITE);
		DrawText("Testing", 190, 200, 20, LIGHTGRAY);
		DrawFPS(10, 10);
		EndDrawing();
	}
	UnloadTexture(texture);
	CloseWindow();
}