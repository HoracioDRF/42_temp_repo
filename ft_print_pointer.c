/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horrodri <horrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:02:50 by horrodri          #+#    #+#             */
/*   Updated: 2025/08/17 19:02:52 by horrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_long(unsigned long n);

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				len;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	len = 2 + ft_print_hex_long(address);
	return (len);
}

static int	ft_print_hex_long(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_print_hex_long(n / 16);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
}
