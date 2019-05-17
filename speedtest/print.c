# include "speedtest.h"

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
