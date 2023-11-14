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

long	long_convert(int nbr)  //forse posso togliere questa funzione e invece di convertire il neg in positivo lo casto a unsigned
{                              //questo perchè in questo modo si comporta come printf
	long	nbrl;

	nbrl = nbr;
	if (nbrl < 0)
		nbrl = -nbrl;
	return (nbrl);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long		nbrl;     //quindi questo no long ma unsigned int       
	static int	st;

	nbrl = long_convert(nbr); //è qui non uso la funzione ma lo casto a unsigned int
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
