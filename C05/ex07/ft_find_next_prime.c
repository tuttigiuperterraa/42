/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:29:43 by gcosenza          #+#    #+#             */
/*   Updated: 2023/08/05 16:33:08 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	i = nb - 1;
	while (i > 1)
	{
		if (nb % i == 0)
		{
			nb += 1;
			ft_find_next_prime(nb);
		}
		i--;
	}
	return (nb);
}
/*int	main()
{
	printf("%d\n", ft_find_next_prime(1445926260));
}*/
