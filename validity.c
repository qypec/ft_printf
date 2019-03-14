#include <stdio.h>


#include "header.h"


static char		*check_for_spaces(char *specifier);
static int		check_for_cspdiouxX(char *specifier);

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
	printf("specifier = %s\n", specifier);
	specifier = check_for_spaces(specifier);
	// if (check_for_spaces(&specifier) == -1)
	// 	return (-1);
	printf("symbol = %c\n", *specifier);
	// if (check_for_cspdiouxX(specifier) == -1)
	// 	return (-1);

	return (1);
}

static char		*check_for_spaces(char *specifier)
{
	if (*specifier == ' ')
	{
		while (*specifier == ' ')
			specifier++;
		if (*specifier == '\0')
			exit(-1);
	}
	return (specifier);
}

// static int		check_for_cspdiouxX(char *specifier)
// {
// 	if (*specifier)
// }


//	%% 
//	%%%  no
//	%%%d
//	%