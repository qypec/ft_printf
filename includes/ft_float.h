#ifndef FT_FLOAT_H
# define FT_FLOAT_H

typedef union
{
	float f;
	struct
	{
		int mantisa : 23;
		short exponent : 8;
		int sign : 1;
	}	parts;
}	float_cast;

typedef union
{
  
	double f;
	struct
	{
		long int mantisa : 52;
		short exponent : 11;
		int sign : 1;
	}   parts;
}	double_cast;

typedef union
{
  
	long double f;
	struct
	{
		__int128_t mantisa : 112;
		short exponent : 15;
		int sign : 1;
	}   parts;
}   long_double_cast;

#endif