/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:33:46 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:34 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr2(long nbl)
{
	char	numero;

	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = (-nbl);
	}
	numero = '0' + (nbl % 10);
	if (nbl >= 10)
		ft_putnbr2 (nbl / 10);
	write (1, &numero, 1);
}

int	ft_putnbr(int nb)
{
	int	size;
	long	nbl;
	
	nbl = (long)nb;
	ft_putnbr2(nbl);
	size = 0;
	if (nbl <= 0)
	{
		nbl *= -1;
		size++;
	}
	while (nbl > 0)
	{
		nbl /= 10;
		size++;
	}
	return (size);
}
/*int	main()
{
	ft_putnbr(42);
}*/
