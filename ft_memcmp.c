/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:23:26 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/16 21:08:06 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcmp(void *dst, const void *src, size_t n)
{
	size_t	p;
	unsigned char *x;
	unsigned char *y;
	
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	p = 0;
	while (p < n)
	{
		x[p] = y[p];
	       p++;
	}
	return (x)
}	

