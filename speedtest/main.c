#include "speedtest.h"

static void			init_structtest(void)
{
	g_speed	= ft_memalloc(sizeof(t_speedtest));
	g_speed->alltest = 0;
}

static void			open_files(void)
{
	if ((g_outputfile_1 = open(OUTPUT_FILE_1, O_RDWR)) < 0)
	{
		printf("%s\n", O_ERROR);
		exit(1);
	}
	if ((g_outputfile_2 = fopen(OUTPUT_FILE_2, "r+")) < 0)
	{
		printf("%s\n", O_ERROR);
		exit(1);
	}
}
static void			processing(long long int own, long long int real, int flag)
{
	printf("symbs of ownn = %lld\n", own);
	printf("symbs of real = %lld\n", real);
}

static int			alltest_ftprintf(void)
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
	while (ttime < TIME_CONST)
	{
		stop = clock();
		ttime = (stop - start) / CLOCKS_PER_SEC;
		len += ft_printf("a");
		if (timer != ttime)
		{
			write(1, ".", 1);
			timer = ttime;
		}
	}
	close(g_outputfile_1);
	printf("  %d sec\n", TIME_CONST);
	return (len);
}

static int			alltest_printf(void)
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
	while (ttime < TIME_CONST)
	{
		ttime = (clock() - start) / CLOCKS_PER_SEC;
		len += fprintf(g_outputfile_2, "a");
		if (timer != ttime)
		{
			write(1, ".", 1);
			timer = ttime;
		}
	}
	fclose(g_outputfile_2);
	printf("  %d sec\n", TIME_CONST);
	return (len);
}

int 				main(int argc, char **argv)
{
	open_files();
	init_structtest();
	if (argc == 1)
		processing(alltest_ftprintf(), alltest_printf(), ALLTEST);
	return (0);
}
