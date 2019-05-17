#ifndef SPEEDTEST_H
# define SPEEDTEST_H

# include "../ft_printf/header.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <time.h>

# define TIME_CONST		10

int					g_fd;
FILE				*g_fdreal;

#endif