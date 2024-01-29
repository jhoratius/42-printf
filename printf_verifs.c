/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_verifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:18 by jhoratiu          #+#    #+#             */
/*   Updated: 2023/12/05 15:03:25 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_write_string(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}	
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_write_pointer(void *ptr, int *len)
{
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	write(1, "0x", 2);
	*len += 2;
	ft_putnbr_base((unsigned long)ptr, "0123456789abcdef", len);
}

void	ft_write_decimal(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		*len += 2;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_write_decimal(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}
