#include <stdint.h>
#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_MAGIC	0xCAFEC007

typedef struct {
	uint32_t	 magic;
	uint32_t	 id;
	uint16_t	 width;
	uint16_t	 height;
	uint16_t	 x;
	uint16_t	 y;
	int		 pixbuf;
	char		 title[128];
	int		 buffer_count;
	int		 current_buf;
	int		 display_buf;
} posgui_window_t;

typedef struct {
	int		 ctlbuf;
	posgui_window_t *winfo;	
	uint32_t	*pixels;
} wlib_window_t;

wlib_window_t *window_open(posgui_window_t *wp);

uint32_t *window_get_buffer(wlib_window_t *w);

void window_swap_buffers(wlib_window_t *w);

#endif

