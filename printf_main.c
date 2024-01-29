/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:43 by jhoratiu          #+#    #+#             */
/*   Updated: 2023/12/05 15:03:21 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_verifications(char c, va_list *args, int *length)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), length);
	else if (c == 's')
		ft_write_string(va_arg(*args, char *), length);
	else if (c == 'd' || c == 'i')
		ft_write_decimal(va_arg(*args, int), length);
	else if (c == 'u')
		ft_write_unsigned_decimal(va_arg(*args, unsigned int), length);
	else if (c == 'p')
		ft_write_pointer(va_arg(*args, void *), length);
	else if (c == 'x')
		ft_write_hexadecimal(va_arg(*args, unsigned int), 'x', length);
	else if (c == 'X')
		ft_write_hexadecimal(va_arg(*args, unsigned int), 'X', length);
	else if (c == '%')
		ft_putchar('%', length);
	return (*length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_verifications(str[i + 1], &args, &length);
			i++;
		}
		else
			ft_putchar(str[i], &length);
		i++;
	}
	return (length);
}
