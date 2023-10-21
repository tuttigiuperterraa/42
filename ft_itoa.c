/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:01:42 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/19 19:18:37 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int magnitude(long n)
{
	int i;
	
	i = 0;
	if (n < 0)
		i++;
	while (n > 10)
	{
		n/=10;
		i++;
	}
	return (i);
}

char *ft_itoa(int n)
{
	long l;
	char *str;
	int i;
	
	l = (long)n;
	i = magnitude(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n=n*-1;
		str[0] = '-';
	}
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (n/10) + '0';
		i--;
	}
	return (str);
}
