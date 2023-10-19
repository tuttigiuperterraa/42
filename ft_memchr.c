/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/16 19:12:08 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *conv;

	conv = (unsigned char *)s;
	while (n > 0)
	{
		if (*(conv++) == (unsigned char)c)
			return (--conv);
		n--;
	}
	return 0;
}

int	main()
{
	char *str = "ciao";
	
	printf("mia %s \n",(char *)ft_memchr(str, 0, 1));
	printf("sua %s \n", (char *)memchr(str, 0, 1));
	
	return 0;
	}


