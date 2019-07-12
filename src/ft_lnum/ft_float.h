#ifndef FT_FLOAT_H
# define FT_FLOAT_H

typedef union
{
	long double		ldouble;
	struct
	{
		unsigned long mantissa : 63;
		unsigned long exponent : 15;
		unsigned long sign : 1;
	}				components;
}					lnum;

typedef struct		s_charlnum
{
	char	*mantissa;
	char	*exponent;
	short			sign;
}					t_charlnum;

#endif