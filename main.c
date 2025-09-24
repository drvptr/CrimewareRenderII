#include <X11/Xlib.h>
#include <X11/extensions/XShm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "io.h"

#define RGB(r,g,b) (((r)<<16)|((g)<<8)|(b))

void DrawBackground(io_window_t *w, int width, int height){
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			io_SetPixel(w, x, y, RGB(x, y, 128));
		}
	}
}

int main(void) {
	io_keys_t *c = io_InitKeys();
	io_window_t *w = io_InitWindow();
	int playloop = 1;
	while (playloop) {
		io_PollKeys(w, c, 0);
		if(c->status[KEY_ESC] == IO_TOGGLED)
			playloop = 0;
		DrawBackground(w, io_GetWidth(w), io_GetHeight(w));
		io_UpdateFrame(w);
	}
	io_CloseWindow(w);
	io_FreeKeys(c);
	return 0;
}

