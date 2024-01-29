/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:01:15 by jhoratiu          #+#    #+#             */
/*   Updated: 2023/12/05 15:04:02 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
void	ft_write_string(char *str, int *len);
void	ft_write_pointer(void *ptr, int *len);
void	ft_write_decimal(int n, int *len);
void	ft_write_unsigned_decimal(unsigned int n, int *len);
void	ft_write_hexadecimal(unsigned int n, char c, int *len);
void	ft_putnbr_base(unsigned long n, char *base, int *len);
void	ft_putchar(char c, int *len);
int		ft_strlen(char *str);
int		ft_verifications(char c, va_list *args, int *length);

#endif