/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/16 17:59:54 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	char *p;

	p = NULL;
	if (c == 0)
		return ("");
		
	while (*s != '\0')
	{
		if (*s == (int)c)
			p = (char *)s;
		s++;
	}
	return (p);
}

int	main()
{
	const char *str = "ciaocI";
	
	printf("mia %s \n", ft_strrchr(str,'h'));
	printf("sua %s \n", strrchr(str,'h'));
	
	return 0;
	}


