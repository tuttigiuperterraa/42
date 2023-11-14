/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:51:30 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/08 17:39:40 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		i;
	int		size;

	if (*str == '\0')
		return (0);
	va_start(arg_ptr, str);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			size += checktype(str[i + 1], arg_ptr, 0);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			size++;
		}
	}
	return (size);
}
