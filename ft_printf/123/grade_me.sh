#clang ft_printf.c ft_printf_utils.c main.c -L. -lft && ./a.out > my_results.txt
#clang ft_memcpy.c ft_strlen.c ft_atoi.c ft_toupper.c ft_strjoin.c \
#ft_printf.c ft_printf_utils.c ft_strdup.c ft_memmove.c ft_substr.c ft_strlcpy.c \
#main.c &&  ./a.out  #> my_results.txt
make re
clang main.c -L. -lftprintf && ./a.out #> MYresults.txt
