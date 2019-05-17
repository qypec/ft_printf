#ifndef SPEEDTEST_H
# define SPEEDTEST_H

# include "../ft_printf/header.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <time.h>

# define O_ERROR 		"open error"

# define TIME_CONST		10

# define OUTPUT_FILE_1	"ft_printf_output.txt"
# define OUTPUT_FILE_2	"printf_output.txt"

# define BIGTEST		1

int						g_outputfile_1;
FILE					*g_outputfile_2;

typedef struct			s_speedtest
{
	int					bigtest;
}						t_speedtest;

t_speedtest				*g_speed;

void					color_set(const char *color, int size);

void					print_sec(int sec);
clock_t					print_timer(clock_t timer, clock_t ttime);

void					processing(long long int own, long long int real, int flag);
void					bigtest(void);

#endif