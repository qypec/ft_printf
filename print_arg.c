 #include "header.h"

// 'd' // 'i' // 'o' // 'u' // 'X' // 'x' int 

// f // e // 'g'  float

// 'c' // 's' // // 'p'  string and char and point  
 
// 'к'     
// 'k'   
// '%'  
// 'b'

void            width_processing(t_spec *spec, char *str)
{
    int     size;
    int     width;

    width = 0;
    size = ft_strlen(str);
    if (spec->width - size >= 0)
        width = spec->width - size;
    if (spec->minus == 1)
        addstr_glbuffer(str, size);
    if (spec->zero == 1)
    {
        while (width--)
            addsymb_glbuffer('0');
    }
    else
    {
        while (width--)
            addsymb_glbuffer(' ');
    }
    if (spec->minus != 1)
        addstr_glbuffer(str, size);
}

int             print_arg(char *traverse, t_spec *spec, va_list arg)
{
    if (spec->symb == 'k')
    	print_date(traverse, arg);
    if (spec->symb == '%')
        width_processing(spec, "%");
    // if (spec->symb == 'd' || spec->symb == 'i' || spec->symb == 'o' || spec->symb == 'u' || spec->symb == 'x' || spec->symb == 'X')
        // assembly_int(spec, arg);
    // if (spec->symb == 'c' || spec->symb == 's' || spec->symb == 'p')
        // size_len = print_char(spec, arg);
          // if (spec->symb == 'f' || spec->symb == 'e' || spec->symb == 'g')
    //     size = print_float(spec, arg);
    return (0);
}
