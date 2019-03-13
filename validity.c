#include <stdio.h>


#include "header.h"

static char		*read_specifier(const char *step)
{
	char	*specifier;
	int		len;

	len = ft_strlenchr(step, '%');
	specifier = (char *)malloc(sizeof(char) * (len + 1));
	specifier = ft_strncpy(specifier, step, len + 1);
	// if (specifier[len] == '%')
	// 	specifier[len] = '\0';
	return (specifier);
}

int				validity(char *step, va_list arg)
{
	char	*specifier;

	while (*step != '%' && *step != '\0')
		step++;
	if (*step == '%')
		specifier = read_specifier(step + 1);
	printf("%s\n", specifier);
	if (*specifier == ' ')
	{
		while (*specifier == ' ')
			specifier++;
		if (*specifier == '\0')
			return (-1);
	}
	if (*specifier == )

	return (1);
}


//	%% 
//	%%%  no
//	%%%d
//	%