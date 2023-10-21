/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:24:00 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/17 18:18:23 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_src + 1)
		return (len_dst);
	i = 0;
	while (src[i] != '\0' && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (src[i - 1] == '\0')
		dst[len_dst + i] = '\0';
	return (len_dst + i);
}


/*int	main()
{
	printf("mia %zu \n", ft_strlcat("dest", "src", 1));
	//printf("sua %d \n", strlcat("dest", "src", 1));
}*/
