#include "ft_printf.h"

int main(void)
{
    char *string_to_print;
    long count;

    string_to_print = NULL;
    count = 80+32;
    ft_printf("hola %s\n%c", count, "asdasd");
}
