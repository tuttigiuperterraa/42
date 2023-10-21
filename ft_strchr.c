/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/16 15:48:18 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#incluse "libft.h"

char *ft_strchr(const char *s, int c)
{		
	while (*s != '\0')
	{
		if (*s == (int)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*int	main()
{
	const char *str = "ciao";
	
	printf("mia %s \n", ft_strchr(str, 1));
	printf("sua %s \n", strchr(str, 1));
	
	return 0;
	}*/


