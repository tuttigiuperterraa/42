/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:26:52 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/17 17:32:03 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = 0;

	while (src[len_src] != '\0')
		len_src++;

	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst[i] != '\0')
		dst[i] = '\0';
	return (len_src);
}
/*
int main(void)
{
	char d[] = "ciao cla";
	char s[] = "come stai";
	printf("reale: %zu\n", strlcpy(d, s, 7));
	printf("mio: %zu\n", ft_strlcpy(d, s, 7));
}*/
