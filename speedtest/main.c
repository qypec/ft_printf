#include "speedtest.h"

static void			open_file(void)
{
	if ((g_fd = open("ft_printf_output.txt", O_RDWR)) < 0)
		exit(1);
}

int 				main(int argc, char **argv)
{
	open_file();
	return (0);
}