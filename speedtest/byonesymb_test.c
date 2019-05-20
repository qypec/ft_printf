# include "speedtest.h"

static int			byonesymb_test_ftprintf(void)
{
	clock_t			ttime;
	clock_t			start;
	clock_t			stop;
	long long int	len;
	clock_t			timer;

	len = 0;
	timer = 0;
	start = clock();
	ttime = 0;
	color_set(COLOR_YELLOW, COLOR_SIZE);
	print_testname(BYONESYMB_STR, BYONESYMB_SIZE);
	color_set(COLOR_RESET, COLOR_SIZE - 1);
	color_set(COLOR_BLUE, COLOR_SIZE);
	while (ttime < TIME_CONST)
	{
		stop = clock();
		ttime = (stop - start) / CLOCKS_PER_SEC;
		len += ft_printf("a");
		timer = print_timer(timer, ttime);
	}
	close(g_outputfile_1);
	color_set(COLOR_GREEN, COLOR_SIZE);
	print_sec(TIME_CONST);
	color_set(COLOR_RESET, COLOR_SIZE - 1);
	return (len);
}

static int			byonesymb_test_printf(void)
{
	clock_t			ttime;
	clock_t			start;
	clock_t			stop;
	long long int	len;
	clock_t			timer;

	len = 0;
	timer = 0;
	start = clock();
	ttime = 0;
	color_set(COLOR_BLUE, COLOR_SIZE);
	while (ttime < TIME_CONST)
	{
		ttime = (clock() - start) / CLOCKS_PER_SEC;
		len += fprintf(g_outputfile_2, "a");
		timer = print_timer(timer, ttime);
	}
	fclose(g_outputfile_2);
	color_set(COLOR_GREEN, COLOR_SIZE);
	print_sec(TIME_CONST);
	color_set(COLOR_RESET, COLOR_SIZE - 1);
	return (len);
}

void				byonesymb_test(void)
{
	processing(byonesymb_test_ftprintf(), byonesymb_test_printf(), BYONESYMB_TEST);
}