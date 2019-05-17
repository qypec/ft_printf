# include "speedtest.h"

void				color_set(const char *color, int size)
{
	write(1, color, size);
}
