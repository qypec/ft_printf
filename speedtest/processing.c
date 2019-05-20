#include "speedtest.h"

static void		processing_byonesymb_test(long long int own, \
					long long int real, int flag)
{
	int			persent;

	persent = own / ((double)(real / 100));
	print_result(persent, own, real, flag);
}

void			processing(long long int own, long long int real, int flag)
{
	if (flag == BYONESYMB_TEST)
		processing_byonesymb_test(own, real, flag);
}
