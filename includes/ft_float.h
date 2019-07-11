#ifndef FT_FLOAT_H
# define FT_FLOAT_H

typedef union
{
	float f;
	struct
	{
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	}	parts;
}	float_cast;

typedef union
{
  
	double f;
	struct
	{
		unsigned long mantisa : 52;
		unsigned long exponent : 11;
		unsigned long sign : 1;
	}   parts;
}	double_cast;

typedef union
{
  
	long double f;
	struct
	{
		unsigned long mantisa : 63;
		unsigned long exponent : 15;
		unsigned long  sign : 1;
	}   parts;
}   long_double_cast;

#endif