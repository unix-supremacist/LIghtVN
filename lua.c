Vector2 ws;
int FPS;

void setRes(int w, int h){
	ws.x=w;
	ws.y=h;
}

void setFramerateTarget(int fps){
	FPS=fps;
	SetTargetFPS(fps);
}

void drawTexture(char* path, float x, float y, float w, float h, Color color){
	dltexture texture = loadTexture(path);
	renderTexture(texture, x, y, w, h, color);
	unloadTexture(texture);
}

void renderInit(char* name){
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(ws.x, ws.y, name);
}

void drawtext(char* text, s32 x, s32 y, s32 fs){
	 DrawText(text, x, y, fs, LIGHTGRAY);
}