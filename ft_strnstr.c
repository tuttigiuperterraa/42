/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:33:00 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/16 19:23:16 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p_big;
	const char	*p_little;
	int	i;
	
	i = 0;
	if (*little == '\0')
		return ((char *)big); 
	while (*big != '\0')
	{
		p_big = big;
		p_little = little;
		while (*p_big == *p_little && *p_little != '\0' && len > 0)
		{
			p_big++;
			p_little++;
			len--;
		}
		if (*p_little == '\0')
			return ((char *)big);
		big++;
	}
	return (0);
}
/*int main()
{
	char str[40] = "canegatocttane";
	char to_find[40] = "tane";
	char *dest;
	
	dest = ft_strnstr(str, to_find, 20);
	
	printf("mio %s\n", dest);
	printf("vero %d\n", strnstr(str, to_find, 20));
}*/
