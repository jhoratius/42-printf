/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_verifs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:50:13 by jhoratiu          #+#    #+#             */
/*   Updated: 2023/12/05 15:03:28 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_write_unsigned_decimal(unsigned int n, int *len)
{
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_write_unsigned_decimal(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_write_hexadecimal(unsigned int n, char c, int *len)
{
	if (c == 'x')
		ft_putnbr_base(n, "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base(n, "0123456789ABCDEF", len);
}

int	ft_hexa_conditions(int n, int next)
{
	if (n < 48 || n > 57)
		return (0);
	if (n == next)
		return (0);
	return (1);
}

void	ft_putnbr_base(unsigned long n, char *base, int *len)
{
	int	i;
	int	buff[100];
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (n == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	while (n)
	{
		buff[i++] = n % base_len;
		n /= base_len;
	}
	while (--i >= 0)
		ft_putchar(base[buff[i]], len);
}
