/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:12:22 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:55 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_invalid(int len);
int	check_duplicates(char *base, int len);

int	ft_putpointer(unsigned int nbr, char *base, int count)
{
	int			len;
	long		nbrl;
	static int	st;

	nbrl = (long)nbr;
	len = 0;
	if (count == 0)
		write(1, "0x", 2);
	count++;
	while (base[len] != '\0')
		len++;
	if (check_invalid(len) || check_duplicates(base, len))
		return (0);
	if (nbrl >= len)
		ft_putnbr_base((nbrl / len), base);
	write (1, &base[nbrl % len], 1);
	st++;
	return (st + 2);
}

/*int	main(void)
{
	ft_putnbr_base(12, "01+");
	return (0);
}*/
