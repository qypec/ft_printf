#include "speedtest.h"

static void			processing(int own, int real)
{
	printf("own = %d\n", own);
	printf("real = %d\n", real);
}

static int			alltest_ftprintf(void)
{
	clock_t			time;

	if ((g_fd = open("ft_printf_output.txt", O_RDWR)) < 0)
	{
		printf("open error\n");
		exit(1);
	}
	time = clock();
	while ((double)time/ CLOCKS_PER_SEC < 15)
	{
		time = clock();
		ft_printf("a");
	}
	close(g_fd);
	return (0);
}

static int			alltest_printf(void)
{
	clock_t			time;

	if ((g_fdreal = fopen("printf_output.txt", "r+")) < 0)
	{
		printf("open error\n");
		exit(1);
	}
	time = clock();
	while ((double)time/ CLOCKS_PER_SEC < 15)
	{
		time = clock();
		fprintf(g_fdreal, "a");
	}
	fclose(g_fdreal);
	if ((g_fd = open("ft_printf_output.txt", O_RDWR)) < 0)
	{
		printf("open error\n");
		exit(1);
	}
	time = clock();
	while ((double)time/ CLOCKS_PER_SEC < 15)
	{
		time = clock();
		ft_printf("a");
	}
	close(g_fd);
	return (0);
}

int 				main(int argc, char **argv)
{
	// if (argc == 1)
		// processing(alltest_ftprintf(), alltest_printf());
		alltest_printf();
		// alltest_ftprintf();
	return (0);
}
