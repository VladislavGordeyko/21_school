#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// int				ft_printf(const char *str, ...);

int main()
{
    printf("%+d\n", -5);
    ft_printf("%+d\n", -5);
}