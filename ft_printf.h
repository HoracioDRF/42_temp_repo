/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horrodri <horrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:03:26 by horrodri          #+#    #+#             */
/*   Updated: 2025/08/17 19:03:31 by horrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* Main function */
int		ft_printf(const char *format, ...);
int		ft_parse_conversion(char specifier, va_list *args);

/* Conversion functions */
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_pointer(void *ptr);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);

/* Helper functions */
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif