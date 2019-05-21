#ifndef SPEEDTEST_H
# define SPEEDTEST_H

# include "../ft_printf/header.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <time.h>

# define O_ERROR 			"open error"

# define COLOR_RED			"\x1b[31m"
# define COLOR_GREEN		"\x1b[32m"
# define COLOR_YELLOW		"\x1b[33m"
# define COLOR_BLUE			"\x1b[34m"
# define COLOR_MAGENTA		"\x1b[35m"
# define COLOR_CYAN			"\x1b[36m"
# define COLOR_RESET		"\x1b[0m"
# define COLOR_SIZE			5

# define TIME_CONST			10

# define OUTPUT_FILE_1		"txt_files/ft_printf_output.txt"
# define OUTPUT_FILE_2		"txt_files/printf_output.txt"

# define BYONESYMB_TEST		1
# define BYONESYMB_STR		"by_one_symb"
# define BYONESYMB_SIZE		11

# define BIGSTRING_TEST		2
# define BIGSTRING_STR		"big_string"
# define BIGSTRING_SIZE		10

int						g_outputfile_1;
FILE					*g_outputfile_2;

typedef struct			s_speedtest
{
	int					byonesymb_test;
}						t_speedtest;

t_speedtest				*g_speed;

void					color_set(const char *color, int size);

void					print_sec(int sec);
clock_t					print_timer(clock_t timer, clock_t ttime);
void					print_testname(const char *test_name, int namesize);
void					print_result(int persent, long long int own, \
							long long int real, int flag);

void					processing(long long int own, long long int real, int flag);

void					byonesymb_test(void);
void					bigstring_test(void);

#endif