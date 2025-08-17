/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horrodri <horrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:30:00 by student           #+#    #+#             */
/*   Updated: 2025/08/17 19:00:42 by horrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_format_char(const char *format, int *i, va_list *args)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1])
		{
			(*i)++;
			return (ft_parse_conversion(format[*i], args));
		}
		return (0);
	}
	else
	{
		write(1, &format[*i], 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	if (!format)
		return (-1);
	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		printed_chars += ft_process_format_char(format, &i, &args);
		i++;
	}
	va_end(args);
	return (printed_chars);
}

int	ft_parse_conversion(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}
