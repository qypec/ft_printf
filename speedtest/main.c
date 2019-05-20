#include "speedtest.h"

static void			init_structtest(void)
{
	g_speed	= ft_memalloc(sizeof(t_speedtest));
	g_speed->byonesymb_test = 0;
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

int 				main(int argc, char **argv)
{
	open_files();
	init_structtest();
	if (argc == 1)
		byonesymb_test();
	return (0);
}
