#include <graphics.c>
#include <types.h>

void render(){
	float i=0.0f;
	float delta;
	renderInit();
	dltexture texture = loadTexture("alexa.png");
	while (!shouldGameClose()){
		delta = GetFrameTime()*60;
		/* this makes speeds act as if you didnt have a delta
		and were just running at 60fps, while also actually having a delta.
		this may not be ideal down the road as this is no longer a second
		delta, look at it later */
		i+=0.01f*delta; if (i > 1.0f) i=0.0f;
		DrawText(TextFormat("DELTA: %f", delta), 280, 130, 40, LIGHTGRAY);
		startDrawing();
		clear();
		renderTexture(texture, i, 0.5, 1, 1, white);
		drawtext("Testing", 190, 200, 20);
		DrawFPS(10, 10);
		stopDrawing();
	}
	unloadTexture(texture);
	uninit();
}