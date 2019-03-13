#include "libft.h"

int		ft_strlenchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (i);
}