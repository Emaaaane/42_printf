/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlpfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-haj <imel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:14 by imel-haj          #+#    #+#             */
/*   Updated: 2024/11/29 14:28:34 by imel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
		ft_putnbr(n, len);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
}

void	ft_putnbr_hexa(unsigned int n, int *len, char c)
{
	char	*tab;

	if (c == 'X')
		tab = "0123456789ABCDEF";
	else if (c == 'x')
		tab = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, len, c);
		ft_putnbr_hexa(n % 16, len, c);
	}
	else
		ft_putchar(tab[n], len);
}

void	ft_putpointer(unsigned long n, int *len)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putpointer(n / 16, len);
		ft_putpointer(n % 16, len);
	}
	else
		ft_putchar(tab[n], len);
}

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
}

// int main()
// {
//     unsigned int i = 1258;
//     //write(1, "\n", 1);
//     ft_hexa(i, 'X');
// }
