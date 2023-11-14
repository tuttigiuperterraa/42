/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:12:22 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:44 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_duplicates(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	while (i < len)
	{
		while (j > i)
		{
			if (base[i] == base[j] || base[i] == '-'
				|| base[i] == '+' || base[j] == '-'
				|| base[j] == '+')
				return (1);
			j--;
		}
		i++;
		j = len - 1;
	}
	return (0);
}

int	check_invalid(int len)
{
	if (len < 2)
		return (1);
	return (0);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long			len;
	unsigned int	nbrl;
	static int		st;

	st = 0;
	nbrl = (unsigned int)nbr;
	len = 0;
	while (base[len] != '\0')
		len++;
	if (check_invalid(len) || check_duplicates(base, len))
		return (0);
	if (nbr < 0)
		write(1, "-", 1);
	if (nbrl >= len)
		ft_putnbr_base((nbrl / len), base);
	write (1, &base[nbrl % len], 1);
	st++;
	return (st);
}

/*int	main(void)
{
	ft_putnbr_base(12, "01+");
	return (0);
}*/
