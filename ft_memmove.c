/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:23:26 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/09 13:49:40 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	size_t	p;
	unsigned char *x;
	unsigned char *y;

	x = (unsigned char *)dst;
	y = (unsigned char *)src;

	p = 0;
	while (p < n)
	{
		tmp[p] = y[p];
	       p++;
	}
	p = 0;
	while (p < n)
	{
		x[p] = tmp[p];
		p++;
	}
	return (x);
}	

