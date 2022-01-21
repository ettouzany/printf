#include "ft_printf.h"


int main()
{
    int a = printf("%x\n%p\n%X\n", &main, &main, &main);
    ft_printf("%d\n", a);
    a = ft_printf("%x\n%p\n%X\n", &main, &main, &main);
    ft_printf("%d\n", a);
    return (0);
}