/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:17:03 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/17 22:19:56 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
//#include <unistd.h>
//#include <stdio.h>


char	*allocate(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*strjoin;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len = len + (ft_strlen(sep) * (size - 1));
	strjoin = (char *) malloc(sizeof(char) * (len + 1));
	return (strjoin);
}

char	*fill(char *strjoin, int size, char **strs, char *sep)
{
	int	i;
	int	q;
	int	j;
	int	k;

	i = 0;
	q = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			strjoin[q++] = strs[i][j++];
		k = 0;
		while (sep[k] != '\0' && i < size - 1)
			strjoin[q++] = sep[k++];
		i++;
	}
	strjoin[q] = '\0';
	return (strjoin);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;

	if (size > 0)
	{
		strjoin = allocate(size, strs, sep);
		fill(strjoin, size, strs, sep);
	}
	else
		strjoin = (char *) malloc(sizeof(char));
	return (strjoin);
}
