# include "speedtest.h"

void				print_result(int persent, long long int own, \
						long long int real, int flag)
{
	char			*tmp3;

	tmp3 = ft_itoa(persent);
	write(1, "\n", 2);
	printf("ft_printf output:           %s", COLOR_GREEN);
	printf("%lld%s\n", own, COLOR_RESET);
	printf("printf output:              %s", COLOR_GREEN);
	printf("%lld%s\n", real, COLOR_RESET);
	write(1, "persent:                    ", 28);
	if (persent >= 50)
		color_set(COLOR_GREEN, COLOR_SIZE);
	else
		color_set(COLOR_RED, COLOR_SIZE);
	write(1, tmp3, ft_strlen(tmp3));
	ft_strdel(&tmp3);
	color_set(COLOR_RESET, COLOR_SIZE - 1);
	write(1, "\n\n", 2);
	color_set(COLOR_CYAN, COLOR_SIZE);
	write(1, "----------------------------\n\n", 30);
}

void				print_testname(const char *test_name, int namesize)
{
	write(1, "test:                       ", 28);
	write(1, test_name, namesize);
	write(1, "\n\n", 2);
}

void				print_sec(int sec)
{
	char			*tmp;

	tmp = ft_itoa(sec);
	write(1, "  ", 2);
	write(1, tmp, ft_strlen(tmp));
	write(1, " sec\n", 5);
	ft_strdel(&tmp);
}

clock_t				print_timer(clock_t timer, clock_t ttime)
{
	if (timer != ttime)
	{
		write(1, ".", 1);
		timer = ttime;
	}
	return (timer);
}
