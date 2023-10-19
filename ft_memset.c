/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:23:26 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/09 13:40:50 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t p;
	unsigned char	*q;
	
	q = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		q[p] = (unsigned char *)c;
	       p++;
	}
	return (q);
}	

