/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-haj <imel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:44:49 by imel-haj          #+#    #+#             */
/*   Updated: 2024/11/30 18:56:41 by imel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_var(char var, va_list args, int *len)
{
	if (var == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (var == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (var == 'd' || var == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (var == 'p')
	{
		ft_putstr("0x", len);
		ft_putpointer(va_arg(args, unsigned long), len);
	}
	else if (var == 'X' || var == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), len, var);
	else if (var == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (var == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (0);
		if (format[i] == '%')
		{
			check_var(format[i + 1], args, &len);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
