#include "speedtest.h"

static void			processing(int own, int real)
{
	printf("own = %d\n", own);
	printf("real = %d\n", real);
}

static int			alltest_ftprintf(void)
{
	clock_t			ttime;
	clock_t			start;
	clock_t			stop;
	int				len;

	len = 0;
	if ((g_fd = open("ft_printf_output.txt", O_RDWR)) < 0)
	{
		printf("open error\n");
		exit(1);
	}
	start = clock();
	ttime = start / CLOCKS_PER_SEC;
	while (ttime < 10)
	{
		stop = clock();
		ttime = (stop - start) / CLOCKS_PER_SEC;
		len += ft_printf("a");
	}
	close(g_fd);
	return (len);
}

static int			alltest_printf(void)
{
	clock_t			ttime;
	clock_t			start;
	clock_t			stop;
	int				len;

	len = 0;
	if ((g_fdreal = fopen("printf_output.txt", "r+")) < 0)
	{
		printf("open error\n");
		exit(1);
	}
	start = clock();
	ttime = start / CLOCKS_PER_SEC;
	while (ttime < 10)
	{
		stop = clock();
		ttime = (stop - start) / CLOCKS_PER_SEC;
		len += fprintf(g_fdreal, "a");
	}
	fclose(g_fdreal);
	return (len);
}

int 				main(int argc, char **argv)
{
	if (argc == 1)
		processing(alltest_ftprintf(), alltest_printf());
	return (0);
}
