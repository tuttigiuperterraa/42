/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:19:46 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/17 18:33:52 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	p;
	
	p = 0;
	if (nmemb == 0 || size == 0 || (size * nmemb) > ULONG_MAX)
		return (NULL);
	arr = (void *)malloc(size * nmemb);
	if (arr == NULL)
		return (NULL);
	while (p < size * nmemb)
	{
		arr[p] = '\0';
		p++;
	}
	return (arr);
}
