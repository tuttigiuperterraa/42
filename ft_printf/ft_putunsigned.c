/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:33:46 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/13 19:58:23 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned2(int nb)
{
	long	nbl;
	char	numero;

	nbl = (unsigned int)nb;
	numero = '0' + (nbl % 10);
	if (nbl >= 10)
		ft_putunsigned2 (nbl / 10);
	write (1, &numero, 1);
}

int	ft_putunsigned(int nb)
{
	int				size;
	unsigned int	unb;

	unb = (unsigned int)nb;
	if (unb == 0)
	{
	    write (1, "0", 1);
	    return (1);
	}
	ft_putunsigned2(nb);
	size = 0;
	while (unb > 0)
	{
		unb /= 10;
		size++;
	}
	return (size);
}
/*int	main()
{
	ft_putnbr(42);
}*/
