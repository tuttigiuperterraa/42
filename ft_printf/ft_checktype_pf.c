/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:43:35 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:00 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checktype(char c, va_list arg_ptr, int size)
{
	if (c == 'c')
		size = ft_putchar(va_arg(arg_ptr, int));
	if (c == 's')
		size = ft_putstr(va_arg(arg_ptr, char *));
	if (c == 'p')
		size = ft_putpointer(va_arg(arg_ptr, void *),
				"0123456789abcdef", 0);
	if (c == 'd')
		size = ft_putnbr(va_arg(arg_ptr, int));
	if (c == 'i')
		size = ft_putnbr(va_arg(arg_ptr, int));
	if (c == 'u')
		size = ft_putunsigned(va_arg(arg_ptr, unsigned int));
	if (c == 'x')
		size = ft_putnbr_base(va_arg(arg_ptr, int), "0123456789abcdef");
	if (c == 'X')
		size = ft_putnbr_base(va_arg(arg_ptr, int), "0123456789ABCDEF");
	if (c == '%')
	{
		write (1, "%", 1);
		size = 1;
	}
	return (size);
}
